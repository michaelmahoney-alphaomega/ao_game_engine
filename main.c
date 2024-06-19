#include <windows.h>
#include <stdio.h>
//#include <sdl2/sdl.h>

int main()
{   
    HINSTANCE hDll = LoadLibrary(TEXT("sdl2/SDL2.dll"));
    if (hDll == NULL)
    {
        printf("Failed to load SDL2.dll\n");
        return 1;
    }
	typedef int position[3];
	typedef int velocity[3][3];
	typedef int acceleration[3][3];
	position current_position;
	velocity current_velocity;
	acceleration current_acceleration;

	position* dot_product(position X, velocity V) 
	{
		size_t pos_len = sizeof(X) / sizeof(int);
		size_t vel_len = sizeof(V) / sizeof(int);
		for (int i = 0; i < pos_len; i++)
		{
			int temp = 0;
			for (int j = 0; j < vel_len; j++) 
			{
				temp += X[i] * V[i][j];
			}
			
			X[i] = temp;
		}
			
		return  X*;
	}

	position[0] = 1;	
    FreeLibrary(hDll);

	return 0;
}
