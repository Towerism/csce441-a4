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

void Mode::update() {
  switch (mode) {
  case NORMAL:
    modalText = "NORMAL";
    break;
  case CAMERA:
    modalText = "CAMERA";
    break;
  case CAMERA_PAN:
    modalText = "CAMERA_PAN";
    break;
  case HEAD:
    modalText = "HEADS";
    break;
  case LEGS:
    modalText = "LEGS";
    break;
  case LEG1:
    modalText = "LEG1";
    break;
  case LEG2:
    modalText = "LEG2";
    break;
  case LEG3:
    modalText = "LEG3";
    break;
  case LEG4:
    modalText = "LEG4";
    break;
  case LEG5:
    modalText = "LEG5";
    break;
  case LEG6:
    modalText = "LEG6";
    break;
  case LEG1_UPPER:
    modalText = "LEG1_UPPER";
    break;
  case LEG2_UPPER:
    modalText = "LEG2_UPPER";
    break;
  case LEG3_UPPER:
    modalText = "LEG3_UPPER";
    break;
  case LEG4_UPPER:
    modalText = "LEG4_UPPER";
    break;
  case LEG5_UPPER:
    modalText = "LEG5_UPPER";
    break;
  case LEG6_UPPER:
    modalText = "LEG6_UPPER";
    break;
  case LEG1_LOWER:
    modalText = "LEG1_LOWER";
    break;
  case LEG2_LOWER:
    modalText = "LEG2_LOWER";
    break;
  case LEG3_LOWER:
    modalText = "LEG3_LOWER";
    break;
  case LEG4_LOWER:
    modalText = "LEG4_LOWER";
    break;
  case LEG5_LOWER:
    modalText = "LEG5_LOWER";
    break;
  case LEG6_LOWER:
    modalText = "LEG6_LOWER";
    break;
  }
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
