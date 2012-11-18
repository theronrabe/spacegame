/*
Theron Rabe
10/7/2012
objects.c
	Contains all functions that interact with the Object and Instance system of the framework,
	as well handling the data structures used by those functions.
*/


Object* createObject() {
	Object *newObj = malloc(sizeof(Object));
	newObj->onCreate = NULL;
	newObj->onDraw = NULL;
	newObj->onStep = NULL;
	newObj->onKeyUp = NULL;
	newObj->onKeyDown = NULL;
	newObj->onMouseLeft = NULL;
	newObj->onMouseRight = NULL;
	newObj->onDestroy = NULL;

	newObj->PREV = GAME.headObj;
	GAME.headObj = newObj;
	return newObj;
}

Instance* createInstance(Object *obj, int dataSize, int x, int y, int z, float direction, float velocity) {
	int size = sizeof(Instance);
	Instance *newInst = (Instance *) malloc(sizeof(Instance));
	Instance *i = GAME.headInst, *n = GAME.headInst->NEXT;

	newInst->OBJ = obj;
	newInst->DATA = (dataSize>0)?malloc(dataSize):NULL;
	newInst->id = GAME.instCount;
	newInst->X = x;
	newInst->Y = y;
	newInst->Z = z;
	newInst->radius = 0;
	newInst->rotation = 0;
	newInst->xVelocity = cos(direction*PI/180) * velocity;
	newInst->yVelocity = sin(direction*PI/180) * velocity;
	newInst->scale = 1;
	
	while(i){
		if(GAME.instCount <= i->id) {
			newInst->NEXT = i;
			n = i->PREV;
			n->NEXT = newInst;
			newInst->PREV = n;
			i->PREV = newInst;
			break;
		} else {
			i = i->NEXT;
		}
	}
	++GAME.instCount;
	
	if(onCreate(obj)) onCreate(obj)(newInst);
	return newInst;
}

void destroyInstance(Instance *id) {
	Instance *n = id->NEXT, *p = id->PREV;
	Object *OBJ = id->OBJ;
	
	p->NEXT = n;
	n->PREV = p;
	if(OBJ->onDestroy) OBJ->onDestroy(id);

	if(id->DATA) free(id->DATA);
	if(id) free(id);
}

void triggerEvent(Script (*E)(Object *obj), Instance *i) { //Takes E as a pointer to a function that returns a Script.
	while(i) {
		if(i->OBJ && E(i->OBJ)) {
			E(i->OBJ)(i);
		}
		i = i->NEXT;
	}
}

void cleanUpInstances() {
	Instance *i = GAME.headInst, *n;
	while(i) {
		n = i->NEXT;
		if(i->DATA) free(i->DATA);
		free(i);
		i = n;
	}
}

void wipeInstances(Object *o) {
	Instance *i = GAME.headInst->NEXT;
	while(i) {
		if(i->OBJ == o) {
			Instance *n = i->NEXT;
			destroyInstance(i);
			i = n;
		} else { i = i->NEXT; }
	}
}

void cleanUpObjects() {
	Object *o;
	while(o=GAME.headObj) {
		GAME.headObj = o->PREV;
		free(o);
	}
}

Object *getObject(Instance *I) {
	Object *ret = I->OBJ;
	return ret;
}

void swapDATA(Instance *I, void *d) {
	free(I->DATA);
	I->DATA = d;
}

char instanceExists(Object *obj) {
	Instance *i = GAME.headInst;
	
	while(i) {
		if(i->OBJ == obj) return 1;
		i = i->NEXT;
	}

	return 0;
}

Instance *nearInstance(Instance *this, Object *obj) {
	Instance *i = GAME.headInst, *ret = i;
	float n=999999, in;

	while(i) {
		in = distanceSq(this->X, this->Y, i->X, i->Y);
		if(in<n) {
			n = in;
			ret = i;
		}
		i = i->NEXT;
	}

	return ret;
}
