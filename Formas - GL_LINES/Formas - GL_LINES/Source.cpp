#include<GL/glut.h>
#include<math.h>
#include <windows.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void lineSegment(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Cuadrado
#pragma region Cuadrado
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(10, 390);
        glVertex2i(10, 300);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(60, 300);
        glVertex2i(10, 300);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(60, 390);
        glVertex2i(60, 300);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(60, 390);
        glVertex2i(10, 390);
    glEnd();
#pragma endregion

    //Rectangulo
#pragma region Rectangulo
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(70, 390);
        glVertex2i(70, 300);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(140, 300);
        glVertex2i(70, 300);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(140, 390);
        glVertex2i(140, 300);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(140, 390);
        glVertex2i(70, 390);
    glEnd();
#pragma endregion

    //Rombo
#pragma region Rombo
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(180, 390);
        glVertex2i(150, 345);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(180, 300);
        glVertex2i(150, 345);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(210, 345);
        glVertex2i(180, 300);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(210, 345);
        glVertex2i(180, 390);
    glEnd();
#pragma endregion

    //Trapecio
#pragma region Trapecio
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(220, 390);
        glVertex2i(235, 300);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(270, 300);
        glVertex2i(235, 300);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(285, 390);
        glVertex2i(270, 300);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(285, 390);
        glVertex2i(220, 390);
    glEnd();
#pragma endregion

    //Triangulo Equilatero
#pragma region Triangulo Equilatero
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(320, 390);
        glVertex2i(295, 300);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(345, 300);
        glVertex2i(295, 300);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(320, 390);
        glVertex2i(345, 300);
    glEnd();
#pragma endregion

    //Triangulo Rectangulo
#pragma region Triangulo Rectangulo
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(10, 190);
        glVertex2i(10, 100);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(60, 100);
        glVertex2i(10, 100);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(10, 190);
        glVertex2i(60, 100);
    glEnd();
#pragma endregion

    //Hexagono
#pragma region Hexagono
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(85, 190);
        glVertex2i(70, 145);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(85, 100);
        glVertex2i(70, 145);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(110, 100);
        glVertex2i(85, 100);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(125, 145);
        glVertex2i(110, 100);

        //Lado Cyan
        glColor3f(0.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(110, 190);
        glVertex2i(125, 145);

        //Lado Verde Caña
        glColor3f(0.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(110, 190);
        glVertex2i(85, 190);
    glEnd();
#pragma endregion

    //Pentagono
#pragma region Pentagono
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(167.5, 190);
        glVertex2i(140, 150);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(155, 100);
        glVertex2i(140, 150);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(180, 100);
        glVertex2i(155, 100);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(195, 150);
        glVertex2i(180, 100);

        //Lado Cyan
        glColor3f(0.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(167.5, 190);
        glVertex2i(195, 150);
    glEnd();
#pragma endregion

    //Simbolo +
#pragma region Simbolo +
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(210, 165);
        glVertex2i(210, 115);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(225, 115);
        glVertex2i(210, 115);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(225, 90);
        glVertex2i(225, 115);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(250, 90);
        glVertex2i(225, 90);

        //Lado Cyan
        glColor3f(0.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(250, 115);
        glVertex2i(250, 90);

        //Lado Verde Caña
        glColor3f(0.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(265, 115);
        glVertex2i(250, 115);

        //Lado Morado
        glColor3f(1.0f, 0.0f, 1.0f);
        glPointSize(3.0);
        glVertex2i(265, 165);
        glVertex2i(265, 115);

        //Lado Naranja
        glColor3f(1.0f, 0.5f, 0.0f);
        glPointSize(3.0);
        glVertex2i(250, 165);
        glVertex2i(265, 165);

        //Lado Violeta
        glColor3f(0.5f, 0.5f, 0.5f);
        glPointSize(3.0);
        glVertex2i(250, 190);
        glVertex2i(250, 165);

        //Lado Lila
        glColor3f(2.0f, 0.5f, 1.0f);
        glPointSize(3.0);
        glVertex2i(225, 190);
        glVertex2i(250, 190);

        //Lado Verde Aqua
        glColor3f(0.0f, 0.5f, 0.5f);
        glPointSize(3.0);
        glVertex2i(225, 165);
        glVertex2i(225, 190);

        //Lado Azul Bebe
        glColor3f(0.0f, 0.5f, 1.0f);
        glPointSize(3.0);
        glVertex2i(210, 165);
        glVertex2i(225, 165);
    glEnd();
#pragma endregion

    //Estrella
#pragma region Estrella
    glBegin(GL_LINES);
        //Lado Azul
        glColor3f(0.0, 0.5, 0.5);
        glPointSize(3.0);
        glVertex2i(302.5, 160);
        glVertex2i(280, 160);

        //Lado Rojo
        glColor3f(1.0, 0.0, 0.0);
        glPointSize(3.0);
        glVertex2i(315, 200);
        glVertex2i(302.5, 160);

        //Lado Amarillo
        glColor3f(1.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(327.5, 160);
        glVertex2i(315, 200);

        //Lado Blanco
        glColor3f(1.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(350, 160);
        glVertex2i(327.5, 160);

        //Lado Cyan
        glColor3f(0.0, 1.0, 1.0);
        glPointSize(3.0);
        glVertex2i(335, 127.5);
        glVertex2i(350, 160);

        //Lado Verde Caña
        glColor3f(0.0, 1.0, 0.0);
        glPointSize(3.0);
        glVertex2i(344, 87.5);
        glVertex2i(335, 127.5);

        //Lado Morado
        glColor3f(1.0f, 0.0f, 1.0f);
        glPointSize(3.0);
        glVertex2i(315, 107.5);
        glVertex2i(344, 87.5);

        //Lado Naranja
        glColor3f(1.0f, 0.5f, 0.0f);
        glPointSize(3.0);
        glVertex2i(286, 87.5);
        glVertex2i(315, 107.5);

        //Lado Violeta
        glColor3f(0.5f, 0.5f, 0.5f);
        glPointSize(3.0);
        glVertex2i(295, 127.5);
        glVertex2i(286, 87.5);

        //Lado Lila
        glColor3f(2.0f, 0.5f, 1.0f);
        glPointSize(3.0);
        glVertex2i(280, 160);
        glVertex2i(295, 127.5);
    glEnd();
#pragma endregion

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(1100, 500);
    glutCreateWindow("Tarea 1 - GL_LINES");
    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();
}