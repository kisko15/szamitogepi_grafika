#include "ball.h"

void move_ball(Ball* ball, float x, float y)
{
    ball->x = x;
    ball->y = y;
}

void start_ball(Ball* ball, float x, float y)
{
	ball->radius = 40;
    move_ball(ball, x, y);
    ball->speed_x = 100;
	ball->speed_y = 100;
}

void update_ball(Ball* ball, double time)
{
    ball->x += ball->speed_x * time;
    ball->y += ball->speed_y * time;
}

void radius_ball(Ball* ball, float radius)
{
	ball->radius = radius;

}

void rotation_ball(Ball* ball)
{
	ball->ball_rotation = 0.0;
}

void update_rotation_ball(Ball* ball, double time)
{
	ball->ball_rotation += 30.0 * time;
}


