#include <definitions.h>

void targetCreate(Instance *this) {
	this->scale = 20;
	this->radius = 50;
}

void targetStep(Instance *this) {
	Instance *other = collide(this, pinball);
	if(other) {
		destroyInstance(ball);
		int i;
		for(i=0;i<30;i++) createInstance(particle2, 0, this->X, this->Y, 0, 0, 0);
		nextLevel();
	}
	int r;
	if(ball) {
		if(ball->OBJ == pinball) {
			r = direction(this->X, this->Y, ball->X, ball->Y);
			oscillator->C = distance(this->X, this->Y, ball->X, ball->Y);
		} else {
			r = direction(this->X, this->Y, GAME.mouseX, GAME.mouseY);
		}
	} else {
		r = direction(this->X, this->Y, GAME.mouseX, GAME.mouseY);
		oscillator->C = 999999;
	}
	this->rotation = r;
}

void targetDraw(Instance *this) {
	drawImage(imgEyeball, this->X+8, this->Y-2, 6, 6, this->rotation);
	drawImage(imgEyeball, this->X-8, this->Y-2, 6, 6, this->rotation);
	drawImage(imgTarget, this->X, this->Y, 24, 24, this->rotation/12);
}
