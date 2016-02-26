//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

#include <GL/glut.h>

#include <memory>
#include <vector>

#include "util/rotation.hh"
#include "util/vector2.hh"
#include "util/vector3.hh"

// Base class for receiving messages from
// opengl callbacks
class Entity {
public:
  Entity(int x = 0, int y = 0, int z = 0)
    : position({x, y, z}), origin({0, 0, 0}), rotations(1, {0.0, {0, 0, 0}}) { }

  // Handle idle event
  virtual void update() {}

  // Handle drawing event
  virtual void draw() {}

  // Handle keyboard event
  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) {}

  // Handle mouse event
  virtual void mouseEvent(int button, int state, Vector2 mousePosition);

  virtual void leftMouse() {}

  virtual void middleMouse() {}

  virtual void rightMouse() {}

  void setOrigin(Vector3 newOrigin) { origin = newOrigin; }

  const Vector3& getPosition() const { return position; }
  const Vector3& getOrigin() const { return origin; }
  const auto& getRotations() const { return rotations; }
  const Rotation& getRotation() const { return rotation; }

  void rotate(float angle, Vector3 axis) { rotations.push_back({ angle, axis }); }

  std::vector<std::unique_ptr<Entity>>& getChildren() { return children; }

  virtual ~Entity() = default;

protected:
  Vector3 position, origin;
  Rotation rotation;
  std::vector<Rotation> rotations;

  std::vector<std::unique_ptr<Entity>> children;

  // last* variables indicate what state the mouse was in
  // for the most recently captured mouse event
  int lastMouseX, lastMouseY, lastMouseState;

  void saveMouseState(int state, Vector2 mousePosition);
};
