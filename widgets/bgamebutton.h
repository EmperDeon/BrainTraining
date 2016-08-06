#ifndef BRAINTRAINING_BGAMEBUTTON_H
#define BRAINTRAINING_BGAMEBUTTON_H
#include <I/bdefines.h>
#include <widgets/bmainmenu.h>

class BMainMenu;

class BGameButton : public QPushButton{
	Q_OBJECT
 BMainMenu* menu;

	const int w = 225, h = 140;
	QColor g_fcolor, g_bcolor;
	QString g_id, g_name, g_type;

public:
	BGameButton(BMainMenu *m, QString i, QString n, QString t);

protected:
	virtual void paintEvent(QPaintEvent *event) override;
};

#endif //BRAINTRAINING_BGAMEBUTTON_H
