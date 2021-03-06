//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "bodyPart.hh"
#include "delegate/entity.hh"
#include "util/vector2.hh"

class HeadPivot : public Entity, BodyPart {
public:
  HeadPivot(int x, int y, int z);

  void keyboardEvent(unsigned char key, Vector2 mousePosition) override;
};
