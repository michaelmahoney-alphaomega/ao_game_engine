void do_input(void)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT) {exit(0); break;}
		else {break;}
	}

