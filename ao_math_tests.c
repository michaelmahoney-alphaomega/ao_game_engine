#include "ao_math.h" 
#include <stdio.h>
#include <assert.h>
#include <errno.h>


void vector_add_test(char* ptr_buff, size_t buff_size)
{
	// create variables
	vector v1 = {1,2,3};
	vector v2 = {4,5,6};
	vector answer2 = {5,7,9};
	vector answer1 = {0,0,0};
	// assign vector addition to pointer
	vector_add(v1, v2, answer1);
	//check the vectors are equal
	bool test = vector_equal(answer2, answer1);
	if (test == 0)
	{
		snprintf(ptr_buff, buff_size, "FAIL: v1: {%f, %f, %f} != v2: {%f, %f, %f}\n", answer2[0], answer2[1], answer2[2] , answer1[0], answer1[1],answer1[2]);
	}
	// return the success message
	else
	{
		snprintf(ptr_buff, buff_size, "PASS: vector_add_test\n");
	}
}

void vector_diff_test(char* ptr_buff, size_t buff_size)
{
	// create variables
	vector v1 = {1,2,3};
	vector v2 = {4,5,6};
	vector answer2 = {-3,-3,-3};
	vector answer1;
	// assign vector addition to pointer
	vector_diff(v1, v2, answer1);
	//check the vectors are equal
	bool test = vector_equal(answer2, answer1);
	if (test == 0)
	{
		snprintf(ptr_buff, buff_size, "FAIL: v1: {%f, %f, %f} != v2: {%f, %f, %f}\n", answer2[0], answer2[1], answer2[2] , answer1[0], answer1[1],answer1[2]);
	}
	// return the success message
	else
	{
		snprintf(ptr_buff, buff_size, "PASS: vector_diff_test\n");
	}
}

void vector_dot_product_test(char* ptr_buff, size_t buff_size)
{
	// create variables
	vector v1 = {1,2,3};
	vector v2 = {4,5,6};
	scalar answer2 = 32;
	scalar answer1;
	scalar epsilon = 0.0000001;
	// assign vector addition to pointer
	scalar* ptr_answer1 = &answer1;
	vector_dot_product(v1, v2, ptr_answer1);
	//check the  ectors are equal
	assert(scalar_equal(answer1, answer2, epsilon));
	bool test = scalar_equal(answer1, answer2, epsilon);
	if (test == 0)
	{
		snprintf(ptr_buff, buff_size, "FAIL: v1_dot: %f != v2_dot: %f\n", answer2 , answer1);
	}
	// return the success message
	else
	{
		snprintf(ptr_buff, buff_size, "PASS: vector_dot_product_test\n");
	}
}

void vector_scalar_product_test(char* ptr_buff, size_t buff_size)
{
	// create variables
	vector v = {1,2,3};
	scalar s = 12;
	vector answer2 = {12, 24, 36};
	vector answer1;
	// assign vector addition to pointer
	vector_scalar_product(v, s, answer1);
	//check the vectors are equal
	bool test = vector_equal(answer2, answer1);
	if (test == 0)
	{
		snprintf(ptr_buff, buff_size, "FAIL: v1: {%f, %f, %f} != v2: {%f, %f, %f}\n", answer2[0], answer2[1], answer2[2] , answer1[0], answer1[1],answer1[2]);
	}
	// return the success message
	else
	{
		snprintf(ptr_buff, buff_size, "PASS: vector_scalar_product_test\n");
	}
}



int main(int argc, char* argv[])
{
	FILE *fptr = fopen("tests.log", "a");
	if (fptr == NULL)
	{
		perror("Failed to open main.log file.");
		//return 1;
	}
	// run the tests
	// create buffer for return test string
	char buff[256];
	size_t buff_size = sizeof(buff)/sizeof(char);
	// vector addition test
	vector_add_test(buff, buff_size);
	fprintf(fptr, buff);	
	//vector difference test
	vector_diff_test(buff, buff_size);
	fprintf(fptr, buff);
	//vector dot product test
	vector_dot_product_test(buff, buff_size);
	fprintf(fptr, buff);
	// vector scalar product test
	vector_scalar_product_test(buff, buff_size);
	fprintf(fptr, buff);
	// clean up
	fclose(fptr);
	fptr = NULL;
	return 0;
}
