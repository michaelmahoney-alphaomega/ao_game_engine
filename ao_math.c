#include "ao_math.h"
bool vector_equal(vector v, vector u)
{
	if ((v[0] == u[0]) & (v[1] == u[1]) & (v[2] == u[2])) {return 1;}
	else {return 0;}
}

bool scalar_equal(scalar a, scalar b, scalar epsilon)
{
	scalar lower_bound = a - epsilon;
	scalar upper_bound = a + epsilon;

	if (lower_bound < b < upper_bound) {return 1;}
	else {return 0;}
}

void vector_add(vector v, vector w, vector u)
{
	u[0] = v[0] + w[0];
	u[1] = v[1] + w[1];
	u[2] = v[2] + w[2];
}

void vector_diff(vector v, vector w, vector u)
{
	// v - w 
	u[0] = v[0] - w[0];
	u[1] = v[1] - w[1];
	u[2] = v[2] - w[2];
}

void vector_dot_product(vector v, vector w, scalar* s_ptr)
{
	*s_ptr = (v[0] * w[0]) + (v[1] * w[1]) + (v[2] * w[2]);
}

void vector_scalar_product( vector v, scalar s, vector u)
{
	u[0] = s * v[0];
	u[1] = s * v[1];
	u[2] = s * v[2];
}

void vector_projection (vector v, vector w, vector u) // project w onto v
{
	// Create locals
	scalar s1;
	scalar s2;
	scalar* s1_ptr = &s1;
	scalar* s2_ptr = &s2;
	// scale w to v
	vector_dot_product(v,w, s1_ptr);
	vector_dot_product(v,v, s2_ptr);
	// align vectors
	scalar s = s1/s2;
	vector_scalar_product(v, s, u);
	// clean up
	s1_ptr = NULL;
	s2_ptr = NULL;
}
