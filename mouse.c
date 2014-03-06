#include "definitions.h"

void mouseCreate(Instance *this) {
	//buildPrimitive(this, 4);
	this->scale = 10;
	//this->A = newImage("img/img_test.png");
}

void mouseStep(Instance *this) {
	this->X = GAME.mouseX;
	this->Y = GAME.mouseY;
}

void mouseDraw(Instance *this) {
	//drawPrimitive(this, GL_LINES, 0, 4);
	//glColor3f(1,1,1);
	//drawImage(this->A, this->X, this->Y, 0, this->X+100, this->Y+100, 0);

	drawImage(imgMouse, this->X, this->Y, 8, 8, 0);
}

