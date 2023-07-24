#include<GL/glut.h>
#include<math.h>

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 500.0, 0.0, 250.0);
}

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

void Pixel(float cx, float cy)
{
	//Tamaño del pixel
	glPointSize(2);
	//Inicializar
	glBegin(GL_POINTS);
	glVertex2f(cx, cy);
	glEnd();
	glFlush();
}

void MediaElipseArriba(int xc, int yc, int xr, int yr)
{
	//Para dibujar la elipse necesitamos dos radios
	int x = 0, y = yr;
	//Parametro de desicion para la region 1/4 de la elipse
	float p1 = pow(yr, 2) - pow(xr, 2) * yr + 0.25 * pow(yr, 2);
	float p2;
	//Punto central y puntos extremos de la elipse
	Pixel(xc, yc);
	Pixel(xc, yc + yr);
	Pixel(xc, yc - yr);
	//Parametros de la region 1
	while (pow(yr, 2) * x < pow(xr, 2) * y)
	{
		if (p1 < 0)
		{
			x++;
			p1 = p1 + 2 * pow(yr, 2) * x + pow(yr, 2);

		}
		else
		{
			x++;
			y--;
			p1 = p1 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(yr, 2);
			//El resto de cuadrantes se obiente por simetria
			Pixel(x + xc, y + yc);
			Pixel(-x + xc, y + yc);
		}
	}
	//Parametros de la region 2
	p2 = pow(yr, 2) * pow(x + 0.5, 2) + pow(xr, 2) * pow(y - 1, 2) - pow(xr, 2) * pow(yr, 2);
	while (y > 0)
	{
		if (p2 > 0)
		{
			y--;
			p2 = p2 - 2 * pow(xr, 2) * y + pow(xr, 2);
		}
		else
		{
			x++;
			y--;
			p2 = p2 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(xr, 2);

		}
		Pixel(x + xc, y + yc);
		Pixel(-x + xc, y + yc);
	}
}

void MediaElipseAbajo(int xc, int yc, int xr, int yr)
{
	//Para dibujar la elipse necesitamos dos radios
	int x = 0, y = yr;
	//Parametro de desicion para la region 1/4 de la elipse
	float p1 = pow(yr, 2) - pow(xr, 2) * yr + 0.25 * pow(yr, 2);
	float p2;
	//Punto central y puntos extremos de la elipse
	Pixel(xc, yc);
	Pixel(xc, yc + yr);
	Pixel(xc, yc - yr);
	//Parametros de la region 1
	while (pow(yr, 2) * x < pow(xr, 2) * y)
	{
		if (p1 < 0)
		{
			x++;
			p1 = p1 + 2 * pow(yr, 2) * x + pow(yr, 2);
		}
		else
		{
			x++;
			y--;
			p1 = p1 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(yr, 2);
			//El resto de cuadrantes se obiente por simetria
			Pixel(-x + xc, -y + yc);
			Pixel(x + xc, -y + yc);
		}
	}
	//Parametros de la region 2
	p2 = pow(yr, 2) * pow(x + 0.5, 2) + pow(xr, 2) * pow(y - 1, 2) - pow(xr, 2) * pow(yr, 2);
	while (y > 0)
	{
		if (p2 > 0)
		{
			y--;
			p2 = p2 - 2 * pow(xr, 2) * y + pow(xr, 2);
		}
		else
		{
			x++;
			y--;
			p2 = p2 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(xr, 2);
		}
		Pixel(-x + xc, -y + yc);
		Pixel(x + xc, -y + yc);
	}
}

void CuartoElipseArribaDerecha(int xc, int yc, int xr, int yr)
{
	//Para dibujar la elipse necesitamos dos radios
	int x = 0, y = yr;
	//Parametro de desicion para la region 1/4 de la elipse
	float p1 = pow(yr, 2) - pow(xr, 2) * yr + 0.25 * pow(yr, 2);
	float p2;
	//Punto central y puntos extremos de la elipse
	Pixel(xc, yc);
	Pixel(xc, yc + yr);
	Pixel(xc, yc - yr);
	//Parametros de la region 1
	while (pow(yr, 2) * x < pow(xr, 2) * y)
	{
		if (p1 < 0)
		{
			x++;
			p1 = p1 + 2 * pow(yr, 2) * x + pow(yr, 2);

		}
		else
		{
			x++;
			y--;
			p1 = p1 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(yr, 2);
			//El resto de cuadrantes se obiente por simetria
			Pixel(x + xc, y + yc);
		}
	}
	//Parametros de la region 2
	p2 = pow(yr, 2) * pow(x + 0.5, 2) + pow(xr, 2) * pow(y - 1, 2) - pow(xr, 2) * pow(yr, 2);
	while (y > 0)
	{
		if (p2 > 0)
		{
			y--;
			p2 = p2 - 2 * pow(xr, 2) * y + pow(xr, 2);
		}
		else
		{
			x++;
			y--;
			p2 = p2 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(xr, 2);

		}
		Pixel(x + xc, y + yc);
	}
}

void CuartoElipseArribaIzquierda(int xc, int yc, int xr, int yr)
{
	//Para dibujar la elipse necesitamos dos radios
	int x = 0, y = yr;
	//Parametro de desicion para la region 1/4 de la elipse
	float p1 = pow(yr, 2) - pow(xr, 2) * yr + 0.25 * pow(yr, 2);
	float p2;
	//Punto central y puntos extremos de la elipse
	Pixel(xc, yc);
	Pixel(xc, yc + yr);
	Pixel(xc, yc - yr);
	//Parametros de la region 1
	while (pow(yr, 2) * x < pow(xr, 2) * y)
	{
		if (p1 < 0)
		{
			x++;
			p1 = p1 + 2 * pow(yr, 2) * x + pow(yr, 2);

		}
		else
		{
			x++;
			y--;
			p1 = p1 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(yr, 2);
			//El resto de cuadrantes se obiente por simetria
			Pixel(-x + xc, y + yc);
		}
	}
	//Parametros de la region 2
	p2 = pow(yr, 2) * pow(x + 0.5, 2) + pow(xr, 2) * pow(y - 1, 2) - pow(xr, 2) * pow(yr, 2);
	while (y > 0)
	{
		if (p2 > 0)
		{
			y--;
			p2 = p2 - 2 * pow(xr, 2) * y + pow(xr, 2);
		}
		else
		{
			x++;
			y--;
			p2 = p2 + 2 * pow(yr, 2) * x - 2 * pow(xr, 2) * y + pow(xr, 2);

		}
		Pixel(-x + xc, y + yc);
	}
}

void drawmyline()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Cuarto Elipse Arriba Derecha - Rojo
	glColor3f(1.0, 0.0, 0.0);
	GLint xc0 = 10;
	GLint yc0 = 60;
	GLint xr0 = 30;
	GLint yr0 = 50;
	CuartoElipseArribaDerecha(xc0, yc0, xr0, yr0);

	//Media Elipse Abajo - Azul
	glColor3f(0.0, 0.5, 0.5);
	GLint xc1 = 70;
	GLint yc1 = 60;
	GLint xr1 = 30;
	GLint yr1 = 50;
	MediaElipseAbajo(xc1, yc1, xr1, yr1);

	//Media Elipse Arriba - Verde Caña
	glColor3f(0.0, 1.0, 0.0);
	GLint xc2 = 130;
	GLint yc2 = 60;
	GLint xr2 = 30;
	GLint yr2 = 50;
	MediaElipseArriba(xc2, yc2, xr2, yr2);

	//Media Elipse Abajo - Morado
	glColor3f(1.0, 0.0, 1.0);
	GLint xc3 = 190;
	GLint yc3 = 60;
	GLint xr3 = 30;
	GLint yr3 = 50;
	MediaElipseAbajo(xc3, yc3, xr3, yr3);

	//Media Elipse Arriba - Naranja
	glColor3f(1.0, 0.5, 0.0);
	GLint xc4 = 250;
	GLint yc4 = 60;
	GLint xr4 = 30;
	GLint yr4 = 50;
	MediaElipseArriba(xc4, yc4, xr4, yr4);

	//Medio Circulo Abajo - Celeste
	glColor3f(0.0, 1.0, 1.0);
	GLint xc5 = 310;
	GLint yc5 = 60;
	GLint xr5 = 30;
	GLint yr5 = 50;
	MediaElipseAbajo(xc5, yc5, xr5, yr5);

	//Cuarto Circulo Arriba Izquierdo - Lila
	glColor3f(2.0, 0.5, 1.0);
	GLint xc6 = 370;
	GLint yc6 = 60;
	GLint xr6 = 30;
	GLint yr6 = 50;
	CuartoElipseArribaIzquierda(xc6, yc6, xr6, yr6);
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 400);
	glutCreateWindow("Laboratorio 5 - Punto Medio Elipse");
	init();
	glutDisplayFunc(drawmyline);
	glutMainLoop();
}