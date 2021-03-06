//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "body.hh"

#include <GL/glut.h>

#include "entity/mode.hh"
#include "headPivot.hh"
#include "legUpper.hh"
#include "util/randomColor.hh"

Body::Body(int x, int y, int z) : Entity(x, y, z) {
  Entity* head = new HeadPivot(0, 0, 0);

  Entity* rightLeg1 = new LegUpper(2, -3, 0, Mode::LEG1_UPPER, Mode::LEG1_LOWER);
  rightLeg1->rotate(20, {0, 1, 0});
  rightLeg1->rotate(50, {1, 0, 0});
  rightLeg1->rotate(40, {0, 0, 1});

  Entity* rightLeg2 = new LegUpper(0, -3, 0, Mode::LEG2_UPPER, Mode::LEG2_LOWER);
  rightLeg2->rotate(0, {0, 1, 0});
  rightLeg2->rotate(50, {1, 0, 0});

  Entity* rightLeg3 = new LegUpper(-2, -3, 0, Mode::LEG3_UPPER, Mode::LEG3_LOWER);
  rightLeg3->rotate(-20, {0, 1, 0});
  rightLeg3->rotate(50, {1, 0, 0});
  rightLeg3->rotate(-40, {0, 0, 1});

  Entity* rightLeg4 = new LegUpper(2, 3, 0, Mode::LEG4_UPPER, Mode::LEG4_LOWER);
  rightLeg4->rotate(180, {0, 0, 1});
  rightLeg4->rotate(-20, {0, 1, 0});
  rightLeg4->rotate(50, {1, 0, 0});
  rightLeg4->rotate(-40, {0, 0, 1});

  Entity* rightLeg5 = new LegUpper(0, 3, 0, Mode::LEG5_UPPER, Mode::LEG5_LOWER);
  rightLeg5->rotate(180, {0, 0, 1});
  rightLeg5->rotate(0, {0, 1, 0});
  rightLeg5->rotate(50, {1, 0, 0});

  Entity* rightLeg6 = new LegUpper(-2, 3, 0, Mode::LEG6_UPPER, Mode::LEG6_LOWER);
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

void Body::draw() {
  color();
  glutSolidSphere(5, 50, 50);
}
