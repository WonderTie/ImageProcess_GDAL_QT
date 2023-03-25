#ifndef DIALOG_WEIGHT_H
#define DIALOG_WEIGHT_H

#include <QDialog>
#include<QStandardItem>
#include<QVariant>
struct weight_laplace
{
	int weight[9];
};
Q_DECLARE_METATYPE(weight_laplace);
namespace Ui {
class Dialog_weight;
}

class Dialog_weight : public QDialog
{
    Q_OBJECT
public slots:
	void send_laplace();
signals:
	void send_laplace_par(QVariant);
public:
    explicit Dialog_weight(QWidget *parent = 0);
    ~Dialog_weight();

private:
	void init();
    Ui::Dialog_weight *ui;
	QStandardItemModel *table_view_;
};

#endif // DIALOG_WEIGHT_H
