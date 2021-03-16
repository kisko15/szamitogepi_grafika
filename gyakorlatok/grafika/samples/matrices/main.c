#include "matrix.h"

int main(int argc, char* argv[])
{
	float a[3][3] = {
        { 1.0f, -2.0f,  3.0f},
        { 5.0f, -3.0f,  0.0f},
        {-2.0f,  1.0f, -4.0f}
    };
	float b[3][3];
	float c[3][3];
	float szor[3][3];

    init_zero_matrix(b);
    b[1][1] =  8.0f;
    b[2][0] = -3.0f;
    b[2][2] =  5.0f;

    print_matrix(a);
	printf("\n");
	
	print_matrix(b);
	printf("\n");
	
	multiply_matrices(a, b, szor);
	print_matrix(szor);
	printf("\n");
	
/*
	matrix_skalar(a);
	print_matrix(a);
	printf("\n");
*/
    
    add_matrices(a, b, c);
    print_matrix(c);
	printf("\n");
	
	init_identity_matrix(a);
	print_matrix(a);
	printf("\n");
	
	


	return 0;
}

