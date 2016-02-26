//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "legUpper.hh"

#include <GL/glut.h>

#include "legLower.hh"

LegUpper::LegUpper(int x, int y, int z, Mode::mode_t mode, Mode::mode_t lowerMode)
  : Entity(x, y, z), mode(mode) {
  Entity* legLower = new LegLower(0, 0, 8, lowerMode);
  children.emplace_back(legLower);
  rotation.axis = { 1, 0, 0 };
}

void LegUpper::update() {
}

void LegUpper::draw() {
  glColor3f(1.0, 0.0, 0.0);
  glutSolidCone(0.5, 9, 20, 20);
}

void LegUpper::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  if (Mode::getInstance()->getMode() == mode) {
    if (key == 'w')
      rotation.angle += 1;
    if (key == 's')
      rotation.angle -= 1;
  }
}
