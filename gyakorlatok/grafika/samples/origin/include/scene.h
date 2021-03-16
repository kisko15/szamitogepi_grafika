#ifndef SCENE_H
#define SCENE_H

#include "camera.h"

typedef struct Scene
{
    // NOTE: Place for model structures and texture ids.
	float shape_rotation;
} Scene;

/**
 * Initialize the scene.
 */
void init_scene(Scene* scene);

/**
 * Update the scene.
 */
void update_scene(Scene* scene, double time);

/**
 * Draw the scene objects.
 */
void draw_scene(const Scene* scene);

/**
 * Draw the cylinder.
 */
void draw_cylinder();

/**
 * Draw the circle.
 */
void draw_circle();

/**
 * Draw the cone.
 */
void draw_cone();

/**
 * Draw the sphere.
 */
void draw_sphere();

/**
 * Draw the origin of the world coordinate system.
 */
void draw_origin();

#endif /* SCENE_H */

