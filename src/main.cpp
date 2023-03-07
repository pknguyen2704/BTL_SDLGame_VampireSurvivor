#include "CommonFunc.h"
#include "BaseObject.h"

BaseObject gBackground;

bool Init();
bool LoadMedia();
void Close();

int main(int argc, char* argv[])
{
    if(Init() == false)
        return -1;
    if(LoadMedia() == false)
        return -1;

    bool isQuit = false;
    while(isQuit == false)
    {
        while(SDL_PollEvent(&gEvent) != 0)
        {
            if(gEvent.type == SDL_QUIT)
            {
                isQuit = true;
            }
        }
        SDL_RenderClear(gScreen);
        SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

        gBackground.Render(gScreen, NULL);
        SDL_RenderPresent(gScreen);
    }
    Close();
    return 0;
}

bool Init()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if(ret < 0)
        return false;
    else
    {
        // Set thong so render
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        gWindow = SDL_CreateWindow("VAMPIRE SURVIVOR v1.0", SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if(gWindow == NULL)
            success = false;
        else
        {
            gScreen = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
            if(gScreen == NULL)
                success = false;
            else
            {
                SDL_SetRenderDrawColor(gScreen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
                int imgFlag = IMG_INIT_PNG;
                if(!(IMG_Init(imgFlag) && imgFlag))
                {
                    success = false;

                }
            }
        }
    }
    return success;
}

bool LoadMedia()
{
    bool success = true;
    bool ret = gBackground.LoadImg("asset/image/background/background.png", gScreen);
    if(ret == false)
        success = false;
    return success;
}
void Close()
{
    gBackground.Free();
    SDL_DestroyRenderer(gScreen);
    gScreen = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    IMG_Quit();
    SDL_Quit();
}
