#ifndef BALL_H
#define BALL_H

/**
 * Ball position and speed
 */
typedef struct Ball
{
    float x;
    float y;
    float radius;
    float speed_x;
    float speed_y;
	float ball_rotation;
} Ball;

/**
 * Move the ball to the given position.
 */
void move_ball(Ball* ball, float x, float y);

/**
 * Start the ball from the given position.
 */
void start_ball(Ball* ball, float x, float y);

/**
 * Update the ball.
 * @param time elapsed time in seconds.
 */
 
 
void update_ball(Ball* ball, double time);

void rotation_ball(Ball* ball);

void update_rotation_ball(Ball* ball, double time);


void radius_ball(Ball* ball, float radius);



#endif /* BALL_H */
