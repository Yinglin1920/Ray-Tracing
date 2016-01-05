#include <GLFW/glfw3.h>  
#include <gl/glut.h>
#include <stdlib.h>  
#include <stdio.h>  

#include "intersectresult.h"
#include "perspectiveCamera.h"
#include "Sphere.h"

#define WINDOW_WIDTH  600  
#define WINDOW_HEIGHT 600  

void initScene()
{
	// 启用阴影平滑  
	glShadeModel(GL_SMOOTH);
	// 黑色背景  
	glClearColor(0.0, 0.0, 0.0, 0.0);
	// 设置深度缓存  
	glClearDepth(1.0);
	// 启用深度测试  
	glEnable(GL_DEPTH_TEST);
	// 所作深度测试的类型  
	glDepthFunc(GL_LEQUAL);
	// 告诉系统对透视进行修正  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void  drawScene() {
	float colorSpan = 0.0005f;
	float color = 0.0f;
	float pixelSize = 2.0f;
	float posY = -1.0f;
	float posX = -1.0f;
	long maxDepth = 20;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	//将原点移动到左下角  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	glBegin(GL_POINTS);
	double dx = 1.0f / WINDOW_WIDTH;
	double dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);

	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		double sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			double sx = dx*x;
			float colorR = x*1.0 / WINDOW_WIDTH * 255;
			float colorB = y*1.0 / WINDOW_HEIGHT * 255;
			glColor3ub(colorR, 0, colorB);
			glVertex2f(sx, sy);
		}
	}

}
/*
void renderDepth()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	float horiz = 0.0;
	float dep = 10;
	perspectiveCamera camera(gvector3(horiz, 10, dep), gvector3(0, 0, -1), gvector3(0, 1, 0), 90);
	long maxDepth = 18;
	CSphere* sphere1 = new CSphere(gvector3(0, 10, -10), 10.0);
	float dx = 1.0f / WINDOW_WIDTH;
	float dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);
	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		float sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			float sx = dx*x;
			CRay ray(camera.generateRay(sx, sy));
			IntersectResult result = sphere1->isIntersected(ray);
			if (result.isHit)
			{
				double t = MIN(result.distance*dD, 255.0f);
				int depth = (int)(255 - t);
				glColor3ub(depth, depth, depth);
				glVertex2f(sx, sy);
			}

		}
	}

	glEnd();

}
*/

void renderDepth()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();                                   // Reset The View  
	glTranslatef(-0.5f, -0.5f, -1.0f);
	glPointSize(2.0);
	perspectiveCamera camera(gvector3(0, 10, 10), gvector3(0, 0, -1), gvector3(0, 1, 0), 90);
	long maxDepth = 20;
	CSphere* sphere1 = new CSphere(gvector3(0, 10, -10), 10.0);

	float dx = 1.0f / WINDOW_WIDTH;
	float dy = 1.0f / WINDOW_HEIGHT;
	float dD = 255.0f / maxDepth;
	glBegin(GL_POINTS);
	for (long y = 0; y < WINDOW_HEIGHT; ++y)
	{
		float sy = 1 - dy*y;
		for (long x = 0; x < WINDOW_WIDTH; ++x)
		{
			float sx = dx*x;
			CRay ray(camera.generateRay(sx, sy));
			IntersectResult result = sphere1->isIntersected(ray);
			if (result.isHit)
			{
				//double t=MIN(result.distance*dD,255.0f);  
				//int depth = (int)(255 -t);  
				//xuanranshengdu  
				//glColor3ub(depth,depth,depth);  
				//xuanran normal  
				glColor3ub(128 * (result.normal.x + 1), 128 * (result.normal.y + 1), 128 * (result.normal.z + 1));
				glVertex2f(sx, sy);
			}
		}
	}
	glEnd();

}

int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	
	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */

		/* Draw a triangle */
		//glBegin(GL_TRIANGLES);

		//glColor3f(1.0, 0.0, 0.0);    // Red
		//glVertex3f(0.0, 1.0, 0.0);

		//glColor3f(0.0, 1.0, 0.0);    // Green
		//glVertex3f(-1.0, -1.0, 0.0);

		//glColor3f(0.0, 0.0, 1.0);    // Blue
		//glVertex3f(1.0, -1.0, 0.0);

		
		//renderDepth()
		//drawScene();
		//glEnd();
		initScene();
		renderDepth();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
