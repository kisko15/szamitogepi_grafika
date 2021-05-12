#include "callbacks.h"	


#define VIEWPORT_RATIO (16.0 / 9.0)
#define VIEWPORT_ASPECT 50.0


int light_on = 0;
int spotlight_on = FALSE;
int squat = FALSE;


struct {
    int x;
    int y;
} mouse_position;

void display()
{
	if (!is_preview_visible){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);

		glPushMatrix();
		set_view_point(&camera);
		draw_old_house(&scene);
		draw_old_house_ceiling(&scene);
		draw_old_house_wall(&scene);
		draw_old_house_wallP_1(&scene);
		draw_old_house_wallP_2(&scene);
		draw_grass(&scene);
		draw_wood(&scene);
		draw_door(&scene);
		draw_woods(&scene);
		draw_skybox_right(&scene);
		draw_skybox_left(&scene);
		draw_tree_leaves(&scene);
		draw_tree_bark(&scene);
		set_lighting();
		draw_help(&scene);
		set_spotlight(&camera);
		glPopMatrix();
		glutSwapBuffers();
	} else {
		glPushMatrix();
		show_texture_preview(&scene);
		glPopMatrix();
	}
	
}

void reshape(GLsizei width, GLsizei height)
{
    int x, y, w, h;
    double ratio;

    ratio = (double)width / height;
    if (ratio > VIEWPORT_RATIO) {
        w = (int)((double)height * VIEWPORT_RATIO);
        h = height;
        x = (width - w) / 2;
        y = 0;
    }
    else {
        w = width;
        h = (int)((double)width / VIEWPORT_RATIO);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(VIEWPORT_ASPECT, VIEWPORT_RATIO, 0.01, 10000.0);
	
}

void mouse(int button, int state, int x, int y)
{
    mouse_position.x = x;
    mouse_position.y = y;
}

void motion(int x, int y)
{
    rotate_camera(&camera, mouse_position.x - x, mouse_position.y - y);
    mouse_position.x = x;
    mouse_position.y = y;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
		action.move_forward = TRUE;
        break;
    case 's':
		action.move_backward = TRUE;
        break;
    case 'a':
		action.step_left = TRUE;
        break;
    case 'd':
		action.step_right = TRUE;
        break;
	case 'c':
        if (squat == FALSE){
			set_camera_position(&camera, -0.25);
			squat = TRUE;
		} else {
			set_camera_position(&camera, +0.25);
			squat = FALSE;
		}
        break;	
    case '+':
        update_lighting(&scene, +0.1);
        break;	
    case '-':
        update_lighting(&scene, -0.1);
        break;		
    case 'k':
		if(light_on==0){
			my_light(0);
			light_on=1;
		}
		else{
			my_light(1);
			light_on=0;
		}
        break;
	case 'l':
        if(spotlight_on == FALSE){
			set_spotlighting(&scene, -10.0);
			spotlight_on = TRUE;
		}
		else if(spotlight_on == TRUE){
			set_spotlighting(&scene, +10.0);
			spotlight_on = FALSE;
		}
        break;
	case 'e':
            
        break;
	case 27:	
		exit(1);
	}

    glutPostRedisplay();
}


void help(int key, int x, int y)
{
    switch (key) {		
    case GLUT_KEY_F1:
	
        if (is_preview_visible) {
            is_preview_visible = FALSE;
        }
        else {
            is_preview_visible = TRUE;
        }
        break;
	}
	
    glutPostRedisplay();
	
}



void keyboard_up(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w':
		action.move_forward = FALSE;
		break;
    case 's':
		action.move_backward = FALSE;
        break;
    case 'a':
		action.step_left = FALSE;
		break;
    case 'd':
		action.step_right = FALSE;
        break;
    }

    glutPostRedisplay();
}

void idle()
{
    static int last_frame_time = 0;
    int current_time;
    double elapsed_time;
   
    current_time = glutGet(GLUT_ELAPSED_TIME);
    elapsed_time = (double)(current_time - last_frame_time) / 1000;
    last_frame_time = current_time;

	update_camera_position(&camera, elapsed_time);
	
    glutPostRedisplay();
}

void update_camera_position(struct Camera* camera, double elapsed_time)
{
	double distance;

	distance = elapsed_time * CAMERA_SPEED;

	if (action.move_forward == TRUE) {
		move_camera_forward(camera, distance);
	}

	if (action.move_backward == TRUE) {
		move_camera_backward(camera, distance);
	}

	if (action.step_left == TRUE) {
		step_camera_left(camera, distance);
	}

	if (action.step_right == TRUE) {
		step_camera_right(camera, distance);
	}
	

}




