void particleCreate(Instance *this) {
	if(this->OBJ == particle6) {
		this->scale = getInstanceSpeed(ball);
		if(this->scale > 8) this->scale = 8;
		this->rotation = ball->rotation;
	} else if(this->OBJ == particle) {
		this->scale = rand()%7+1;
		this->A = (rand()%30)+1;
		this->B = rand()%360;
	} else {
		this->scale = rand()%14+1;
		this->A = (rand()%10)+1;
		this->B = rand()%360;
	} 
}

void particleDraw(Instance *this) {
	if(this->OBJ == particle6) {
		drawImage(imgParticle6, this->X, this->Y, this->scale, this->scale/2, this->rotation);
		this->scale -= 0.08;
	} else {
		if(this->OBJ == particle) drawImage(imgParticle, this->X, this->Y, this->scale, this->scale, this->rotation);
		else if(this->OBJ == particle2) drawImage(imgParticle2, this->X, this->Y, this->scale, this->scale, this->rotation);
		else if(this->OBJ == particle3) drawImage(imgParticle3, this->X, this->Y, this->scale, this->scale, this->rotation);
		else if(this->OBJ == particle4) drawImage(imgParticle4, this->X, this->Y, this->scale, this->scale, this->rotation);
		else if(this->OBJ == particle5) drawImage(imgParticle5, this->X, this->Y, this->scale, this->scale, this->rotation);

		this->rotation += (oscillator->A)?this->A:-this->A;
		int oscSpeed = (int)(8*(this->scale));
		this->B += (((oscillator->B%(2*oscSpeed))-oscSpeed) >= 0)?this->A:-this->A;
		this->scale -= 0.006 * this->A;
		setInstanceDirection(this, this->B);
		setInstanceSpeed(this, this->scale/2);
	}

	if(this->scale < 1) destroyInstance(this);
	else if(this->X > 800||this->X < 0||this->Y > 600||this->Y < 0) destroyInstance(this);
}
