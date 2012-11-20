//Natural Events
void Draw();
void Step();
void Idle();
void Move(int);
void KeyUp(unsigned char key, int x, int y);
void KeyDown(unsigned char key, int x, int y);
void Mouse(int button, int state, int x, int y);
void moveMouse(int x, int y);

Script onCreate(Object *obj);
Script onDraw(Object *obj);
Script onStep(Object *obj);
Script onKeyUp(Object *obj);
Script onKeyDown(Object *obj);
Script onDestroy(Object *obj);
Script onMouseLeft(Object *obj);
Script onMouseRight(Object *obj);
Script onIdle(Object *obj);
