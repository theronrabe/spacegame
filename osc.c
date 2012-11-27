void oscCreate(Instance *this) {
	this->radius = 0;
}

void oscDraw(Instance *this) {
	glClearColor(0,0.08,0,1);
	seeWorld2D(0,0,800,600);

	this->radius++;
	if(!(this->radius%50)) { this->radius = 0; this->A = !this->A; }

	if(keyIsHeld('n')) { GAME.KEYS['n'] = 0; nextLevel(); }
}

void oscIdle(Instance *this) {
	this->radius++;
	if(!(this->radius%50)) { this->radius = 0; this->A = !this->A; }
}
