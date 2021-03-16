#include "scene.h"

#include <GL/glut.h>
#include <math.h>

void init_scene(Scene* scene)
{
	scene->shape_rotation = 0.0;
}

void update_scene(Scene* scene, double time)
{
	scene->shape_rotation += 5.0 * time;
	if (scene->shape_rotation > 360.0) {
		scene->shape_rotation -= 360.0;
	}
}

void draw_scene(const Scene* scene)
{
	int i, k;
	
    draw_origin();

	glPushMatrix();
	glRotatef(scene->shape_rotation, 1, 0, 0);
	draw_sphere();
	glPopMatrix();


/*	
	glPushMatrix();
	for (i=0; i<8; i++){
		glPushMatrix();
		for (k=0; k<8; k++){
			if ((i%2) == 0) {
				if ((k%2) == 0) {
					glColor3f(1,1,1);
				} else {
					glColor3f(0,0,0);
				}
			} else {
				if ((k%2) == 0) {
					glColor3f(0,0,0);
				} else {
					glColor3f(1,1,1);
				}
			}
			draw_cone();
			glTranslatef(1,0,0);
		}
		glPopMatrix();
		glTranslatef(0,1,0);
	}
	glPopMatrix();
*/

	
/*
	draw_cylinder();
	
	glPushMatrix();
	for (i=0; i<2; i++) {
		draw_circle();
		glTranslatef(0,0,1);
	}
	glPopMatrix();
*/

	/*
	glPushMatrix();
	for (k=0; k<8; k++) {
		glPushMatrix();
		for (i=0; i<6; i++){
		
			glBegin(GL_TRIANGLES);

			glColor3f(1, 0, 0);
			glVertex3f(1, 0, 0);

			glColor3f(0, 1, 0);
			glVertex3f(0, 1, 0);

			glColor3f(0, 0, 1);
			glVertex3f(0, 0, 1);

			glEnd();
			
			glTranslatef(0,0,0.2);
		}
		glPopMatrix();
		glTranslatef(1,1,0);
	}
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(scene->shape_rotation, 1, 0, 0);
	glColor3f(cos(scene->shape_rotation / 60), sin(scene->shape_rotation / 60), 0);
	glutWireTeapot(scene->shape_rotation / 360.0);
	glPopMatrix();
	*/
}

void draw_origin()
{
    glBegin(GL_LINES);

    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(1, 0, 0);

    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 1, 0);

    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 1);

    glEnd();
}

void draw_cylinder()
{
	
	float x, y, phi, h;
	
	glPushMatrix();
	glBegin(GL_QUAD_STRIP);
	
	phi = 0.0;
	h = 1.0;
	while (phi < M_PI) {
		x = cos(2 * phi);
		y = sin(2 * phi);
		glColor3f((2 * phi) / M_PI , 1.0 - ((2 * phi) / M_PI), 0);
		glVertex3f(x, y, 0);
		glVertex3f(x, y, h);
		phi += 0.01;
	}
    glEnd();
	glPopMatrix();
}

void draw_circle()
{
	float x, y, phi;
	
	glPushMatrix();
	glBegin(GL_TRIANGLE_STRIP);	
	phi = 0.0;
	while (phi < M_PI) {
		x = cos(2 * phi);
		y = sin(2 * phi);
		glColor3f((2 * phi) / M_PI , 1.0 - ((2 * phi) / M_PI), 0);
		glVertex3f(x, y, 0);
		glVertex3f(0, y, 0);
		phi += 0.01;
	}
	glEnd();
	glPopMatrix();
}

void draw_cone()
{	
	glPushMatrix();
	glBegin(GL_TRIANGLE_FAN);	
		glVertex3f(0, 0, 0);
		glVertex3f(1, 0, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(0, 1, 0);
	glEnd();
	glPopMatrix();
}

void draw_sphere()
{
	glutSolidSphere(1, 15, 15);
}

