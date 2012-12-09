void targetCreate(Instance *this) {
	//buildPrimitive(this, 6);
	this->scale = 20;
	this->radius = 50;
}

void targetStep(Instance *this) {
	Instance *other = collide(this, pinball);
	if(other) {
		destroyInstance(ball);
		int i;
		for(i=0;i<30;i++) createInstance(particle2, 0, this->X, this->Y, 0, oscillator->B%360, i)->A = i;
		nextLevel();
	}
	int r;
	if(ball) {
		r = direction(this->X, this->Y, ball->X, ball->Y);
	} else {
		r = direction(this->X, this->Y, GAME.mouseX, GAME.mouseY);
	}
	this->rotation = r;
}

void targetDraw(Instance *this) {
	//drawPrimitive(this, GL_TRIANGLES, 0, 6);
	drawImage(imgTarget, this->X, this->Y, 16, 16, this->rotation);
}

