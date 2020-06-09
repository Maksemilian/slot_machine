#include "game.h"

int main(int argc, char** argv)
{
    try
    {
        Game game(argc, argv);
        game.exec();
    }
    catch (std::runtime_error& rntErr)
    {
        std::cout << "RUNTIME_ERR:" << rntErr.what() << std::endl;
    }
    catch(std::exception& exception)
    {
        std::cout << "OTHER_EXCEPTION:" << exception.what() << std::endl;
    }

}
