#ifndef CAMERA_H
#define CAMERA_H

#include "utils.h"

#define CAMERA_SPEED 0.9

typedef struct Camera
{
	struct vec3 position;
	struct vec3 pose;
	struct vec3 prev_position;
}Camera;

int is_preview_visible;

void set_camera_position(Camera* camera, double position);

void show_texture_preview();

/*
* Checks if the camera can move. If it can't, loads the previous position.
*/
void can_move(struct Camera* camera);

/**
 * Initialize the camera position and direction.
 */
void init_camera(struct Camera* camera);

/**
 * Transform the models into the view point of the camera.
 */
void set_view_point(const struct Camera* camera);

/**
 * Rotate the camera horizontally and vertically.
 */
void rotate_camera(struct Camera* camera, double horizontal, double vertical);

/**
 * Move the camera forward.
 */
void move_camera_forward(struct Camera* camera, double distance);

/**
 * Move the camera backward.
 */
void move_camera_backward(struct Camera* camera, double distance);

/**
 * Step the camera left.
 */
void step_camera_left(struct Camera* camera, double distance);

/**
 * Step the camera right.
 */
void step_camera_right(struct Camera* camera, double distance);



#endif // CAMERA_H

