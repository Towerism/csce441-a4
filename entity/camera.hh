//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include "delegate/entity.hh"

#include "util/vector2.hh"

class Camera : public Entity {
public:
  Camera(int x, int y, int z);

  void look();
  virtual void mouseEvent(int button, int status, Vector2 mousePosition) override;
  virtual void motionEvent(int x, int y) override;
  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) override;

  float getZoom() const { return zoom; }

private:
  float lookAtX, lookAtY, lookAtZ;
  int prevMouseY;
  float zoom;
  const int positive = -1;
  const int negative = 1;

  void normalizeZoom();
  void pan(unsigned char key);
  void drive(unsigned char key);
};
