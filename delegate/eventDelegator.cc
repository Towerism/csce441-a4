//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "eventDelegator.hh"
#include "util/transform3D.hh"

#include <GL/glut.h>

void EventDelegator::add(Entity* entity) {
  entities.emplace_back(entity);
}

void EventDelegator::draw() {
  for (auto& entity : entities)
    draw(entity);
}

void EventDelegator::draw(std::unique_ptr<Entity>& entity) {
  glPushMatrix();
    
  Transform3D::translate(entity->getPosition());
  for (auto rotation : entity->getRotations())
    Transform3D::rotate(rotation);
  Transform3D::rotate(entity->getRotation());
  entity->draw();

  for (auto& child : entity->getChildren())
    draw(child);
  glPopMatrix();
}

void EventDelegator::idle() {
  for (auto& entity : entities)
    idle(entity);
}

void EventDelegator::idle(std::unique_ptr<Entity>& entity) {
  entity->update();
  for (auto& child : entity->getChildren())
    idle(child);
}

void EventDelegator::mouse(int button, int status, Vector2 mousePosition) {
  for (auto& entity : entities) {
    mouse(entity, button, status, mousePosition);
  }
}

void EventDelegator::mouse(std::unique_ptr<Entity>& entity, int button, int status, Vector2 mousePosition) {
  entity->mouseEvent(button, status, mousePosition);
  for (auto& child : entity->getChildren())
    mouse(child, button, status, mousePosition);
}

void EventDelegator::motion(int x, int y) {
  for (auto& entity : entities)
    motion(entity, x, y);
}

void EventDelegator::motion(std::unique_ptr<Entity>& entity, int x, int y) {
  entity->motionEvent(x, y);
  for (auto& child : entity->getChildren())
    motion(child, x, y);
}

void EventDelegator::keyboard(unsigned char key, Vector2 mousePosition) {
  for (auto& entity : entities)
    keyboard(entity, key, mousePosition);
}

void EventDelegator::keyboard(std::unique_ptr<Entity>& entity, unsigned char key, Vector2 mousePosition) {
  entity->keyboardEvent(key, mousePosition);
  for (auto& child : entity->getChildren())
    keyboard(child, key, mousePosition);
}
