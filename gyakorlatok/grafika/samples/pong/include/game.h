#ifndef GAME_H
#define GAME_H

#include "ball.h"
#include "pad.h"

/**
 * Game state representation
 */
typedef struct Game
{
    Ball ball;
    Pad left_pad;
    Pad right_pad;
    int width;
    int height;
} Game;

/**
 * Resize the game and update positions.
 */
void resize_game(Game* game, int width, int height);

/**
 * Restart the game.
 */
void restart_game(Game* game);

/**
 * Update the state of the game.
 * @param time elapsed time in seconds
 */
void update_game(Game* game, double time);

/**
 * Move the left pad to the given position.
 */
void move_left_pad(Game* game, float position);

/**
 * Move the right pad to the given position.
 */
void move_right_pad(Game* game, float position);

/**
 * Draw the left pad.
 */
void draw_left_pad(Game* game);

/**
 * Draw the right pad.
 */
void draw_right_pad(Game* game);

/**
 * Draw the ball.
 */
void draw_ball(Game* game);

/**
 * Draw the scoreboard.
 */

void draw_scoreboard(Game* game);





#endif /* GAME_H */
