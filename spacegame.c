#include "gameMachine/game.h"

//Objects
Object *cannon, *pinball, *target, *orb, *antiorb, *mouse, *wall, *bounce, *sizeUp, *sizeDown, *osc;
//Images
GLint imgCannon, imgPinball, imgTarget, imgOrb, imgMouse, imgWall, imgSizeUp, imgSizeDown;
//Events
void cannonCreate(Instance *this);
void cannonStep(Instance *this);
void cannonDraw(Instance *this);
void cannonMouse(Instance *this);

void pinballCreate(Instance *this);
void pinballStep(Instance *this);
void pinballDraw(Instance *this);

void targetCreate(Instance *this);
void targetStep(Instance *this);
void targetDraw(Instance *this);

void orbCreate(Instance *this);
void orbStep(Instance *this);
void orbDraw(Instance *this);

void antiorbCreate(Instance *this);

void mouseCreate(Instance *this);
void mouseStep(Instance *this);
void mouseDraw(Instance *this);

void wallCreate(Instance *this);
void wallDraw(Instance *this);

void bounceCreate(Instance *this);
void bounceDraw(Instance *this);

void oscCreate(Instance *this);
void oscStep(Instance *this);

//Primitives
/*
GLfloat basicTexCos[] = {-1,-1, 1,-1, 1,1, -1,1};
GLfloat basicTexPos[] = {-1,-1,0, 1,-1,0, 1,1,0, -1,1,0};

GLfloat bouncePrim[] = {0,-1,0, 0,1,0, 1,-2,0, 1,2,0, 2,-3,0, 2,3,0};
GLfloat bounceCols[] = {1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1};
GLfloat basicPrim[] = {-1,-1,0, 1,-1,0, 1,1,0,
			-1,-1,0, 1,1,0, -1,1,0};
GLfloat shipPrim[] = {0,0,0, -10,20,0, 0,10,0,
			0,0,0, 10,20,0, 0,10,0};
GLfloat pinballCols[] = {1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1};
GLfloat targetCols[] = {0,0,0.8, 0,0,0.8, 0,0,0.8, 
			0,0,0.8, 0,0,0.8, 0,0.5,1};
GLfloat orbCols[] = {0.8,0,0, 0.8,0,0, 0.8,0,0,
			0.8,0,0, 0.8,0,0, 1,0,0.5};
GLfloat antiorbCols[] = {0.8,0,0.8, 0.8,0,0.8, 0.8,0,0.8,
			0.8,0,0.8, 0.8,0,0.8, 1,0,1};
GLfloat cannonCols[] = {1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1};
GLfloat mousePrim[] = {-1,0,0, 1,0,0,
			0,1,0, 0,-1,0};
GLfloat mouseCols[] = {1,0,0, 1,0,0, 1,0,0, 1,0,0};
GLfloat sizeUpCols[] = {0,1,0, 0,1,0, 0,1,0, 0,1,0, 0,1,0, 0,1,0};
GLfloat sizeDownCols[] = {1,1,0, 1,1,0, 1,1,0, 1,1,0, 1,1,0, 1,1,0};
*/

//Global Data
Instance *ball, *myBounce, *oscillator;
int ammo = 10;

//SpaceGame globals
//Levels
#include "levels.c"
void nextLevel();
int level = 0;
funPtr levels[] = {level0, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10};


void startGame(int argc, char **argv) {
	GAME.STEPTIME = 100;
	createWindow("", 180, 180, 800, 600);
	glutSetCursor(GLUT_CURSOR_NONE);
	cannon = createObject();
	pinball = createObject();
	target = createObject();
	orb = createObject();
	antiorb = createObject();
	mouse = createObject();
	wall = createObject();
	bounce = createObject();
	sizeUp = createObject();
	sizeDown = createObject();
	osc = createObject();
	
	cannon->onCreate = cannonCreate;
	cannon->onStep = cannonStep;
	cannon->onDraw = cannonDraw;
	cannon->onMouseLeft = cannonMouse;

	pinball->onCreate = pinballCreate;
	pinball->onStep = pinballStep;
	pinball->onDraw = pinballDraw;
	//pinball->Port[dock_vertices] = basicPrim;
	//pinball->Port[dock_colors] = pinballCols;

	target->onCreate = targetCreate;
	target->onStep = targetStep;
	target->onDraw = targetDraw;

	orb->onCreate = orbCreate;
	orb->onDraw = orbDraw;

	antiorb->onCreate = antiorbCreate;
	antiorb->onDraw = orbDraw;

	mouse->onCreate = mouseCreate;
	mouse->onStep = mouseStep;
	mouse->onDraw = mouseDraw;

	wall->onCreate = wallCreate;
	wall->onDraw = wallDraw;

	sizeUp->onCreate = wallCreate;
	sizeUp->onDraw = wallDraw;

	sizeDown->onCreate = wallCreate;
	sizeDown->onDraw = wallDraw;

	bounce->onCreate = bounceCreate;
	bounce->onDraw = bounceDraw;

	osc->onCreate = oscCreate;
	osc->onDraw = oscStep;

	imgCannon = newImage("img/ship.png");
	imgPinball = newImage("img/rocket.png");
	imgTarget = newImage("img/target.png");
	imgOrb = newImage("img/blackhole.png");
	imgWall = newImage("img/wall.png");
	imgSizeUp = newImage("img/circuit.png");
	imgSizeDown = newImage("img/checker.png");
	imgMouse = newImage("img/mouse.png");

	/*
	myBounce = createInstance(bounce, 0, 0, 0, 0, 0, 0);
	myBounce->scale = 5;
	*/

	oscillator = createInstance(osc, 0, 0, 0, 0, 0, 0);
	
	nextLevel();
}

void nextLevel() {
	oscillator->radius = 0;
	oscillator->xVelocity = 0;

	if(level) {
		wipeInstances(cannon);
		wipeInstances(target);
		wipeInstances(wall);
		wipeInstances(orb);
		wipeInstances(sizeUp);
		wipeInstances(sizeDown);
		wipeInstances(mouse);
		wipeInstances(bounce);
	}
	levels[level++]();
	myBounce = createInstance(bounce, 0, 0, 0, 0, 0, 0);
		myBounce->scale = 4;
	createInstance(mouse, 0, 0, 0, 0, 0, 0);
}

#include "mouse.c"
#include "cannon.c"
#include "orb.c"
#include "pinball.c"
#include "wall.c"
#include "target.c"
#include "bounce.c"
#include "osc.c"
