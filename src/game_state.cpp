#include <game_state.hpp>

#include <iostream>

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

void GameState::start() {
  worldShader = new Shader("shaders/lighting.vert", "shaders/lighting.frag");
  worldTexture = new Texture("img/dirt.jpg");

  world = new World("world.json");

  player = new Player;
  add(player);
}

void GameState::render() {
  glClearColor(0, 0, 0, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  worldTexture->use();
  worldShader->use();

  glm::mat4 view = camera.viewMatrix();
  glm::mat4 projection = camera.projectionMatrix();

  worldShader->setMatrix("view", glm::value_ptr(view));
  worldShader->setMatrix("projection", glm::value_ptr(projection));

  worldShader->setVec3("lightColor", glm::vec3(1.0, 1.0, 1.0));
  worldShader->setVec3("lightPos", glm::vec3(0, 2, 0));
  worldShader->setVec3("viewPos", *camera.position);

  for (int y = 0; y < WORLD_DEPTH; y++) {
    for (int x = 0; x < WORLD_WIDTH; x++) {
      std::shared_ptr<Chunk> chunk = world->chunks[y][x];

      glm::mat4 model;
      model = glm::translate(model, glm::vec3(0.5f, 0.5f, 0.5f));
      model = glm::translate(model, chunk->transform);

      worldShader->setMatrix("model", glm::value_ptr(model));
      chunk->mesh->draw();
    }
  }
}
