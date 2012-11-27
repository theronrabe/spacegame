#include "gameMachine/game.h"

//Objects
Object *cannon, *pinball, *target, *orb, *antiorb, *mouse, *wall, *bounce, *sizeUp, *sizeDown, *osc;
//Images
GLint imgCannon, imgPinball, imgTarget, imgOrb, imgMouse, imgWall, imgSizeUp, imgSizeDown, imgAntiOrb;
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
void oscIdle(Instance *this);
void oscDraw(Instance *this);

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
	GAME.FRAMERATE = 20;
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
	osc->onDraw = oscDraw;
	osc->onIdle = oscIdle;

	imgCannon = newImage("img/ship.png");
	imgPinball = newImage("img/rocket.png");
	imgTarget = newImage("img/target.png");
	imgOrb = newImage("img/blackhole.png");
	imgWall = newImage("img/wall.png");
	imgSizeUp = newImage("img/circuit.png");
	imgSizeDown = newImage("img/checker.png");
	imgMouse = newImage("img/mouse.png");
	imgAntiOrb = newImage("img/whitehole.png");

	
	oscillator = createInstance(osc, 0, 0, 0, 0, 0, 0);
	nextLevel();
	myBounce = createInstance(bounce, 0, 0, 0, 0, 0, 0);
		myBounce->scale = 4;
}

void nextLevel() {
	oscillator->radius = 0;
	oscillator->A = 0;

	if(level) {
		wipeInstances(cannon);
		wipeInstances(target);
		wipeInstances(wall);
		wipeInstances(orb);
		wipeInstances(antiorb);
		wipeInstances(sizeUp);
		wipeInstances(sizeDown);
	}
	createInstance(mouse, 0, 0, 0, 0, 0, 0);
	levels[level++]();
}

#include "mouse.c"
#include "cannon.c"
#include "orb.c"
#include "pinball.c"
#include "wall.c"
#include "target.c"
#include "bounce.c"
#include "osc.c"
