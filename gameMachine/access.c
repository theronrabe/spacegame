/*
Theron Rabe
10/7/2012
access.c
	Contains all the getters, setters, and query functions for the framework.
*/

#include <game.h>

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
	GAME.tailInst->id = 999999999;
	
	GAME.instCount = 0;
}

float getInstanceDirection(Instance *i) {
	if(i) {
		return atan2(i->yVelocity, i->xVelocity) * 180/PI;
	} else {
		return -1.0;
	}
}

void setInstanceDirection(Instance *i, float direction) {
	if(i) {
		i->xVelocity = cos(direction*PI/180);
		i->yVelocity = sin(direction*PI/180);
	}
}

float getInstanceSpeed(Instance *i) {
	if(i) {
		return sqrt(pow(i->xVelocity, 2) + pow(i->yVelocity, 2));
	} else {
		return -1.0;
	}
}

void setInstanceSpeed(Instance *i, float s) {
	if(i) {
		float dir = getInstanceDirection(i);
		float xC = cos(dir*PI/180);
		float yC = sin(dir*PI/180);

		i->xVelocity = s*xC;
		i->yVelocity = s*yC;
	}
}
