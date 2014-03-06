#ifndef _definitions.h_
#define _definitions.h_

#include <game.h>
#include <levels.h>

//Objects
Object *splash, *cannon, *pinball, *target, *orb, *antiorb, *mouse, *wall, *bounce, *sizeUp, *sizeDown, *osc, *particle, *particle2, *particle3, *particle4, *particle5;
Object *particle6, *grid, *resetWall, *resetParticle, *reset2Wall, *reset2Particle;

//Images
GLint imgSplash, imgCannon, imgPinball, imgTarget, imgOrb, imgMouse, imgWall, imgSizeUp, imgSizeDown, imgAntiOrb, imgParticle, imgParticle2, imgParticle3, imgParticle4;
GLint imgParticle5, imgEyeball, imgParticle6, imgSquare, imgResetWall, imgResetParticle, imgReset2Wall, imgReset2Particle;

//Events
void cannonCreate(Instance *this);
void cannonStep(Instance *this);
void cannonDraw(Instance *this);
void cannonMouse(Instance *this);

void pinballCreate(Instance *this);
void pinballStep(Instance *this);
void pinballDraw(Instance *this);
void pinballDestroy(Instance *this);

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

void particleCreate(Instance *this);
void particleDraw(Instance *this);

void splashDraw(Instance *this);

void gridCreate(Instance *this);
void gridStep(Instance *this);
void gridDraw(Instance *this);
void gridDestroy(Instance *this);

//Global Data
Instance *ball, *myBounce, *oscillator;
extern int ammo;

//SpaceGame globals
//Levels
//#include "levels.c"
void nextLevel();
extern int level;
extern funPtr levels[];

#endif
