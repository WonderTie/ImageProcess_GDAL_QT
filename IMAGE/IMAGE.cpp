#include "IMAGE.h"

IMAGE::IMAGE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	poDataest = NULL;
	file = "";
	init_tran();
	counter_ = false;
	image_color = false;
	treeview = new QStandardItemModel;
	tableview = new QStandardItemModel;
	laplace = new Dialog_weight;
	gaussian_ = new Dialog_Gaussian_Filter;
	liner_enhancement = new Dialog_slider_line;
	region = new Dialog_region_growing;
	tableview->setColumnCount(2);
	ui.graphicsView->setMouseTracking(true);//鼠标移动事件
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(open_image()));

	connect(ui.actionsave, SIGNAL(triggered()), this, SLOT(save()));
	connect(ui.actionGRAY, SIGNAL(triggered()), this, SLOT(rgb2gray()));
	connect(ui.actionLaplace, SIGNAL(triggered()), this, SLOT(open_Laplace()));
	connect(laplace, SIGNAL(send_laplace_par(QVariant)), this, SLOT(receive_laplace_par(QVariant)));
	connect(ui.actionImage_linear_enhancement, SIGNAL(triggered()), this, SLOT(open_image_linear_enhancement()));
	connect(liner_enhancement, SIGNAL(send_line(int)), this, SLOT(receive_image_linear_enhancement_max_value(int)));
	connect(liner_enhancement, SIGNAL(send_line_min(int)), this, SLOT(receive_image_linear_enhancement_min_value(int)));
	connect(this, SIGNAL(send_line_value(int,int)), liner_enhancement, SLOT(receive_par(int,int)));
	connect(ui.actionRegion_growing, SIGNAL(triggered()), this, SLOT(open_dialog_region_grwoing()));
	connect(region, SIGNAL(send_auto_region_par(QVariant)), this, SLOT(receive_region_auto(QVariant)));
	connect(region, SIGNAL(send_peo_region_par(QVariant)), this, SLOT(receive_region_peo(QVariant)));
	connect(ui.actionGuassian, SIGNAL(triggered()), this, SLOT(open_gaussian()));
	connect(gaussian_, SIGNAL(send_guassian_matrix(QVariant)), this, SLOT(receive_guassian_par(QVariant)));
}

void IMAGE::show_image_opencv(Mat *image_){
 	MAT2QImage(image_);//mat格式转Qimage格式
	QGraphicsPixmapItem *image_view = new QGraphicsPixmapItem(QPixmap::fromImage(qimage_));
	QGraphicsScene *myScene = new QGraphicsScene();
	myScene->addItem(image_view);
	ui.graphicsView->setScene(myScene);
}
Mat IMAGE::rgb2gray(){
	if (opencv_image.type()==CV_8UC1)
	{
		QMessageBox::critical(this, tr("ERROR"), tr("One Bands do not Convert to Gray ! Please Choose Another Image"));
		return opencv_image;
	}
	else{
		cvtColor(opencv_image, opencv_image, CV_RGB2GRAY);
		show_image_opencv(&opencv_image);
		tableview->setItem(5, 1, new QStandardItem(QString::number(1)));
		return opencv_image;
	}
}
Mat IMAGE::init_image_opencv(GDALDataset*podataest){
	int rows = podataest->GetRasterYSize();
	int cols = podataest->GetRasterXSize();
	int channels = podataest->GetRasterCount();
	Mat R(rows, cols, CV_8UC1, Scalar(0));//to save R img
	Mat G(rows, cols, CV_8UC1, Scalar(0));//to save G img
	Mat B(rows, cols, CV_8UC1, Scalar(0));//to save B img
	Mat GRAY(rows, cols, CV_8UC1, Scalar(255));//to save B img
	vector<Mat> RGB(channels, cv::Mat(rows, cols, CV_8UC3, Scalar(0)));//create RGB channels
	if (channels==1)
	{
		GDALRasterBand* band = podataest->GetRasterBand(1);
		// Read the band 1 data
		band->RasterIO(GF_Read, 0, 0, cols, rows, GRAY.data, cols, rows, GDT_Byte, 0, 0);
		opencv_image = GRAY;
		return opencv_image;
	}
	else{
		// 6、get data
		// Fetch the band 1
		GDALRasterBand* band = podataest->GetRasterBand(1);
		// Read the band 1 data
		band->RasterIO(GF_Read, 0, 0, cols, rows, B.data,
			cols, rows, GDT_Byte, 0, 0);
		// Fetch the band 2
		band = podataest->GetRasterBand(2);
		// Read the band 2 data
		band->RasterIO(GF_Read, 0, 0, cols, rows, G.data,
			cols, rows, GDT_Byte, 0, 0);
		// Fetch the band 3
		band = podataest->GetRasterBand(3);
		// Read the band 3 data
		band->RasterIO(GF_Read, 0, 0, cols, rows, R.data,
			cols, rows, GDT_Byte, 0, 0);
		RGB[0] = R;
		RGB[1] = G;
		RGB[2] = B;
		// 8、Merge images,合并通道数据
		cv::merge(RGB, opencv_image);
		//cvtColor(opencv_image, opencv_image, CV_RGB2GRAY);
		//imwrite("C:\\Users\\Administrator\\Desktop\\gary.tif", opencv_image);
		return opencv_image;
	}
}
void IMAGE::init_tran(){
	for (int i = 0; i < 6; i++){
		tranform[i] = 0;
	}
}
void IMAGE::init_label(){
	ui.imagex->setText(QString::number(0));
	ui.imagey->setText(QString::number(0));
	ui.prox->setText(QString::number(0));
	ui.proy->setText(QString::number(0));
}
void IMAGE::open_image(){//打开图像文件
	init_tran();
	init_label();
    file = QFileDialog::getOpenFileName(this, tr("Open image"), ".", tr("Open Image flies(*.tif *.tiff *.bmp *.jpg *.pbm *.pgm *.png *.ppm *.xbm *.xpm)"));
	GDALAllRegister();
	poDataest = (GDALDataset*)GDALOpen(file.toStdString().c_str(), GA_ReadOnly);
	if (poDataest==NULL)
	{
		QMessageBox::critical(this, tr("read flase!"), tr("Can not read image %1").arg(file));
		return;
	}
	init_image_opencv(poDataest);//将GDAL读入的影像转入opencv
	show_tableview();
	show_treeview();
	int bands_counts = poDataest->GetRasterCount();
	if (bands_counts!=3)
	{
		image_color = false;
		GDALRasterBand *band_grey = poDataest->GetRasterBand(1);
		showband(band_grey);
	}
	else
	{
		image_color = true;
		vector<GDALRasterBand*>vec_bands;
		vec_bands.push_back(poDataest->GetRasterBand(1));
		vec_bands.push_back(poDataest->GetRasterBand(2));
		vec_bands.push_back(poDataest->GetRasterBand(3));
		showimage(&vec_bands);
	}
}
void IMAGE::save() {
	QString filename = QFileDialog::getSaveFileName(this,
		tr("Save Image"),
		"",
		tr("*.bmp;; *.png;; *.jpg;; *.tif;; *.tiff")); //选择路径
	if (filename.isEmpty())
	{
		return;
	}
	else
	{
		if (!(save_image(filename))) //保存图像
		{

			QMessageBox::information(this,
				tr("Failed to save the image"),
				tr("Failed to save the image!"));
			return;
		}
		ui.statusBar->showMessage(QString::fromLocal8Bit("图片保存成功!"), 3000);
	}
	

}

int IMAGE::save_image(QString filename) {//保存图像文件

	if (opencv_image.empty())    //    判断是否为空
		return 0;

	const int nBandCount = opencv_image.channels();
	const int nImgSizeX = opencv_image.cols;
	const int nImgSizeY = opencv_image.rows;
	GDALAllRegister();
	GDALDataset *poDataset;   //GDAL数据集
	GDALDriver *poDriver;      //驱动，用于创建新的文件
	poDriver = GetGDALDriverManager()->GetDriverByName("Gtiff");

	if (poDriver == NULL)
		return 0;

	poDataset = poDriver->Create(filename.toStdString().c_str(), nImgSizeX, nImgSizeY, nBandCount,
		GDT_Byte, NULL);
	  //循环写入文件
	int nl = nImgSizeY;
	int nc = nImgSizeX;
	vector<Mat> channels;
	GDALRasterBand*pBand=NULL;
	split(opencv_image, channels);
	Mat tmpMat;
	for (int n = 1; n <= nBandCount; n++)
	{
		pBand=poDataset->GetRasterBand(nBandCount-n+1);
		tmpMat = channels.at(n-1).clone();
		pBand->RasterIO(GF_Write, 0, 0, nImgSizeX, nImgSizeY,
			tmpMat.data, nImgSizeX, nImgSizeY, GDT_Byte, 0, 0);
		tmpMat.release();
		pBand = NULL;
	}
	GDALClose(poDataset);
	return 1;
}


void IMAGE::showband(GDALRasterBand* image_band){
	if (image_band == NULL)
	{
		return;
	}
	vector<GDALRasterBand*>vec_bands;
	vec_bands.push_back(image_band);
	vec_bands.push_back(image_band);
	vec_bands.push_back(image_band);

	showimage(&vec_bands);
}
void IMAGE::showimage(vector<GDALRasterBand *>*imgBand){
	if (imgBand->size() != 3){ return; }
	int imgwidth = imgBand->at(0)->GetXSize();
	int imgheight = imgBand->at(0)->GetYSize();

	img_scale_height = 1; 

	int new_scale_width = int(imgwidth*img_scale_height - 1);
	int new_scale_height = int(imgheight*img_scale_height - 1);

	int new_size = new_scale_height*new_scale_width;

	float *rband = new float[new_size];
	float *gband = new float[new_size];
	float *bband = new float[new_size];

	unsigned char *Rband, *Gband, *Bband;

	if (image_color)
	{
		imgBand->at(0)->RasterIO(GF_Read, 0, 0, imgwidth, imgheight, rband, new_scale_width, new_scale_height, GDT_Float32, 0, 0);
		imgBand->at(1)->RasterIO(GF_Read, 0, 0, imgwidth, imgheight, gband, new_scale_width, new_scale_height, GDT_Float32, 0, 0);
		imgBand->at(2)->RasterIO(GF_Read, 0, 0, imgwidth, imgheight, bband, new_scale_width, new_scale_height, GDT_Float32, 0, 0);
		Rband = imgsketch(rband, imgBand->at(0), new_size);
		Gband = imgsketch(gband, imgBand->at(0), new_size);
		Bband = imgsketch(bband, imgBand->at(0), new_size);
	}
	else
	{
		imgBand->at(0)->RasterIO(GF_Read, 0, 0, imgwidth, imgheight, rband, new_scale_width, new_scale_height, GDT_Float32, 0, 0);
		Rband = imgsketch(rband, imgBand->at(0), new_size);
		Gband = Rband;
		Bband = Rband;
	}

	int bytePerLine = (new_scale_width * 24 + 31) / 8;
	unsigned char* allBandUC = new unsigned char[bytePerLine * new_scale_height];
	for (int h = 0; h < new_scale_height; h++)
	{
		for (int w = 0; w < new_scale_width; w++)
		{
			allBandUC[h * bytePerLine + w * 3 + 0] = Rband[h * new_scale_width + w];
			allBandUC[h * bytePerLine + w * 3 + 1] = Gband[h * new_scale_width + w];
			allBandUC[h * bytePerLine + w * 3 + 2] = Bband[h * new_scale_width + w];
		}
	}
	QGraphicsPixmapItem *image_view = new QGraphicsPixmapItem(QPixmap::fromImage(QImage(allBandUC, new_scale_width, new_scale_height, bytePerLine, QImage::Format_RGB888)));
	QGraphicsScene *myScene = new QGraphicsScene();
	myScene->addItem(image_view);
	//int nwidth = ui.graphicsView->width();
	//int nheight = ui.graphicsView->height();
	//ui.graphicsView->setSceneRect(QRectF(-(nwidth / 2), -(nheight / 2), nwidth, nheight));
	ui.graphicsView->setScene(myScene);
}
void IMAGE::show_tableview(){
	int rows_ = 0;
	tableview->setHorizontalHeaderLabels(QStringList() << QStringLiteral("数据类型") << QStringLiteral("数值"));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Description")));
	tableview->setItem(rows_++, 1, new QStandardItem(poDataest->GetDriver()->GetDescription()));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Meta Infor")));
	tableview->setItem(rows_++, 1, new QStandardItem(poDataest->GetDriver()->GetMetadataItem(GDAL_DMD_LONGNAME)));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Data Type")));
	tableview->setItem(rows_++, 1, new QStandardItem(GDALGetDataTypeName((poDataest->GetRasterBand(1)->GetRasterDataType()))));

	tableview->setItem(rows_, 0, new QStandardItem(tr("X Size")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(poDataest->GetRasterXSize())));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Y Size")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(poDataest->GetRasterYSize())));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Bands Size")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(poDataest->GetRasterCount())));


	int depth = GDALGetDataTypeSize(poDataest->GetRasterBand(1)->GetRasterDataType()) / 8;    //图像深度
	tableview->setItem(rows_, 0, new QStandardItem(tr("depth")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(depth)));

	

	tableview->setItem(rows_, 0, new QStandardItem(tr("Projection")));
	tableview->setItem(rows_++, 1, new QStandardItem(poDataest->GetProjectionRef()));

	QString origin = "";
	QString pixelSize = "";
	double transform_[6];
	if (poDataest->GetGeoTransform(transform_)==CE_None)
	{
		for (int i = 0; i < 6;i++)
		{
			tranform[i] = transform_[i];
		}
		origin = QString::number(transform_[0]) + "," + QString::number(transform_[3]);
		pixelSize = QString::number(transform_[1]) + ", " + QString::number(transform_[5]);
	}
	tableview->setItem(rows_, 0, new QStandardItem(tr("Origin")));
	tableview->setItem(rows_++, 1, new QStandardItem(origin));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Pixel Size")));
	tableview->setItem(rows_++, 1, new QStandardItem(pixelSize));
	
	minMaxLoc(opencv_image, &image_min_grey, &image_max_grey);
	tableview->setItem(rows_, 0, new QStandardItem(tr("Max Gray")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(image_max_grey)));
	tableview->setItem(rows_, 0, new QStandardItem(tr("Min Gray")));
	tableview->setItem(rows_++, 1, new QStandardItem(QString::number(image_min_grey)));
	ui.tableView->setModel(tableview);
}





void IMAGE::show_treeview(){
	treeview->setHorizontalHeaderLabels(QStringList() << QStringLiteral("影像名"));
	QStandardItem *parent_ = new QStandardItem(file);
	for (int i = 0; i < poDataest->GetRasterCount();i++)
	{
		QStandardItem *son_ = new QStandardItem(tr("Band %1").arg(i+1));
		parent_->setChild(i,son_);
	}
	treeview->setItem(0, parent_);
	
	ui.treeView->setModel(treeview);

}
unsigned char * IMAGE::imgsketch(float*buffer, GDALRasterBand* now_band, int band_size){
	unsigned char * new_result = new unsigned char[band_size];
	double max_min_image[2];
	now_band->ComputeRasterMinMax(1,max_min_image);
	double min_image = max_min_image[0];
	double max_image = max_min_image[1];

	double nodata = now_band->GetNoDataValue();
	if (nodata>=min_image&&nodata<=max_image)
	{
		min_image = 0;
	}

	for (int i = 0; i < band_size;i++)
	{
		if (buffer[i]==min_image)
		{
			new_result[i] = 0;
		}
		else if (buffer[i]>max_image)
		{
			new_result[i] = 255;
		}
		else
		{
			new_result[i] = static_cast<uchar>(((buffer[i] - min_image) / (max_image - min_image)) * 255);
		}
	}
	return new_result;
}

void IMAGE::ScaleImg(QWheelEvent *event, double factor){
 	img_scale_height *= factor;
	QMatrix matrix;
 	matrix.scale(img_scale_height, img_scale_height);
 	ui.graphicsView->setMatrix(matrix);
};
void IMAGE::mousePressEvent(QMouseEvent *event)
{
	// 滚轮键按下，平移图像
	if (event->button() == Qt::MidButton)
	{
		ui.graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
		ui.graphicsView->setInteractive(false);
		lastEventCursorPos = event->pos();
	}
	if (event->button() == Qt::LeftButton)
	{
		QPoint global_point = event->globalPos();//获取鼠标拾取的点
		point_ = ui.graphicsView->mapFromGlobal(global_point);//将点转化为graphicsView控件内实际的点坐标
		ui.imagex->setText(QString::number(point_.x()));
		ui.imagey->setText(QString::number(point_.y()));
		if ((tranform[0] != 0 || tranform[1] != 0 || tranform[2] != 0))
		{
			double Xp = tranform[0] + point_.x()*tranform[1] + point_.y()*tranform[2];
			double Yp = tranform[3] + point_.x()*tranform[4] + point_.y()*tranform[5];
			ui.prox->setText(QString::number(Xp));
			ui.proy->setText(QString::number(Yp));
		}
	}
}

void IMAGE::mouseMoveEvent(QMouseEvent *event)
{
	if (ui.graphicsView->dragMode() == QGraphicsView::ScrollHandDrag)
	{
		QPoint delta = (event->pos() - lastEventCursorPos) / 10;
		ui.graphicsView->horizontalScrollBar()->setValue(ui.graphicsView->horizontalScrollBar()->value() + (isRightToLeft() ? delta.x() : -delta.x()));
		ui.graphicsView->verticalScrollBar()->setValue(ui.graphicsView->verticalScrollBar()->value() - delta.y());
		ui.graphicsView->viewport()->setCursor(Qt::ClosedHandCursor);
	}

}
void IMAGE::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::MidButton)
	{
		ui.graphicsView->setDragMode(QGraphicsView::NoDrag);
	}
}
void IMAGE::wheelEvent(QWheelEvent *event)
{
	// 滚轮向上滑动，放大图像
	if (event->delta() > 0)
	{
		ZoomIn();
	}
	// 滚轮向下滑动，缩小图像
	if (event->delta() < 0)
	{
		ZoomOut();
	}
}
void IMAGE::add_information_coordinate(QPoint *point_, double Xp, double Yp){
	ui.imagex->setText(QString::number(point_->x()));
	ui.imagey->setText(QString::number(point_->y()));
	ui.prox->setText(QString::number(Xp));
	ui.proy->setText(QString::number(Yp));
}
void IMAGE::MAT2QImage(Mat *image_){
	// 8-bits unsigned, NO. OF CHANNELS = 1
	if (image_->type() == CV_8UC1)
	{
		//qDebug() << "CV_8UC1";
		QImage image(image_->cols, image_->rows, QImage::Format_Indexed8);
		// Set the color table (used to translate color indexes to qRgb values)
		image.setColorCount(256);
		for (int i = 0; i < 256; i++)
		{
			image.setColor(i, qRgb(i, i, i));
		}
		// Copy input Mat
		uchar *pSrc = image_->data;
		for (int row = 0; row < image_->rows; row++)
		{
			uchar *pDest = image.scanLine(row);
			memcpy(pDest, pSrc, image_->cols);
			pSrc += image_->step;
		}
		qimage_= image;
	}
	// 8-bits unsigned, NO. OF CHANNELS = 3
	else if (image_->type() == CV_8UC3)
	{
		//qDebug() << "CV_8UC3";
		// Copy input Mat
		const uchar *pSrc = (const uchar*)image_->data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, image_->cols, image_->rows, image_->step, QImage::Format_RGB888);
		qimage_= image.rgbSwapped();
	}
	else if (image_->type() == CV_8UC4)
	{
		//qDebug() << "CV_8UC4";
		// Copy input Mat
		const uchar *pSrc = (const uchar*)image_->data;
		// Create QImage with same dimensions as input Mat
		QImage image(pSrc, image_->cols, image_->rows, image_->step, QImage::Format_ARGB32);
		qimage_= image.copy();
	}
	else
	{
		QMessageBox::critical(this, tr("ERROR"), tr("ERROR: Mat could not be converted to QImage ! Please Choose Another Image"));
	}
}
void IMAGE::open_Laplace(){
	laplace->show();
	laplace->setModal(true);
}
void IMAGE::receive_laplace_par(QVariant var){
	weight_laplace lap;
	lap = var.value<weight_laplace>();

	Mat result;
	int rows_ = opencv_image.rows;
	int cols_ = opencv_image.cols;
	int nchannels = opencv_image.channels();
	result.create(opencv_image.size(), opencv_image.type());
	Vec3b temp_rgb;
	for (int i_rows = 1; i_rows < rows_ - 1; i_rows++)
	{
		const uchar *priv_ = opencv_image.ptr<const uchar>(i_rows - 1);
		const uchar *curr_ = opencv_image.ptr<const uchar>(i_rows);
		const uchar *next_ = opencv_image.ptr<const uchar>(i_rows + 1);
		uchar *output_ = result.ptr<uchar>(i_rows);
		for (int i_cols = nchannels; i_cols < (cols_ - 1)*nchannels; i_cols++)//彩色图像需要考虑通道数
		{
			*output_++ = saturate_cast<uchar>(
				lap.weight[4] * curr_[i_cols] + curr_[i_cols - nchannels] * lap.weight[3] + curr_[i_cols + nchannels] * lap.weight[5]
				+ priv_[i_cols] * lap.weight[1] + priv_[i_cols - nchannels] * lap.weight[0] + priv_[i_cols + nchannels] * lap.weight[2]
				+ next_[i_cols] * lap.weight[7] + next_[i_cols - nchannels] * lap.weight[6] + next_[i_cols + nchannels] * lap.weight[8]);
		}
	}
	result.row(0).setTo(Scalar(0, 0, 0));
	result.row(result.rows - 1).setTo(Scalar(0, 0, 0));
	result.col(0).setTo(Scalar(0, 0, 0));
	result.col(result.cols - 1).setTo(Scalar(0, 0, 0));
	opencv_image = result;
	show_image_opencv(&opencv_image);
}
void IMAGE::open_image_linear_enhancement(){
	line_enhancement_max = int(image_max_grey);
	line_enhancement_min = int(image_min_grey);
	emit send_line_value(line_enhancement_max, line_enhancement_min);
	liner_enhancement->show();
	liner_enhancement->setModal(false);
	counter_ = true;
}
void IMAGE::line_shrink(Mat input_image, Mat &output_image, int max_, int min_){
	output_image.create(input_image.size(), CV_8UC1);
	uchar gray_;
	int temp;
	int pix_num = input_image.rows*input_image.cols;
	for (int i = 0; i < pix_num; i++)
	{
		gray_ = input_image.at<uchar>(i);
		temp = int(((int)(gray_)-(int)(image_min_grey))  * double((max_ - min_) / (image_max_grey - image_min_grey)) + min_);
		output_image.at<uchar>(i) = saturate_cast<uchar>(temp);
	}
}
void IMAGE::operate_image_linear_enhancement(){
	int max_gray = line_enhancement_max;
	int min_gray = line_enhancement_min;
	
	if (opencv_image.type()==CV_8UC1)
	{
		Mat grey;
		line_shrink(opencv_image, grey, max_gray, min_gray);
		show_image_opencv(&grey);
	}
	else if (opencv_image.type()==CV_8UC3)
	{
		Mat R, G, B,R_,G_,B_,output_image;
		vector<Mat> newChannels;
		split(opencv_image, newChannels);
		R = newChannels[0];
		G = newChannels[1];
		B = newChannels[2];
		line_shrink(R, R_, max_gray, min_gray);
		line_shrink(G, G_, max_gray, min_gray);
		line_shrink(B, B_, max_gray, min_gray);
		newChannels[0] = R_;
		newChannels[1] = G_;
		newChannels[2] = B_;

		merge(newChannels, output_image);
		show_image_opencv(&output_image);

	}
	else
	{
		QMessageBox::critical(this,tr("ERROR"), tr("This format image is not supported temporarily"));
	}

}

void IMAGE::receive_image_linear_enhancement_max_value(int max_value){
	line_enhancement_max = max_value;
	if (counter_){ operate_image_linear_enhancement(); }

}
void IMAGE::receive_image_linear_enhancement_min_value(int min_value){
	line_enhancement_min = min_value;
	if (counter_){ operate_image_linear_enhancement(); }
}


void IMAGE::open_dialog_region_grwoing(){
	region->show();
	region->setModal(false);
}
void IMAGE::receive_region_auto(QVariant par_auto){
	region_par auto_reg;
	auto_reg = par_auto.value<region_par>();
	Mat clusters_image;
	region_growing_sf region_auto;
	region_auto.method = auto_reg.method;
	region_auto.min_number = auto_reg.min_number;
	region_auto.threshold_ = auto_reg.gray_diff_auto;
	region_auto.set_input_image(&opencv_image);
	region_auto.region_Auto();
	region_auto.output_image(clusters_image);
	show_image_opencv(&clusters_image);
}
void IMAGE::receive_region_peo(QVariant par_peo){
	region_par peo_reg;
	peo_reg = par_peo.value<region_par>();
	vector<vector<Point2i>>cluster_;
	Mat clusters_image;
	region_growing_sf region_peo_;
	region_peo_.threshold_ = peo_reg.gray_diff_peo;;
	Point2i seed;
	seed.x = int(point_.x());
	seed.y = int(point_.y());
	region_peo_.set_input_image(&opencv_image);
	region_peo_.region_peo(seed);
	region_peo_.output_image(clusters_image);
	show_image_opencv(&clusters_image);
}
void IMAGE::open_gaussian(){
	gaussian_->show();
	gaussian_->setModal(true);
}
void IMAGE::receive_guassian_par(QVariant par_guassian){
	guassian_par par;
	par = par_guassian.value<guassian_par>();
	guassian guassian_;
	opencv_image = guassian_.Gaussian_read(&opencv_image, par.windows_size, par.sigma, par.array_,par.weight_direction_);
	show_image_opencv(&opencv_image);
}
