#include<GL/glut.h>
#include<math.h>
#include <windows.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
}

void Triangulo(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    //Ejes
#pragma region Ejes
    glBegin(GL_LINES);
        //Eje X
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(500, 0);
        glVertex2i(-500, 0);

        //Eje Y
        glColor3f(1.0, 1.0, 1.0);
        glVertex2i(0, 500);
        glVertex2i(0, -500);
    glEnd();
#pragma endregion

    //Triangulo 1 - Amarillo
#pragma region Triangulo 1 - Amarillo
    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
        //Primer Punto
        glVertex2f(-75, 0);
        //Segundo Punto
        glVertex2f(75, 0);
        //Tercer Punto
        glVertex2f(0, 100);
    glEnd();
#pragma endregion

    //Triangulo 2 - Azul
#pragma region Triangulo 2 - Azul
    glColor3f(0.0, 0.5, 0.5);
    glScalef(2.0, 3, 1);
    glBegin(GL_TRIANGLES);
        //Primer Punto
        glVertex2f(-150, 0);
        //Segundo Punto
        glVertex2f(-150, 100);
        //Tercer Punto
        glVertex2f(-200, 50);
    glEnd();
#pragma endregion

    //Triangulo 3 - Rojo
#pragma region Triangulo 3 - Rojo
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(275, -50, 0);
    glRotatef(180,0,0,1);
    glBegin(GL_TRIANGLES);
        //Primer Punto
        glVertex2f(125, -25);
        //Segundo Punto
        glVertex2f(175, -25);
        //Tercer Punto
        glVertex2f(150, 25);
    glEnd();
    glPopMatrix();
#pragma endregion

    //Triangulo 4 - Naranja
#pragma region Triangulo 4 - Naranja
    glPushMatrix();
    glColor3f(1.0, 0.5, 0.0);
    glRotatef(45, 0, 0, 1);
    glBegin(GL_TRIANGLES);
        //Primer Punto
        glVertex2f(125, -25);
        //Segundo Punto
        glVertex2f(175, -25);
        //Tercer Punto
        glVertex2f(150, 25);
    glEnd();
    glPopMatrix();
#pragma endregion

    //Triangulo 5 - Morado
#pragma region Triangulo 5 - Morado
    glPushMatrix();
    glColor3f(1.0, 0.0, 1.0);
    glRotatef(220, 0, 0, 1);
    glTranslatef(-20, -25, 0);
    glBegin(GL_TRIANGLES);
        //Primer Punto
        glVertex2f(125, -25);
        //Segundo Punto
        glVertex2f(175, -25);
        //Tercer Punto
        glVertex2f(150, 25);
    glEnd();
    glPopMatrix();
#pragma endregion

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(1000, 1000);
    glutCreateWindow("Tarea 3 - Triangulos");
    init();
    glutDisplayFunc(Triangulo);
    glutMainLoop();
}