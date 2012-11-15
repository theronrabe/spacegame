/*
Theron Rabe
10/10/12
graphics.c
	This file takes defines any functions that either interact with OpenGL, or user-oriented graphics functions.
*/
GLuint _V,_F,_P;

void loadShaders(char *vertShader, char *fragShader) {
	char *vs = NULL,*fs = NULL;

        _V = glCreateShader(GL_VERTEX_SHADER);
        _F = glCreateShader(GL_FRAGMENT_SHADER);


        vs = textFileRead(vertShader);
        fs = textFileRead(fragShader);

        const char * ff = fs;
        const char * vv = vs;

        glShaderSource(_V, 1, &vv,NULL);
        glShaderSource(_F, 1, &ff,NULL);

        free(vs);free(fs);

        glCompileShader(_V);
        glCompileShader(_F);

        _P = glCreateProgram();
        glAttachShader(_P,_F);
        glAttachShader(_P,_V);

	glBindAttribLocation(_P, 0, "position");
	glBindAttribLocation(_P, 1, "color");

        glLinkProgram(_P);
        glUseProgram(_P);
}

void createWindow(char *title, int x, int y, int w, int h) {
	glutInitWindowPosition(x,y);
	glutInitWindowSize(w,h);
	glutCreateWindow(title);
}

void seeWorld2D(int x1, int y1, int x2, int y2) {
	glMatrixMode(GL_PROJECTION);
	glOrtho(x1, x2, y2, y1, -1, 100);
}

void seeWorld3D(int cx, int cy, int cz, int fx, int fy, int fz, int vx, int vy, int vz) {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cx, cy, cz, fx, fy, fz, vx, vy, vz);
}

void buildPrimitive(Instance *I, int size) {
	Object *obj = getObject(I);
	GLuint *VAO = I->VAO, *VBO = I->VBO;
	
	glGenVertexArrays(1, &VAO[0]);
	glBindVertexArray(VAO[0]);
	glGenBuffers(2,VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, 3*size*sizeof(GLfloat), obj->Port[dock_vertices], GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
	glBufferData(GL_ARRAY_BUFFER, 3*size*sizeof(GLfloat), obj->Port[dock_colors], GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 0, 0);
	glEnableVertexAttribArray(1);

	/*
	glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLint), obj->Port[dock_textured], GL_STATIC_DRAW);
	glVertexAttribPointer(2, 1, GL_INT, GL_FALSE, 0, 0);
	*/

	glBindVertexArray(0);
}

void drawPrimitive(Instance *I, char glType, int first, int count) {
	GLuint *VAO = I->VAO;
	glBindVertexArray(VAO[0]);
	glPushMatrix();
		glTranslatef(I->X, I->Y, I->Z);
		glRotatef(I->rotation, 0,0,1);
		glScalef(I->scale, I->scale, I->scale);
		glDrawArrays(glType, first, count);
	glPopMatrix();
	glBindVertexArray(0);
}

GLuint newImage(char *fn) {
	GLuint ret = SOIL_load_OGL_texture(fn, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);

	return 0;
}

void drawPrimitiveAt(Instance *i, char glType, float x, float y, float z, float scale, float rotation, int first, int count) {
	GLuint *VAO = i->VAO;
	glBindVertexArray(VAO[0]);
	glPushMatrix();
		glTranslatef(x, y, z);
		glRotatef(rotation, 0,0,1);
		glScalef(scale, scale, scale);
		glDrawArrays(glType, first, count);
	glPopMatrix();
	glBindVertexArray(0);
}
