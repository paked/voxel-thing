#include <tooltip_renderer.hpp>

#include <iostream>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

TooltipRenderer::TooltipRenderer() {
  std::vector<float> quad = {
    0.5f,  0.5f, -0.5f, // top right
    0.5f, -0.5f, -0.5f, // bottom right
    -0.5f,  0.5f, -0.5f, // top left

    0.5f, -0.5f, -0.5f, // bottom right
    -0.5f, -0.5f, -0.5f, // bottom left
    -0.5f,  0.5f, -0.5f // top left
  };

  shader = new Shader("shaders/tooltip.vert", "shaders/tooltip.frag");
  mesh = new Mesh(quad, { VEC3_VERTEX_ATTRIB });
  mesh->bind();
}

void TooltipRenderer::render(Camera *camera, Config *config) {
  shader->use();

  glm::mat4 view = camera->viewMatrix();
  glm::mat4 projection = camera->projectionMatrix();

  shader->setMatrix("view", glm::value_ptr(view));
  shader->setMatrix("projection", glm::value_ptr(projection));

  for (int i = 0; i < tooltips.size(); i++) {
    Tooltip *t = tooltips[i];

    if (!t->shouldRender) continue;

    glm::vec3 rotateAround;
    float rotateBy;

    rotationForSide(t->side, &rotateAround, &rotateBy);

    shader->setVec3("color", t->color);

    glm::mat4 model;
    model = glm::translate(model, t->position);
    model = glm::rotate(model, glm::radians(rotateBy), rotateAround);
    model = glm::translate(model, glm::vec3(0, 0, -0.01));

    shader->setMatrix("model", glm::value_ptr(model));

    mesh->draw();
  }

  glm::vec3 rotateAround;
  glm::vec3 normal;
  float rotateBy;
}

void TooltipRenderer::add(Tooltip *t) {
  tooltips.push_back(t);
}

void TooltipRenderer::rotationForSide(BlockSide side, glm::vec3 *axis, float *degrees) {
  switch(side) {
    case FRONT:
      *axis = glm::vec3(0.0f, 1.0f, 0.0f);
      *degrees = 0.0f;

      break;
    case BACK:
      *axis = glm::vec3(0.0f, 1.0f, 0.0f);
      *degrees = 180.0f;

      break;
    case LEFT:
      *axis = glm::vec3(0.0f, 1.0f, 0.0f);
      *degrees = 270.0f;

      break;
    case RIGHT:
      *axis = glm::vec3(0.0f, 1.0f, 0.0f);
      *degrees = 90.0f;

      break;
    case TOP:
      *axis = glm::vec3(1.0f, 0.0f, 0.0f);
      *degrees = 90.0f;

      break;
    case BOTTOM:
      *axis = glm::vec3(1.0f, 0.0f, 0.0f);
      *degrees = 270.0f;

      break;
    default:
      throw std::runtime_error("invalid side");
  }
}
