#include "callbacks.h"
#include "init.h"

#include <time.h>
#include <stdlib.h>
#include <SOIL/SOIL.h>
#include <GL/glut.h>
#include <stdio.h>


 
void set_callbacks()
{
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);
	glutSpecialFunc(help);
    glutIdleFunc(idle);
}


void initialize()
{
	glShadeModel(GL_SMOOTH);

    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);

    glClearColor(1.0, 1.0, 1.0, 0.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glClearDepth(1.0);
    glEnable(GL_TEXTURE_2D);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

}

/**
 * Main function
 */
int main(int argc, char* argv[])
{
    int window;
	
	srand(time(0));
    glutInit(&argc, argv);
	glutInitWindowSize(1366, 768);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    window = glutCreateWindow("Indie horror game");
    glutSetWindow(window);
	
	initialize();
    init_opengl();
    init_scene(&scene);
    init_camera(&camera);
    set_callbacks();

    glutMainLoop();
    return 0;
}
		