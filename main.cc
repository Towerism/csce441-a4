//  Copyright 2016 Martin Fracker, Jr.
//  All Rights Reserved.
// 
//  This project is free software, released under the terms
//  of the GNU General Public License v3. Please see the
//  file LICENSE in the root directory or visit
//  www.gnu.org/licenses/gpl-3.0.en.html for license terms.

#include <GL/glut.h>
#include <iostream>

#include "delegate/eventDelegator.hh"
#include "entity/camera.hh"
#include "entity/insect.hh"
#include "entity/mode.hh"
#include "util/vector2.hh"

// Captures events and delegates them to entities
EventDelegator eventDelegator;
Vector2 screenDimensions = { 800, 600 };
Camera* camera = new Camera(0, 0, 0);
Mode* mode = new Mode();

void initGlut() {
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (screenDimensions.x, screenDimensions.y);
  glutInitWindowPosition (100, 100);
  glutCreateWindow ("Martin Fracker - Assignment 2");
}

void initDisplay() {
  glClearColor (0.0, 0.0, 0.0, 0.0);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK); 
 
  glDepthMask(GL_TRUE);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void initEntities() {
  Entity* insect = new Insect(0, 0, -30);
  eventDelegator.add(camera);
  eventDelegator.add(insect);

  Mode::setInstance(mode);
  eventDelegator.add(mode);
}

void initLighting() {
  GLfloat mat_specular[] = { 0.0f, 0.0f, 0.0f, 1.0f };
  GLfloat mat_shininess[] = { 0.0f };
  GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 0.25f };
  GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 0.25f };
  GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 0.25f };
  GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_SMOOTH);

  glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
  glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
  glEnable(GL_COLOR_MATERIAL);

  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT1, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
  glLightfv(GL_LIGHT3, GL_POSITION, light_position);

  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHT1);
  glEnable(GL_LIGHT2);
  glEnable(GL_LIGHT3);
}

void init(void) {
  initGlut();
  initDisplay();
  initEntities();
  initLighting();
}

void reshape(int w, int h) {
  const float aspectRatio = (float) w / (float) h;

  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0, aspectRatio, 2.0, 500.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

#include "util/transform3D.hh"
#include "util/randomColor.hh"
void draw(void) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  Transform3D::rotate(camera->getRotation());
  camera->look();
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

void motion(int x, int y) {
  eventDelegator.motion(x, y);
}

void keyboard(unsigned char key, int x, int y) {
  eventDelegator.keyboard(key, {x, y});
}

void attachCallbacks() {
  glutDisplayFunc(draw); 
  glutReshapeFunc(reshape); 
  glutMouseFunc(mouse);
  glutMotionFunc(motion);
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
