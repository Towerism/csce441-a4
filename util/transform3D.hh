//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

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
