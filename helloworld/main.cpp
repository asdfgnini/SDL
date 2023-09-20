#include "MySDL.h"


//要写参数
int main(int argc, char *argv[])
{
    MySDL* mySdl = new MySDL();

    mySdl->Init();


    delete mySdl;

    return 0;
}