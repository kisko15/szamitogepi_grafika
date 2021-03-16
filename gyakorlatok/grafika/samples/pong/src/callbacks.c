#include "callbacks.h"
#include "draw.h"


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    draw_game(&game);

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height)
{
   
    resize_game(&game, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, height, 0, -200, 200);
    glViewport(0, 0, width, height);

}

 
 

void motion(int x, int y)
{
    move_right_pad(&game, y);
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    float position;
	float radius;

    position = game.left_pad.position;
	radius = game.ball.radius;
    switch (key) {
    case 'w':
        position -= 10;
        break;
    case 's':
        position += 10;
        break;
	case 'n':
        if (radius < 40) {
			radius += 1;
			break;
		}
    case 'm':
        if (radius > 10) {
			radius -= 1;
			break;
		}
	}
    move_left_pad(&game, position);
	radius_ball(&game, radius);

    glutPostRedisplay();
}

void onMouseClick(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{ 
		//store the x,y value where the click happened
		move_ball(&game, x, y);
	}	
}



void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 500;
    last_frame_time = current_time;

    update_game(&game, elapsed_time);
	update_rotation_ball(&game, elapsed_time);
	
    glutPostRedisplay();
}

