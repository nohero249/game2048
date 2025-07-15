#define SDL_MAIN_USE_CALLBACKS 1
#include <iostream>
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "main.h"


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
    SDL_SetAppMetadata("Shooter Game", "0.0", "-");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    if (!SDL_CreateWindowAndRenderer("Shooter Game", 480, 272, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }

    if (event->type == SDL_EVENT_KEY_DOWN){
        switch (event->key.key) {
            case SDLK_ESCAPE:
                std::cout << "Kew pressed ESC\t |\t code " << event->key.scancode << std::endl;
                return SDL_APP_SUCCESS;
            case SDLK_W:
                std::cout << "Kew pressed W\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_A:
                std::cout << "Kew pressed A\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_S:std::cout << "Kew pressed S\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_D:std::cout << "Kew pressed D\t |\t code " << event->key.scancode << std::endl;
                break;
            default:
                break;
        }
    }

    if (event->type == SDL_EVENT_KEY_UP) {
        switch (event->key.key) {
            case SDLK_W:
                std::cout << "Kew released W\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_A:
                std::cout << "Kew released A\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_S:
                std::cout << "Kew released S\t |\t code " << event->key.scancode << std::endl;
                break;
            case SDLK_D:
                std::cout << "Kew released D\t |\t code " << event->key.scancode << std::endl;
                break;
            default:
                break;
        }
    }

    if (event->type == SDL_EVENT_MOUSE_BUTTON_DOWN) {
        switch (event->button.button) {
            case SDL_BUTTON_LEFT:
                printf("Mouse left button down\t |\t code %d\t |\t %f\t %f\n", event->button.button, event->button.x, event->button.y);
                break;
            case SDL_BUTTON_RIGHT:
                printf("Mouse right button down\t |\t code %d\t |\t %f\t %f\n", event->button.button, event->button.x, event->button.y);
                break;
            default:
                break;
        }
    }
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;
}

void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

}