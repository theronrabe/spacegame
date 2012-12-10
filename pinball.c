void pinballCreate(Instance *this) {
	this->radius = 8;
	this->scale = 8;
	this->A = imgPinball;
}

void moveBounce(Instance *this, Instance *other) {
		myBounce->X = this->X;
		myBounce->Y = this->Y;
		myBounce->radius = 150;
		if(this->Y>=other->Y && this->X>=other->X-16 && this->X<=other->X+16) {
			myBounce->rotation = 90;
			this->yVelocity *= -0.7; this->Y += 16; } //bottom side
		else if(this->Y<=other->Y && this->X>=other->X-16 && this->X<=other->X+16) {
			myBounce->rotation = 270;
			this->Y -= 16; this->yVelocity *= -0.7; } //top side
		else if(this->X>=other->X && this->Y>=other->Y-16 && this->Y<=other->Y+16) {
			myBounce->rotation = 0;
			this->xVelocity *= -0.7; this->X += 16; } //right side
		else if(this->X<=other->X && this->Y>=other->Y-16 && this->Y<=other->Y+16) {
			myBounce->rotation = 180;
			this->xVelocity *= -0.7; this->X -= 16; } //left side

		Object *p;
		if(other->OBJ == wall) p = particle;
		else if(other->OBJ == sizeUp) p = particle3;
		else if(other->OBJ == sizeDown) p = particle4;
		
		int i;
		for(i=1;i<getInstanceSpeed(this)+10;i++) createInstance(p, 0, this->X, this->Y, 0, 0, 1);
}

void pinballStep(Instance *this) {
	if(this->X < 0) destroyInstance(this);
	else if(this->X > 800) destroyInstance(this);
	else if(this->Y > 600) destroyInstance(this);
	else if(this->Y < 0) destroyInstance(this);
	else if(collide(this, orb)) {
		int i;
		for(i=1;i<20;i++) createInstance(particle5, 0, this->X, this->Y, 0, 0, 1)->A = i;
		destroyInstance(this);
	}
	else if(collide(this, antiorb)) destroyInstance(this);

	this->rotation = getInstanceDirection(this);
	int i;
	for(i=1;i<2;i++) createInstance(particle6, 0, this->X-(this->xVelocity), this->Y-(this->yVelocity), 0, 0, 0);
}

void pinballDraw(Instance *this) {
	drawImage(imgPinball, this->X, this->Y, this->scale, this->scale, this->rotation);

	if(getInstanceSpeed(this) > 15) setInstanceSpeed(this, 15);
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

