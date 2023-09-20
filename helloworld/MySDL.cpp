//
// Created by Shmiky__ on 20/9/2023.
//

#include "MySDL.h"

MySDL::MySDL() {

}

MySDL::~MySDL() {

}

bool MySDL::Init() {
    bool re_value = true;


    //初始化SDL 视频子系统
    re_value = SDL_Init(SDL_INIT_VIDEO);
    if (re_value)
    {
        SDL_Log("fail to SDL_Init %s",SDL_GetError());
    }
    else
    {
        SDL_Log("success to SDL_Init");
    }


    //
    return re_value;
}
