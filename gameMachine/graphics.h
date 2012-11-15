#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

//Framework Functions
void loadShaders(char *vert, char *frag);

//User Functions
void createWindow(char *title, int x, int y, int width, int height);
void seeWorld2D(int x1, int y1, int x2, int y2);
void seeWorld3D(int cx, int cy, int cz, int fx, int fy, int fz, int vx, int vy, int vz);
void drawImage(void *Image, int x1, int y1, int z1, int x2, int y2, int z2);
void buildPrimitive(Instance *I, int size);
void drawPrimitive(Instance *I, char glType, int first, int count);
void drawPrimitiveAt(Instance *I, char glType, float x, float y, float z, float scale, float rotation, int first, int count);
GLuint newImage(char *file);
