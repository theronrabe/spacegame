/*
Theron Rabe
10/7/2012
events.c
	Contains all the event functions for the framework that can be bound to user-defined scripts.
*/


int main(int argc, char **argv) {
	//Graphics Stuff
	glutInit(&argc, argv);

	//Framework Stuff
	createHeadInst();
	startGame(argc, argv);
	glutKeyboardFunc(KeyDown);
	glutKeyboardUpFunc(KeyUp);
	glutMouseFunc(Mouse);
	glutTimerFunc(GAME.STEPTIME, Step, 0);
	glutDisplayFunc(Draw);
	glutTimerFunc(GAME.FRAMERATE, FPS, 0);
	glutPassiveMotionFunc(moveMouse);
	//glutIdleFunc(Draw);

	//Aaaaand... we're off!
	loadShaders("gameMachine/vertShader", "gameMachine/fragShader");
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH|GLUT_STENCIL);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnable(GL_DEPTH_TEST);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glutMainLoop();

	return 0;
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

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	triggerEvent(onDraw, GAME.headInst);
	glFlush();
	glutSwapBuffers();
	
	//if(flagDraw) {
		Instance *i = GAME.headInst->NEXT;
		while(i) {
			i->X += i->xVelocity;
			i->Y += i->yVelocity;
			i = i->NEXT;
		}
	//}
	flagDraw = 0;
}

void FPS(int x) {
	glutTimerFunc(GAME.FRAMERATE, FPS, 0);
	//flagDraw = 1;
	//triggerEvent(onIdle, GAME.headInst);
	glutPostRedisplay();
}

void Idle() {
	triggerEvent(onIdle, GAME.headInst);
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

Script onIdle(Object *obj) {
	return obj->onIdle;
}

void endGame() {
	cleanUpInstances();
	cleanUpObjects();
	exit(0);
}
