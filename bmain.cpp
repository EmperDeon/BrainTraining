#include "bmain.h"
#include <c++/ctime>

int main(int argc, char** argv){
	qsrand(uint(time(nullptr)));

	QApplication a(argc, argv);
	a.setStyleSheet(BIO::loadText(":/res/qss.qss"));
	a.setWindowIcon(QIcon(":/res/icon.ico"));

	QFontDatabase::addApplicationFont(":/res/FantasqueSansMono-Regular.ttf");
//	QFontDatabase::addApplicationFont(":/res/GothamSSm.ttf");

	B_SETT = new BSettings;

	a.connect(&a, &QGuiApplication::lastWindowClosed, [=](){ B_SETT->save(); });

 B_MAIN = new BMainWindow;
	B_MAIN->changeWidget("mainMenu");
 B_MAIN->show();

	return a.exec();
}