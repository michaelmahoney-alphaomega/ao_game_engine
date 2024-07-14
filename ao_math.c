#include "ao_math.h"
bool vector_equal(vector v, vector u)
{
	if ((v[0] == u[0]) & (v[1] == u[1]) & (v[2] == u[2])) {return 1;}
	else {return 0;}
}
void vector_add(vector v, vector w, vector* u_ptr)
{
	*u_ptr[0] = v[0] + w[0];
	*u_ptr[1] = v[1] + w[1];
	*u_ptr[2] = v[2] + w[2];
}

void v_diff(vector v, vector w, vector* u_ptr)
{
	// v - w 
	(*u_ptr)[0] = v[0] - w[0];
	(*u_ptr)[1] = v[1] - w[1];
	(*u_ptr)[2] = v[2] - w[2];
}

void dot_product(vector v, vector w, scalar* s_ptr)
{
	*s_ptr = (v[0] * w[0]) + (v[1] * w[1]) + (v[2] * w[2]);
}

void scalar_product( vector v, scalar s, vector* u_ptr)
{
	(*u_ptr)[0] = s * v[0];
	(*u_ptr)[1] = s * v[1];
	(*u_ptr)[2] = s * v[2];
}

//void vector_projection (vector v, vector w, vector* u_ptr)
//{
//	scalar s1 = 0;
//	scalar s2 = 0;
//	scalar* s1_ptr = &s1;
//	scalar* s2_ptr = &s2;
//
//	dot_product(v,w, s1_ptr);
//	dot_product(v,v, s2_ptr);
//	
//	scalar s = s1/s2;
//	scalar_product(v, s, u_ptr);
//	
//	s1_ptr = NULL;
//	s2_ptr = NULL;
//}
