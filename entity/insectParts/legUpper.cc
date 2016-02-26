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
  : Entity(x, y, z), BodyPart(mode) {
  Entity* legLower = new LegLower(0, 0, 8, lowerMode);
  children.emplace_back(legLower);
  rotation.axis = { 1, 0, 0 };
}

void LegUpper::draw() {
  color();
  glutSolidCone(0.5, 9, 20, 20);
}

void LegUpper::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  rotateForMode(key, rotation);
}
