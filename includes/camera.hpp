#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>

class Camera {
  public:
    glm::mat4 viewMatrix();

    glm::vec3 *position = new glm::vec3();
    glm::vec3 *facing = new glm::vec3();
};

#endif
