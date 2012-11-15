void targetCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->scale = 20;
	this->radius = 50;
}

void targetStep(Instance *this) {
	Instance *other = collide(this, pinball);
	if(other) {
		destroyInstance(ball);
		nextLevel();
	}
}

void targetDraw(Instance *this) {
	drawPrimitive(this, GL_TRIANGLES, 0, 6);
}

