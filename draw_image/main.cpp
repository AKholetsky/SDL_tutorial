#include <SDL2/SDL.h>
#include <stdio.h>

bool init();

bool loadMedia();

void close();

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;
SDL_Surface* imageSurface = NULL;

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* argv[]) {
    if (!init()) {
        printf("Can't initialize sdl\n");
    } else {
        if (!loadMedia()) {
            printf("Failed to load media\n");
        } else {
            SDL_BlitSurface(imageSurface, NULL, screenSurface, NULL);
            SDL_UpdateWindowSurface(window);
            SDL_Delay(2000);
        }
    }
    close();
    return 0;
}

bool init() {
    bool success = false;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL not initialized %s", SDL_GetError());
        success = false;
    } else {
        window = SDL_CreateWindow("SDL Tutorial", 
                SDL_WINDOWPOS_UNDEFINED,
                SDL_WINDOWPOS_UNDEFINED,
                SCREEN_WIDTH, 
                SCREEN_HEIGHT,
                SDL_WINDOW_SHOWN);
        
        if (window == NULL) {
            printf("Window not created %s", SDL_GetError());
            success = false;
        } else {
            screenSurface = SDL_GetWindowSurface(window);
            success = true;
        }
    }
    return success;
}

bool loadMedia() {
    bool success = true;

    imageSurface = SDL_LoadBMP("resource/image.bmp");
    if (imageSurface == NULL) {
        printf("Can't load image. SDL Error %s\n", SDL_GetError());
        success = false;
    }
    return success;
}

void close() {

    SDL_FreeSurface(imageSurface);
    imageSurface = NULL;

    SDL_DestroyWindow(window);
    window = NULL;

    SDL_Quit();
}