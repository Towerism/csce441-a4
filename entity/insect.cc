//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "insect.hh"

#include "insectParts/body.hh"

#include <GL/glut.h>

Insect::Insect(int x, int y, int z) : Entity(x, y, z) {
  auto* body = new Body(0, 0, 0);
  children.emplace_back(body);
}

void Insect::update() {
}

void Insect::draw() {
}

void Insect::keyboardEvent(unsigned char key, Vector2 mousePosition) {
}
