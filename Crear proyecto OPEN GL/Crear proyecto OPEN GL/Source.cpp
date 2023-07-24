#include<GL/glut.h>
#include<math.h>
#include <windows.h>

void init(void)
{
    // Establece el color de la ventana de visualización 
    glClearColor(1.0, 1.0, 1.0, 0.0);

    // Establece los parámetros de proyeccion
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
}

/*************************************
*  El procedimiento "lineSegment" contiene la descripción geométrica de la imagen
* que queremos visualizar y es el procedimiento que será referenciado por glutDisplayFunc
*************************************/

void lineSegment(void)
{
    // Borra la vent. de visualización
    glClear(GL_COLOR_BUFFER_BIT);

    // Establece el color para el segmento de línea en rojo  
    glColor3f(0.0, 0.5, 0.5);

    // Especifica la geometría del segmento de línea
    glBegin(GL_LINES);

    // Punto de coordenada final del segmento
        glVertex2i(50, 65);

    // Punto de coordenada inicial del segmento 
        glVertex2i(130, 125);

    glEnd();

    // Procesa todas las subrutinas OpenGL tan rápidamente como sea posible
    glFlush();
}

/************************************
*  Finalmente, el procedimiento Main contiene las funciones de GLUT que configuran
*  la ventana de visualización y que muestran nuestro segmento (la imagen) en pantalla
************************************/

int main(int argc, char** argv)
{
    // Incializa GLUT
    glutInit(&argc, argv);

    // Establece el modo de visualización
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    // Posición de la esquina sup. izqda. de la ventana de visualización
    glutInitWindowPosition(50, 100);

    // Ancho y altura de la ventana de visualización
    glutInitWindowSize(500, 500);

    // Crea la ventana de visualización
    glutCreateWindow("Programa OpenGL de Ejemplo");

    // Ejecuta el procedimiento de inicialización
    init();

    // Envía los gráficos a la ventana de visualización
    glutDisplayFunc(lineSegment);

    // Muestra todo y espera
    glutMainLoop();
}