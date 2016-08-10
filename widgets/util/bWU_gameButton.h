#ifndef BRAINTRAINING_BGAMEBUTTON_H
#define BRAINTRAINING_BGAMEBUTTON_H
#include <bdefines.h>
#include <widgets/bW_mainMenu.h>

class BMainMenu;

class BGameButton : public QPushButton{
	Q_OBJECT
 BMainMenu* menu;

	const int w = 225, h = 140;
	QString g_id, g_name, g_type;
	QColor g_bcolor, g_fcolor;

public:
	BGameButton(BMainMenu *m, QString i, QString n, QString t);

protected:
	virtual void paintEvent(QPaintEvent *event) override;
};

#endif //BRAINTRAINING_BGAMEBUTTON_H
