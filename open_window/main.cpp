#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gImageSurface = NULL;

bool init() {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("Error happende on Init: %s", SDL_GetError());
        success = false;
    } else {
        //Create window
        gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf("Can't create window %s", SDL_GetError());
            success = false;
        } else {
            //get surfce
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia() {
    bool success = true;

    gImageSurface = SDL_LoadBMP("images/awesome.bmp");
    if (gImageSurface == NULL) {
        printf("Can't load image : %s ", SDL_GetError());
        success = false;
    }

    return success;
}

void close() {
    SDL_FreeSurface(gImageSurface);
    gImageSurface = NULL;

    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    SDL_Quit();    
}

int main(int argc, char* argv[]) {

    if (!init()) {
        printf("Failed to initialize\n");
    } else {
        if (!loadMedia()) {
            printf("Failed to load media\n");
        } else {
            SDL_BlitSurface(gImageSurface, NULL, gScreenSurface, NULL);
            SDL_UpdateWindowSurface(gWindow);
            SDL_Delay(2000);
        }
    }
    close();
    
    return 0;
}

