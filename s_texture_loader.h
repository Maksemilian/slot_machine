#ifndef TEXTURE_H
#define TEXTURE_H

#include <vector>
#include <string>
#include <GL/gl.h>

struct Texture
{
    Texture(): _textureId(0), _w(0), _h(0) {}
    Texture(GLuint texturId, int w, int h)
        : _textureId(texturId), _w(w), _h(h)
    {

    }
    operator GLuint& ()
    {
        return _textureId;
    }
    operator GLuint* ()
    {
        return &_textureId;
    }
    friend std::ostream& operator<<(std::ostream& out, const Texture& lhs);
    GLuint _textureId;
    int _w;
    int _h;
};

std::ostream& operator<<(std::ostream& out, const Texture& lhs);

class TextureLoader
{
    static const std::string CLASS_NAME;
  public:
    static Texture loadTexture(const std::string& path);

    static std::vector<Texture> loadTextures(const std::string& dirName);
  private:
    static void bindTexture(Texture& texture, unsigned char* image);

};

#endif // TEXTURE_H
