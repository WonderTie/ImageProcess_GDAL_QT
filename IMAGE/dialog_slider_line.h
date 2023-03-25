#ifndef DIALOG_SLIDER_LINE_H
#define DIALOG_SLIDER_LINE_H

#include <QDialog>

namespace Ui {
class Dialog_slider_line;
}

class Dialog_slider_line : public QDialog
{
    Q_OBJECT
signals:
	void send_line(int silder_value);
	void send_line_min(int silder_value_min);
public slots:
    void slider_changed_();
	void slider_changed_min();
	void receive_par(int max_value,int min_value);
public:
    explicit Dialog_slider_line(QWidget *parent = 0);
    ~Dialog_slider_line();

private:
    Ui::Dialog_slider_line *ui;
};

#endif // DIALOG_SLIDER_LINE_H
