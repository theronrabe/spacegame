void mouseCreate(Instance *this) {
	buildPrimitive(this, 4);
	this->scale = 10;
}

void mouseStep(Instance *this) {
	this->X = GAME.mouseX;
	this->Y = GAME.mouseY;
}

void mouseDraw(Instance *this) {
	drawPrimitive(this, GL_LINES, 0, 4);
}

