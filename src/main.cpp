#include <array>
#include <iostream>

// GLM includes
#include <glm/vec3.hpp>

// SDL2 includes
#include <SDL.h>

int main(int argc, char** args)
{
	// GLM tests
	std::array<int, 5> myArray;
	for (auto i : myArray)
	{
		i = i;
	}

	glm::vec3 myVec(1.0f, 2.0f, 3.0f);
	std::cout << myVec.x << " " << myVec.y << " " << myVec.z << std::endl;

	// SDL tests
	if (SDL_Init(SDL_INIT_VIDEO) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	else
	{
		std::cout << "SDL2 enabled!" << std::endl;
	}
	SDL_Quit();
	return 0;
}