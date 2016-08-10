#ifndef BRAINTRAINING_MATH_EXPR_MAIN_H
#define BRAINTRAINING_MATH_EXPR_MAIN_H
#include <bdefines.h>

namespace BME {

	class Game : public IGame {


	public:
		Game();

		virtual QString getName();
		virtual QString getCategory();
		virtual IGameWidget *getWidget();
	};

}

#endif //BRAINTRAINING_MATH_EXPR_MAIN_H
