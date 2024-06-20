#include "GLHeader.h"
#include "Shader.h"
#include "Camera.h"
#include "RenderModeUtil.h"
#include "ImageUtil.h"
#include "MouseUtil.h"
#include "FWL.h"

#include <iostream>
#include <map>
#include <ctime>

int WIDTH = 1200;
int HEIGHT = 800;
GLfloat ASPECT;
Rect rect;

std::string VENDOR;

Shader shader;
Camera cam;
CamaraControlUtil camUtil;
RenderModeUtil renderMode;
ImageUtil imageUtil;
MouseUtil mouse;
FWL fw;

clock_t StartTime, EndTime;


GLvoid DisplayReshape(int w, int h) {
	glViewport(0, 0, w, h);
	WIDTH = w;
	HEIGHT = h;
}

GLvoid GLMain() {
	StartTime = clock();

	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	cam.CalculateASPECT();
	fw.Routine();

	glutSwapBuffers();
	glutPostRedisplay();

	EndTime = clock();
	fw.SetFrameTime(float(EndTime - StartTime) / 1000);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GL_MULTISAMPLE);

	glutInitWindowPosition(GetSystemMetrics(SM_CXSCREEN) / 2 - WIDTH / 2, GetSystemMetrics(SM_CYSCREEN) / 2 - HEIGHT / 2);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("GL2D");

	if (StartWithFullScreen)
		glutFullScreen();

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK) {
		std::cout << "Unable to initialize GLEW" << std::endl;
		exit(EXIT_FAILURE);
	}
	else
		std::cout << "GLEW Initialized" << std::endl;

	const GLubyte* VecdorInfo = glGetString(GL_VENDOR);
	if (VecdorInfo) {
		VENDOR = reinterpret_cast<const char*>(VecdorInfo);
		if (PrintVendorInfoOpt)
			std::cout << "GPU Vendor: " << VENDOR << std::endl;
	}

	glEnable(GL_MULTISAMPLE);
	glEnable(GL_ALPHA_TEST);
	glEnable(GL_BLEND);
	glEnable(GL_SMOOTH);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	shader.LoadVertexShader("GLSL//GLSL_vertex.glsl");
	shader.LoadFragmentShader("GLSL//GLSL_fragment.glsl");
	shader.CreateShader(ImageShader);

	shader.LoadVertexShader("GLSL//GLSL_vertex.glsl");
	shader.LoadFragmentShader("GLSL//GLSL_fragment_text.glsl");
	shader.CreateShader(TextShader);

	imageUtil.Init();

	glutDisplayFunc(GLMain);
	glutReshapeFunc(DisplayReshape);
	glutMainLoop();
}