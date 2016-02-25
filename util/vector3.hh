//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#pragma once

struct Vector3 {
  int x, y, z;
};

inline Vector3 operator-(Vector3 vector3) {
  return { -vector3.x, -vector3.y, -vector3.z };
}

inline bool operator==(Vector3 lhs, Vector3 rhs) {
  return lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z;
}

inline Vector3 operator+(Vector3 lhs, Vector3 rhs) {
  return { lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z };
}

inline void operator+=(Vector3& lhs, Vector3 rhs) {
  lhs.x += rhs.x;
  lhs.y += rhs.y;
  lhs.z += rhs.z;
}

inline Vector3 operator-(Vector3 lhs, Vector3 rhs) {
  return lhs + (-rhs);
}

inline void operator -=(Vector3& lhs, Vector3 rhs) {
  lhs += -rhs;
}
