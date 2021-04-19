#include "Camera.h"

//This Function will rotate the object according to the Angles

void Camera::ManipulateViewAngle() {
    glRotatef(view_rotx, 1.0, 0.0, 0.0);//Rotate Arround X axis
    glRotatef(view_roty, 0.0, 1.0, 0.0);//Rotate Arround Y axis
    glRotatef(view_rotz, 0.0, 0.0, 1.0);//Rotate Arround Z axis
}