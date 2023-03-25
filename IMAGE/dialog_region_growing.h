#ifndef DIALOG_REGION_GROWING_H
#define DIALOG_REGION_GROWING_H

#include <QDialog>
#include <QVariant>

struct region_par
{
	int gray_diff_auto;
	int gray_diff_peo;
	int min_number;
	int method;
};
Q_DECLARE_METATYPE(region_par);


namespace Ui {
class Dialog_region_growing;
}

class Dialog_region_growing : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_region_growing(QWidget *parent = 0);
    ~Dialog_region_growing();
public slots:
	void run_auto_region();
	void run_peo_region();
signals:
	void send_auto_region_par(QVariant AUTO_PAR);
	void send_peo_region_par(QVariant PEO_PAR);
private:
    Ui::Dialog_region_growing *ui;
};

#endif // DIALOG_REGION_GROWING_H
