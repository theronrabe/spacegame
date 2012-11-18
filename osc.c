void oscCreate(Instance *this) {
	this->radius = 0;
}

void oscStep(Instance *this) {
	++this->radius;
	this->A = (this->radius>0x8FFFFFFF);
}
