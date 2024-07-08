#ifndef AO_MATH_H_
#define AO_MATH_H_
typedef double vector[3];
typedef double scalar;
void vector_add(vector v, vector w, vector *u_ptr);
void v_diff(vector v, vector w, vector* u_ptr);
void dot_product(vector v, vector w, scalar* s_prt);
void scalar_product( vector v, scalar s, vector* u_ptr);
void vector_projection (vector v, vector w, vector* u_ptr);
#endif
