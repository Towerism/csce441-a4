//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "entity/mode.hh"
#include "util/rotation.hh"

class BodyPart {
public:
  BodyPart(Mode::mode_t mode) : mode(mode) {}

  void rotateForMode(unsigned char key, Rotation& rotation);

private:
  Mode::mode_t mode;

  const float maxAngle = 45.0;
};
