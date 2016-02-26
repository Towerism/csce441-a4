#include "transform3D.hh"

namespace Transform3D {

void translate(Vector3 translation) {
  glTranslatef(translation.x, translation.y, translation.z);
}

void rotate(Rotation rotation) {
  glRotatef(rotation.angle, rotation.axis.x, rotation.axis.y, rotation.axis.z);
}

}
