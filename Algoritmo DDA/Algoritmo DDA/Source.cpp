#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

/*** Declaración de la función de redondeo ***/
inline GLint round(const GLfloat a) 
{ 
	return GLint(a + 0.5); 
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

/************************************
 *  La función setPixel dibuja un punto del segmento de línea en la ventana de visualización;
*   se le llama cada vez que se determina un nuevo valor de coordenadas x, y.
 ************************************/

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

/************************************
 *  La función lineDDA implementa el algoritmo en estudio.
 ************************************/

void lineDDA(GLint x0, GLint y0, GLint xEnd, GLint yEnd)
{
	GLint dx = xEnd - x0;
	GLint dy = yEnd - y0;
	GLint steps, k;
	GLfloat xIncrement, yIncrement, x = x0, y = y0;
	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);
	xIncrement = GLfloat(dx) / GLfloat(steps);
	yIncrement = GLfloat(dy) / GLfloat(steps);
	setPixel(round(x), round(y));
	for (k = 0; k < steps; k++)
	{
		x += xIncrement;
		y += yIncrement;
		setPixel(round(x), round(y));
	}
}

/*************************************
*  Finalmente, el procedimiento "dibuja" contiene la llamada al algoritmo de generación de líneas que
 * queremos implementar y es el procedimiento que será referenciado por glutDisplayFunc
 *************************************/

void drawMyLine(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Linea 1 - GL_LINE
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_LINES);
		glVertex2i(5, 225);
		glVertex2i(5, 10);
	glEnd();

	//Linea 1 - DDA
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x01 = 15;
	GLint y01 = 10;
	GLint xEnd1 = 15;
	GLint yEnd1 = 225;
	lineDDA(x01, y01, xEnd1, yEnd1);

	//Linea 2 - GL_LINE
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_LINES);
		glVertex2i(110, 150);
		glVertex2i(30, 150);
	glEnd();

	//Linea 2 - DDA
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x03 = 30;
	GLint y03 = 130;
	GLint xEnd3 = 110;
	GLint yEnd3 = 130;
	lineDDA(x03, y03, xEnd3, yEnd3);

	//Linea 3 - GL_LINE
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_LINES);
		glVertex2i(180, 185);
		glVertex2i(105, 30);
	glEnd();

	//Linea 3 - DDA
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x05 = 115;
	GLint y05 = 10;
	GLint xEnd5 = 190;
	GLint yEnd5 = 165;
	lineDDA(x05, y05, xEnd5, yEnd5);

	//Linea 4 - GL_LINE
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(3.0);
	glBegin(GL_LINES);
		glVertex2i(270, 80);
		glVertex2i(185, 270);
	glEnd();

	//Linea 4 - DDA
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x07 = 185;
	GLint y07 = 235;
	GLint xEnd7 = 270;
	GLint yEnd7 = 45;
	lineDDA(x07, y07, xEnd7, yEnd7);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1200, 450);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laboratorio 2 - Algoritmo DDA");
	init();
	glutDisplayFunc(drawMyLine);
	glutMainLoop();
}