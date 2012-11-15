void cannonCreate(Instance *this) {
	buildPrimitive(this, 6);
	this->scale = 2;
}

void cannonMouse(Instance *this) {
	if(!instanceExists(pinball)) {
		float velocity = distance(this->X, this->Y, GAME.mouseX, GAME.mouseY)/500;
		Instance *i = createInstance(pinball, 0, this->X, this->Y, this->Z, this->rotation-90, velocity);
		i->scale = 5;
		i->rotation = this->rotation - 90;
		ball = i;
		--ammo;
	}
}

void cannonStep(Instance *this) {
	int r = direction(this->X, this->Y, GAME.mouseX, GAME.mouseY);
	this->rotation = r+90;
}

void cannonDraw(Instance *this) {
	seeWorld2D(0,0,800,600);
	//seeWorld3D(400, 700, -100, 400, 300, 0, 0, 0, 1);
	glClearColor(0,0,0,1);
	drawPrimitive(this, GL_TRIANGLES, 0, 6);

	int i;
	for(i=0;i<ammo;i++) {
		drawPrimitiveAt(this, GL_TRIANGLES, i*8+40, 40, 0, 0.5, 0, 0, 6);
	}

	if(keyIsHeld('q')) endGame();
}

