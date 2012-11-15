void orbCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->scale = 20;
	this->radius = 20;
	this->A = 0;
	this->C = 0;
}

void antiorbCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->scale = 20;
	this->radius = 20;
	this->A = 0;
	this->C = 1;
}

void orbDraw(Instance *this) {
	if(this->A) this->X += oscillator->xVelocity/this->A;
	else if(this->B) this->Y += oscillator->xVelocity/this->B;

	if(ball) {
		if(ball->OBJ == pinball) {
			float dist = distance(this->X, this->Y, ball->X, ball->Y);
			float grav = (ball->scale*this->scale)/4/pow(dist, 2);
			if(this->C)
				grav = -grav;

			ball->xVelocity += (ball->X > this->X)?-grav:grav;
			ball->yVelocity += (ball->Y > this->Y)?-grav:grav;
		}
	}
	drawPrimitive(this, GL_TRIANGLES, 0, 6);
}