#include "MySDL.h"


//要写参数
int main(int argc, char *argv[])
{
    auto* mySdl = new MySDL();
    mySdl->Init(50,SDL_WINDOWPOS_CENTERED,1080,800);
    mySdl->load_bmp();


    while(!mySdl->Get_isStop())
    {
        while(SDL_PollEvent(mySdl->Get_Myevent()) != 0)
        {
            if(mySdl->Get_Myevent()->type == SDL_KEYDOWN)
            {
                mySdl->Set_isStop(true);
            }
        }
       mySdl->update_surface();

    };

    SDL_Log("玩完了");


    delete mySdl;

    return 0;

}