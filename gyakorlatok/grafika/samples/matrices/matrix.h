#ifndef MATRIX_H
#define MATRIX_H

/**
 * Initializes all elements of the matrix to zero.
 */
void init_zero_matrix(float matrix[3][3]);

/**
 * Print the elements of the matrix.
 */
void print_matrix(const float matrix[3][3]);

/**
 * Add matrices.
 */
void add_matrices(const float a[3][3], const float b[3][3], float c[3][3]);

/**
 * Inicializáljuk az egység mátrixot.
 */

void init_identity_matrix(float matrix[3][3]);

/**
 * Skalárral való szorzás.
 */

void matrix_skalar(float a[3][3]);

/**
 * Mátrix szorzása mátrixal.
 */

void multiply_matrices(const float a[3][3], const float b[3][3], float szor[3][3]);

#endif // MATRIX_H

