//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "camera.hh"

#include <GL/glut.h>

#include "entity/mode.hh"

#define PI 3.14159265

Camera::Camera(int x, int y, int z) : Entity(x, y, z) {
  lookAtX = 0;
  lookAtY = 0;
  lookAtZ = -1;
  zoom = 1;
}

void Camera::look() {
  gluLookAt(position.x,
            position.y,
            position.z,

            position.x + lookAtX,
            position.y + lookAtY,
            position.z + lookAtZ,

            0.0,
            1.0,
            0.0);
}

void Camera::mouseEvent(int button, int status, Vector2 mousePosition) {
  if (button == GLUT_LEFT_BUTTON) {
    if (status == GLUT_DOWN)
      prevMouseY = mousePosition.y;
  }
}

void Camera::motionEvent(int x, int y) {
  zoom += (float)(y - prevMouseY) * 0.01;
  normalizeZoom();
  prevMouseY = y;
}

void Camera::normalizeZoom() {
  if (zoom > 2.5) {
    zoom = 2.5;
  }
  if (zoom < 0.1) {
    zoom = 0.1;
  }
}

void Camera::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  Mode::mode_t mode = Mode::getInstance()->getMode();

  if (mode == Mode::CAMERA_PAN) {
    pan(key);
  } else if (mode == Mode::CAMERA_DRIVE) {
    drive(key);
  }
}

void Camera::pan(unsigned char key) {
  switch(key) {
  case 'w':
      position.y += 1;
      break;
  case 'a':
      position.x -= 1;
      break;
  case 's':
      position.y -= 1;
      break;
  case 'd':
      position.x += 1;
      break;
  }
}

void Camera::drive(unsigned char key) {
  switch(key) {
  case 'w':
    position.z -= 1;
    break;
  case 's':
    position.z += 1;
    break;
  }
}
