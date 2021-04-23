#include "Menu.h"
#include "../graphics/Render.h"

bool Menu::gameStart = false; 

void Menu::DisplayFunc() {
    return gameStart ? Render::DrawGameBoard() : drawMenu();
}

void Menu::drawMenu()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.5, 0.0);
    glVertex3f(0.4, 0.15, 0.0);
    glVertex3f(-0.4, 0.15, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(-0.4, -0.5, 0.0);
    glVertex3f(0.4, -0.5, 0.0);
    glVertex3f(0.4, -0.15, 0.0);
    glVertex3f(-0.4, -0.15, 0.0);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINES);
    glVertex3f(-0.6, 0.8, 0.0);
    glVertex3f(-0.6, -0.7, 0.0);
    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(0.6, -0.7, 0.0);
    glVertex3f(-0.6, 0.8, 0.0);
    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(-0.6, -0.7, 0.0);
    glVertex3f(0.6, -0.7, 0.0);
    glEnd();

    glRasterPos2f(-0.18, 0.6);
    char string[10] = "MAIN MENU";

    int len = (int)strlen(string);
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }

    char string2[13] = "N - NEW GAME";
    glRasterPos2f(-0.23, 0.32);
    len = (int)strlen(string2);
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string2[i]);
    }

    char string3[13] = "ESC - EXIT";
    glRasterPos2f(-0.16, -0.33);
    len = (int)strlen(string3);
    for (int i = 0; i < len; i++){
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string3[i]);
    }

    glFlush();
    glutSwapBuffers();
}

void Menu::Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;

    case 'N':
    case 'n':
        gameStart = true; 
        DisplayFunc();
        break;
    }
}