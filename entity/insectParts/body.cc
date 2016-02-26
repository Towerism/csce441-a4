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
#include "legUpper.hh"

Body::Body(int x, int y, int z) : Entity(x, y, z) {
  Entity* head = new Head(6, 0, 0);

  Entity* rightLeg1 = new LegUpper(2, -3, 0);
  rightLeg1->rotate(20, {0, 1, 0});
  rightLeg1->rotate(50, {1, 0, 0});
  rightLeg1->rotate(40, {0, 0, 1});

  Entity* rightLeg2 = new LegUpper(0, -3, 0);
  rightLeg2->rotate(0, {0, 1, 0});
  rightLeg2->rotate(50, {1, 0, 0});

  Entity* rightLeg3 = new LegUpper(-2, -3, 0);
  rightLeg3->rotate(-20, {0, 1, 0});
  rightLeg3->rotate(50, {1, 0, 0});
  rightLeg3->rotate(-40, {0, 0, 1});

  Entity* rightLeg4 = new LegUpper(2, 3, 0);
  rightLeg4->rotate(180, {0, 0, 1});
  rightLeg4->rotate(-20, {0, 1, 0});
  rightLeg4->rotate(50, {1, 0, 0});
  rightLeg4->rotate(-40, {0, 0, 1});

  Entity* rightLeg5 = new LegUpper(0, 3, 0);
  rightLeg5->rotate(180, {0, 0, 1});
  rightLeg5->rotate(0, {0, 1, 0});
  rightLeg5->rotate(50, {1, 0, 0});

  Entity* rightLeg6 = new LegUpper(-2, 3, 0);
  rightLeg6->rotate(180, {0, 0, 1});
  rightLeg6->rotate(20, {0, 1, 0});
  rightLeg6->rotate(50, {1, 0, 0});
  rightLeg6->rotate(40, {0, 0, 1});

  children.emplace_back(head);
  children.emplace_back(rightLeg1);
  children.emplace_back(rightLeg2);
  children.emplace_back(rightLeg3);
  children.emplace_back(rightLeg4);
  children.emplace_back(rightLeg5);
  children.emplace_back(rightLeg6);
}

void Body::update() {
}

void Body::draw() {
  glColor3f(1.0, 1.0, 1.0);
  glutSolidSphere(5, 50, 50);
}

void Body::keyboardEvent(unsigned char key, Vector2 mousePosition) {
}
