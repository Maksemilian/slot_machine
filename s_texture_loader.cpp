#include "s_texture_loader.h"

#include <SOIL/SOIL.h>
#include <iostream>
#include <boost/filesystem.hpp>


std::ostream& operator<<(std::ostream& out, const Texture& lhs)
{
    out << "(TexId:" << lhs._textureId << " w:" << lhs._w << " h:" << lhs._h << " )";
    return out;
}

Texture TextureLoader::loadTexture(const std::string& path)
{
    Texture texture;
    unsigned char* image = SOIL_load_image(path.data(),
                                           &texture._w,
                                           &texture._h, nullptr,
                                           SOIL_LOAD_RGB);
    if(image)
    {
        glGenTextures(1, &texture._textureId);
        glBindTexture(GL_TEXTURE_2D, texture._textureId);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                     texture._w,
                     texture._h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

        SOIL_free_image_data(image);
    }
    else
    {
        std::cout << "Not load:" << path << std::endl;
    }
    return texture;
}


std::vector<Texture> TextureLoader::loadTextures(const std::string& dirName)
{
    namespace fs = boost::filesystem;

    std::vector<Texture>loadedTextures;
    for (fs::directory_iterator it(dirName), end;
            it != end; ++it)
    {
        if (it->path().extension() == ".png")
        {
            Texture texture;
            glGenTextures(1, texture);

            //            int w,h;
            unsigned char* image = SOIL_load_image((*it).path().string().data(),
                                                   &texture._w,
                                                   &texture._h,
                                                   nullptr,
                                                   SOIL_LOAD_RGB);
            if(image)
            {
                glBindTexture(GL_TEXTURE_2D, texture);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                             texture._w,
                             texture._h, 0,
                             GL_RGB,
                             GL_UNSIGNED_BYTE,
                             image);
                loadedTextures.push_back(texture);
                SOIL_free_image_data(image);
            }
            else
            {
                std::cout << "Not load:" << *it << std::endl;
            }
        };

    }

    return loadedTextures;
}
