#include<GL/glut.h>

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

void MedioCirculoArriba(int Xc, int Yc, int r)
{
	//Se declaran las variables para el algoritmo
	int x = 0, y = r;
	//Parametros de desicion inicial
	float p = (5 / 4) - r;
	//Graficar siguiente punto del circulo con el radio
	Pixel(Xc, r + Yc);
	//Se calculan los puntos para 1/8 del ciruclo y el resto se hace por simetria
	do
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * x + 1;
		}
		else
		{
			x++;
			y--;
			p = p + 2 * x + 2 - 2 * y;
		}
		Pixel(x + Xc, y + Yc);
		Pixel(y + Xc, x + Yc);
		Pixel(-y + Xc, x + Yc);
		Pixel(-x + Xc, y + Yc);
	} while (x < y);
}

void MedioCirculoAbajo(int Xc, int Yc, int r)
{
	//Se declaran las variables para el algoritmo
	int x = 0, y = r;
	//Parametros de desicion inicial
	float p = (5 / 4) - r;
	do
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * x + 1;
		}
		else
		{
			x++;
			y--;
			p = p + 2 * x + 2 - 2 * y;
		}
		Pixel(-x + Xc, -y + Yc);
		Pixel(-y + Xc, -x + Yc);
		Pixel(y + Xc, -x + Yc);
		Pixel(x + Xc, -y + Yc);
	} while (x < y);
}

void CuartoCirculoArribaDerecho(int Xc, int Yc, int r)
{
	//Se declaran las variables para el algoritmo
	int x = 0, y = r;
	//Parametros de desicion inicial
	float p = (5 / 4) - r;
	//Graficar siguiente punto del circulo con el radio
	Pixel(Xc, r + Yc);
	//Se calculan los puntos para 1/8 del ciruclo y el resto se hace por simetria
	do
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * x + 1;
		}
		else
		{
			x++;
			y--;
			p = p + 2 * x + 2 - 2 * y;
		}
		Pixel(x + Xc, y + Yc);
		Pixel(y + Xc, x + Yc);
	} while (x < y);
}

void CuartoCirculoArribaIzquierdo(int Xc, int Yc, int r)
{
	//Se declaran las variables para el algoritmo
	int x = 0, y = r;
	//Parametros de desicion inicial
	float p = (5 / 4) - r;
	//Graficar siguiente punto del circulo con el radio
	Pixel(Xc, r + Yc);
	//Se calculan los puntos para 1/8 del ciruclo y el resto se hace por simetria
	do
	{
		if (p < 0)
		{
			x++;
			p = p + 2 * x + 1;
		}
		else
		{
			x++;
			y--;
			p = p + 2 * x + 2 - 2 * y;
		}
		Pixel(-y + Xc, x + Yc);
		Pixel(-x + Xc, y + Yc);
	} while (x < y);
}

void drawmyline()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Cuarto Circulo Arriba Derecho - Rojo
	glColor3f(1.0, 0.0, 0.0);
	GLint xc5 = 10;
	GLint yc5 = 50;
	GLint r5 = 20;
	CuartoCirculoArribaDerecho(xc5, yc5, r5);

	//Medio Circulo Abajo - Azul
	glColor3f(0.0, 0.5, 0.5);
	GLint xc1 = 50;
	GLint yc1 = 50;
	GLint r1 = 20;
	MedioCirculoAbajo(xc1, yc1, r1);

	//Medio Circulo Arriba - Verde Caña
	glColor3f(0.0, 1.0, 0.0);
	GLint xc = 90;
	GLint yc = 50;
	GLint r = 20;
	MedioCirculoArriba(xc, yc, r);

	//Medio Circulo Abajo - Morado
	glColor3f(1.0, 0.0, 1.0);
	GLint xc2 = 130;
	GLint yc2 = 50;
	GLint r2 = 20;
	MedioCirculoAbajo(xc2, yc2, r2);

	//Medio Circulo Arriba - Naranja
	glColor3f(1.0, 0.5, 0.0);
	GLint xc3 = 170;
	GLint yc3 = 50;
	GLint r3 = 20;
	MedioCirculoArriba(xc3, yc3, r3);

	//Medio Circulo Abajo - Celeste
	glColor3f(0.0, 1.0, 1.0);
	GLint xc4 = 210;
	GLint yc4 = 50;
	GLint r4 = 20;
	MedioCirculoAbajo(xc4, yc4, r4);

	//Cuarto Circulo Arriba Izquierdo - Lila
	glColor3f(2.0, 0.5, 1.0);
	GLint xc6 = 250;
	GLint yc6 = 50;
	GLint r6 = 20;
	CuartoCirculoArribaIzquierdo(xc6, yc6, r6);
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 400);
	glutCreateWindow("Laboratorio 4 - Punto Medio Circulo");
	init();
	glutDisplayFunc(drawmyline);
	glutMainLoop();
}