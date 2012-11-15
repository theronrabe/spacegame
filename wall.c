void wallCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->scale = 16;
	this->radius = 24;
	this->A = 0;
	this->B = 0;
}

void wallDraw(Instance *this) {
	if(this->A) this->X += oscillator->xVelocity/this->A;
	else if(this->B) this->Y += oscillator->xVelocity/this->B;
	drawPrimitive(this, GL_TRIANGLES, 0, 6);
}
