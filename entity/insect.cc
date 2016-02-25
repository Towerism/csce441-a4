//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "insect.hh"

#include <GL/glut.h>

void Insect::update() {
  
}

void Insect::draw() {
  glColor3f(1.0, 1.0, 1.0);
  glutSolidSphere(5, 50, 50);
}

void Insect::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  
}
