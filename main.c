//stdlib imports
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//third party imports
#include <SDL2/SDL.h>

// local imports
#include "./ao_physics.c"
//#include "init

////////////////////////////////////////////
// BEGIN MAIN
////////////////////////////////////////////

int main(int argc, char *argv[])
{   
	FILE *fptr = fopen("main.log", "a");
	if (fptr == NULL)
	{
		perror("Failed to open main.log file.");
		return 1;
	}

	// Init SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{ 
		fprintf(fptr, "ERROR: Failed to initialize SDL_Video: %f\n", SDL_GetError()); 
	}

	SDL_Window *window = NULL;
	
	window = SDL_CreateWindow
	(
		 "AO_GAME_ENGINE",
		 SDL_WINDOWPOS_CENTERED,
		 SDL_WINDOWPOS_CENTERED,
		 1280,
		 960, 
		 SDL_WINDOW_SHOWN
	 );

	if(window == NULL);	 
	{
		fprintf(fptr, "ERROR: FAILED TO INITIALIZE SDL_Window: %f\n", SDL_GetError()); 
	}

	bool running = true;
	SDL_Event event;
	SDL_Surface *window_surface = NULL;
	SDL_Surface *image_surface = NULL;

	////////////////////
	/// MAIN LOOP
	////////////////////
	while(running)
	{
		// Loop through Events
		while (SDL_PollEvent(&event) != 0) 
		{
			if (event.type == SDL_QUIT) // close the window if user clicks exit. Check this first. 
			running = false;
		}

		window_surface = SDL_GetWindowSurface(window);
		image_surface = SDL_LoadBMP("test.bmp");
		
		if (image_surface == NULL) 
		{ 
			fprintf(fptr, "ERROR: Failed to load image: %f\n", SDL_GetError()); 
			running = false;
		}
		
		SDL_BlitSurface(image_surface, NULL, window_surface, NULL);
		SDL_UpdateWindowSurface(window);
	}

	// CLEAN UP
	SDL_FreeSurface(image_surface);
	image_surface = NULL;
	
	SDL_FreeSurface(window_surface);
	window_surface = NULL;
	
	SDL_DestroyWindow(window);
	window = NULL;

	SDL_Quit();
	
	fclose(fptr);
	return 0;
}
