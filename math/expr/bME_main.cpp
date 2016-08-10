#include "math/expr/bME_main.h"
#include "math/expr/bME_widget.h"

BME::Game::Game(){

}

QString BME::Game::getName() {
	return "Expressions";
}

QString BME::Game::getCategory() {
	return "Mathematics";
}

IGameWidget *BME::Game::getWidget() {
	return new Wgt();
}

