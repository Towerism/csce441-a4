//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "head.hh"

#include <GL/glut.h>

Head::Head(int x, int y, int z) : Entity(x, y, z) {
}

void Head::update() {
}

void Head::draw() {
  glColor3f(1.0, 1.0, 1.0);
  glutSolidSphere(2, 50, 50);
}

void Head::keyboardEvent(unsigned char key, Vector2 mousePosition) {
}
