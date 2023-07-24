#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<stdio.h>

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(2.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

/************************************
*  La función setPixel dibuja un punto del segmento de línea en la ventana de visualización;
*   se le llama cada vez que se determina un nuevo valor de coordenadas x, y.
************************************/

void Plot(int ix, int iy)
{
	glBegin(GL_POINTS);
	glVertex2i(ix, iy);
	glEnd();
}

void swap(int* x, int* y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

/************************************
 *  La función lineBresenham implementa el algoritmo en estudio.
 ************************************/

void BLA(int x0, int y0, int x1, int y1)
{
	int dy, x, y, error;
	int delta_x, delta_y;
	bool steep = abs(y1 - y0) > abs(x1 - x0);
	if (steep == true)
	{
		swap(&x0, &y0);
		swap(&x1, &y1);
	}
	if (x0 > x1)
	{
		swap(&x0, &x1);
		swap(&y0, &y1);
	}
	if (y0 > y1)
		dy = -1;
	else
		dy = 1;
	delta_x = x1 - x0;
	delta_y = abs(y1 - y0);
	y = y0;
	error = 0;
	for (x = x0; x <= x1; x++)
	{
		if (steep == true)
			Plot(y, x);
		else
			Plot(x, y);
		error = error + delta_y;
		if (2 * error >= delta_x)
		{
			y = y + dy;
			error = error - delta_x;
		}
	}
}

/*************************************
*  Finalmente, el procedimiento "dibuja" contiene la llamada al algoritmo de generación de líneas que
* queremos implementar y es el procedimiento que será referenciado por glutDisplayFunc
*************************************/

void Iniciador()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Linea 1
	GLint x0 = 5, y0 = 10, xEnd = 5, yEnd = 225;
	BLA(x0, y0, xEnd, yEnd);

	//Linea 2
	GLint x01 = 30, y01 = 150, xEnd1 = 110, yEnd1 = 150;
	BLA(x01, y01, xEnd1, yEnd1);

	//Linea 3
	GLint x02 = 115, y02 = 30, xEnd2 = 190, yEnd2 = 200;
	BLA(x02, y02, xEnd2, yEnd2);

	//Linea 4
	GLint x03 = 270, y03 = 45, xEnd3 = 185, yEnd3 = 235;
	BLA(x03, y03, xEnd3, yEnd3);

	glFlush();
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1200, 450);
	glutCreateWindow("Laboratorio 3 - Algoritmo Bresenham");
	init();
	glutDisplayFunc(Iniciador);
	glutMainLoop();
}