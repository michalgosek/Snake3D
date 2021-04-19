#include "Render.h"
#include "../scene/Scene.h"

GLint Render::h = 550;
GLint Render::w = 800;

void Render::resize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1, 800.0);
}

void Render::enableGLCapabilities() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1); //Change the background to sky blue

    glEnable(GL_COLOR_MATERIAL); //Enable color
    glEnable(GL_LIGHTING); //Enable lighting
    glEnable(GL_LIGHT0); //Enable light #0
    glEnable(GL_LIGHT1); //Enable light #1
    glEnable(GL_NORMALIZE); //Automatically normalize normals
}

void Render::InitGL(int argc, char **argv) {
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(w, h);
    glutInitWindowPosition(80, 80); // to cha
    glutCreateWindow("Snake Game)");

    glutDisplayFunc(Scene::Render); //singleton 
    glutReshapeFunc(Render::resize);

    enableGLCapabilities();
    glutMainLoop();
}