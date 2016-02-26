#pragma once

#include "util/vector3.hh"

struct Rotation {
  Rotation(float angle, Vector3 axis) : angle(angle), axis(axis) {}

  float angle;
  Vector3 axis;
};
