#include "dialog_gaussian_filter.h"
#include "ui_dialog_gaussian_filter.h"

Dialog_Gaussian_Filter::Dialog_Gaussian_Filter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Gaussian_Filter)
{
    ui->setupUi(this);
	tableview = new QStandardItemModel;
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(scjz()));
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(button_sure()));
}

Dialog_Gaussian_Filter::~Dialog_Gaussian_Filter()
{
    delete ui;
}
void Dialog_Gaussian_Filter::init_weight(double **array){
	tableview->setColumnCount(weight_size);
	for (int i = 0; i < weight_size; i++)
	{
		for (int j = 0; j < weight_size; j++)
		{
			tableview->setItem(i, j, new QStandardItem(QString::number(array[i][j])));
		}
	}
	ui->tableView->setModel(tableview);
}
void Dialog_Gaussian_Filter::scjz(){
	weight_size = ui->spinBox->value();
	double sigma = ui->doubleSpinBox->value();
	vector<vector<pair<int, int>>>weight_direction;
	guassian gaussian_;
	double **array = gaussian_.matrix_weight(weight_size, sigma, weight_direction);
	init_weight(array);
	guassian_par par;
	par.array_ = array;
	par.sigma = sigma;
	par.weight_direction_ = weight_direction;
	par.windows_size = weight_size;
	variant.setValue(par);


}
void Dialog_Gaussian_Filter::button_sure(){
	emit(send_guassian_matrix(variant));
}

