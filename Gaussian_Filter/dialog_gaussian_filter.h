#ifndef DIALOG_GAUSSIAN_FILTER_H
#define DIALOG_GAUSSIAN_FILTER_H

#include <QDialog>
#include <QStandardItemModel>
#include "../Gaussian_Filter/gaussian.h"
#include <QVariant>
struct guassian_par{
	int windows_size;
	double sigma;
	double **array_;
	vector<vector<pair<int, int>>>weight_direction_;
};
Q_DECLARE_METATYPE(guassian_par);
namespace Ui {
class Dialog_Gaussian_Filter;
}

class Dialog_Gaussian_Filter : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Gaussian_Filter(QWidget *parent = 0);
    ~Dialog_Gaussian_Filter();
public slots:
    void scjz();
	void button_sure();
signals:
	void send_guassian_matrix(QVariant guassian_par_);

private:
	int weight_size;
    Ui::Dialog_Gaussian_Filter *ui;
	QStandardItemModel *tableview;
	void init_weight(double **array);
	QVariant variant;

};

#endif // DIALOG_GAUSSIAN_FILTER_H
