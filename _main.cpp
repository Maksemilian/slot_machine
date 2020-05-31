#include "game.h"

int main(int argc, char **argv)
{
    Game game(argc,argv);
    game.exec();
//    std::string applicationDirPath(argv[0]);
//    std::replace(applicationDirPath.begin(),applicationDirPath.end(),'\\','/');

//    applicationDirPath.erase(applicationDirPath.find_last_of('/'));
//    std::cout<<"APP_PATH:"<<applicationDirPath<<std::endl;

//    int w=800;
//    int h=600;
//    Game game(applicationDirPath,w,h);
//    game.exec();

}
