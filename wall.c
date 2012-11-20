void wallCreate(Instance *this) {
	this->scale = 16;
	this->radius = 24;
	this->A = 0;
	this->B = 0;
}

void wallDraw(Instance *this) {
	drawImage(imgWall, this->X, this->Y, 16, 16, 0);
	if(this->A) this->xVelocity = (oscillator->A)?this->A:-this->A;
	else if(this->B) this->yVelocity = (oscillator->A)?this->B:-this->B;
}
