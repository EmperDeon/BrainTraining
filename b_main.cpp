#include "b_main.h"
#include <c++/ctime>

int main(int argc, char** argv){
	qsrand(uint(time(nullptr)));

	QApplication a(argc, argv);
	a.setStyleSheet(BIO::loadText(":/qss.qss"));
	a.setWindowIcon(QIcon(":/icon.ico"));

	QFontDatabase::addApplicationFont(":/FantasqueSansMono-Regular.ttf");
//	QFontDatabase::addApplicationFont(":/GothamSSm.ttf");

	B_SETT = new BSettings;

	a.connect(&a, &QGuiApplication::lastWindowClosed, [=](){ B_SETT->save(); });

 B_MAIN = new BMainWindow;
	B_MAIN->changeWidget("mainMenu");
 B_MAIN->show();

	return a.exec();
}