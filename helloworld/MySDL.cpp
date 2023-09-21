//
// Created by Shmiky__ on 20/9/2023.
//

#include "MySDL.h"

MySDL::MySDL()
{

}

MySDL::~MySDL()
{
    if (BMP_surface)
    {
        SDL_FreeSurface(BMP_surface);
        BMP_surface = nullptr;
        SDL_Log("删除 BMP加载表面");
    }
    if (MySurface)
    {
        SDL_FreeSurface(MySurface);
        MySurface = nullptr;
        SDL_Log("删除 表面");
    }

    if (MyWindows)
    {
        SDL_DestroyWindow(MyWindows);
        MyWindows = nullptr;
        SDL_Log("删除 窗口");
    }
    if (MyTexture)
    {
        SDL_DestroyTexture(MyTexture);
        SDL_Log("删除 纹理");
    }
    if (MyRender)
    {
        SDL_DestroyRenderer(MyRender);
        SDL_Log("删除 渲染器");
    }

    delete Myevent;
    SDL_Log("删除事件循环");
    IMG_Quit();
    SDL_Log("退出 SDL_image 子系统");
    SDL_Quit();
    SDL_Log("退出 SDL 系统");

}

bool MySDL::Init_Surface(int posX,int posY,int weight,int height)
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

    if( !( IMG_Init( IMG_INIT_JPG ) & IMG_INIT_JPG ) )
    {
        SDL_Log( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
        re_value = false;
    }
    else
    {
        SDL_Log("success to IMG_Init");
    }

    BMP_surface = IMG_Load("C:\\Users\\Shmiky__\\Desktop\\Clion\\SDL\\helloworld\\bk.jpg");
    if (BMP_surface == nullptr)
    {
        SDL_Log("fail to IMG_load %s",IMG_GetError());
        re_value = false;
    }
    else
    {
        SDL_Log("success to IMG_Load");
    }
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

bool MySDL::Init_texture(int posX,int posY,int weight,int height)
{
    bool re_value = true;
    re_value = SDL_Init(SDL_INIT_VIDEO);
    if (re_value)
    {
        SDL_Log("fail to SDL_Init %s", SDL_GetError());
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
        else
        {
            SDL_Log("success to SDL_CreateWindow");
            MyRender = SDL_CreateRenderer(MyWindows,-1,SDL_RENDERER_ACCELERATED);
            if (MyRender == nullptr)
            {
                SDL_Log("fail to SDL_CreateRenderer %s",SDL_GetError());
                re_value = false;
            }
            else
            {
                SDL_Log("success to SDL_CreateRenderer");
                SDL_SetRenderDrawColor(MyRender,128,128,128,128);
                if(!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
                {
                    SDL_Log("fail to IMG_Init %s",IMG_GetError());
                    re_value = true;
                }
            }
        }
    }
    //初始化事件循环
    Myevent = new SDL_Event ;
    return re_value;
}

bool MySDL::load_texture()
{
    bool re_value = true;

    SDL_Surface* load_surface = nullptr;
    load_surface = IMG_Load("C:\\Users\\Shmiky__\\Desktop\\Clion\\SDL\\helloworld\\bk.jpg");
    if (load_surface == nullptr)
    {
        SDL_Log("fail to IMG_Load %s",IMG_GetError());
    }
    else
    {
        SDL_Log("success to IMG_Load");
    }

    MyTexture = SDL_CreateTextureFromSurface(MyRender,load_surface);
    if (MyTexture == nullptr)
    {
        SDL_Log("fail to SDL_CreateTextureFromSurface %s",SDL_GetError());
    }
    else
    {
        SDL_Log("success to SDL_CreateTextureFromSurface");
    }
    SDL_FreeSurface(load_surface);

    return re_value;
}

bool MySDL::update_Texture()
{
    bool re_value = true;

    SDL_RenderClear(MyRender);
    //通过矩形来控制图像输出的位置和区域
    SDL_Rect rect_01;
    rect_01.x = 0;
    rect_01.y = 0;
    rect_01.w = 800;
    rect_01.h = 480;
    SDL_RenderCopy(MyRender,MyTexture, nullptr, &rect_01);
    SDL_RenderPresent(MyRender);

    return re_value;
}
