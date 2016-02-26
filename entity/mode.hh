#pragma once

#include "delegate/entity.hh"

class Mode : public Entity {
public:
  Mode() {}
  
  enum mode_t {
    NORMAL,
    CAMERA,
    LEGS,
    CAMERA_PAN,
    LEG1, LEG2, LEG3,
    LEG4, LEG5, LEG6,
    LEG1_UPPER, LEG1_LOWER,
    LEG2_UPPER, LEG2_LOWER,
    LEG3_UPPER, LEG3_LOWER,
    LEG4_UPPER, LEG4_LOWER,
    LEG5_UPPER, LEG5_LOWER,
    LEG6_UPPER, LEG6_LOWER,
    HEAD
  };

  virtual void keyboardEvent(unsigned char key, Vector2 mousePosition) override;

  mode_t getMode() const { return mode; }

  static const Mode* getInstance() { return instance; } 
  static void setInstance(Mode* mode) { instance = mode; }

private:

  static Mode* instance;

  mode_t mode;

};