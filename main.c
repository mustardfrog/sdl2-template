#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

void initSDL(void);
void exitSDL(void);
void handleInput(void);
void startDrawing(void);

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 620

typedef struct {
  SDL_Window *window;
  SDL_Renderer *renderer;
} App;

static App app;
static SDL_Event event;

int main() {

  initSDL();

  int running = 1;
  while (running) {

    handleInput();

    startDrawing();
  }

  exitSDL();

  return EXIT_SUCCESS;
}

void initSDL(void) {

  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    printf("Could not initialize SDL: %s\n", SDL_GetError());
    exit(1);
  }

  app.window = SDL_CreateWindow("SHOOT THE MOFOS", SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                SCREEN_HEIGHT, SDL_RENDERER_ACCELERATED);

  app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED);
}

void exitSDL(void) {

  SDL_DestroyRenderer(app.renderer);
  SDL_DestroyWindow(app.window);
  SDL_Quit();
}

void handleInput(void) {
  while (SDL_PollEvent(&event)) {
    switch (event.type) {
    case SDL_QUIT:
      exit(0);
      break;
    case SDL_SCANCODE_F:
      exit(0);
      break;
    default:
      break;
    }
  }
}

void startDrawing(void) {
  SDL_SetRenderDrawColor(app.renderer, 111, 111, 111, 255);
  SDL_RenderClear(app.renderer);
  SDL_RenderPresent(app.renderer);
  SDL_Delay(16);
}
