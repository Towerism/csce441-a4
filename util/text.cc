//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "text.hh"

#include <GL/glut.h>

namespace Text {

void display(float rasterX, float rasterY, std::string str) {
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glLoadIdentity();
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glLoadIdentity();

  glDisable(GL_DEPTH_TEST);

  glRasterPos2f(rasterX, rasterY);
  glColor3f(1.0, 1.0, 1.0);

  for (char c : str)
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);

  glEnable(GL_DEPTH_TEST);

  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
}

}
