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
  drawEntities();
}

void EventDelegator::drawEntities() {
  for (auto& entity : entities)
    drawEntity(entity);
}

void EventDelegator::drawEntity(std::unique_ptr<Entity>& entity) {
  glPushMatrix();
  Transform3D::translate(entity->getPosition());
  Transform3D::rotate(entity->getSpin(), entity->getOrigin());
  entity->draw();
  glPopMatrix();
}

void EventDelegator::idle() {
  for (auto& entity : entities)
    entity->update();
}

void EventDelegator::mouse(int button, int status, Vector2 mousePosition) {
  for (auto& entity : entities)
    entity->mouseEvent(button, status, mousePosition);
}

void EventDelegator::keyboard(unsigned char key, Vector2 mousePosition) {
  for (auto& entity : entities)
    entity->keyboardEvent(key, mousePosition);
}
