void oscCreate(Instance *this) {
	this->radius = 0;
	this->B = 0;
}

void oscDraw(Instance *this) {
	glClearColor(0,0.01,0.08,1);
	seeWorld2D(0,0,800,600);

	this->radius++;
	this->B++;
	if(!(this->radius%50)) { this->radius = 0; this->A = !this->A; }

	if(keyIsHeld('n')) { GAME.KEYS['n'] = 0; nextLevel(); }
}

void oscIdle(Instance *this) {
	//this->radius++;
	//if(!(this->radius%50)) { this->radius = 0; this->A = !this->A; }
}

void splashDraw(Instance *this) {
	drawImage(imgSplash, 400,300, 400,300, 0);
	if(keyIsHeld(' ')) { GAME.KEYS[' '] = 0; nextLevel(); }
}
