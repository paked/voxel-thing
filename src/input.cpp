#include <input.hpp>

Input::Input() {
  keys = new KeyManager();
}

void Input::update() {
  keys->update();
}

void Input::endFrame() {
  mouseMoved = false;

  deltaMouseScrollX = 0;
  deltaMouseScrollY = 0;
}

double Input::deltaMouseX() {
  if (!mouseMoved) {
    return 0;
  }

  if (!lastMouseX || !mouseX) {
    return 0;
  }

  return lastMouseX - mouseX;
}

double Input::deltaMouseY() {
  if (!mouseMoved) {
    return 0;
  }

  if (!lastMouseY || !mouseY) {
    return 0;
  }

  return lastMouseY - mouseY;
}

bool Input::mouseClicked() {
  return (!lastMousePrimaryPressed && mousePrimaryPressed);
}

Input* Input::instance() {
  if (!s_instance) {
    s_instance = new Input();
  }

  return s_instance;
}

void Input::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
  Input* input = Input::instance();

  if (action != GLFW_PRESS && action != GLFW_RELEASE) {
    return;
  }

  input->keys->set(key, action == GLFW_PRESS);
}

void Input::mouseButtonCallback(GLFWwindow *window, int button, int action, int mode) {
  Input* input = Input::instance();

  input->lastMousePrimaryPressed = input->mousePrimaryPressed;

  if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
    input->mousePrimaryPressed = true;
  } else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
    input->mousePrimaryPressed = false;
  }
}

void Input::mouseMovementCallback(GLFWwindow *window, double x, double y) {
  Input* input = Input::instance();

  input->mouseMoved = true;

  input->lastMouseX = input->mouseX;
  input->lastMouseY = input->mouseY;

  input->mouseX = x;
  input->mouseY = y;
}

void Input::mouseScrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
  Input *input = Input::instance();

  input->deltaMouseScrollX = xOffset;
  input->deltaMouseScrollY = yOffset;
}

Input* Input::s_instance;
