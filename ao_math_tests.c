#include "ao_math.h" 
#include <stdio.h>
#include <assert.h>
#include <errno.h>

void vector_add_test(char* ptr_buff)
{
	
	FILE *fptr = fopen("tests.log", "a");
	if (fptr == NULL)
	{
		perror("Failed to open main.log file.");
		//return 1;
	}
	// create variables
	vector v1 = {1,2,3};
	vector v2 = {4,5,6};
	vector answer2 = {5,7,9};
	vector answer1 = {0,0,0};
	// assign vector addition to pointer
	vector* ptr_answer1 = &answer1;
	vector_add(v1, v2, ptr_answer1);
	//check the vectors are equal
	
	bool test = vector_equal(answer2, answer1);
	if (test == 1)
	{
		snprintf(ptr_buff, "FAIL: v1: {%f, %f, %f} != v2: {%f, %f, %f}\n", answer2[0], answer2[1], answer2[2] , answer1[0], answer1[1],answer1[2]);
	}
	// return the success message
	else
	{
		ptr_buff = "PASS: vector_add_test\n";
	}
}

int main(int argc, char* argv[])
{

	
	char buff[256];
	char* ptr_buff;
	vector_add_test(ptr_buff);
	//fprintf(fptr, buff);	

	// clean up
	//fclose(fptr);
	//fptr = NULL;
	return 0;
}
