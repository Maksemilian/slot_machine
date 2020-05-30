#include "texture.h"
#include <SOIL/SOIL.h>
#include <iostream>

#include <boost/filesystem.hpp>

//using namespace std;
namespace fs = boost::filesystem;


std::ostream &operator<<(std::ostream &out,const Texture &lhs)
{
    out<<"(TexId:"<<lhs._textureId<<" w:"<<lhs._w<<" h:"<<lhs._h<<" )";
    return out;

}

//int main()
//{
//    cout<<"WELLCOME TO EXAMPLE APPLICATION!\n";

//    fs::path p = fs::current_path();
//    std::vector<fs::path> files;
//    std::copy( fs::directory_iterator(p), fs::directory_iterator(), std::back_inserter(files) );
//    std::copy( files.begin(), files.end(), std::ostream_iterator< fs::path > (std::cout, "\n") );

//}

Texture TextureLoader::loadTexture(const std::string &path)
{
    Texture texture;
    unsigned char* image = SOIL_load_image(path.data(),
                                           &texture._w,
                                           &texture._h, nullptr,
                                           SOIL_LOAD_RGB);
    if(image){
        glGenTextures(1, &texture._textureId);
        glBindTexture(GL_TEXTURE_2D,texture._textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
//                        GL_LINEAR_MIPMAP_NEAREST);
//        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,
//                               GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                     texture._w,
                     texture._h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//TODO не работает на intel graphics 530
//        glTexImage2D(GL_TEXTURE_2D, 0, 3,
//                     texture._w,
//                     texture._h, 1, GL_RGB, GL_UNSIGNED_BYTE, image);

        std::cout<<"Load Tex:"<<texture<<" "<<texture._textureId<<path<<std::endl;
        //        std::cout<<texture<<" SOIL:"<<width<<"||"<<height<<"||"
        //                <<path<<"TEX:"<<texture<<std::endl;
        //        SOIL_free_image_data(image);
    }else  std::cout<<"Not load:"<<path<<std::endl;
    return texture;
}


std::vector<Texture> TextureLoader::loadTextures(const std::string &dirName)
{
    std::vector<Texture>loadedTextures;
        for (fs::directory_iterator it(dirName), end;
             it != end; ++it)
        {
            if (it->path().extension() == ".png") {

    //            std::cout <<"F:"<<(*it).path().string().data()<< std::endl;
                Texture texture;
                glGenTextures(1,texture);

                //            int w,h;
                unsigned char* image = SOIL_load_image((*it).path().string().data(),
                                                       &texture._w,
                                                       &texture._h,
                                                       nullptr,
                                                       SOIL_LOAD_RGB);
                if(image){
                    glBindTexture(GL_TEXTURE_2D,texture);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                    //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
                    //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
                    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                                 texture._w,
                                 texture._h, 0,
                                 GL_RGB,
                                 GL_UNSIGNED_BYTE,
                                 image);
//                    glTexImage2D(GL_TEXTURE_2D, 0, 3,
//                                 texture._w,
//                                 texture._h, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
                    loadedTextures.push_back(texture);
                    std::cout<<loadedTextures.back()<<std::endl;
                    SOIL_free_image_data(image);
                }else  std::cout<<"Not load:"<<*it<<std::endl;
            };

        }

    //    QDir dir(dirName.data());

    //    if(dir.entryList(QDir::Files).isEmpty()) return {};

    //    std::vector<GLuint> textures(dir.entryList(QDir::Files).size());
    //    glGenTextures(dir.entryList(QDir::Files).size(),
    //                  textures.data());
    //    std::vector<Texture>loadedTextures;
    //    auto it=textures.begin();
    //    for (auto name:dir.entryList(QDir::Files))
    //    {
    //        std::string path=dirName+name.toStdString();

    //        int w,h;
    //        unsigned char* image = SOIL_load_image(path.data(),
    //                                               &w,
    //                                               &h,
    //                                               nullptr,
    //                                               SOIL_LOAD_RGB);
    //        if(image){
    //            glBindTexture(GL_TEXTURE_2D,*it);
    //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //            //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    //            //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
    //            glTexImage2D(GL_TEXTURE_2D, 0, 3,
    //                         w,
    //                         h, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
    //            loadedTextures.push_back({*it,w,h});
    //            std::cout<<loadedTextures.back()<<std::endl;
    //            SOIL_free_image_data(image);
    //        }else  std::cout<<"Not load:"<<path<<std::endl;
    //        ++it;
    //    };
    return loadedTextures;
}
//********
/*
GLuint loadTexture(const std::string &path)
{
    GLuint texture=0;
    int width,height;
    unsigned char* image = SOIL_load_image(path.data(),
                                           &width, &height, nullptr,
                                           SOIL_LOAD_RGB);
    if(image){
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D,texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
        //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
        std::cout<<texture<<" SOIL:"<<width<<"||"<<height<<"||"
                <<path<<"TEX:"<<texture<<std::endl;
    }else  std::cout<<"Not load:"<<path<<std::endl;
    return texture;
}

GLuint loadTextureT(const std::string &path)
{
    GLuint texture=0;
    int width,height;
    unsigned char* image = SOIL_load_image(path.data(),
                                           &width, &height, nullptr,
                                           SOIL_LOAD_RGB);
    if(image)
    {
        glBindTexture(GL_TEXTURE_2D,texture);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
        std::cout<<"SOIL:"<<width<<"||"<<height<<"||"<<path<<"TEX:"<<texture<<std::endl;
    }else  std::cout<<"Not load:"<<path<<std::endl;
    return texture;
}


std::vector<GLuint> loadTextures(const std::string &dirName)
{
    QDir dir(dirName.data());
    if(dir.entryList(QDir::Files).isEmpty()) return {};

    std::vector<GLuint> _textures(dir.entryList(QDir::Files).size());
    glGenTextures(dir.entryList(QDir::Files).size(), _textures.data());
    auto it=_textures.begin();
    for (auto name:dir.entryList(QDir::Files))
    {
        std::string path=dirName+name.toStdString();

        int width,height;
        unsigned char* image = SOIL_load_image(path.data(),
                                               &width, &height, nullptr,
                                               SOIL_LOAD_RGB);
        if(image){
            glBindTexture(GL_TEXTURE_2D,*it);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
            //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
            glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
            std::cout<<"***SOIL:"<<width<<"||"<<height<<"||"
//                    <<path
                   <<"TEX:"<<*it<<std::endl;
        }else  std::cout<<"Not load:"<<path<<std::endl;
        ++it;
    };
    return _textures;
}
*/
//GLuint Game::loadTexture(const std::string &path)
//{
//    GLuint texture=0;
//    int width,height;
//    unsigned char* image = SOIL_load_image(path.data(),
//                                           &width, &height, nullptr,
//                                           SOIL_LOAD_RGB);
//    if(image){
//        glGenTextures(1, &texture);
//        glBindTexture(GL_TEXTURE_2D,texture);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
//        //        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);
//        glTexImage2D(GL_TEXTURE_2D, 0, 3, width, height, 1, GL_RGB, GL_UNSIGNED_BYTE, image);
//        std::cout<<texture<<" SOIL:"<<width<<"||"<<height<<"||"
//                <<path<<"TEX:"<<texture<<std::endl;
//    }else  std::cout<<"Not load:"<<path<<std::endl;
//    return texture;
//}

//std::vector<GLuint> Game::loadTextures(const std::string &dirName)
//{
//    std::vector<GLuint> _textures;
//    QDir dir(dirName.data());
//    GLuint texture;
//    for (auto name:dir.entryList(QDir::Files)) {
//        std::string path=dirName+name.toStdString();
//        if((texture=loadTexture(path))!=0){
//            _textures.push_back(texture);
//            //            std::cout<<"TT:"<<texture<<std::endl;
//        }
//    };
//    return _textures;
//}
