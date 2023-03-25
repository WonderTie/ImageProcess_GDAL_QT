#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/types_c.h>

#include <QtWidgets/QMainWindow>
#include "ui_IMAGE.h"
#include "gdal_priv.h"
#include <QMessageBox>
#include <QFileDialog>
#include <vector>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QStandardItemModel>
#include<QWheelEvent>
#include<QScrollBar>
#include <QPoint>
#include<QGraphicsSceneMouseEvent >
#include <QLabel>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include "dialog_slider_line.h"
#include <QTreeView>

//子窗口
#include"dialog_weight.h"
#include"../Region_growing/region_growing.h"
#include "dialog_region_growing.h"
#include "../Gaussian_Filter/dialog_gaussian_filter.h"


using namespace cv;
using namespace std;
class IMAGE : public QMainWindow
{
    Q_OBJECT
public slots:
	void open_image();
	int save_image(QString filename);
	void save();
	Mat rgb2gray();
	
	void open_Laplace();
	void receive_laplace_par(QVariant var);
	void open_image_linear_enhancement();
	void receive_image_linear_enhancement_max_value(int max_value);
	void receive_image_linear_enhancement_min_value(int min_value);
	void operate_image_linear_enhancement();
	
	void open_dialog_region_grwoing();
	void receive_region_auto(QVariant par_auto);
	void receive_region_peo(QVariant par_peo);
	void open_gaussian();
	void receive_guassian_par(QVariant par_guassian);
signals:
	void send_line_value(int max_value,int min_value);
public:
    IMAGE(QWidget *parent = Q_NULLPTR);
	GDALDataset *poDataest;
	template<typename T>Mat Shrink(vector<vector<T>>input_image);
	template<typename T>std::vector<T>vector_normalization(std::vector<T> vector_input);
protected:
	void wheelEvent(QWheelEvent *event);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);
	void mouseReleaseEvent(QMouseEvent *event);
private:
	void MAT2QImage(Mat *image_);
	void show_image_opencv(Mat *image_);
	void init_tran();
	void init_label();
	Mat init_image_opencv(GDALDataset*podataest);
	void add_information_coordinate(QPoint *point_, double Xp, double Yp);
	void show_tableview();
	void show_treeview();


	void showband(GDALRasterBand* image_band);
	void showimage(vector<GDALRasterBand*>*imgBand);
	unsigned char * imgsketch(float*buffer,GDALRasterBand* now_band,int band_size);
	void line_shrink(Mat input_image, Mat &output_image, int max_, int min_);
	void ScaleImg(QWheelEvent  *event, double factor);
	void ZoomIn(){ QWheelEvent  *even_ = NULL; ScaleImg(even_, 1.2); };
	void ZoomOut(){ QWheelEvent  *even_ = NULL; ScaleImg(even_, 0.8); };
	QString file;
	bool image_color;
    Ui::IMAGEClass ui;
	QStandardItemModel*treeview;
	QStandardItemModel*tableview;
	QImage qimage_;
	QPoint lastEventCursorPos;
	vector<Mat>image_opencv;
	Mat opencv_image;
	Mat VDVI_image;
	Dialog_weight *laplace;
	Dialog_slider_line *liner_enhancement;
	Dialog_region_growing *region;
	Dialog_Gaussian_Filter*gaussian_;
	int line_enhancement_max;
	int line_enhancement_min;
	double image_max_grey;
	double image_min_grey;
	bool counter_;
	double tranform[6];
	float img_scale_height;
	QPoint point_;//鼠标拾取的像素位置
};




template<typename T>
Mat IMAGE::Shrink(vector<vector<T>>input_image){
	int rows_ = input_image.size();
	int cols_ = input_image.front().size();
	Mat image_(rows_, cols_, CV_8UC1);
	int max_ = -10000;
	int min_ = 10000;
	for (int i = 0; i < rows_;i++)
	{
		for (int j = 0; j < cols_;j++)
		{
		     T NUM=(input_image[i][j]);
			if (NUM >= max_){max_ = NUM;}
			if (NUM <= min_){min_ = NUM;}
		}
	}
	Mat_<uchar>img = image_;
	for (int i = 0; i < rows_; i++)
	{
		for (int j = 0; j < cols_; j++)
		{
			int temp = (int)(255*(input_image[i][j] - min_) / (max_ - min_));
			img(i, j) = temp;
		}
	}
	return image_;

}
template<typename T>std::vector<T>
	IMAGE::vector_normalization(std::vector<T> vector_input){
		T minValue = *min_element(vector_input.begin(), vector_input.end());
		T maxValue = *max_element(vector_input.begin(), vector_input.end());
		double temp;
		for (int i_seg = 0; i_seg < vector_input.size(); i_seg++)
		{
			double temp = (vector_input[i_seg] - minValue) *(double(255) / (maxValue - minValue));
			//vector_input[i_seg] = 
			vector_input[i_seg] = int(temp);
		}
		return vector_input;
	}


