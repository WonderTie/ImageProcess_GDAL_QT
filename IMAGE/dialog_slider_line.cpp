#include "dialog_slider_line.h"
#include "ui_dialog_slider_line.h"

Dialog_slider_line::Dialog_slider_line(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_slider_line)
{
    ui->setupUi(this);
	
	connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(slider_changed_()));
	connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(slider_changed_min()));
}

Dialog_slider_line::~Dialog_slider_line()
{
    delete ui;
}
void Dialog_slider_line::slider_changed_(){
	int value_ = ui->horizontalSlider->value();
	emit send_line(value_);
}
void Dialog_slider_line::slider_changed_min(){
	int value_ = ui->horizontalSlider_2->value();
	emit send_line_min(value_);
}
void Dialog_slider_line::receive_par(int max_value, int min_value){
	ui->horizontalSlider->setValue(max_value);
	ui->horizontalSlider_2->setValue(min_value);
}