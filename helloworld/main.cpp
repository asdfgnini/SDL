#include "MySDL.h"


//要写参数
int main(int argc, char *argv[])
{
    auto* mySdl = new MySDL();

    mySdl->Init(100,SDL_WINDOWPOS_CENTERED,1080,800);

    mySdl->load_bmp();

    SDL_Delay(2000);

    delete mySdl;

    return 0;
}