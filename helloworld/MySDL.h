//
// Created by Shmiky__ on 20/9/2023.
//

#ifndef HELLO_WORLD_MYSDL_H
#define HELLO_WORLD_MYSDL_H


#include "SDL.h"
#include "SDL_image.h"
#include "iostream"
using namespace std;

class MySDL {

public:
    MySDL();
    ~MySDL();
public:
    bool Init_Surface(int posX,int posY,int weight,int height);//初始化SDL视频子系统，创建窗口，获取表面
    bool Init_texture(int posX,int posY,int weight,int height);//创建窗口，初始化渲染器，创建纹理
    bool load_bmp();//加载bmp图像到表面，SDL默认支持bmp
    bool load_jpg();//加载jpg图像
    bool load_texture();//加载纹理
    bool update_surface();//将图像复制到窗口表面，并刷新窗口表面
    bool update_Texture();//将图像复制到纹理，并刷新窗口



public:
    void Set_isStop(bool state);
    bool Get_isStop();
    SDL_Event* Get_Myevent();



private:
    SDL_Window* MyWindows = nullptr;//视频子系统窗口
    SDL_Surface* MySurface = nullptr;//视频子系统窗口的表面
    SDL_Surface* BMP_surface = nullptr;//加载bmp的表面

    SDL_Renderer* MyRender = nullptr;//渲染器
    SDL_Texture* MyTexture = nullptr;//纹理

    bool isStop = false;//是否结束SDL
    SDL_Event* Myevent;

    int weight;
    int height;
    int Texture_weight;
    int Texture_height;


};


#endif //HELLO_WORLD_MYSDL_H