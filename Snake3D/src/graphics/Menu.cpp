#include "Menu.h"
#include "../graphics/Render.h"


#include <iostream>       
//#include <thread>         
//#include <chrono> 

bool Menu::gameStart = false; 
bool Menu::gameBreak = false; 


void Menu::DisplayFunc() {
    if (gameStart && !gameBreak)
        Render::DrawGameBoard();
    else if (!gameStart && !gameBreak)
        drawMenu();
    else if (gameStart && gameBreak)
        drawQuitMenu();
    else if (!gameStart && gameBreak)
        drawQuitMenu();

    glutPostRedisplay();
}

void Menu::drawMenu()
{
    //rectangles
    float leftx_r, rightx_r;

    //first rectangle
    float topy_f, bottomy_f;

    //second rectangle
    float topy_s, bottomy_s;

    //third rectangle
    float topy_t, bottomy_t;

    //border
    float leftx_b, rightx_b;
    float topy_b, bottomy_b;

    float z;

    z = 0.0;

    leftx_r = -0.4;
    rightx_r = 0.4;

    topy_f = 0.55;
    bottomy_f = 0.2;

    topy_s = 0.1;
    bottomy_s = -0.25;

    topy_t = -0.35;
    bottomy_t = -0.7;

    leftx_b = -0.6;
    rightx_b = 0.6;

    topy_b = 0.8;
    bottomy_b = -0.8;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(leftx_r, topy_f, z);
    glVertex3f(rightx_r, topy_f, z);
    glVertex3f(rightx_r, bottomy_f, z);
    glVertex3f(leftx_r, bottomy_f, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(leftx_r, bottomy_s, z);
    glVertex3f(rightx_r, bottomy_s, z);
    glVertex3f(rightx_r, topy_s, z);
    glVertex3f(leftx_r, topy_s, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(leftx_r, bottomy_t, z);
    glVertex3f(rightx_r, bottomy_t, z);
    glVertex3f(rightx_r, topy_t, z);
    glVertex3f(leftx_r, topy_t, z);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINES);
    glVertex3f(leftx_b, topy_b, z);
    glVertex3f(leftx_b, bottomy_b, z);
    glVertex3f(rightx_b, topy_b, z);
    glVertex3f(rightx_b, bottomy_b, z);
    glVertex3f(leftx_b, topy_b, z);
    glVertex3f(rightx_b, topy_b, z);
    glVertex3f(leftx_b, bottomy_b, z);
    glVertex3f(rightx_b, bottomy_b, z);
    glEnd();

    glRasterPos2f(-0.24, 0.65);
    char string[10] = "MAIN MENU";

    int len = (int)strlen(string);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
    }

    char string2[13] = "N - NEW GAME";
    glRasterPos2f(-0.3, 0.35);
    len = (int)strlen(string2);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string2[i]);
    }

    char string3[13] = "ESC - EXIT";
    glRasterPos2f(-0.22, -0.1);
    len = (int)strlen(string3);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string3[i]);
    }


    glRasterPos2f(-0.3, -0.54);
    std::string tmp1 = "L - LOAD GAME";
    char const* num_char = tmp1.c_str();
    len = (int)strlen(num_char);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num_char[i]);
    }


    glFlush();
    glutSwapBuffers();
}

void Menu::drawQuitMenu()
{
    //rectangles
    float topy, bottomy;

    //first rectangle
    float leftx_f, rightx_f;
   
    //second rectangle
    float leftx_s, rightx_s;

    //border
    float leftx_b, rightx_b;
    float topy_b, bottomy_b;

    float z;

    z = 0.0;

    leftx_f = -0.8;
    rightx_f = -0.1;
    
    topy = 0.1;
    bottomy = -0.2;

    leftx_s = 0.1;
    rightx_s = 0.8;

    leftx_b = -0.9;
    rightx_b = 0.9;

    topy_b = 0.4;
    bottomy_b = -0.4;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2f(-0.56, 0.2);
    std::string tmp1 = "DO YOU WANT TO SAVE GAME?";
    char const* num_char = tmp1.c_str();
    int len = (int)strlen(num_char);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num_char[i]);
    }

    glColor3f(1.0, 0.0, 0.0);

    glBegin(GL_POLYGON);
    glVertex3f(leftx_f, topy, z);
    glVertex3f(rightx_f, topy, z);
    glVertex3f(rightx_f, bottomy, z);
    glVertex3f(leftx_f, bottomy, z);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(leftx_s, topy, z);
    glVertex3f(rightx_s, topy, z);
    glVertex3f(rightx_s, bottomy, z);
    glVertex3f(leftx_s, bottomy, z);
    glEnd();

    glColor3f(0.0, 0.0, 1.0);

    glBegin(GL_LINES);
    glVertex3f(leftx_b, topy_b, z);
    glVertex3f(leftx_b, bottomy_b, z);
    glVertex3f(rightx_b, topy_b, z);
    glVertex3f(rightx_b, bottomy_b, z);
    glVertex3f(leftx_b, topy_b, z);
    glVertex3f(rightx_b, topy_b, z);
    glVertex3f(leftx_b, bottomy_b, z);
    glVertex3f(rightx_b, bottomy_b, z);
    glEnd();

    glRasterPos2f(-0.6, -0.07);
    tmp1 = "Y - YES";
    num_char = tmp1.c_str();
    len = (int)strlen(num_char);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num_char[i]);
    }

    glRasterPos2f(0.3, -0.07);
    tmp1 = "X - NO";
    num_char = tmp1.c_str();
    len = (int)strlen(num_char);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num_char[i]);
    }

    glFlush();
    glutSwapBuffers();
}

void Menu::Keyboard(unsigned char key, int x, int y)
{
    char key2;
    switch (key)
    {
    case 27:
    {
        gameBreak = true;
       
        switch (key)
        {
            case '27':
            case 'y':
            { //funkcja do wrzucenia danych do pliku
                exit(0);
                break;
            }
            case 'X':
            case 'x':
                exit(0);
                break;
        }
        break;
    }

    case 'N':
    case 'n':
        if (!gameStart) 
            gameStart = true;
        break;
    case 'L':
    case 'l':
    {
        gameStart = true;
        Snake::load = true;
        break;
    }

    case 'Y':
    case 'y':
        if (gameBreak)
            //funkcja do ladowania danych do pliku
            exit(0);
        break;

    case 'X':
        if (gameBreak)
            exit(0);
        break;
    }
}