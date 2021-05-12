#include "camera.h"
#include <GL/glut.h>
#include <math.h>


void can_move(struct Camera* camera)
{
    if(camera->position.x > 1.1 && camera->position.x < 3.8 && camera->position.y > -1.2 && camera->position.y < 1.4){
        camera->position=camera->prev_position;
	}
	
	if(camera->position.x > 4.2 && camera->position.x < 5.5 && camera->position.y > -1.2 && camera->position.y < 1.4){
        camera->position=camera->prev_position;
	}
	
	if(camera->position.x > 3.8 && camera->position.x < 4.2 && camera->position.y > 1.2 && camera->position.y < 1.4){
        camera->position=camera->prev_position;
	}
}

void init_camera(struct Camera* camera)
{
	camera->position.x = 4.5;
	camera->position.y = -5.5;
	camera->position.z = 0.5;

	camera->pose.x = 0;
	camera->pose.y = 0;
	camera->pose.z = 90;
}

void set_view_point(const struct Camera* camera)
{
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glRotatef(-(camera->pose.x + 90), 1.0, 0, 0);
    glRotatef(-(camera->pose.z - 90), 0, 0, 1.0);
    glTranslatef(-camera->position.x, -camera->position.y, -camera->position.z);
    
}

void rotate_camera(struct Camera* camera, double horizontal, double vertical)
{
	camera->pose.z += horizontal;
	camera->pose.x += vertical;

	if (camera->pose.z < 0) {
		camera->pose.z += 360.0;
	}

	if (camera->pose.z > 360.0) {
		camera->pose.z -= 360.0;
	}

	if (camera->pose.x < 0) {
		camera->pose.x += 360.0;
	}

	if (camera->pose.x > 360.0) {
		camera->pose.x -= 360.0;
	}
}

void set_camera_position(Camera* camera, double position)
{
	camera->position.z += position;
}


void move_camera_forward(struct Camera* camera, double distance)
{
	camera->prev_position = camera->position;
	double angle = degree_to_radian(camera->pose.z);
	camera->position.x += cos(angle) * distance;
    camera->position.y += sin(angle) * distance;
	can_move(camera);
}

void move_camera_backward(struct Camera* camera, double distance)
{
	camera->prev_position = camera->position;
	double angle = degree_to_radian(camera->pose.z);
	camera->position.x -= cos(angle) * distance;
    camera->position.y -= sin(angle) * distance;
	can_move(camera);
}

void step_camera_left(struct Camera* camera, double distance)
{
	camera->prev_position = camera->position;
	double side_angle = degree_to_radian(camera->pose.z + 90.0);
	camera->position.x += cos(side_angle) * distance;
    camera->position.y += sin(side_angle) * distance;
	can_move(camera);
}

void step_camera_right(struct Camera* camera, double distance)
{
	camera->prev_position = camera->position;
	double side_angle = degree_to_radian(camera->pose.z + 90.0);
	camera->position.x -= cos(side_angle) * distance;
    camera->position.y -= sin(side_angle) * distance;
	can_move(camera);
}



void show_texture_preview()
{
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1, 1, 1);

    glBegin(GL_QUADS);
    glTexCoord2f(0, 0);
    glVertex3f(-2, 1, -4);
    glTexCoord2f(1, 0);
    glVertex3f(2, 1, -4);
    glTexCoord2f(1, 1);
    glVertex3f(2, -1, -4);
    glTexCoord2f(0, 1);
    glVertex3f(-2, -1, -4);
    glEnd();

    glDisable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_DEPTH_TEST);
	glutSwapBuffers();
}

