#pragma once

#include <GL/glut.h>

#include "util/vector3.hh"

namespace Transform3D {

// translate current matrix to (x, y, z)
void translate(Vector3 translation);

// rotate current matrix about (x, y, z) by spin degrees
void rotate(float spin, Vector3 origin);

}
