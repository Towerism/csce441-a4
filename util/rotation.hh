#pragma once

#include "util/vector3.hh"

struct Rotation {
  Rotation(float angle = 0.0, Vector3 axis = {0, 0, 0}) : angle(angle), axis(axis) {}

  float angle;
  Vector3 axis;
};
