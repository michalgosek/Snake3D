#include "Render.h"
#include "../game/Snake.h"
#include "../game/Food.h"
#include "../game/Obstacle.h"

const int ::Render::HEIGHT = 700;
const int ::Render::WIDTH = 600;
double x_pos_food = (-6 + (rand() % 12));
double y_pos_food = (-2.5 + (rand() % 12));

const double x_pos_ob_1 = (2);
const double y_pos_ob_1 = (-2);

const double x_pos_ob_2 = (1);
const double y_pos_ob_2 = (4);

const double x_pos_ob_3 = (6);
const double y_pos_ob_3 = (6);

int points = 0;
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
	const GLfloat BG_Color[] = { 0.275f, 0.784f, 0.827f, 0.0f };
	glClearColor(BG_Color[0], BG_Color[1], BG_Color[2], BG_Color[3]);

	initializeLighting();
}

void Render::renderPlane() {
	glColor3f(0, 1.0, 0); // green color 
	glutSolidCube(15);
}

void Render::renderSnake() {
	const float SNAKE_BODY_COLOR[] = { 0.800f, 0.200f, 0.280f };
	const float SNAKE_HEAD_COLOR[] = { 1.000f, 0.190f, 0.210f };
	
	Snake::Control_System();
	glColor3fv(SNAKE_BODY_COLOR);
	for (int i = 0; i < Snake::GetLength(); i++) {
		glLoadIdentity();

		
		auto x = Snake::GetBodyPart(i).GetXPos();// -9.5f;
		auto y = Snake::GetBodyPart(i).GetYPos();// -9.5f;
		auto z = Snake::GetBodyPart(i).GetZPos();// -9.5f;

		glTranslatef(x, y, z);
		glutSolidCube(1.0);
	}
	
}

void Render::renderFood(double x_pos, double y_pos) {
	const float FOOD_COLOR[] = { 1.0f, 1.0f, 0.0f };

	Food* s = new Food(x_pos, y_pos); // todo: change to param 
	glColor3fv(FOOD_COLOR);
	for (int i = 0; i < s->GetLength(); i++) {
		glLoadIdentity();

		auto x = s->GetBodyPart().GetXPos();
		auto y = s->GetBodyPart().GetYPos();
		auto z = s->GetBodyPart().GetZPos();

		glTranslatef(x, y, z);
		glutSolidCube(1.0);
	}

	 delete s;
}

void Render::renderObstacle(double x_pos, double y_pos) {
	const float OBSTACLE_COLOR[] = { 1.0f, 0.0f, 1.0f };

	Obstacle* s = new Obstacle(x_pos, y_pos); // todo: change to param 
	glColor3fv(OBSTACLE_COLOR);
	for (int i = 0; i < s->GetLength(); i++) {
		glLoadIdentity();

		auto x = s->GetBodyPart().GetXPos();
		auto y = s->GetBodyPart().GetYPos();
		auto z = s->GetBodyPart().GetZPos();

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

void Render::addPoint() {
	points++;
}
void Render::checkInteractionSnakeWithFood() {
	if (x_pos_food + 1 > Snake::GetBodyPart(0).GetXPos() &&
		x_pos_food - 1 < Snake::GetBodyPart(0).GetXPos() &&
		y_pos_food + 1 > Snake::GetBodyPart(0).GetYPos() &&
		y_pos_food - 1 < Snake::GetBodyPart(0).GetYPos()) {
		
		srand(time(NULL));
		x_pos_food = (-6) + (rand() % 12);
		y_pos_food = (-2.5) + (rand() % 12);
		addPoint();
	}
}

void Render::checkInteractionSnakeWithObstancle() {
	if((x_pos_ob_1 + 1 > Snake::GetBodyPart(0).GetXPos() &&
		x_pos_ob_1 - 1 < Snake::GetBodyPart(0).GetXPos() &&
		y_pos_ob_1 + 1 > Snake::GetBodyPart(0).GetYPos() &&
		y_pos_ob_1 - 1 < Snake::GetBodyPart(0).GetYPos()) ||
		(x_pos_ob_2 + 1 > Snake::GetBodyPart(0).GetXPos() &&
		x_pos_ob_2 - 1 < Snake::GetBodyPart(0).GetXPos() &&
		y_pos_ob_2 + 1 > Snake::GetBodyPart(0).GetYPos() &&
		y_pos_ob_2 - 1 < Snake::GetBodyPart(0).GetYPos()) ||
		(x_pos_ob_3 + 1 > Snake::GetBodyPart(0).GetXPos() &&
		x_pos_ob_3 - 1 < Snake::GetBodyPart(0).GetXPos() &&
		y_pos_ob_3 + 1 > Snake::GetBodyPart(0).GetYPos() &&
		y_pos_ob_3 - 1 < Snake::GetBodyPart(0).GetYPos())){

		Menu::gameStart = false;
		

	}
}

void Render::renderPoints() {
	glRasterPos2f(-4, 7);

	std::string tmp = std::to_string(points);
	std::string tmp1 = "Liczba punktow: " + tmp;
	char const* num_char = tmp1.c_str();
	int len = (int)strlen(num_char);
	for (int i = 0; i < len; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, num_char[i]);
	}

}
void Render::DrawGameBoard() {
	enableGLCapabilities();
	prepareMatrixProjection();
	prepareModelView();

 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	renderPlane();
	renderSnake();

	checkInteractionSnakeWithFood();
	checkInteractionSnakeWithObstancle();
	renderFood(x_pos_food, y_pos_food);
	renderObstacle(x_pos_ob_1, y_pos_ob_1);
	renderObstacle(x_pos_ob_2, y_pos_ob_2);
	renderObstacle(x_pos_ob_3, y_pos_ob_3);
	renderPoints();
	glLoadIdentity();
	glutSwapBuffers();
}

void Render::initializeCallbacks() {
	glutKeyboardFunc(Menu::Keyboard);

	glutDisplayFunc(Menu::DisplayFunc);
	glutSpecialFunc(Snake::specialKeys); 
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
	Snake::initSnakeBody(); // todo do przeniesniea w inne miejsce..
	initializeCallbacks();
	glutMainLoop();
}
