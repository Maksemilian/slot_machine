#include "game.h"
//#include <QCoreApplication>
//#include <QDebug>

int main(int argc, char **argv)
{
//    QCoreApplication a(argc,argv);
    std::string s(argv[0]);
    s.erase(s.find_last_of('\\'));
    std::cout<<"APP_PATH:"<<s<<std::endl;
    int w=800;
    int h=600;
    Game game(s,w,h);
    game.exec();
//    return a.exec();
}
