//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include "delegate/eventDelegator.hh"
#include "entity/camera.hh"
#include "entity/insect.hh"
#include "util/vector2.hh"

#include <GL/glut.h>
#include <iostream>

// Captures events and delegates them to entities
EventDelegator eventDelegator;
Vector2 screenDimensions = { 800, 600 };
Entity* camera = new Camera(0, 0, 0);

void initGlut() {
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (screenDimensions.x, screenDimensions.y);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Martin Fracker - Assignment 2");
}

void initDisplay() {
  glClearColor (0.0, 0.0, 0.0, 0.0);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK); 
 
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LESS);
  glShadeModel (GL_FLAT);
}

void initEntities() {
  Entity* insect = new Insect(0, 0, -30);
  eventDelegator.add(insect);
  eventDelegator.add(camera);
}

void init(void) {
  initGlut();
  initDisplay();
  initEntities();
}

void reshape(int w, int h) {
  const float aspectRatio = (float) w / (float) h;

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(90.0, aspectRatio, 2.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

#include "util/transform3D.hh"
void draw(void) {
  Vector3 cameraPos = camera->getPosition();

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  std::cout << "Camera position: "
            << cameraPos.x << ", "
            << cameraPos.y << ", "
            << cameraPos.z << std::endl;
  glPushMatrix();
  gluLookAt(cameraPos.x,
            cameraPos.y,
            cameraPos.z,

            cameraPos.x,
            cameraPos.y,
            cameraPos.z - 1.0,

            0.0,
            -1.0,
            0.0);
  eventDelegator.draw();
  glPopMatrix();

  glutSwapBuffers();
}

void idle() {
  eventDelegator.idle();
  glutPostRedisplay();
}

void mouse(int button, int status, int x, int y) {
  eventDelegator.mouse(button, status, {x, y});
}

void keyboard(unsigned char key, int x, int y) {
  eventDelegator.keyboard(key, {x, y});
}

void attachCallbacks() {
  glutDisplayFunc(draw); 
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutKeyboardFunc(keyboard);
  glutIdleFunc(idle);
}

/* 
 *  Request double buffer mode.
 *  Register mouse input callback functions
 */
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  init();
  attachCallbacks();
  glutMainLoop();
  return 0;   /* ANSI C requires main to return int. */
}
