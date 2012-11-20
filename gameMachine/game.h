#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

//Vital Scripts
void startGame(int argc, char **argv);
void endGame();

//Data Structures
typedef struct {
	int A,B,C;
	void *OBJ;
	void *DATA;
	void *NEXT;
	void *PREV;
	int id;
	float X;
	float Y;
	float Z;
	int radius;
	float rotation;
	float xVelocity;
	float yVelocity;
	float scale;
} Instance;
typedef void (*Script)(Instance *);
typedef void (*funPtr)();
typedef struct {
	Script onCreate, onDraw, onStep, onKeyUp, onKeyDown, onMouseLeft, onMouseRight, onDestroy, onIdle;
	void *PREV;
} Object;
typedef Script (*Event)(Object *);
typedef struct {
	int STEPTIME;
	int FRAMERATE;
	char KEYS[256];
	Instance *headInst, *tailInst;
	Object *headObj;
	int instCount;
	int mouseX, mouseY;
} Game;

//Data Declarations
Game GAME;

#include "graphics.h"
#include "events.h"
#include "objects.h"
#include "access.h"
#include "text.h"
#include "collisions.h"
#include "motion.h"

#include "graphics.c"
#include "events.c"
#include "objects.c"
#include "access.c"
#include "text.c"
#include "collisions.c"
#include "motion.c"
