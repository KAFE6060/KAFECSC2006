#include "pyramid.h"
#include "Renderer3D.h"
#include <iostream>
#include <vector>
#include <SDL.h>


std::vector<Point3D> points{
    Point3D{ (-10.0f / 3) * 20,  (10.0f / 3) * 20, (-10.0f / 3) * 20 }, // Base point 1, further adjusted
    Point3D{ (10.0f / 3) * 20,   (10.0f / 3) * 20, (-10.0f / 3) * 20 }, // Base point 2, further adjusted
    Point3D{ (-10.0f / 3) * 20,  (10.0f / 3) * 20, (10.0f / 3) * 20  }, // Base point 3, further adjusted
    Point3D{ (10.0f / 3) * 20,   (10.0f / 3) * 20, (10.0f / 3) * 20  }, // Base point 4, further adjusted
    Point3D{ 0,                  (-10.0f / 3) * 20, 0                 }  // Apex point, further adjusted
};


std::vector<Edge> edges{
         Edge{ 0, 1 },
         Edge{ 1, 3 },
         Edge{ 3, 2 },
         Edge{ 2, 0 },
         Edge{ 0, 4 },
         Edge{ 1, 4 },
         Edge{ 2, 4 },
         Edge{ 3, 4 },

};



int main(int argc, char* argv[])
{
    
    SDL_Window* window;
    SDL_Renderer* renderer;

    
    window = SDL_CreateWindow("Pyramid Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 960, 540, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool running = true;

    
    Renderer3D render3D(window, renderer, points, edges);

    while (running)
    {
        
        if (SDL_QuitRequested()) { running = false; break; }

        
        render3D.render();
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL initialization failed. SDL Error: " << SDL_GetError();
    }
    else
    {
        std::cout << "SDL initialization succeeded!";
    }

    std::cin.get();
    return 0;


    return 0;
}