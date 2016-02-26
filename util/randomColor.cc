#include "randomColor.hh"

#include <random>

namespace RandomColor {

std::default_random_engine generator;
std::uniform_real_distribution<float> distribution(0.0, 1.0);

ColorSetter nextColor() {
  return ColorSetter(distribution(generator),
                     distribution(generator),
                     distribution(generator));
}

}
