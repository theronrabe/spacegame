void wallCreate(Instance *this) {
	//buildPrimitive(this, 6);
	this->scale = 16;
	this->radius = 24;
	this->A = 0;
	this->B = 0;
}

void wallDraw(Instance *this) {
	if(this->A) this->xVelocity = oscillator->A*8;
	else if(this->B) this->yVelocity = oscillator->A/8;
	//drawPrimitive(this, GL_TRIANGLES, 0, 6);
	drawImage(imgWall, this->X, this->Y, 16, 16, 0);
}
