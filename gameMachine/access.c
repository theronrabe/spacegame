/*
Theron Rabe
10/7/2012
access.c
	Contains all the getters, setters, and query functions for the framework.
*/



void setStepTime(int step) {
	GAME.STEPTIME = step;
}

char keyIsHeld(char key) {
	return GAME.KEYS[key];
}

void createHeadInst() {
        GAME.headInst = (Instance *) malloc(sizeof(Instance));
        GAME.tailInst = (Instance *) malloc(sizeof(Instance));

        GAME.headInst->OBJ = NULL;
        GAME.headInst->DATA = NULL;
        GAME.headInst->NEXT = GAME.tailInst;
        GAME.headInst->PREV = NULL;
        GAME.headInst->id = -1;

        GAME.tailInst->OBJ = NULL;
        GAME.tailInst->DATA = NULL;
        GAME.tailInst->NEXT = NULL;
	GAME.tailInst->PREV = GAME.headInst;
	GAME.tailInst->id = 999;
	
	GAME.instCount = 0;
}

float getInstanceDirection(Instance *i) {
	return atan2(i->yVelocity, i->xVelocity) * 180/PI;
}

void setInstanceDirection(Instance *i, float direction) {
	i->xVelocity = cos(direction*PI/180);
	i->yVelocity = sin(direction*PI/180);
}

float getInstanceSpeed(Instance *i) {
	return sqrt(pow(i->xVelocity, 2) + pow(i->yVelocity, 2));
}

void setInstanceSpeed(Instance *i, float s) {
	float dir = getInstanceDirection(i);
	float xC = cos(dir*PI/180);
	float yC = sin(dir*PI/180);

	i->xVelocity = s*xC;
	i->yVelocity = s*yC;
}
