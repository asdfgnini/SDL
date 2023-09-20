//
// Created by Shmiky__ on 20/9/2023.
//

#include "MySDL.h"

MySDL::MySDL() {

}

MySDL::~MySDL() {

}

bool MySDL::Init(int posX,int posY,int weight,int height)
{
    bool re_value = true;

    //初始化SDL 视频子系统
    re_value = SDL_Init(SDL_INIT_VIDEO);
    if (re_value)
    {
        SDL_Log("fail to SDL_Init %s",SDL_GetError());
        re_value = false;
    }
    else
    {
        SDL_Log("success to SDL_Init");
        MyWindows = SDL_CreateWindow("first_windows",posX,posY,weight,height,SDL_WINDOW_SHOWN);
        if (MyWindows == nullptr)
        {
            SDL_Log("fail to SDL_CreateWindow %s",SDL_GetError());
            re_value = false;
        }
        else {
            SDL_Log("success to SDL_CreateWindow");
            MySurface = SDL_GetWindowSurface(MyWindows);
            if (MySurface == nullptr)
            {
                SDL_Log("fail to SDL_GetWindowSurface %s", SDL_GetError());
                re_value = false;
            }
            else
            {
                SDL_Log("success to SDL_GetWindowSurface");
            }
        }
    }

    return re_value;
}

bool MySDL::load_bmp() {
    bool re_value = true;
    //加载bmp图片
    SDL_Surface* pSdlSurface = SDL_LoadBMP("C:\\Users\\Shmiky__\\Desktop\\Clion\\SDL\\helloworld\\bk1.bmp");
    if (pSdlSurface == nullptr)
    {
        SDL_Log("fail to SDL_loadBMP %s",SDL_GetError());
        re_value = false;
    }
    else
    {
        SDL_Log("success to SDL_LoadBMP");
        //将表面复制到窗口所在的表面
        SDL_BlitSurface(pSdlSurface, nullptr,MySurface, nullptr);
        //使用表面刷新窗口
        SDL_UpdateWindowSurface(MyWindows);
    }

    return false;
}
