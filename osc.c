void oscCreate(Instance *this) {
	this->radius = 0;
}

void oscDraw(Instance *this) {
	seeWorld2D(0,0,800,600);
	++this->radius;
	this->A = (this->radius%100)>=50;
}
