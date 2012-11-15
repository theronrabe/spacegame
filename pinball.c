void pinballCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->radius = 5;
}

void moveBounce(Instance *this, Instance *other) {
		myBounce->X = this->X;
		myBounce->Y = this->Y;
		myBounce->radius = 150;
		if(this->Y>other->Y && this->X>other->X-16 && this->X<other->X+16) {
			myBounce->rotation = 90;
			this->yVelocity *= -0.7; this->Y += 10; } //bottom side
		if(this->Y<other->Y && this->X>other->X-16 && this->X<other->X+16) {
			myBounce->rotation = 270;
			this->Y -= 10; this->yVelocity *= -0.7; } //top side
		if(this->X>other->X && this->Y>other->Y-16 && this->Y<other->Y+16) {
			myBounce->rotation = 0;
			this->xVelocity *= -0.7; this->X += 10; } //right side
		if(this->X<other->X && this->Y>other->Y-16 && this->Y<other->Y+16) {
			myBounce->rotation = 180;
			this->xVelocity *= -0.7; this->X -= 10; } //left side
}

void pinballStep(Instance *this) {
	if(this->X < 0) destroyInstance(this);
	else if(this->X > 800) destroyInstance(this);
	else if(this->Y > 600) destroyInstance(this);
	else if(this->Y < 0) destroyInstance(this);
	else if(collide(this, orb)) destroyInstance(this);
	else if(collide(this, antiorb)) destroyInstance(this);

	this->rotation = getInstanceDirection(this);
}

void pinballDraw(Instance *this) {
	drawPrimitive(this, GL_TRIANGLES, 0, 6);

	if(getInstanceSpeed(this) > 6) setInstanceSpeed(this, 6);

	Instance *other;
	if(other = collide(this, wall)) {
		moveBounce(this, other);
	}
	if(other = collide(this, sizeUp)) {
		moveBounce(this, other);
		if(this->scale < 32) {
			this->scale += 4;
			this->radius += 4;
		} else {
			this->scale = 32;
			this-> radius = 32;
		}
	}
	if(other = collide(this, sizeDown)) {
		moveBounce(this, other);
		if(this->scale > 4) {
			this->scale -= 4;
			this->radius -= 4;
		} else {
			this->scale = 1;
			this->radius = 1;
		}
	}
}

