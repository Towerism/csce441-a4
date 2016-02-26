//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "body.hh"

#include <GL/glut.h>

#include "head.hh"

Body::Body(int x, int y, int z) : Entity(x, y, z) {
  Entity* head = new Head(0, 6, 0);
  children.emplace_back(head);
  rotation.axis = {1, 0, 0};
}

void Body::update() {
  rotation.angle += 1;
}

void Body::draw() {
  glColor3f(1.0, 1.0, 1.0);
  glutSolidSphere(5, 50, 50);
}

void Body::keyboardEvent(unsigned char key, Vector2 mousePosition) {
}
