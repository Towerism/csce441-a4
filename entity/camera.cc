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

Camera::Camera(int x, int y, int z) : Entity(x, y, z) {
  rotation.axis = { 0, 1, 0 };
}

void Camera::look() {
  gluLookAt(0,
            0,
            0,

            0,
            0,
            -1.0,

            0.0,
            1.0,
            0.0);
}

void Camera::mouseEvent(int button, int status, Vector2 mousePosition) {
  if (button == GLUT_LEFT_BUTTON) {
    if (status == GLUT_DOWN)
      prevMouseX = mousePosition.x;
  }
}

void Camera::motionEvent(int x, int y) {
  rotation.angle += (float)(x - prevMouseX) * 0.2;
  prevMouseX = x;
}

void Camera::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  int delta = 1;

  if (Mode::getInstance()->getMode() != Mode::CAMERA_PAN)
    return;

  switch(key) {
  case 'w':
    position.z -= delta;
    break;
  case 'a':
    position.x -= delta;
    break;
  case 's':
    position.z += delta;
    break;
  case 'd':
    position.x += delta;
    break;
  }
}
