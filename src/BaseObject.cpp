#include "BaseObject.h"

BaseObject::BaseObject()
{
    pObject = NULL;
    objectRect.w = 0;
    objectRect.h = 0;
    objectRect.x = 0;
    objectRect.y = 0;
}
BaseObject::~BaseObject()
{
    Free();
}
bool BaseObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadSurface = IMG_Load(path.c_str());
    if(loadSurface != NULL)
    {
        // render tach nen moi anh
        SDL_SetColorKey(loadSurface, SDL_TRUE, SDL_MapRGB(loadSurface->format, COLOR_KEY_R, COLOR_KEY_G, COLOR_KEY_B));
        newTexture = SDL_CreateTextureFromSurface(screen, loadSurface);
        if(newTexture != NULL)
        {
            objectRect.h = loadSurface->h;
            objectRect.w = loadSurface->w;
        }
        SDL_FreeSurface(loadSurface);
    }
    pObject = newTexture;
    return pObject != NULL;
}
void BaseObject::Render(SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderQuad = {objectRect.x, objectRect.y, objectRect.w, objectRect.h};
    SDL_RenderCopy(des, pObject, clip, &renderQuad);
}
void BaseObject::Free()
{
    if(pObject != NULL)
    {
        SDL_DestroyTexture(pObject);
        pObject = NULL;
        objectRect.w = 0;
        objectRect.h = 0;
        objectRect.x = 0;
        objectRect.y = 0;
    }
}