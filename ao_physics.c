#include <SDL2/SDL.h>

static int FRAME_RATE = 60;
typedef int position[3];
typedef int velocity[3];
typedef int acceleration[3];

static size_t pos_len = sizeof(position)/sizeof(int);
static size_t vel_len = sizeof(velocity)/sizeof(int);
static size_t acc_len = sizeof(acceleration)/sizeof(int);

struct ao_surface 
{
	SDL_Surface* surface;
	acceleration acc;
	velocity vel;
	position pos;
};

void update_acceleration (acceleration a) // need to define the input change to acceleration
{
}

void update_velocity(velocity v, acceleration a)
{
	for (int i = 0; i < vel_len; i++)
	{
		int v_new = v[i] + a[i];
		v[i] = v_new;
	}
}


void update_position(position x, velocity v) 
{
	for (int i = 0; i < pos_len; i++)
	{
		int x_new = x[i] + v[i]; 
		x[i] = x_new;
	}
}

void motion(struct ao_surface* s)
{
	//while (input)
	{
		update_velocity(s->vel, s->acc);
		update_position(s->pos, s->vel);
		update_acceleration(s->acc);
	}
}


