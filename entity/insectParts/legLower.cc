//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "legLower.hh"

#include <GL/glut.h>

LegLower::LegLower(int x, int y, int z, Mode::mode_t mode)
  : Entity(x, y, z), BodyPart(mode) {
  rotate(100, {1, 0, 0});
  rotation.axis = { 1, 0, 0 };
}

void LegLower::draw() {
  color();
  glutSolidCone(0.2, 9, 20, 20);
  glutSolidSphere(0.5, 50, 50);
}

void LegLower::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  rotateForMode(key, rotation);
}
