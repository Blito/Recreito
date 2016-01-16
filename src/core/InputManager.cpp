#include "InputManager.h"

#include <SDL.h>

#include <iostream>

using namespace Core;

InputManager::InputManager()
{

}

void InputManager::update(float millis)
{
    SDL_Event event;
    /* Check for new events */
    while(SDL_PollEvent(&event))
    {
        switch( event.type )
        {
            case SDL_QUIT:
                shouldQuit = true;
            break;
            case SDL_KEYDOWN:
            switch( event.key.keysym.sym )
            {
                case SDLK_LEFT:
                    std::cout << "Left pressed." << std::endl;
                    break;
                case SDLK_RIGHT:
                    std::cout << "Right pressed." << std::endl;
                    break;
                case SDLK_UP:
                    std::cout << "Up pressed." << std::endl;
                    break;
                case SDLK_DOWN:
                    std::cout << "Down pressed." << std::endl;
                    break;
                default:
                    break;
            }
            break;
            case SDL_KEYUP:
                std::cout << "Key released." << std::endl;
            break;
        }
    }
}
