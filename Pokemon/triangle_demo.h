#ifndef _TRIANGLE_DEMO_H
#define _TRIANGLE_DEMO_H
#define PI 3.14159263
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 5

#include "demo_base.h"
#include <cmath>

#define TEXTURE_COUNT 1

class Vertex
{
public :
	float x;
	float y;
	float z;

	Vertex()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vertex(float a, float b, float c)
	{
		x = a; 
		y = b;
		z = c;
	}
};

Vertex SphereFunction(float u, float v, float radius)
{
	u = u * PI / 180.0f;
	v = v * PI / 180.0f;
	Vertex answer;
	answer.x = cos(u) * sin(v) * radius;
	answer.y = cos(v) * radius;
	answer.z = sin(u) * sin(v) * radius;
	return answer;
}

class TriangleDemo : public DemoBase, Vertex
{
private:
	float m_rotation;
	float m_value;

public:
	float x;
	float y;
	float z;

	void init()
	{
		m_rotation = 0;
		m_value = 90.0f;
	}

	void deinit()
	{

	}

	void drawAxis(const Matrix& viewMatrix)
	{
	// ============draw axis.
		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		glBegin(GL_LINES);
			glColor3f(1.0f, 0.3f, 0.3f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(1.0f, 0.0f, 0.0f);

			glColor3f(0.3f, 1.0f, 0.3f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 1.0f, 0.0f);
			
			glColor3f(0.3f, 0.3f, 1.0f);
			glVertex3f(0.0f, 0.0f, 0.0f);
			glVertex3f(0.0f, 0.0f, 1.0f);
		glEnd();
		// ============================
	}

	void drawSquare(void)
	{
		glBegin(GL_TRIANGLES);								// Drawing Using Triangles
			
			glColor3f( 255.0f, 0.0f, 0.0f);					// Color
			glVertex3f( 0.0f, 0.0f, 0.0f);					// Top
			glVertex3f( 1.0f, 1.0f, 0.0f);					// Bottom Right
			glVertex3f( 1.0f, 0.0f, 0.0f);					// Bottom Left

			glColor3f(255.0f, 0.0f, 0.0f);					// Color
			glVertex3f( 0.0f, 0.0f, 0.0f);					// Top
			glVertex3f( 0.0f, 1.0f, 0.0f);					// Bottom Left
			glVertex3f( 1.0f, 1.0f, 0.0f);					// Bottom Right	
		glEnd();	
	}

	void drawCubeLegRight(void)
	{
		glBegin(GL_TRIANGLES);
		
		glVertex3f(-6.0f, 0.0f, 0.0f);
		glVertex3f(-4.0f, 1.0f, 0.0f);
		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 1.0f, 0.0f);
		glVertex3f(-4.0f, 1.0f, 0.0f);

		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 1.0f, 2.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);

		// x-axis
		glVertex3f(-6.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 1.0f, 2.0f);
		glVertex3f(-6.0f, 1.0f, 0.0f);
		glVertex3f(-6.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 1.0f, 2.0f);


		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);
		glVertex3f(-4.0f, 1.0f, 0.0f);
		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);

		// y-axis
		glVertex3f(-6.0f, 1.0f, 0.0f);
		glVertex3f(-4.0f, 1.0f, 0.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);
		glVertex3f(-6.0f, 1.0f, 0.0f);
		glVertex3f(-6.0f, 1.0f, 2.0f);
		glVertex3f(-4.0f, 1.0f, 2.0f);

		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 0.0f, 0.0f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-4.0f, 0.0f, 0.0f);
		glVertex3f(-6.0f, 0.0f, 2.0f);

		glEnd();
	}

	void drawPyramidLegRight_1()
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(-6.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-6.0f, 0.0f, 1.0f);

		// Back
		glVertex3f(-6.0f, 0.0f, 1.0f);
		glVertex3f(-5.5f, 0.0f, 1.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-5.5f, 0.0f, 1.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);

		// Front
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-5.5f, 0.0f, 2.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);
		glVertex3f(-5.5f, 0.0f, 2.0f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);

		// Left
		glVertex3f(-6.0f, 0.0f, 1.0f);
		glVertex3f(-6.0f, 0.0f, 1.5f);
		glVertex3f(-5.5f, -0.5f, 1.5f);
		glVertex3f(-6.0f, 0.0f, 1.5f);
		glVertex3f(-6.0f, 0.0f, 2.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);

		// Right
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, 1.5f);
		glVertex3f(-5.5f, -0.5f, 1.5f);
		glVertex3f(-5.0f, 0.0f, 1.5f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-5.5f, -0.5f, 1.5f);

		glEnd();
	}

	void drawPyramidLegRight_2()
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-4.0f, 0.0f, 1.0f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-5.0f, 0.0f, 1.0f);

		// Back
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);
		glVertex3f(-4.0f, 0.0f, 1.0f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);

		// Front
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-4.5f, 0.0f, 2.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-4.5f, 0.0f, 2.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);

		// Left
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, 1.5f);
		glVertex3f(-4.5f, -0.5f, 1.5f);
		glVertex3f(-5.0f, 0.0f, 1.5f);
		glVertex3f(-5.0f, 0.0f, 2.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);

		// Right
		glVertex3f(-4.0f, 0.0f, 1.0f);
		glVertex3f(-4.0f, 0.0f, 1.5f);
		glVertex3f(-4.5f, -0.5f, 1.5f);
		glVertex3f(-4.0f, 0.0f, 1.5f);
		glVertex3f(-4.0f, 0.0f, 2.0f);
		glVertex3f(-4.5f, -0.5f, 1.5f);

		glEnd();
	}

	void drawPyramidLegRight_3()
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(-5.5f, 0.0f, 0.0f);
		glVertex3f(-4.5f, 0.0f, 0.0f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-5.5f, 0.0f, 1.0f);
		glVertex3f(-5.5f, 0.0f, 0.0f);

		// Back
		glVertex3f(-5.5f, 0.0f, 0.0f);
		glVertex3f(-5.0f, 0.0f, 0.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);
		glVertex3f(-5.0f, 0.0f, 0.0f);
		glVertex3f(-4.5f, 0.0f, 0.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);

		// Front
		glVertex3f(-5.5f, 0.0f, 1.0f);
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);
		glVertex3f(-5.0f, 0.0f, 1.0f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);

		// Left
		glVertex3f(-5.5f, 0.0f, 0.0f);
		glVertex3f(-5.5f, 0.0f, 0.5f);
		glVertex3f(-5.0f, -0.5f, 0.5f);
		glVertex3f(-5.5f, 0.0f, 0.5f);
		glVertex3f(-5.5f, 0.0f, 1.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);

		// Right
		glVertex3f(-4.5f, 0.0f, 0.0f);
		glVertex3f(-4.5f, 0.0f, 0.5f);
		glVertex3f(-5.0f, -0.5f, 0.5f);
		glVertex3f(-4.5f, 0.0f, 0.5f);
		glVertex3f(-4.5f, 0.0f, 1.0f);
		glVertex3f(-5.0f, -0.5f, 0.5f);

		glEnd();
	}

	void drawCubeLegLeft(void)
	{
		glBegin(GL_TRIANGLES);

		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);

		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 1.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);

		// x-axis
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 2.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 1.0f, 2.0f);


		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);

		// y-axis
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 0.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 2.0f);
		glVertex3f(2.0f, 1.0f, 2.0f);

		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(2.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);

		glEnd();
	}

	void drawPyramidLegLeft_1(void)
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);

		// Back
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, 1.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);

		// Front
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.5f, 0.0f, 2.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(0.5f, 0.0f, 2.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);

		// Left
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 1.5f);
		glVertex3f(0.5f, -0.5f, 1.5f);
		glVertex3f(0.0f, 0.0f, 1.5f);
		glVertex3f(0.0f, 0.0f, 2.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);

		// Right
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.5f);
		glVertex3f(0.5f, -0.5f, 1.5f);
		glVertex3f(1.0f, 0.0f, 1.5f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(0.5f, -0.5f, 1.5f);

		glEnd();
	}

	void drawPyramidLegLeft_2(void)
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(2.0f, 0.0f, 1.0f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);

		// Back
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);
		glVertex3f(2.0f, 0.0f, 1.0f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);

		// Front
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(1.5f, 0.0f, 2.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(1.5f, 0.0f, 2.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);

		// Left
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.5f);
		glVertex3f(1.5f, -0.5f, 1.5f);
		glVertex3f(1.0f, 0.0f, 1.5f);
		glVertex3f(1.0f, 0.0f, 2.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);

		// Right
		glVertex3f(2.0f, 0.0f, 1.0f);
		glVertex3f(2.0f, 0.0f, 1.5f);
		glVertex3f(1.5f, -0.5f, 1.5f);
		glVertex3f(2.0f, 0.0f, 1.5f);
		glVertex3f(2.0f, 0.0f, 2.0f);
		glVertex3f(1.5f, -0.5f, 1.5f);

		glEnd();
	}

	void drawPyramidLegLeft_3(void)
	{
		glBegin(GL_TRIANGLES);

		// Base
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(1.5f, 0.0f, 0.0f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, 0.0f);

		// Back
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);
		glVertex3f(1.5f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);

		// Front
		glVertex3f(0.5f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);

		// Left
		glVertex3f(0.5f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.5f);
		glVertex3f(1.0f, -0.5f, 0.5f);
		glVertex3f(0.5f, 0.0f, 0.5f);
		glVertex3f(0.5f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);

		// Right
		glVertex3f(1.5f, 0.0f, 0.0f);
		glVertex3f(1.5f, 0.0f, 0.5f);
		glVertex3f(1.0f, -0.5f, 0.5f);
		glVertex3f(1.5f, 0.0f, 0.5f);
		glVertex3f(1.5f, 0.0f, 1.0f);
		glVertex3f(1.0f, -0.5f, 0.5f);

		glEnd();
	}

	void drawCircle(void)
	{
		glBegin(GL_TRIANGLES);

		//for (int i = 0; i <= )

		glColor3f(1.0f, 1.0f, 1.0f);
		
		glVertex3f(0.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.98f, 0.2f, 0.0f);

		glEnd();
	}

	void drawFilledCircle(void) 
	{	
		int triangleAmount = 208;
		float x, y, z;
		float twicePi = 2.0f * PI;
		glBegin(GL_TRIANGLES);

		for (float i = 0; i <= triangleAmount; i += 0.5f)
		{
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(
				(1.0f * cos(5 * i *  twicePi / triangleAmount)),
				1.0f,
				(1.0f * sin(5 * i * twicePi / triangleAmount))
			);
		}
		glEnd();
	}

	void DrawEllipse(float startU, float startV, float endU, float endV, float radius, float UResolution, float VResolution, float xFactor, float yFactor)
	{
		float stepU = (endU - startU) / UResolution;
		float stepV = (endV - startV) / VResolution;
		glBegin(GL_TRIANGLES);

		for (int i = 0; i < UResolution; i++)
		{
			for (int j = 0; j < VResolution; j++)
			{
				float u = i * stepU + startU;
				float v = j * stepV + startV;
				float un = (j + 1 == UResolution) ? endU : (j + 1) * stepU + startU;
				float vn = (j + 1 == VResolution) ? endV : (j + 1) * stepV + startV;

				Vertex p0 = SphereFunction(u, v, radius);
				Vertex p1 = SphereFunction(u, vn, radius);
				Vertex p2 = SphereFunction(un, v, radius);
				Vertex p3 = SphereFunction(un, vn, radius);

				glVertex3f(p0.x * xFactor, p0.y * yFactor, p0.z);
				glVertex3f(p2.x * xFactor, p2.y * yFactor, p2.z);
				glVertex3f(p1.x * xFactor, p1.y * yFactor, p1.z);

				glVertex3f(p3.x * xFactor, p3.y * yFactor, p3.z);
				glVertex3f(p1.x * xFactor, p1.y * yFactor, p1.z);
				glVertex3f(p2.x * xFactor, p2.y * yFactor, p2.z);
			}
		}

		glEnd();
	}

	void DrawSphere(float startU, float startV, float endU, float endV, float radius, float UResolution, float VResolution)
	{
		float stepU = (endU - startU) / UResolution;
		float stepV = (endV - startV) / VResolution;
		glBegin(GL_TRIANGLES);
		for (int i = 0; i < UResolution; i++)
		{
			for (int j = 0; j < VResolution; j++)
			{
				float u = i * stepU + startU;
				float v = j * stepV + startV;
				float un = (i + 1 == UResolution) ? endU : (i + 1)*stepU + startU;
				float vn = (j + 1 == VResolution) ? endV : (j + 1)*stepV + startV;

				Vertex p0 = SphereFunction(u, v, radius);
				Vertex p1 = SphereFunction(u, vn, radius);
				Vertex p2 = SphereFunction(un, v, radius);
				Vertex p3 = SphereFunction(un, vn, radius);
				
				glVertex3f(p0.x, p0.y, p0.z);
				glVertex3f(p2.x, p2.y, p2.z);
				glVertex3f(p1.x, p1.y, p1.z);

				glVertex3f(p3.x, p3.y, p3.z);
				glVertex3f(p1.x, p1.y, p1.z);
				glVertex3f(p2.x, p2.y, p2.z);
			}
		}
		glEnd();
	}

	void drawCylinder(void)
	{
		int triangleAmount = 208;
		float x, y, z;
		float twicePi = 2.0f * PI;
		glBegin(GL_TRIANGLES);
		//glColor3f(1.0f, 0.0f, 2.0f);

		for (float i = 0; i <= triangleAmount; i += 0.5f)
		{
			glVertex3f(0.0f, 1.0f, 0.0f);
			glVertex3f(
				(1.0f * cos(5 * i *  twicePi / triangleAmount)),
				1.0f,
				(1.0f * sin(5 * i * twicePi / triangleAmount))
			);
		}
		for (float i = 0; i <= triangleAmount; i += 0.5f)
		{
			glVertex3f(0.0f, -1.0f, 0.0f);
			glVertex3f(
				(1.0f * cos(5 * i *  twicePi / triangleAmount)),
				-1.0f,
				(1.0f * sin(5 * i * twicePi / triangleAmount))
			);
		}
		for (float j = 0; j <= 416.0f; j += 0.1f) {
			glColor3f(1.0f, 4.0f, 2.0f);
			glVertex3f(cos(5 * j * PI / 208.0f), +1, sin(5 * j * PI / 208.0f));
			glVertex3f(cos(5 * j * PI / 208.0f), -1, sin(5 * j * PI / 208.0f));
		}

		glEnd();
	}

	void draw(const Matrix& viewMatrix)
	{
		m_rotation += 0.1f;
		//m_value += 90.0f;

		glLoadMatrixf((GLfloat*)viewMatrix.mVal);
		drawAxis(viewMatrix);

		//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

		Matrix body = Matrix::makeTranslationMatrix(0.0f, sinf(m_rotation), 0.0f);
		Matrix viewSpaceMatrix = viewMatrix * body;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

		Matrix Bottom = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f) * Matrix::makeTranslationMatrix(0.0f, 0.0f, 0.0f) * Matrix::makeRotateMatrix(40 * sinf(m_value), Vector(1.0f, 0.0f, 0.0f));
		viewSpaceMatrix = viewMatrix * Bottom;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

		// Draw Rowlet
		glColor3f(0.6f, 0.4f, 0.2f);

		glColor3f(0.8f, 0.5f, 0.0f);
		drawCubeLegRight();
		drawPyramidLegRight_1();
		drawPyramidLegRight_2();
		drawPyramidLegRight_3();

		Matrix BottomLeft = Matrix::makeScaleMatrix(0.5f, 0.5f, 0.5f) * Matrix::makeTranslationMatrix(0.0f, 0.0f, 0.0f) * Matrix::makeRotateMatrix(40 * cosf(m_value), Vector(1.0f, 0.0f, 0.0f));
		viewSpaceMatrix = viewMatrix * BottomLeft;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);

		drawCubeLegLeft();
		glColor3f(1.0f, 0.5f, 0.0f);
		drawPyramidLegLeft_1();
		drawPyramidLegLeft_2();
		drawPyramidLegLeft_3();

		// LeftLegBottom
		Matrix LeftLegBottom = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f) * Matrix::makeTranslationMatrix(0.5f, 1.0f, 0.5f);
		viewSpaceMatrix = viewMatrix * LeftLegBottom;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// RightLegBottom
		Matrix RightLegBottom = Matrix::makeScaleMatrix(1.0f, 1.0f, 1.0f) * Matrix::makeTranslationMatrix(-2.5f, 1.0f, 0.5f);
		viewSpaceMatrix = viewMatrix * RightLegBottom;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Torso
		Matrix Torso = Matrix::makeScaleMatrix(3.5f, 4.0f, 3.0f) * Matrix::makeTranslationMatrix(-0.3f, 1.1f, 0.1f);
		viewSpaceMatrix = viewMatrix * Torso;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.6f, 0.4f, 0.12f);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Eye-Right-Outer
		Matrix EyeRight = Matrix::makeScaleMatrix(1.7f, 2.0f, 1.0f) * Matrix::makeTranslationMatrix(-1.0f, 2.0f, 2.5f);
		viewSpaceMatrix = viewMatrix * EyeRight;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(1.0f, 1.0f, 1.0f);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Eye-Left-Outer
		Matrix EyeLeft = Matrix::makeScaleMatrix(1.7f, 2.0f, 1.0f) * Matrix::makeTranslationMatrix(-0.1f, 2.0f, 2.5f);
		viewSpaceMatrix = viewMatrix * EyeLeft;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Eye-Right-Inner
		Matrix EyeRightInner = Matrix::makeScaleMatrix(0.7f, 1.0f, 1.0f) * Matrix::makeTranslationMatrix(-3.0f, 3.6f, 2.7f);
		viewSpaceMatrix = viewMatrix * EyeRightInner;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.0f, 0.0f, 0.0f);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Eye-Left-Inner
		Matrix EyeLeftInner = Matrix::makeScaleMatrix(0.7f, 1.0f, 1.0f) * Matrix::makeTranslationMatrix(0.4f, 3.6f, 2.7f);
		viewSpaceMatrix = viewMatrix * EyeLeftInner;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		// Nose-Outer
		Matrix Nose = Matrix::makeScaleMatrix(0.7f, 1.3f, 1.0f) * Matrix::makeTranslationMatrix(-1.3f, 2.8f, 3.0f);
		viewSpaceMatrix = viewMatrix * Nose;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(1.0f, 0.5f, 0.0f);
		DrawSphere(0.0f, 0.0f, 360.0f, 180.0f, 1.0f, 20.0f, 20.0f);

		/// Right Hand
		// RightHand-1
		m_value += 0.1f;

		Matrix RightHand1 = Matrix::makeRotateMatrix(40 * sinf(m_value), Vector(0.0f, 0.0f, 1.0f));
		viewSpaceMatrix = viewMatrix * RightHand1;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.5f, 0.4f, 0.12f);
		drawCubeLegLeft();
		//drawFilledCircle();

		/*m_value -= 1.0f;
		if (m_value < -60.0f)
		{
			m_value = -40.0f;
		}
		Matrix RightHand1 = Matrix::makeTranslationMatrix(-8.6f, 2.8f, 1.0f) * Matrix::makeRotateMatrix(m_value, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHand1;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.5f, 0.4f, 0.12f);
		drawFilledCircle();*/

		// RightHand-2
		Matrix RightHand2 = Matrix::makeTranslationMatrix(-8.6f, 2.8f, 0.2f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHand2;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// RightHand-3
		Matrix RightHand3 = Matrix::makeTranslationMatrix(-8.6f, 2.8f, -0.5f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHand3;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// RightHandInner1-1
		Matrix RightHandInner11 = Matrix::makeTranslationMatrix(-6.5f, 2.8f, 1.0f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHandInner11;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.0f, 1.0f, 0.0f);
		drawFilledCircle();

		// RightHandInner1-2
		Matrix RightHandInner12 = Matrix::makeTranslationMatrix(-6.5f, 2.8f, 0.2f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHandInner12;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// RightHandInner1-3
		Matrix RightHandInner13 = Matrix::makeTranslationMatrix(-6.5f, 2.8f, -0.5f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * RightHandInner13;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		/// Left Hand
		// LeftHand-1
		Matrix LeftHand1 = Matrix::makeTranslationMatrix(-1.5f, 2.8f, 1.0f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHand1;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.5f, 0.4f, 0.12f);
		drawFilledCircle();

		// LeftHand-2
		Matrix LeftHand2 = Matrix::makeTranslationMatrix(-1.5f, 2.8f, 0.2f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHand2;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// LeftHand-3
		Matrix LeftHand3 = Matrix::makeTranslationMatrix(-1.5f, 2.8f, -0.5f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(2.0f, 4.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHand3;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// LeftHandInner1-1
		Matrix LeftHandInner11 = Matrix::makeTranslationMatrix(0.4f, 2.8f, 1.0f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHandInner11;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		glColor3f(0.0f, 1.0f, 0.0f);
		drawFilledCircle();

		// LeftHandInner1-2
		Matrix LeftHandInner12 = Matrix::makeTranslationMatrix(0.4f, 2.8f, 0.2f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHandInner12;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();

		// LeftHandInner1-3
		Matrix LeftHandInner13 = Matrix::makeTranslationMatrix(0.4f, 2.8f, -0.5f) * Matrix::makeRotateMatrix(90.0f, Vector(0.0f, 0.0f, 1.0f)) * Matrix::makeScaleMatrix(1.0f, 2.0f, 1.0f);
		viewSpaceMatrix = viewMatrix * LeftHandInner13;
		glLoadMatrixf((GLfloat*)viewSpaceMatrix.mVal);
		drawFilledCircle();
	}
};

#endif
