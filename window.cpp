#include <SDL2/SDL.h>

int main() {
    SDL_Window* window { nullptr };
    SDL_Renderer* renderer { nullptr };
    SDL_Event event;
    bool running { true };

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer);
    // SDL_RenderSetScale(renderer, 4, 4);

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT) running = false;
        }
        
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, 640 / 2, 480 / 2);

        SDL_RenderPresent(renderer);

        // SDL_Delay(10000);
    }

    return 0;
}