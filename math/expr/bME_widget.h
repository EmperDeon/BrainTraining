#ifndef BRAINTRAINING_MATH_EXPR_WIDGET_H
#define BRAINTRAINING_MATH_EXPR_WIDGET_H
#include <bdefines.h>
#include <math/expr/bME_gen.h>
#include <util/bU_math.h>

class BMathGen;
class BMathExpr;

namespace BME {

	class Wgt : public IGameWidget {
	Q_OBJECT

		BMathExpr *expr = nullptr;

		QLabel *l_time, *l_expr, *l_edit;
		QPushButton *b_lead, *b_stat;
		QTimer *t_time;

		int time, correct, wrong, score, num = 0;

	public:
		Wgt();

		void showNext();
		void check();
		void tick();

		virtual void pause();
		virtual void resume();

		virtual void keyPress(int key);

	};

}

#endif //BRAINTRAINING_MATH_EXPR_WIDGET_H
