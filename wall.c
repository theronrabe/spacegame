void wallCreate(Instance *this) {
	this->scale = 16;
	this->radius = 24;
	this->A = 0;
	this->B = 0;
	this->C = 0;
}

void wallDraw(Instance *this) {
	if(this->A) this->C = (oscillator->A)?this->A:-this->A;
	else if(this->B) this->C = (oscillator->A)?this->B:-this->B;

	if(this->OBJ == wall) {
		drawImage(imgWall, this->X+this->C*10, this->Y, 16, 16, 0);
		//this->radius = 24+this->C;
	}
	else if(this->OBJ ==  sizeUp) {
		drawImage(imgSizeUp, this->X, this->Y, 32, 32, 0);
		this->xVelocity = this->C;
		//this->radius = 24+this->C;
	}
	else if(this->OBJ ==  sizeDown) {
		drawImage(imgSizeDown, this->X, this->Y, 32, 32, 0);
		this->yVelocity = this->C;
		//this->radius = 24+this->C;
	}
}
