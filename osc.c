void oscCreate(Instance *this) {
	this->radius = 0;
	this->xVelocity = 0;
}
void oscStep(Instance *this) {
	//radius => counter; X => oscillation
	this->xVelocity = sin(this->radius);
	++this->radius;
}
