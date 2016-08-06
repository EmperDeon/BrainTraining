#include "math/bmathwidget.h"


BMathWidget::BMathWidget() {
 QVBoxLayout *l_main = new QVBoxLayout;

	l_time = new QLabel("0:00"); l_time->setObjectName("math_time");
	l_expr = new QLabel("Press Enter"); l_expr->setObjectName("math_expr");
	l_edit = new QLineEdit;
	t_time = new QTimer;

 t_time->setInterval(10);

	l_main->addWidget(l_time, 0, Qt::AlignTop | Qt::AlignRight);
	l_main->addSpacing(60);
	l_main->addWidget(l_expr, 0, Qt::AlignCenter);
	l_main->addStretch(1);
	l_main->addWidget(l_edit, 0, Qt::AlignBottom | Qt::AlignHCenter);

	connect(l_edit, &QLineEdit::returnPressed, [=](){ check(); });
 connect(t_time, &QTimer::timeout, [=](){ tick(); });

	setLayout(l_main);
}

void BMathWidget::showNext() {
	if(correct + wrong >= 20){
  t_time->stop();
		l_time->setText("0:00.00");
		l_expr->setStyleSheet("color: black");
		l_expr->setText(QString("<div align=\"center\" style=\"font: normal normal 18pt \"Fantasque Sans Mono\";\">"
			                        "<div style=\"color: green;\"> Correct answers: %1 </div>"
			                        "<div style=\"color: red;\"> Wrong answers: %2 </div><br />"
			                        "<div style=\"color: black;\"> Score: %3 </div><br /><br />"
			                        "<div>Press Enter to open Main menu</div>"
			                       "</div>")
			                .arg(correct).arg(wrong).arg(score));
		l_edit->setVisible(false);

	}else {
		expr = BMathGen::getNextExpr();

		l_expr->setText(expr->toString());
		l_expr->setStyleSheet("color: black");
		l_edit->setText("");

		l_time->setText("0:30");
		time = 1000;
		t_time->start();
	}
}

void BMathWidget::check() {
	if(t_time->isActive()){
  t_time->stop();

  if(l_edit->text() == QString::number(expr->getResult())){
   l_expr->setStyleSheet("color: green");
   correct++;
	  score += time;

  }else{
  	l_expr->setStyleSheet("color: red");
   l_expr->setText(QString::number(expr->getResult()));
   wrong++;

  }

  QTimer::singleShot(150, [=](){ showNext(); });

	}else if(l_expr->text() == "Press Enter"){
		score = correct = wrong = 0;
		QTimer::singleShot(150, [=](){ showNext(); });

	}else{
  B_SETT->addLEntry("game_01", BLEntry(QDateTime::currentDateTime(), score));
	 B_MAIN->changeWidget("mainMenu");

	}
}

void BMathWidget::tick() {
 if(time > 1){
	 time--;
	 l_time->setText(QString("%1:%2").arg(0).arg((float)time/100, 2, 'f', 2, '0'));

 }else{
	 check();
 }
}


void BMathWidget::pause() {

}

void BMathWidget::resume() {

}

void BMathWidget::focus() {
 l_edit->setFocus(Qt::OtherFocusReason);
}



