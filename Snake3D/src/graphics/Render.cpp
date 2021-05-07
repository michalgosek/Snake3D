#include "Render.h"
#include "../game/Snake.h"

const int ::Render::HEIGHT = 700;
const int ::Render::WIDTH = 600;

int ::Render::POS_X = 0;
int ::Render::POS_Y = 0;
  
void Render::reshapeFunc(int width, int height) {
	glutPositionWindow(POS_X, POS_Y);
	glutReshapeWindow(WIDTH, HEIGHT);
}

void Render::initializeLighting() {
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
 	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
}

void Render::enableGLCapabilities() {
	initializeLighting();
}

void Render::renderPlane() {
	glColor3f(0, 1.0, 0); // green color 
	glutSolidCube(15);
}

void Render::renderSnake() {
	const float SNAKE_BODY_COLOR[] = { 0.800f, 0.200f, 0.280f };
	const float SNAKE_HEAD_COLOR[] = { 1.000f, 0.190f, 0.210f };

	Snake* s = new Snake(); // todo: change to param 
	glColor3fv(SNAKE_BODY_COLOR);
	for (int i = 0; i < s->GetLength(); i++) {
		glLoadIdentity();

		auto x = s->GetBodyPart(i).GetXPos() - 9.5f;
		auto y = s->GetBodyPart(i).GetYPos() - 9.5f;
		auto z = s->GetBodyPart(i).GetZPos() - 9.5f;

		glTranslatef(x, y, z);
		glutSolidCube(1.0);
	}
	
	delete s; 
}

void Render::prepareModelView() {
	const float xAngle = 16;
	const float yAngle = 0;
	const float zAngle = 0;

	// transform objects inside the viewspace 
	glTranslatef(0.0f, 0.0f, -100.0f);
	glRotatef(xAngle, 1.0f, 0.0f, 0.0f);
	glRotatef(yAngle, 0.0f, 1.0f, 0.0f);
	glRotatef(zAngle, 0.0f, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
}

void Render::prepareMatrixProjection() {
	const float fovY = 15;
	const float aspect = 1;
	const float zNear = 1;
	const float zFar = 150;

	// render the visible viewspace 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, WIDTH, HEIGHT);
	gluPerspective(fovY, aspect, zNear, zFar);
}

void Render::DrawGameBoard() {
	const GLfloat BG_Color[] = { 0.275f, 0.784f, 0.827f, 0.0f };
	glClearColor(BG_Color[0], BG_Color[1], BG_Color[2], BG_Color[3]);

	enableGLCapabilities();
	prepareMatrixProjection();
	prepareModelView();

 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	renderPlane();
	renderSnake();
	glLoadIdentity();
	glutSwapBuffers();
}

void Render::initializeCallbacks() {
	glutDisplayFunc(Menu::DisplayFunc);
	glutKeyboardFunc(Menu::Keyboard);
	glutReshapeFunc(reshapeFunc);
}


void Render::Run(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
	 
    POS_X = (glutGet(GLUT_SCREEN_WIDTH) - WIDTH) >> 1;
	POS_Y = (glutGet(GLUT_SCREEN_HEIGHT) - HEIGHT) >> 1;

	glutInitWindowPosition(POS_X, POS_Y);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("Snake3D");
	 
	initializeCallbacks();

	glutMainLoop();
}
