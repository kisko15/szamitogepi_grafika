#ifndef SCENE_H
#define SCENE_H

#include "camera.h"
#include "texture.h"

#include <obj/model.h>
#define SKYBOX_SIZE 10000.0


typedef struct Scene
{
    Camera camera;
	Model old_house;
	Model old_house_ceiling;
	Model old_house_wall;
	Model old_house_wallP_1;
	Model old_house_wallP_2;
	Model old_house_wallP_3;
	Model wood;
	Model door;
	Model woods;
	Model grass;
	Model tree_leaves;
	Model tree_bark;
    Material material;
    GLuint texture_old_house;
	GLuint texture_old_house_wall;
	GLuint texture_old_house_wallp_1;
	GLuint texture_old_house_wallp_2;
	GLuint texture_old_house_ceiling;
	GLuint texture_wood;
	GLuint texture_door;
    GLuint texture_tree_1;
	GLuint texture_tree_2;
	GLuint texture_tree_3;
    GLuint texture_grass;
    GLuint help;
    int texture_sky;
	
} Scene;


/**
 * Initialize the scene by loading models.
 */
void init_scene(Scene* scene);

/**
 * Set the lighting of the scene.
 */
void set_lighting();

void update_lighting(Scene* scene, double value);

void set_spotlighting(Scene* scene, double value);

void my_light(int value);

/**
 * Set the spotlight
 */
void set_spotlight(Camera* camera);


/**
 * Set the current material.
 */
void set_material(const Material* material);

/**
 * Draw the scene objects.
 */
void draw_old_house(const Scene* scene);

void draw_old_house_ceiling(const Scene* scene);

void draw_old_house_wall(const Scene* scene);

void draw_old_house_wallP_1(const Scene* scene);

void draw_old_house_wallP_2(const Scene* scene);

void draw_wood(const Scene* scene);

void draw_grass(const Scene* scene);

void draw_tree_leaves(const Scene* scene);

void draw_tree_bark(const Scene* scene);

void draw_woods(const Scene* scene);

void draw_door(const Scene* scene);

/**
 * Draw the help 
 */
void draw_help(const Scene* scene);

/**
 * Draw the top skybox.
 */
void draw_skybox_right(const Scene* scene);
void draw_skybox_left(const Scene* scene);



#endif /* SCENE_H */
