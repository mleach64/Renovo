#include "Renovo.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Renovo w;
	w.show();
	return a.exec();
}
