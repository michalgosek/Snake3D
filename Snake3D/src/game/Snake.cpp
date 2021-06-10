#include "Snake.h"

int Snake::length = 1;
SnakeBody* Snake::body = new SnakeBody[400];

void Snake::initSnakeBody() {
    body[0].SetDirection('N');
    body[0].SetXPos(10);

    for (int i = 0; i <= length; i++) {
        body[i].SetYPos(10);
        body[i].SetZPos(19);
    }
}


void Snake::SetLength(int l) {
	length = l;
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

 void Snake::Control_System()
{
	float x = body[0].GetXPos();
    float y = body[0].GetYPos();

    if (body[0].GetDirection() == 'N')
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        y += 1;
        body[0].SetYPos(y);
        body[0].SetXPos(x);
    }

    if (body[0].GetDirection() == 'S')
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        y -= 1;
        body[0].SetYPos(y);
        body[0].SetXPos(x);
    }
	
    if (body[0].GetDirection() == 'R')
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        x += 1;
        body[0].SetXPos(x);
        body[0].SetYPos(y);
    }
        
    if (body[0].GetDirection() == 'L')
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        x -= 1;
        body[0].SetXPos(x);
        body[0].SetYPos(y);
    }
        
}