#include <GL/glut.h>
#include <math.h>

void iniciar()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);

	glLineWidth(3.f);

	glOrtho(800, 0, 600, 0, -1, 1);
}

void Pixel(float cx, float cy)
{
	//Tamaño del pixel
	glPointSize(3);
	//Color
	glColor3f(0.0f, 0.5f, 0.5f);
	//Inicializar
	glBegin(GL_POINTS);
	glVertex2f(cx, cy);
	glEnd();
	glFlush();

}

void setPixel(GLint xCoordinate, GLint yCoordinate)
{
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

void Circulo(int Xc, int Yc, int r)
{
	//Se declaran las variables para el algoritmo
	int x = 0, y = r;
	//Parametros de desicion inicial
	float p = (5 / 4) - r;
	//graficar punto Central
	Pixel(Xc, Yc);
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
		Pixel(-x + Xc, -y + Yc);
		Pixel(-x + Xc, -y + Yc);
		Pixel(-y + Xc, -x + Yc);
		Pixel(y + Xc, -x + Yc);
		Pixel(x + Xc, -y + Yc);

	} while (x < y);

}

void Elipse(int xc, int yc, int xr, int yr)
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
		Pixel(x + xc, y + yc);
		Pixel(-x + xc, y + yc);
		Pixel(-x + xc, -y + yc);
		Pixel(x + xc, -y + yc);
	}
}

void MediaElipse(int xc, int yc, int xr, int yr)
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
	//graficar punto Central

	//Graficar siguiente punto del circulo con el radio

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



		Pixel(-x + Xc, -y + Yc);
		Pixel(-y + Xc, -x + Yc);
		Pixel(y + Xc, -x + Yc);
		Pixel(x + Xc, -y + Yc);

	} while (x < y);
}

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

void dibujar()
{
	glClear(GL_COLOR_BUFFER_BIT);

	//Punta
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x0 = 400;
	GLint y0 = 100;
	GLint xEnd = 400;
	GLint yEnd = 50;
	lineDDA(x0, y0, xEnd, yEnd);

	//Palo
	glColor3f(0.0, 0.5, 0.5);
	glPointSize(3.0);
	GLint x01 = 400;
	GLint y01 = 400;
	GLint xEnd1 = 400;
	GLint yEnd1 = 170;
	lineDDA(x01, y01, xEnd1, yEnd1);

	glBegin(GL_LINE);
	//Elipse del paraguas la parte que cubre pues
	MediaElipse(400, 200, 150, 100);
	//Circulos debajo de la parte que cubre
	MedioCirculoAbajo(280, 200, 30);
	MedioCirculoAbajo(340, 200, 30);
	MedioCirculoAbajo(400, 200, 30);
	MedioCirculoAbajo(460, 200, 30);
	MedioCirculoAbajo(520, 200, 30);

	//Circulo del mango del paraguas
	MedioCirculoArriba(425, 400, 25);

	glEnd();
	glFlush();
}

int main(int argc, char* args[])
{
	//Iniciar la libreria
	glutInit(&argc, args);

	//Modo de display
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

	//Inicializar ventana
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(700, 500);
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

	glutCreateWindow("Tarea 2 - Paraguas");

	iniciar();

	glutDisplayFunc(dibujar);
	//Mantiene la ventana en Loop hasta que se cierre la ventana
	glutMainLoop();

	return 0;
}