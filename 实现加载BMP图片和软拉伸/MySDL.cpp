//
// Created by Shmiky__ on 20/9/2023.
//

#include "MySDL.h"

MySDL::MySDL()
{

}

MySDL::~MySDL()
{
    SDL_FreeSurface(BMP_surface);
    BMP_surface = nullptr;
    SDL_FreeSurface(MySurface);
    MySurface = nullptr;

    SDL_DestroyWindow(MyWindows);
    MyWindows = nullptr;


    delete Myevent;
    SDL_Quit();

}

bool MySDL::Init(int posX,int posY,int weight,int height)
{
    bool re_value = true;

    this->weight = weight;
    this->height = height;

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
    //初始化事件循环
    Myevent = new SDL_Event ;
    return re_value;
}

bool MySDL::load_bmp() {
    bool re_value = true;
    //加载bmp图片

    BMP_surface = SDL_LoadBMP("C:\\Users\\Shmiky__\\Desktop\\Clion\\SDL\\helloworld\\bk1.bmp");
    if (BMP_surface == nullptr)
    {
        SDL_Log("fail to SDL_loadBMP %s",SDL_GetError());
        re_value = false;
    }
    else
    {
        SDL_Log("success to SDL_LoadBMP");

    }

    return false;
}

bool MySDL::load_jpg()
{
    bool re_value = true;



    return re_value;
}

bool MySDL::Get_isStop()
{
    return isStop;
}

bool MySDL::update_surface()
{

#if 1
        SDL_Rect rect_01;
        rect_01.x = (weight - BMP_surface->w) / 2;
        rect_01.y = (height - BMP_surface->h) / 2;
//        rect_01.w = 1080;
//        rect_01.h = 800;

        SDL_BlitSurface(BMP_surface, nullptr,MySurface, &rect_01);
        SDL_UpdateWindowSurface(MyWindows);

#else
        //将表面复制到窗口所在的表面
        SDL_Rect rect_01;
        rect_01.x = 0;
        rect_01.y = 0;
        rect_01.w = 1080;
        rect_01.h = 800;


        SDL_ConvertSurface(BMP_surface,MySurface->format,0);//转换格式
        SDL_BlitScaled(BMP_surface, nullptr,MySurface, &rect_01);//缩放
        //使用表面刷新窗口
        SDL_UpdateWindowSurface(MyWindows);

#endif


    return false;
}

SDL_Event *MySDL::Get_Myevent()
{

    return Myevent;
}

void MySDL::Set_isStop(bool state)
{
    this->isStop = state;
}
