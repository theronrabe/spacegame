#include <game.h>

void bounceCreate(Instance *this) {
	//buildPrimitive(this, 6);
}

void bounceDraw(Instance *this) {
	this->radius -= (this->radius>0)?1:0;

	//if(this->radius) drawPrimitive(this, GL_LINES, 0, 6);
}
