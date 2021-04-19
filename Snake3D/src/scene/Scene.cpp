#include <GL/glut.h>

#include "Scene.h"
#include "Camera.h"
#include "../objects/Snake.h"


//Configure the lightning
void Scene::initLighting() {
    //Add ambient light
    GLfloat ambientColor[] = { 0.3f, 0.4f, 0.8f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);

    //Add positioned light
    GLfloat lightColor0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat lightPos0[] = { 4.0f, 0.0f, 8.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);

    //Add directed light
    GLfloat lightColor1[] = { 0.5f, 0.2f, 0.2f, 1.0f };
    //Coming from the direction (-1, 0.5, 0.5)
    GLfloat lightPos1[] = { -1.0f, 0.5f, 0.5f, 0.0f };
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
}


void Scene::renderPlane() {
    glPushMatrix();
    glColor3f(1, 0.7, 0.2);
    glTranslatef(75.0, -16.0, 75.0);
    glScalef(155, 5.0, 155);
    glutSolidCube(1);
    glPopMatrix();
}

void Scene::renderSnake() {
    const GLfloat headRotation = 90.0f; 

    Snake *s = new Snake(80, 80); 

    //Here we will draw the Head of the snake
    glPushMatrix();

    glColor3f(0, 1, 0);//green 

    glTranslatef(s->GetX(), -10.0, s->GetZ());//Give it the location according to _x & _z
    glScalef(0.5, 0.5, 0.5);

    glutSolidSphere(10, 20, 20);//Draw the head as a sphere a litle bit bigger than the body spheres
    glRotatef(headRotation, 0.0, 1.0, 0.0);
    glColor3f(0, 1, 0);//green 
    glTranslatef(0, 0.0, 6.0);
    glScalef(0.8, 1.0, 1.0);

    glutSolidCone(10, 10, 20, 20);
    glColor3f(1, 1, 1);
    glTranslatef(-4.0, 10.0, 0.0);
    glScalef(0.3, 0.3, 0.3);

    glutSolidSphere(10, 20, 20);
    glTranslatef(26.0, 0.0, 0.0);
    glutSolidSphere(10, 20, 20);
    glPopMatrix();
}
 
void Scene::Render() {
    Camera* c = new Camera(45.0f, 0.0f, 0.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    initLighting();
    glTranslatef(-80.0, 60.0, -300.0f);
   
    c->ManipulateViewAngle();
    renderPlane();
    renderSnake(); 

    // Updates the screen
    glutPostRedisplay();
    glutSwapBuffers();
}
