#include "Snake.h"
#include <vector>
#include "../graphics/Render.h"

int Snake::length = 1;

bool boollength = false;

SnakeBody* Snake::body = new SnakeBody[100];

void Snake::initSnakeBody() {

    if (Menu::returnGameLoad())
    {
        int length;
        float* xpos = Menu::returnxPosFile();
        float *ypos = Menu::returnyPosFile();
        float *zpos = Menu::returnzPosFile();
        char* direct = Menu::returnDirectionFile();

        length = Menu::returnLengthFile();

        for (int i = 0; i < length; i++)
        {
            body[i].SetDirection(*(direct+i));
            body[i].SetXPos(*(xpos+i));
            body[i].SetYPos(*(ypos+i));
            body[i].SetZPos(*(zpos+i));

        }

    }
    else
    {
        for (int i = 0; i <= 100; i++) {
            body[i].SetDirection('N');
            body[i].SetXPos(body[i].GetXPos());
            body[i].SetYPos(body[i].GetYPos());
            body[i].SetZPos(body[i].GetZPos());
        }
    }
    


}

void Snake::initNewGame() {

    for (int i = 0; i <= 100; i++) {
        body[i].SetDirection('N');
        body[i].SetXPos(0);
        body[i].SetYPos(0);
        body[i].SetZPos(8);
    }

    length = 1;


}


void Snake::updateSnake() {
    int snakeSize = GetLength();
    snakeSize++;
    length++;

    if (body[snakeSize - 2].GetDirection() == 'N') {
        body[snakeSize - 1].SetXPos(body[snakeSize - 2].GetXPos());
        body[snakeSize - 1].SetYPos(body[snakeSize - 2].GetYPos() - 1);
        body[snakeSize - 1].SetZPos(body[snakeSize - 2].GetZPos());
        body[snakeSize - 1].SetDirection(body[snakeSize - 2].GetDirection());
    }
    else if (body[snakeSize - 2].GetDirection() == 'S') {
        body[snakeSize - 1].SetXPos(body[snakeSize - 2].GetXPos());
        body[snakeSize - 1].SetYPos(body[snakeSize - 2].GetYPos() + 1);
        body[snakeSize - 1].SetZPos(body[snakeSize - 2].GetZPos());
        body[snakeSize - 1].SetDirection(body[snakeSize - 2].GetDirection());
    }
    else if (body[snakeSize - 2].GetDirection() == 'L') {
        body[snakeSize - 1].SetXPos(body[snakeSize - 2].GetXPos() + 1);
        body[snakeSize - 1].SetYPos(body[snakeSize - 2].GetYPos());
        body[snakeSize - 1].SetZPos(body[snakeSize - 2].GetZPos());
        body[snakeSize - 1].SetDirection(body[snakeSize - 2].GetDirection());
    }
    else if (body[snakeSize - 2].GetDirection() == 'R') {
        body[snakeSize - 1].SetXPos(body[snakeSize - 2].GetXPos() - 1);
        body[snakeSize - 1].SetYPos(body[snakeSize - 2].GetYPos());
        body[snakeSize - 1].SetZPos(body[snakeSize - 2].GetZPos());
        body[snakeSize - 1].SetDirection(body[snakeSize - 2].GetDirection());
    }

}
void Snake::SetLength() {
    
    if (!boollength)
    {
        if (Menu::returnGameLoad())
        {
            length = Menu::returnLengthFile();
        }

        else
        {
            length = 1;
        }

        boollength = true;
    }
    

    if (length == 100) {
        Menu::gameStart = false;
    }
}

bool Snake::checkIntersectionWithSelf()
{
    for (int i = 1; i < length; i++) {
        if (body[i].GetXPos() == body[0].GetXPos() &&
            body[i].GetYPos() == body[0].GetYPos() &&
            body[i].GetZPos() == body[0].GetZPos()) {
            return true;
        }
    }
    return false;
}

int Snake::GetLength() {
    return length;
}

SnakeBody Snake::GetBodyPart(int index) {
    return body[index];
}


void Snake::specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        if (body[0].GetDirection() != 'R')
        {
            body[0].SetDirection('L');
        }
        break;
    case GLUT_KEY_RIGHT:
        if (body[0].GetDirection() != 'L')
        {
            body[0].SetDirection('R');
        }
        break;
    case GLUT_KEY_UP:
        if (body[0].GetDirection() != 'S')
        {
            body[0].SetDirection('N');
        }
        break;
    case GLUT_KEY_DOWN:
        if (body[0].GetDirection() != 'N')
        {
            body[0].SetDirection('S');
        }
        break;
    }
}

void Snake::checkKeyNotification() {
    std::vector <char> tab;

    for (int i = 0; i <= length; i++) {
        tab.push_back(body[i].GetDirection());
    }
    for (int j = 1; j <= length; j++) {
        body[j].SetDirection(tab[j - 1]);
    }
}
void Snake::Control_System()
{
    for (int i = 0; i <= length; i++) {
        float x = body[i].GetXPos();
        float y = body[i].GetYPos();


        if (body[i].GetDirection() == 'N')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200 / length));
            if (i == 0) {
                Render::changeAngleX(2);
                Render::changeYPoints(0.2);
            }
            y += 1;
            body[i].SetYPos(y);
        }

        if (body[i].GetDirection() == 'S')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200 / length));

            if (i == 0) {
                Render::changeAngleX(-2);
                Render::changeYPoints(-0.2);
            }
            y -= 1;
            body[i].SetYPos(y);
        }

        if (body[i].GetDirection() == 'R')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200 / length));
            if (i == 0) {
                Render::changeAngleY(-2);
                Render::changeXPoints(0.2);
            }
            x += 1;
            body[i].SetXPos(x);
        }

        if (body[i].GetDirection() == 'L')
        {
            std::this_thread::sleep_for(std::chrono::milliseconds(200 / length));
            if (i == 0) {
                Render::changeAngleY(2);
                Render::changeXPoints(-0.2);
            }

            x -= 1;
            body[i].SetXPos(x);
        }
    }
}