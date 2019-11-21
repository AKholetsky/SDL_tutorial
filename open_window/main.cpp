#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL.h>
#endif
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {

    //Window render to
    SDL_Window* window = NULL;

    //Window surface - 2d image
    SDL_Surface* surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error happende on Init: %s", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == NULL) {
            printf("Can't create window %s", SDL_GetError());
        } else {
            //get surfce
            surface = SDL_GetWindowSurface(window);
            //draw rectangle
            SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0x00, 0xFF));
            //update
            SDL_UpdateWindowSurface(window);
            //delay
            SDL_Delay(2000);
        }
    }
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

