//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "camera.hh"

#include <GL/glut.h>

void Camera::update() {
  
}

void Camera::draw() {
}

void Camera::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  int delta = 1;
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
