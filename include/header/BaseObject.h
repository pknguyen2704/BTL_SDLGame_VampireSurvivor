#ifndef BASE_OBJECT_H_
#define BASE_OBJECT_H_

#include "CommonFunc.h"

class BaseObject
{
public:
    BaseObject();
    ~BaseObject();
    void SetRect(const int& x, const int& y) {objectRect.x = x; objectRect.y = y;}
    SDL_Rect GetRect() const {return objectRect;}
    SDL_Texture* GetObject() const {return pObject;}
    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
    void Free();
protected:
    SDL_Texture* pObject = NULL;
    SDL_Rect objectRect;
};

#endif