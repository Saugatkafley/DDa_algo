#include<iostream>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>

void putpixel(int, int);
int Round(float);
using namespace std;

float xincr, yincr, x, y, dx, dy;
int steps, k, x1, y_1, x2, y2;

void draw()
{
    dx = (float)(x2 - x1 );
    dy = (float)(y2 - y_1);

    if (abs(dx) >= abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xincr = dx / steps;
    yincr = dy / steps;

    x = x1;
    y = y_1;

    for (k = 1; k <= steps; k++)
    {
        putpixel(Round(x), Round(y));
        x = x + xincr;
        y = y + yincr;
    }
}
int Round(float a)
{
    int b = a + 0.5;
    return b;
}
void putpixel(int x, int y)
{
    glColor3f(0, 0, 1);                         // sets the current drawing (foreground) color to blue 
    glPointSize(3);                             // sets the size of points to be drawn (in pixels)
    glBegin(GL_POINTS);                         // writes pixels on the frame buffer with the current drawing color
    glVertex2i(x, y);                           //sets vertex
    glEnd();
    glFlush();
}
void myinit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);                   // clears the frame buffer and set values defined in glClearColor() function call 
    draw();
    glFlush();                                      // flushes the frame buffer to the screen
}
int main(int argc, char** argv)
{
    cout << "Enter the value of x1 and y1 : ";
    cin >> x1 >> y_1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;
    glutInit(&argc, argv);
    glutInitWindowSize(100,100);                   //sets the width and height of the window in pixels
    glutInitWindowPosition(50, 50);                 //sets the position of the window in pixels from top left corner 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);    //creates a single frame buffer of RGB color capacity.
    glutCreateWindow("DDA Line Drawing");           //creates the window as specified by the user as above.
    glutDisplayFunc(display);                       //links the display event with the display event handler(display)
    myinit();
    glutIdleFunc(draw);
    glutMainLoop();                                 //loops the current event
    return 0;
}