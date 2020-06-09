#include "s_texture_loader.h"

#include <SOIL/SOIL.h>
#include <iostream>
#include <boost/filesystem.hpp>

const std::string TextureLoader::CLASS_NAME = std::string("Class:") +
        typeid (TextureLoader).name();

std::ostream& operator<<(std::ostream& out, const Texture& lhs)
{
    out << "(TexId:" << lhs._textureId << " w:" << lhs._w << " h:" << lhs._h << " )";
    return out;
}

void TextureLoader::bindTexture(Texture& texture, unsigned char* image)
{
    glBindTexture(GL_TEXTURE_2D, texture._textureId);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA,
                 texture._w,
                 texture._h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
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
        bindTexture(texture, image);
        SOIL_free_image_data(image);
    }
    else
    {
        throw std::runtime_error(CLASS_NAME +
                                 " Texture " + path + " isn't loaded");
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

            const std::string fileName = (*it).path().string();
            unsigned char* image = SOIL_load_image(fileName.data(),
                                                   &texture._w,
                                                   &texture._h,
                                                   nullptr,
                                                   SOIL_LOAD_RGB);
            if(image)
            {
                glBindTexture(GL_TEXTURE_2D, texture);

                bindTexture(texture, image);
                SOIL_free_image_data(image);

                loadedTextures.push_back(texture);
            }
            else
            {
                throw std::runtime_error(CLASS_NAME +
                                         " Texture" + fileName + " isn't loaded");
            }
        };
    }

    return loadedTextures;
}
