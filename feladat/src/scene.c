#include "scene.h"
#include "camera.h"

#include <GL/glut.h>

#include <time.h>
#include <obj/load.h>
#include <obj/draw.h>
#include <math.h>


float brightness=0;
float my_brightnesss=-1.5;
float spotlight = 10.3;

void init_scene(Scene* scene)
{
	/**
	* Ház textúra és obj betöltése
	*/
    load_model(&(scene->old_house), "obj/old_house.obj");
	load_model(&(scene->old_house_ceiling), "obj/old_house_ceiling.obj");
	load_model(&(scene->old_house_wall), "obj/old_house_wall.obj");
	load_model(&(scene->old_house_wallP_1), "obj/old_house_wallP_1.obj");
	load_model(&(scene->old_house_wallP_2), "obj/old_house_wallP_2.obj");
	
    scene->texture_old_house = load_texture("textures/Map.png");
	scene->texture_old_house_ceiling = load_texture("textures/Ceiling.jpg");
	scene->texture_old_house_wall = load_texture("textures/Wall.jpg"); 
	
	
	/**
	* Farönkök textúra és obj betöltése
	*/
    load_model(&(scene->wood), "obj/wood.obj");
    scene->texture_wood = load_texture("textures/WoodTexture.png");

	/**
	* A fű betöltése - Megjegyzés: még ha lehet, akkor mini fűcsomókat is be lehetne tölteni
	*/
    load_model(&(scene->grass), "obj/grass.obj");
    scene->texture_grass = load_texture("textures/grass_1.jpg"); 
	
	/**
	* Égbolt textúra betöltése
	*/
    scene->texture_sky = load_texture("textures/sky.png");
	
	/**
	* Erdő betöltése 
	*/
	load_model(&(scene->tree_leaves), "obj/leaves.obj");
	load_model(&(scene->tree_bark), "obj/bark.obj");
    scene->texture_tree_1 = load_texture("textures/maple_leaf.png");
	scene->texture_tree_3 = load_texture("textures/maple_bark.png");
	
	/**
	* Help textúra betöltése
	*/
	scene->help = load_texture("textures/help.png"); 

    scene->material.ambient.red = 1.0;
    scene->material.ambient.green = 1.0;
    scene->material.ambient.blue = 1.0;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;
	
    scene->material.specular.red = 1.0;
    scene->material.specular.green = 1.0;
    scene->material.specular.blue = 1.0;

    scene->material.shininess = 6.0;
}



void set_lighting()
{
    float ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    float diffuse_light[] = { 0.5f+brightness, 0.5f+brightness, 0.5f+brightness, 1.0f+brightness };
    float specular_light[] = { 0.3f+my_brightnesss, 0.3f+my_brightnesss, 0.3f+my_brightnesss, 1.0f+my_brightnesss };
    float position[] = { 40.0f, 20.0f, 10.0f, 40.0f };
	
	
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
	
	glEnable(GL_LIGHT0);
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE); // Enable local viewpoint.
	
}

void set_spotlight(Camera* camera)
{
	float position[] = { camera->position.x, camera->position.z, camera->position.y*(-1), 1.0f };
	float mat_ambient[] ={ 0.329412f, 0.223529f, 0.027451f,1.0f };
	float mat_diffuse[] ={ 0.780392f, 0.568627f, 0.113725f, 1.0f };
	float mat_specular[] ={ 0.992157f, 0.941176f, 0.807843f, 1.0f };

	glLightf(GL_LIGHT1,GL_SPOT_CUTOFF, 10.0);
	glLightfv(GL_LIGHT1, GL_POSITION, position);
	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.0+spotlight);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, mat_diffuse);
	glLightfv(GL_LIGHT1, GL_AMBIENT, mat_ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular);
	glLightf(GL_LIGHT1,GL_SPOT_EXPONENT, 100);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

}



void update_lighting(Scene* scene, double value)
{
	brightness+=value;
	
}

void set_spotlighting(Scene* scene, double value)
{
	spotlight+=value;
	
}	

void my_light(int value)
{
	if(value==0){
			my_brightnesss=1.5;
	}	
	if(value==1){
			my_brightnesss=-1.5;
	}		
}



void set_material(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
	
}

void draw_old_house(const Scene* scene)
{
	glRotatef(90,1,0,0);
    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_old_house);
	glPushMatrix();
		glScalef(0.23, 0.23, 0.23);
		glTranslatef(15,0.3,0);
		draw_model(&(scene->old_house));
	glPopMatrix();		
}

void draw_old_house_ceiling(const Scene* scene)
{
    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_old_house_ceiling);
	glPushMatrix();
		glScalef(0.23, 0.23, 0.23);
		glTranslatef(7.575,0.31,0);
		draw_model(&(scene->old_house_ceiling));
	glPopMatrix();
}

void draw_old_house_wall(const Scene* scene)
{
	set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_old_house_wall);
	glPushMatrix();
		glScalef(0.2305, 0.2305, 0.2305);
		glTranslatef(16.45,0.31,0);
		draw_model(&(scene->old_house_wall));
	glPopMatrix();
}


void draw_old_house_wallP_1(const Scene* scene)
{
	set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_old_house_wallp_1);
	glPushMatrix();
		glScalef(0.2308, 0.2308, 0.2308);
		glTranslatef(14.935,0.31,-17.6);
		draw_model(&(scene->old_house_wallP_1));
	glPopMatrix();
}

void draw_old_house_wallP_2(const Scene* scene)
{
	set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_old_house_wallp_2);
	glPushMatrix();
		glScalef(0.229, 0.229, 0.229);
		glTranslatef(15.048,0.31,14.9);
		draw_model(&(scene->old_house_wallP_2));
	glPopMatrix();
}



void draw_grass(const Scene* scene)
{
	int i, k;

    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_grass);	
	glPushMatrix();
		glScalef(0.01, 0.01, 0.01);
		glTranslatef(-5000.0,0,-5000.0);
		for (i=0; i<50; i++) {
			glPushMatrix();
			for(k=0;k<50;k++) {
				glTranslatef(0,0.0,200.0);
				draw_model(&(scene->grass));
			}
			glPopMatrix();
			glTranslatef(200,0.0,0.0);
		}
	glPopMatrix();
}

void draw_wood(const Scene* scene)
{
    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_wood);
	glPushMatrix();
		glScalef(0.08, 0.08, 0.08);
		glTranslatef(90.0,1.2,20.0);
		glRotatef(20.0, 0.0, 1.0, 0.0);
		draw_model(&(scene->wood));
	glPopMatrix();
}

void draw_tree_leaves(const Scene* scene)
{
    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_tree_1);
	glPushMatrix();
		glScalef(0.08, 0.08, 0.08);
		glTranslatef(95.0,0.1,12.0);
		draw_model(&(scene->tree_leaves));
	glPopMatrix();
}

void draw_tree_bark(const Scene* scene)
{
    set_material(&(scene->material));
	glBindTexture(GL_TEXTURE_2D, scene->texture_tree_3);
	glPushMatrix();
		glScalef(0.08, 0.08, 0.08);
		glTranslatef(95.0,0.1,12.0);
		draw_model(&(scene->tree_bark));
	glPopMatrix();
}

void draw_help(const Scene* scene)
{
	glBindTexture(GL_TEXTURE_2D, scene->help);
}


void draw_skybox_right(const Scene* scene)
{
    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;

    int n_slices, n_stacks;
    double radius;
    int i, k;

    n_slices = 12;
    n_stacks = 6;
    radius = 5000;

    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->texture_sky);
    glScaled(radius, radius, radius);

    glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i < n_stacks; ++i) {
        v1 = (double)i / n_stacks;
        v2 = (double)(i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double)k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1);
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2);
            glTexCoord2d(u, 1.0 - v1);
            glVertex3d(x1, y1, z1);
            glTexCoord2d(u, 1.0 - v2);
            glVertex3d(x2, y2, z2);
        }
    }
	
    glEnd();

    glPopMatrix();
}

void draw_skybox_left(const Scene* scene)
{
    double theta, phi1, phi2;
    double x1, y1, z1;
    double x2, y2, z2;
    double u, v1, v2;

    int n_slices, n_stacks;
    double radius;
    int i, k;

    n_slices = 12;
    n_stacks = 6;
    radius = 5000;

    glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, scene->texture_sky);
    glScaled(radius, radius, radius);

    glColor3f(1, 1, 1);

	glBegin(GL_TRIANGLE_STRIP);

    for (i = 0; i < n_stacks; ++i) {
        v1 = (double)i / n_stacks;
        v2 = (double)(i + 1) / n_stacks;
        phi1 = v1 * M_PI / 2.0;
        phi2 = v2 * M_PI / 2.0;
        for (k = 0; k <= n_slices; ++k) {
            u = (double)k / n_slices;
            theta = u * 2.0 * M_PI;
            x1 = cos(theta) * cos(phi1);
            y1 = sin(theta) * cos(phi1);
            z1 = sin(phi1);
            x2 = cos(theta) * cos(phi2);
            y2 = sin(theta) * cos(phi2);
            z2 = sin(phi2);
            glTexCoord2d(u, 1.0 - v1);
            glVertex3d(x1, y1, -z1);
            glTexCoord2d(u, 1.0 - v2);
            glVertex3d(x2, y2, -z2);
        }
    }
	
    glEnd();

    glPopMatrix();
}

	

	
