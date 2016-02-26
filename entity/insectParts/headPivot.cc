//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "headPivot.hh"

#include <GL/glut.h>

#include "entity/mode.hh"
#include "head.hh"

HeadPivot::HeadPivot(int x, int y, int z)
  :  Entity(x, y, z), BodyPart(Mode::HEAD) {
  Entity* head = new Head(6, 0, 0);
  children.emplace_back(head);
  rotation.axis = { 0, 1, 0 };
}

void HeadPivot::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  rotateForMode(key, rotation);
}
