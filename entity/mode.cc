//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "mode.hh"

#include <GL/glut.h>

#include "util/text.hh"

Mode* Mode::instance = nullptr;

static inline std::string stringFromMode(Mode::mode_t mode) {
  static const std::string strings[] = {
    "NORMAL", "CAMERA", "CAMERA_PAN", "HEAD", "LEGS", "LEG1", "LEG2", "LEG3", "LEG4",
    "LEG5", "LEG6", "LEG1_UPPER", "LEG1_LOWER", "LEG2_UPPER", "LEG2_LOWER",
    "LEG3_UPPER", "LEG3_LOWER", "LEG4_UPPER", "LEG4_LOWER", "LEG5_UPPER",
    "LEG5_LOWER", "LEG6_UPPER", "LEG6_LOWER" };

  return strings[mode];
}

void Mode::update() {
  modalText = stringFromMode(mode);
  modeIndicator = modeLabel + modalText;
}

void Mode::draw() {
  Text::display(-1, 0.9, modeIndicator);
}

void Mode::keyboardEvent(unsigned char key, Vector2 mousePosition) {
  if (mode == NORMAL) {
    if (key == 'c')
      mode = CAMERA;
    if (key == 'h')
      mode = HEAD;
    if (key == 'l')
      mode = LEGS;
  } 

  if (mode == CAMERA) {
    if (key == 'p') {
      mode = CAMERA_PAN;
    }
  }

  if (mode == LEGS) {
    if (key == '1')
      mode = LEG1;
    if (key == '2')
      mode = LEG2;
    if (key == '3')
      mode = LEG3;
    if (key == '4')
      mode = LEG4;
    if (key == '5')
      mode = LEG5;
    if (key == '6')
      mode = LEG6;
  }

  if (mode == LEG1) {
    if (key == 'u')
      mode = LEG1_UPPER;
    if (key == 'l')
      mode = LEG1_LOWER;
  }

  if (mode == LEG2) {
    if (key == 'u')
      mode = LEG2_UPPER;
    if (key == 'l')
      mode = LEG2_LOWER;
  }

  if (mode == LEG3) {
    if (key == 'u')
      mode = LEG3_UPPER;
    if (key == 'l')
      mode = LEG3_LOWER;
  }

  if (mode == LEG4) {
    if (key == 'u')
      mode = LEG4_UPPER;
    if (key == 'l')
      mode = LEG4_LOWER;
  }

  if (mode == LEG5) {
    if (key == 'u')
      mode = LEG5_UPPER;
    if (key == 'l')
      mode = LEG5_LOWER;
  }

  if (mode == LEG6) {
    if (key == 'u')
      mode = LEG6_UPPER;
    if (key == 'l')
      mode = LEG6_LOWER;
  }

  if (key == '=')
    mode = NORMAL;
}
