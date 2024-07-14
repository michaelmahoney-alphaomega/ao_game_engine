#ifndef AO_MATH_H_
#define AO_MATH_H_
#include <stdbool.h>
#include <stddef.h>
typedef double vector[3];
typedef double scalar;
bool vector_equal(vector v, vector u);
bool scalar_equal(scalar a,  scalar b, scalar epsilon);
void vector_add(vector v, vector w, vector u);
void vector_diff(vector v, vector w, vector u);
void vector_dot_product(vector v, vector w, scalar* s_prt);
void vector_scalar_product( vector v, scalar s, vector u);
void vector_projection (vector v, vector w, vector u);
#endif

