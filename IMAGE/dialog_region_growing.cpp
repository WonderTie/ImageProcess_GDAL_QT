#include "dialog_region_growing.h"
#include "ui_dialog_region_growing.h"

Dialog_region_growing::Dialog_region_growing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_region_growing)
{
    ui->setupUi(this);
	ui->checkBox->setChecked(true);
	connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(run_auto_region()));
	connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(run_peo_region()));
	connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog_region_growing::~Dialog_region_growing()
{
    delete ui;
}
void Dialog_region_growing::run_auto_region(){
	QVariant variant1;
	region_par par_auto;
	par_auto.gray_diff_auto = ui->spinBox->value();
	par_auto.min_number = ui->spinBox_2->value();
	if (ui->checkBox->isChecked())
	{
		par_auto.method = 1;
	}
	else if (ui->checkBox_2->isChecked()){
		par_auto.method = 2;
	}
	else if (ui->checkBox_3->isChecked())
	{
		par_auto.method = 3;
	}
	variant1.setValue(par_auto);
	emit send_auto_region_par(variant1);
}
void Dialog_region_growing::run_peo_region(){
	QVariant variant1;
	region_par par_peo;
	par_peo.gray_diff_peo = ui->spinBox_3->value();
	variant1.setValue(par_peo);
	emit send_peo_region_par(variant1);
}