//stdlib imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//third party imports
#include <SDL3/SDL.h>

//local imports
//#include "init.c"

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



int main(int argc, char **args)
{   
	FILE *fptr = fopen("main.log", "a");
	if (fptr == NULL)
	{
		perror("Failed to open main.log file.");
		return 1;
	}


	position x0 = {1,1,1};
	velocity v0 = {1,1,1};
	acceleration a0 = {1,1,1};

	//fprintf(fptr, "current position: x = %f y = %f z = %f\n", x0[0], x0[1], x0[2]);
	////fprintf(fptr, "current velocity: x = %f y = %f z = %f\n", v0[0], v0[1], v0[2]);
	//fprintf(fptr, "current acceleration: x = %f y = %f z = %f\n", a0[0], a0[1], a0[2]);


	double (*ptr_x0)[3];
	ptr_x0 = &x0;

	double (*ptr_v0)[3];
	ptr_v0 = &v0;

	double (*ptr_a0)[3];
	ptr_a0 = &a0;
	
	update_acceleration(ptr_a0);
	update_velocity(ptr_v0, ptr_a0);
	update_position(ptr_x0, ptr_v0);

	//fprintf(fptr, "current position: %f %f %f\n", x0[0], x0[1], x0[2]);
	//fprintf(fptr, "current velocity: %f %f %f\n", v0[0], v0[1], v0[2]);
	//fprintf(fptr, "current acceleration: %f %f %f\n", a0[0], a0[1], a0[2]);

	// clean up
	fprintf(fptr, "INFO: Cleaning up pointers, libs, SDL\n");
	
	ptr_x0 = NULL;
	ptr_v0 = NULL;
	ptr_a0 = NULL;
	
	///////////// BEGIN SDL /////////////
	SDL_Window *window = NULL;
	SDL_Surface *window_surface = NULL;
	SDL_Surface *image_surface = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) { fprintf(fptr, "ERROR: Failed to initialize SDL_Video: %f\n", SDL_GetError()); exit(1);}

	bool running = true;
	SDL_Event event;

	while (running)
	{
		window = SDL_CreateWindow ("ao_game_engine", 640, 480, SDL_EVENT_WINDOW_SHOWN);

		if(window == NULL) 
		{
			fprintf(fptr, "ERROR: Failed to initialize SDL_Window: %f\n", SDL_GetError()); 
			exit(1);
		}

		while (SDL_PollEvent(&event) != 0)
		{
			if (event.type == SDL_EVENT_QUIT)
			{
				running = false;
			}
		}

			
		window_surface = SDL_GetWindowSurface(window);
		image_surface = SDL_LoadBMP("./test.bmp");

		if (image_surface == NULL) { fprintf(fptr, "ERROR: Failed to load image: %f\n", SDL_GetError()); exit(1); }

		//SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
		//SDL_UpdateWindowSurface(window);
		//SDL_Delay(2000);
				
		SDL_DestroySurface(image_surface);
		image_surface = NULL;

		SDL_DestroySurface(window_surface);
		window_surface = NULL;

		SDL_DestroyWindow(window);
		window = NULL;

	}
	
	SDL_Quit();
	///////////// END SDL //////////////
	
	//close log function
	fclose(fptr);
	
	// end program
	return 0;
}
