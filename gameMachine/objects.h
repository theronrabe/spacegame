//Object/Instance Functions
Object* createObject();
Instance* createInstance(Object *obj, int dataSize, int x, int y, int z, float direction, float velocity);
void destroyInstance(Instance *id);
void destroyObject(Object *obj);
void triggerEvent(Script (*E)(Object *obj), Instance *i);
void cleanUpInstances();
void wipeInstances(Object *o);
void cleanUpObjects();
Object *getObject(Instance *I);
void swapDATA(Instance *I, void *d);
void setObjectPrimitive(Object *obj, GLfloat *verts[][3], GLfloat *cols[][3]);
void setObjectImage(Object *obj, int img, int x, int y);
char instanceExists(Object *obj);
Instance *nearInstance(Instance *this, Object *obj);
typedef enum {
	dock_vertices,
	dock_colors,
	dock_numVerts,
	dock_textured,
	dock_15,
	dock_14,
	dock_13,
	dock_12,
	dock_11,
	dock_10,
	dock_9,
	dock_8,
	dock_7,
	dock_6,
	dock_5,
	dock_4,
	dock_3,
	dock_2,
	dock_1,
	dock_0
} Dock;
