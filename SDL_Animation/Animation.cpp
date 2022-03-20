#include<SDL.h>
#include<iostream>
#include<time.h>

SDL_Window* win = NULL;
SDL_Renderer* ren = NULL;

int win_width = 900, win_height = 700;

void deInit(int error)
{
	if (ren != NULL) SDL_DestroyRenderer(ren);
	if (win != NULL) SDL_DestroyWindow(win);
	SDL_Quit();
	exit(error);
}

void init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("Couldn't init SDL! Error: %s", SDL_GetError());
		system("pause");
		deInit(1);
	}

	win = SDL_CreateWindow("Rain", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		win_width, win_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (win == NULL)
	{
		printf("Couldn't creat window! Error: %s", SDL_GetError());
		system("pause");
		deInit(1);
	}

	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	if (ren == NULL)
	{
		printf("Couldn't creat renderer! Error: %s", SDL_GetError());
		system("pause");
		deInit(1);
	}
}

void drawGrid()
{
	for (int j = 0; j < win_height; j += 10)
	{
		//SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		//SDL_RenderClear(ren);

		for (int i = 0; i < win_width; i += 10)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
			SDL_RenderDrawLine(ren, i, j, i + 10, j + 10);
		}

		SDL_RenderPresent(ren);

		SDL_Delay(1);
	}

	SDL_Delay(100);

	for (int j = 0; j < win_height; j += 10)
	{
		//SDL_SetRenderDrawColor(ren, 200, 200, 200, 255);
		//SDL_RenderClear(ren);

		for (int i = win_width - 1; i >= 0; i -= 10)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
			SDL_RenderDrawLine(ren, i, j, i - 10, j + 10);
		}

		SDL_RenderPresent(ren);

		SDL_Delay(1);
	}

	SDL_RenderPresent(ren);
}

void drawParty()
{
	while(true)
	{
		//SDL_SetRenderDrawColor(ren, rand() % 255, rand() % 255, rand() % 255, 255);
		//SDL_RenderClear(ren);

		for (int i = 0; i < win_width; i += 10)
		{
			SDL_SetRenderDrawColor(ren, rand() % 255, rand() % 255, rand() % 255, 255);
			SDL_RenderDrawLine(ren, rand() % win_width, rand() % win_height, rand() % win_width, rand() % win_height);
		}

		SDL_RenderPresent(ren);

		SDL_Delay(10);
	}
}

void drawRain()
{
	for (int i = 0; i < win_width; i += 10)
	{
		for (int j = 0; j < win_height; j += 10)
		{
			SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
			SDL_RenderDrawLine(ren, i, j, i + 10, j);
		}

		SDL_RenderPresent(ren);

		SDL_Delay(10);
	}
}

void drawRain2()
{	
	while (true)
	{
		SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
		SDL_RenderClear(ren);

		for (int j = rand() % 50; j < win_height; j += rand() % 50)
		{

			for (int i = rand() % 100; i < win_width; i += rand() % 100)
			{
				SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
				SDL_RenderDrawLine(ren, i, j, i + 10, j + 10);
			}
		}

		SDL_RenderPresent(ren);
		SDL_Delay(100);

		/*SDL_SetRenderDrawColor(ren, 0, 0, 255, 255);
		
		for(int i = 0; i < 10; i++)
			SDL_RenderDrawLine(ren, rand() % win_width, rand() % win_height, rand() % win_width, rand() % win_height);

		SDL_RenderPresent(ren);

		SDL_Delay(50);*/
	}
}

int main(int argc, char* argv[])
{
	init();

	srand(time(0));

	SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
	SDL_RenderClear(ren);

	//drawGrid();
	//drawParty();
	drawRain2();

	SDL_Delay(1000);
	
	deInit(0);
	return 0;
}