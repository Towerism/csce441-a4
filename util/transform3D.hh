#pragma once

#include <GL/glut.h>

#include "vector3.hh"
#include "rotation.hh"

namespace Transform3D {

// translate current matrix to (x, y, z)
void translate(Vector3 translation);

// rotate current matrix about (x, y, z) by spin degrees
void rotate(Rotation rotation);

}
