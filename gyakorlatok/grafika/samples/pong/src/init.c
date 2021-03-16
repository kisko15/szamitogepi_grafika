#include <GL/glut.h>

void init_opengl()
{
    glClearColor(0.1, 0.3, 0.4, 0.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

