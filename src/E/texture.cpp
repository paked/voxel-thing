#include <E/texture.hpp>

#include <stdexcept>

#include <stb_image.h>

E::Texture::Texture(std::string fname) {
  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);

  int nChannels;
  unsigned char *data = stbi_load(fname.c_str(), &width, &height, &nChannels, 0);

  if (!data) {
    throw std::runtime_error("could not load texture");

    return;
  }


  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

  glGenerateMipmap(GL_TEXTURE_2D);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 1);

  glGenerateMipmap(GL_TEXTURE_2D);

  stbi_image_free(data);
}

void E::Texture::use(unsigned int unit) {
  glActiveTexture(unit);

  glBindTexture(GL_TEXTURE_2D, id);
}
