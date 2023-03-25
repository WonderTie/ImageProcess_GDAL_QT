#include "IMAGE.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	QFile qss(":/IMAGE/Resources/AMOLED.qss");
	if (qss.open(QFile::ReadOnly))
	{
		qDebug("open success");
		QString style = QLatin1String(qss.readAll());
		a.setStyleSheet(style);
		qss.close();
	}
	else{
		qDebug("Open failed");
	}
    IMAGE w;
    w.show();
    return a.exec();
}


