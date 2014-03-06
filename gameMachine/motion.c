#include <game.h>

float distance(float x1, float y1, float x2, float y2) {
	float ret = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
	return ret;
}

float distanceSq(float x1, float y1, float x2, float y2) {
	return pow(x2-x1,2) + pow(y2-y1,2);
}

float direction(float x1, float y1, float x2, float y2) {
	float ret = atan2((y2-y1), (x2-x1)) * 180/PI;
	return ret;
}

void move(Instance *i, float direction, float distance) {
	float xC = cos(direction*PI/180), yC = sin(direction*PI/180);
	i->X += distance*xC;
	i->Y += distance*yC;
}

void moveToward(Instance *i, float x, float y, float distance) {
	move(i, direction(i->X, i->Y, x, y), distance);
}
