//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "bodyPart.hh"

void BodyPart::rotateForMode(unsigned char key, Rotation& rotation) {
  if (Mode::getInstance()->getMode() == mode) {
    if (key =='w')
      if (rotation.angle < maxAngle)
        rotation.angle += 1;
    if (key == 's')
      if (rotation.angle > -maxAngle)
        rotation.angle -= 1;
  }

}
