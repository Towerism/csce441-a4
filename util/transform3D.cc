#include "transform3D.hh"

namespace Transform3D {

void translate(Vector3 translation) {
  glTranslatef(translation.x, translation.y, translation.z);
}

void rotate(float spin, Vector3 origin) {
  translate(-origin);
  glRotatef(spin, 0, 0, 1);
  translate(origin);
}

}
