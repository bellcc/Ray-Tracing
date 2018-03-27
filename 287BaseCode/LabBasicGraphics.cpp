#include <ctime>
#include <vector>
#include "defs.h"
#include "Utilities.h"
#include "FrameBuffer.h"
#include "ColorAndMaterials.h"
#include "Rasterization.h"

FrameBuffer frameBuffer(WINDOW_WIDTH, WINDOW_HEIGHT);

void closed5x5Square(int x, int y, color C) {
	drawLine(frameBuffer, x, y, x+10, y+10, C);
}

void closed5x5Square(const glm::vec2 &centerPt, color C) {
	drawLine(frameBuffer, centerPt.x, centerPt.y, centerPt.x + 10, centerPt.y + 10, C);
}

void open5x5Square(const glm::vec2 &centerPt, color C) {
	drawLine(frameBuffer, centerPt.x, centerPt.y, centerPt.x + 10, centerPt.y + 10, C);
}

void pieChart(const glm::vec2 &centerPt, float rad, float perc, const color &C1, const color &C2) {
	drawArc(frameBuffer, centerPt, rad, 0, M_PI, C1);
}

void render() {
	frameBuffer.clearColorAndDepthBuffers();
	closed5x5Square(50, 50, red);
	closed5x5Square(glm::vec2(100, 50), green);
	open5x5Square(glm::vec2(150, 50), blue);
	pieChart(glm::vec2(250, 100), 50, 0.25, red, green);
	frameBuffer.showColorBuffer();
}

void resize(int width, int height) {
	frameBuffer.setFrameBufferSize(width, height);
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case ESCAPE:	glutLeaveMainLoop();
					break;
	}
}

int main(int argc, char *argv[]) {
	/*
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	GLuint world_Window = glutCreateWindow(__FILE__);
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_GLUTMAINLOOP_RETURNS);

	glutDisplayFunc(render);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyboard);

	frameBuffer.setClearColor(black);

	glutMainLoop();
	
	*/
	std::cout << directionInDegrees(2, 10, 3, 11) << std::endl;
	std::cout << directionInDegrees(3, 11, 2, 10) << std::endl;
	std::cout << directionInDegrees(0, 0, 10, 10) << std::endl;
	std::cout << directionInDegrees(2, 2, 2, 0) << std::endl;

	std::cout << directionInDegrees(glm::vec2(2, 10), glm::vec2(3, 11)) << std::endl;

	std::cout << directionInDegrees(glm::vec2(1, 0)) << std::endl;
	std::cout << directionInDegrees(glm::vec2(1, 1)) << std::endl;

	return 0;
}
