#include "dialog_weight.h"
#include "ui_dialog_weight.h"

Dialog_weight::Dialog_weight(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_weight)
{
    ui->setupUi(this);
	table_view_ = new QStandardItemModel;
	init();
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(send_laplace()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}
void Dialog_weight::init(){
	table_view_->setColumnCount(3);
	table_view_->setItem(0, 0, new QStandardItem(QString::number(0)));
	table_view_->setItem(0, 1, new QStandardItem(QString::number(-1)));
	table_view_->setItem(0, 2, new QStandardItem(QString::number(0)));
	table_view_->setItem(1, 0, new QStandardItem(QString::number(-1)));
	table_view_->setItem(1, 1, new QStandardItem(QString::number(5)));
	table_view_->setItem(1, 2, new QStandardItem(QString::number(-1)));
	table_view_->setItem(2, 0, new QStandardItem(QString::number(0)));
	table_view_->setItem(2, 1, new QStandardItem(QString::number(-1)));
	table_view_->setItem(2, 2, new QStandardItem(QString::number(0)));
	ui->tableView->setModel(table_view_);
}
Dialog_weight::~Dialog_weight()
{
    delete ui;
}
void Dialog_weight::send_laplace(){
	QVariant variant1;
	weight_laplace wei;
	QModelIndex index;
	int counter_ = 0;
	for (int i = 0; i < 3;i++)
	{
		for (int j = 0; j < 3;j++)
		{
			index=table_view_->index(i, j, QModelIndex());//rowNum,columnNumÎªÐÐÁÐºÅ
			wei.weight[counter_] = index.data().toInt();
			counter_++;
		}
	}
	variant1.setValue(wei);
	close();
	emit send_laplace_par(variant1);
}