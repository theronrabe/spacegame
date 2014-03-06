#include <definitions.h>

void gridCreate(Instance *this) {
	this->radius = 2;
	this->scale = 0;
	this->A = this->X;
	this->B = this->Y;
	this->xVelocity = 0;
	this->yVelocity = 0;

	if(this->OBJ == grid) this->scale = 0;
	else this->scale = 1;
}

void gridStep(Instance *this) {
	int targetX, targetY;
	int dist;

	if(this->X > 800 || this->X < 0 || this->Y > 600 || this->Y < 0) { destroyInstance(this); return; }

	Instance *other;
	if(this->OBJ == reset2Particle) {
		other = nearInstance(this, antiorb);
	} else {
		other = nearInstance(this, orb);
	}

	if(other) {
		targetX = other->X;
		targetY = other->Y;
	} else {
		if(this->OBJ == grid) {
			targetX = this->X;
			targetY = this->Y;
		} else {
			destroyInstance(this);
			return;
		}
	}
	this->rotation = direction(this->X, this->Y, targetX, targetY);
	if(this->OBJ == grid) {
		moveToward(this, targetX, targetY, 5);
	} else {
		moveToward(this, targetX, targetY, 10);
	}
	
	dist = distance(this->X, this->Y, targetX, targetY);
	this->scale += 500/(dist+1);

	if((dist < 30 || this->scale > (this->B*this->A)%200) && this->OBJ == grid) {
		destroyInstance(this);
		return;
	}
}

void gridDraw(Instance *this) {
	Instance *other;
	if (this->OBJ == grid) {
		drawImage(imgSquare, this->X, this->Y, this->scale/10, 1, this->rotation);
	}
	else if(this->OBJ == resetParticle) {
		drawImage(imgResetParticle, this->X, this->Y, this->scale/5, 1, this->rotation);
		if (other = collide(this, orb)) {
			other->scale -= 1;
			if(other->scale < 0) {
				other->OBJ = antiorb;
				other->scale = 10;
				other->C = 1;
			}
			destroyInstance(this);
		}
	}
	else if(this->OBJ == reset2Particle) {
		drawImage(imgReset2Particle, this->X, this->Y, this->scale/5, 1, this->rotation);
		if (other = collide(this, antiorb)) {
			other->scale -= 1;
			if(other->scale < 0) {
				other->OBJ = orb;
				other->scale = 10;
				other->C = 0;
			}
			destroyInstance(this);
		}
	}
}

void gridDestroy(Instance *this) {
	int rand = oscillator->B%21 - 10;
	createInstance(this->OBJ, 0, this->A+rand, this->B+rand, 0, 0, 0);
}
