void cannonCreate(Instance *this) {
	//buildPrimitive(this, 6);
	this->scale = 2;
}

void cannonMouse(Instance *this) {
	if(!instanceExists(pinball)) {
		float velocity = distance(this->X, this->Y, GAME.mouseX, GAME.mouseY)/32;
		Instance *i = createInstance(pinball, 0, this->X, this->Y, this->Z, this->rotation, velocity);
		i->scale = 5;
		i->rotation = this->rotation;
		ball = i;
		--ammo;
	}
}

void cannonStep(Instance *this) {
	int r = direction(this->X, this->Y, GAME.mouseX, GAME.mouseY);
	this->rotation = r;
}

void cannonDraw(Instance *this) {
	//drawPrimitive(this, GL_TRIANGLES, 0, 6);

	/*
	int i;
	for(i=0;i<ammo;i++) {
		drawPrimitiveAt(this, GL_TRIANGLES, i*8+40, 40, 0, 0.5, 0, 0, 6);
	}
	*/

	float stretch = distance(this->X, this->Y, GAME.mouseX, GAME.mouseY)/4;
	drawImage(imgCannon, this->X, this->Y, stretch, 16, this->rotation);

	if(keyIsHeld('q')) endGame();
}

