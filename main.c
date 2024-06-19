#include <windows.h>
#include <stdio.h>
//#include <stdlib.h>

static int FRAME_RATE = 60;

typedef double position[3];
typedef double velocity[3];
typedef double acceleration[3];

static size_t pos_len = sizeof(position)/sizeof(double);
static size_t vel_len = sizeof(velocity)/sizeof(double);
static size_t acc_len = sizeof(acceleration)/sizeof(double);

void update_acceleration (acceleration *a) // need to define the input change to acceleration
{
}


void update_velocity(velocity *v, acceleration *a)
{
	for (int i = 0; i < vel_len; i++)
	{
		double v_new = (*v)[i] + (*a)[i] * 1.0/FRAME_RATE;
		(*v)[i] = v_new;
	}
}


void update_position(position *x, velocity  *v) 
{
	for (int i = 0; i < pos_len; i++)
	{
		double x_new = (*x)[i] + (*v)[i] * 1.0/FRAME_RATE; 
		(*x)[i] = x_new;
	}
}

void motion(position *x, velocity *v, acceleration *a)
{
}


int main()
{   
	FILE *fptr = fopen("main.log", "a");
	if (fptr == NULL)
	{
		perror("Failed to open main.log file.");
		return 1;
	}


    // HINSTANCE hDll = LoadLibrary(TEXT("sdl2/SDL2.dll"));
    //if (hDll == NULL)
    //{
      //  fprintf(fptr, "Failed to load SDL2.dll\n");
       // return 1;
    //}

	position x0 = {1,1,1};
	velocity v0 = {1,1,1};
	acceleration a0 = {1,1,1};

	fprintf(fptr, "current position: x = %f y = %f z = %f\n", x0[0], x0[1], x0[2]);
	fprintf(fptr, "current velocity: x = %f y = %f z = %f\n", v0[0], v0[1], v0[2]);
	fprintf(fptr, "current acceleration: x = %f y = %f z = %f\n", a0[0], a0[1], a0[2]);


	double (*ptr_x0)[3];
	ptr_x0 = &x0;

	double (*ptr_v0)[3];
	ptr_v0 = &v0;

	double (*ptr_a0)[3];
	ptr_a0 = &a0;
	
	update_acceleration(ptr_a0);
	update_velocity(ptr_v0, ptr_a0);
	update_position(ptr_x0, ptr_v0);

	fprintf(fptr, "current position: %f %f %f\n", x0[0], x0[1], x0[2]);
	fprintf(fptr, "current velocity: %f %f %f\n", v0[0], v0[1], v0[2]);
	fprintf(fptr, "current acceleration: %f %f %f\n", a0[0], a0[1], a0[2]);




	// clean up
	ptr_x0 = NULL;
	ptr_v0 = NULL;
	ptr_a0 = NULL;
	
	fclose(fptr);
	
	// end program
	return 0;
}
