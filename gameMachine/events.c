/*
Theron Rabe
10/7/2012
events.c
	Contains all the event functions for the framework that can be bound to user-defined scripts.
*/


int main(int argc, char **argv) {
	//Graphics Stuff
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);

	//Framework Stuff
	createHeadInst();
	startGame(argc, argv);
	glutDisplayFunc(Draw);
	glutIdleFunc(Draw);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(Mouse);
	glutTimerFunc(GAME.STEPTIME, Step, 0);
	glutPassiveMotionFunc(moveMouse);

	//Aaaaand... we're off!
	loadShaders("gameMachine/vertShader", "gameMachine/fragShader");
	glutMainLoop();

	return 0;
}

void Draw() {
	//Prepare OpenGL
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//Crank Engine!
	triggerEvent(onDraw, GAME.headInst);

	//update instance locations based on direction and velocity
	Instance *i = GAME.headInst->NEXT;

	while(i) {
		/*
		float xComp = cos(i->direction*3.14159265/180), yComp = sin(i->direction*3.14159265/180);
		i->X += i->velocity*xComp;
		i->Y += i->velocity*yComp;
		*/
		i->X += i->xVelocity;
		i->Y += i->yVelocity;
		i = i->NEXT;
	}

	glutSwapBuffers();
}

void moveMouse(int x, int y) {
	GAME.mouseX = x;
	GAME.mouseY = y;
}

void Mouse(int button, int state, int x, int y) {
	Object *OBJ = GAME.headInst->OBJ;
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		triggerEvent(onMouseLeft, GAME.headInst);
	else if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
		triggerEvent(onMouseRight, GAME.headInst);
}

void Step(int x) {
	glutTimerFunc(GAME.STEPTIME, Step, 0);
	triggerEvent(onStep, GAME.headInst);
}

void KeyUp(unsigned char key, int x, int y) {
	GAME.KEYS[key] = 0;
	triggerEvent(onKeyUp, GAME.headInst);
}

void KeyDown(unsigned char key, int x, int y) {
	GAME.KEYS[key] = 1;
	triggerEvent(onKeyDown, GAME.headInst);
}

Script onCreate(Object *obj) {
	return (obj->onCreate);
}

Script onDraw(Object *obj) {
	return obj->onDraw;
}

Script onStep(Object *obj) {
	return obj->onStep;
}

Script onKeyUp(Object *obj) {
	return obj->onKeyUp;
}

Script onKeyDown(Object *obj) {
	return obj->onKeyDown;
}

Script onMouseLeft(Object *obj) {
	return obj->onMouseLeft;
}

Script onMouseRight(Object *obj) {
	return obj->onMouseRight;
}
Script onDestroy(Object *obj) {
	return obj->onDestroy;
}

void endGame() {
	cleanUpInstances();
	cleanUpObjects();
	exit(0);
}
