#include "mode.hh"

Mode* Mode::instance = nullptr;

void Mode::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  if (mode == NORMAL) {
    if (key == 'c')
      mode = CAMERA;
    if (key == 'h')
      mode = HEAD;
    if (key == 'l')
      mode = LEGS;
  } 

  if (mode == CAMERA) {
    if (key == 'p') {
      mode = CAMERA_PAN;
    }
  }

  if (mode == LEGS) {
    if (key == '1')
      mode = LEG1;
    if (key == '2')
      mode = LEG2;
    if (key == '3')
      mode = LEG3;
    if (key == '4')
      mode = LEG4;
    if (key == '5')
      mode = LEG5;
    if (key == '6')
      mode = LEG6;
  }

  if (mode == LEG1) {
    if (key == 'u')
      mode = LEG1_UPPER;
    if (key == 'l')
      mode = LEG1_LOWER;
  }

  if (mode == LEG2) {
    if (key == 'u')
      mode = LEG2_UPPER;
    if (key == 'l')
      mode = LEG2_LOWER;
  }

  if (mode == LEG3) {
    if (key == 'u')
      mode = LEG3_UPPER;
    if (key == 'l')
      mode = LEG3_LOWER;
  }

  if (mode == LEG4) {
    if (key == 'u')
      mode = LEG4_UPPER;
    if (key == 'l')
      mode = LEG4_LOWER;
  }

  if (mode == LEG5) {
    if (key == 'u')
      mode = LEG5_UPPER;
    if (key == 'l')
      mode = LEG5_LOWER;
  }

  if (mode == LEG6) {
    if (key == 'u')
      mode = LEG6_UPPER;
    if (key == 'l')
      mode = LEG6_LOWER;
  }

  if (key == '=')
    mode = NORMAL;
}
