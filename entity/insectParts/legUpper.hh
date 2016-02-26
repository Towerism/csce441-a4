//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "delegate/entity.hh"

#include "bodyPart.hh"
#include "entity/mode.hh"
#include "util/vector2.hh"

class LegUpper : public Entity, BodyPart {
public:
  LegUpper(int x, int y, int z, Mode::mode_t mode, Mode::mode_t lower_mode);

  void draw() override;
  void keyboardEvent(unsigned char key, Vector2 mousePosition) override;
};
