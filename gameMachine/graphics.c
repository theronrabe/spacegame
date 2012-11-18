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

        glLinkProgram(_P);
        glUseProgram(_P);
	
	buildPrimitive();
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(cx, cy, cz, fx, fy, fz, vx, vy, vz);
}

void buildPrimitive() {
	glGenVertexArrays(1, &_VAO[0]);
	glBindVertexArray(_VAO[0]);
	glGenBuffers(1,_VBO);

	glBindBuffer(GL_ARRAY_BUFFER, _VBO[0]);
	glBufferData(GL_ARRAY_BUFFER, 4*4*sizeof(GLfloat), _PRIM, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 16, 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 16, (void*)(sizeof(float)*2));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);
	_SAMPLER_LOC = glGetUniformLocation(_P, "baseMap");
}

GLuint newImage(char *fn) {
	GLuint ret = SOIL_load_OGL_texture(fn, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, 0);
	return ret;
}

void drawImage(GLuint image, int x1, int y1, int width, int height, float rotation) {
	glBindVertexArray(_VAO[0]);
	glUniform1i(_SAMPLER_LOC, 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, image);

	glPushMatrix();
	glTranslatef(x1,y1,0);
	glRotatef(rotation, 0,0,1);
	glScalef(width, height, 1);
	glDrawArrays(GL_QUADS, 0, 4);
	glPopMatrix();

	glBindVertexArray(0);
}

void drawImagePoints(GLuint image, int x1, int y1, int z1, int x2, int y2, int z2, float rotation) {
	glBindTexture(GL_TEXTURE_2D, image);
	glPushMatrix();
	glTranslatef(x1,y1,z1);
	glRotatef(rotation, 0,0,1);
	glBegin(GL_QUADS);
		glTexCoord2i(0,0);
		glVertex3i(0,0,0);
		glTexCoord2i(0,1);
		glVertex3i(0,y2-y1,0);
		glTexCoord2i(1,1);
		glVertex3i(x2-x1,y2-y1,z2-z1);
		glTexCoord2i(1,0);
		glVertex3i(x2-x1,0,z2-z1);
	glEnd();
	glPopMatrix();
}
