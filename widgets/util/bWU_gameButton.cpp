#include "bWU_gameButton.h"


BGameButton::BGameButton(BMainMenu *m, QString i, QString n, QString t)
	: menu(m), g_id(i), g_name(n), g_type(t), g_bcolor(B_SETT->getColor(t)), g_fcolor(255, 255, 255) {
 setFixedSize(w, h);
	g_fcolor.setAlpha(210);

	QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
	effect->setBlurRadius(10);
	effect->setXOffset(2);
	effect->setYOffset(3);
	effect->setColor(QColor(100, 100, 100, 200));

	setGraphicsEffect(effect);
 setProperty("menu", "true");

	connect(this, &QPushButton::clicked, [=](){ menu->menuClick(g_id); });
}

void BGameButton::paintEvent(QPaintEvent *event) {
	QPushButton::paintEvent(event);

	QPainter p(this);
	p.setRenderHint(QPainter::Antialiasing, true);
	p.setRenderHint(QPainter::TextAntialiasing, true);
	p.setRenderHint(QPainter::SmoothPixmapTransform, true);
 p.setPen(Qt::NoPen);

	p.setBrush(QBrush(g_bcolor));
	p.drawRect(0, 0, w, h);
 p.drawImage(QRect(0, 0, w, h), QImage(":/img_cat_1.png"));

	p.setBrush(QBrush(g_fcolor));
	p.drawRect(0, h/2 - 30, w, 60);

	p.setFont(QFont("Fantasque Sans", 12, 58));
	p.setPen(QPen(QBrush(QColor(0, 0, 0)), 3));
	p.drawText(QRect(10, h/2 - 20, w - 10, 25), g_name);

	p.end();
 event->accept();
}
