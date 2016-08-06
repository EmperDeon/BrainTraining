#include "bmathmain.h"
#include "bmathwidget.h"

BMathGame::BMathGame(){

}

QString BMathGame::getName() {
	return "Expressions";
}

QString BMathGame::getCategory() {
	return "Mathematics";
}

IGameWidget *BMathGame::getWidget() {
	return new BMathWidget();
}

