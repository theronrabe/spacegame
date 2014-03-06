#include <definitions.h>

int level = 0;
funPtr levels[] = {splashScreen, level0, level1, level2, level3, level4, level5, level6, level7, level8, level9, level10, splashScreen};
int ammo = 10;

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
	particle = createObject();
	particle2 = createObject();
	particle3 = createObject();
	particle4 = createObject();
	particle5 = createObject();
	particle6 = createObject();
	splash = createObject();
	grid = createObject();
	resetWall = createObject();
	resetParticle = createObject();
	reset2Wall = createObject();
	reset2Particle = createObject();

	splash->onDraw = splashDraw;
	
	cannon->onCreate = cannonCreate;
	cannon->onStep = cannonStep;
	cannon->onDraw = cannonDraw;
	cannon->onMouseLeft = cannonMouse;

	pinball->onCreate = pinballCreate;
	pinball->onStep = pinballStep;
	pinball->onDraw = pinballDraw;
	pinball->onDestroy = pinballDestroy;

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

	resetWall->onCreate = wallCreate;
	resetWall->onDraw = wallDraw;

	reset2Wall->onCreate = wallCreate;
	reset2Wall->onDraw = wallDraw;

	bounce->onCreate = bounceCreate;
	bounce->onDraw = bounceDraw;

	osc->onCreate = oscCreate;
	osc->onDraw = oscDraw;

	particle->onCreate = particleCreate;
	particle->onDraw = particleDraw;
	particle2->onCreate = particleCreate;
	particle2->onDraw = particleDraw;
	particle3->onCreate = particleCreate;
	particle3->onDraw = particleDraw;
	particle4->onCreate = particleCreate;
	particle4->onDraw = particleDraw;
	particle5->onCreate = particleCreate;
	particle5->onDraw = particleDraw;
	particle6->onCreate = particleCreate;
	particle6->onDraw = particleDraw;

	resetParticle->onCreate = gridCreate;
	resetParticle->onStep = gridStep;
	resetParticle->onDraw = gridDraw;

	reset2Particle->onCreate = gridCreate;
	reset2Particle->onStep = gridStep;
	reset2Particle->onDraw = gridDraw;

	grid->onCreate = gridCreate;
	grid->onStep = gridStep;
	grid->onDraw = gridDraw;
	grid->onDestroy = gridDestroy;

	imgCannon = newImage("img/ship.png");
	imgPinball = newImage("img/rocket.png");
	imgTarget = newImage("img/target.png");
	imgOrb = newImage("img/blackhole.png");
	imgWall = newImage("img/wall.png");
	imgSizeUp = newImage("img/circuit.png");
	imgSizeDown = newImage("img/checker.png");
	imgMouse = newImage("img/mouse.png");
	imgAntiOrb = newImage("img/whitehole.png");
	imgParticle = newImage("img/particle.png");
	imgParticle2 = newImage("img/particle2.png");
	imgParticle3 = newImage("img/particle3.png");
	imgParticle4 = newImage("img/particle4.png");
	imgParticle5 = newImage("img/particle5.png");
	imgParticle6 = newImage("img/particle6.png");
	imgSplash = newImage("img/splash.png");
	imgEyeball = newImage("img/eye.png");
	imgSquare = newImage("img/square.png");
	imgResetWall = newImage("img/resetWall.png");
	imgResetParticle = newImage("img/resetParticle.png");
	imgReset2Wall = newImage("img/reset2Wall.png");
	imgReset2Particle = newImage("img/reset2Particle.png");
	
	oscillator = createInstance(osc, 0, 0, 0, 0, 0, 0);
	nextLevel();
	myBounce = createInstance(bounce, 0, 0, 0, 0, 0, 0);
		myBounce->scale = 4;
}

void nextLevel() {
	oscillator->radius = 0;
	oscillator->A = 0;

	if(level) {
		wipeInstances(splash);
		wipeInstances(cannon);
		wipeInstances(target);
		wipeInstances(wall);
		wipeInstances(orb);
		wipeInstances(antiorb);
		wipeInstances(sizeUp);
		wipeInstances(sizeDown);
		wipeInstances(resetWall);
		wipeInstances(reset2Wall);
	}
	createInstance(mouse, 0, 0, 0, 0, 0, 0);

	levels[level++]();
}
