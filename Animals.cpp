#include "fun.h"

float chicken_position = 0.0 ;
void Chicken(){
    //head
    glColor3ub(139,69,19);//brown
    DrawCircle(chicken_position-580, -395, 20, 1000);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    DrawCircle(chicken_position-580, -395, 5, 1000);
    // lips
//    glColor3ub (0,100,0);
    glColor3ub(139,69,19);//brown
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    //up
    glVertex2i(chicken_position-563,-394);
    glVertex2i(chicken_position-549,-399);
    //down
    glVertex2i(chicken_position-563,-399);
    glVertex2i(chicken_position-549,-399);
    glEnd();
//gola
    glBegin(GL_POLYGON);
    glVertex2i(chicken_position-600.5,-395);
    glVertex2i(chicken_position-564.5,-405);
    glVertex2i(chicken_position-574.5,-441.5);
    glVertex2i(chicken_position-605.5,-431.5);
    glEnd();
    DrawCircle(chicken_position-594.5, -450, 22, 1000);
    
    glBegin(GL_POLYGON);
    glVertex2i(chicken_position-665.5,-450);
    glVertex2i(chicken_position-614.5,-439);
    
    glVertex2i(chicken_position-584.5,-471.5);

    glVertex2i(chicken_position-655.5,-470);
    glEnd();
//    glColor3f(0.0f, 0.0f, 0.0f);
    
    //body
    Halfcircle(80, 50, chicken_position-654.5, -450.5);
    
    //leg 1
    //leg up
    glLineWidth(4.0f);
    glBegin(GL_LINES);

    glVertex2i(chicken_position-640,-500);//middle
    glVertex2i(chicken_position-640,-521);
    glEnd();
    //leg down
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(chicken_position-640,-520);//left
    glVertex2i(chicken_position-650,-522.5);
    glEnd();

    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2i(chicken_position-640,-520);//right
    glVertex2i(chicken_position-630,-522.5);

    glVertex2i(chicken_position-640,-520);//middle
    glVertex2i(chicken_position-633.5,-526.5);
    glEnd();
    
    //leg 2
    
    //leg up
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    
    glVertex2i(chicken_position-665,-500);//middle
    glVertex2i(chicken_position-665,-518);
    glEnd();
    //leg down
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex2i(chicken_position-665,-518);//left
    glVertex2i(chicken_position-675,-520.5);
    glEnd();
    
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    glVertex2i(chicken_position-665,-518);//right
    glVertex2i(chicken_position-655,-520.5);
    
    glVertex2i(chicken_position-665,-518);//middle
    glVertex2i(chicken_position-658.5,-524.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
//    glColor3f(1.0, 1.0, 1.0 );
    glVertex2i(chicken_position-780, -440);
    glVertex2i( chicken_position-700, -460);
    glVertex2i(chicken_position-790, -445);

    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(chicken_position-780, -450);
    glVertex2i(chicken_position-700, -460);
    glVertex2i(chicken_position-790, -455);

    glEnd();
    
    glBegin(GL_TRIANGLES);
    glVertex2i(chicken_position-780, -460);
    glVertex2i(chicken_position-700, -460);
    glVertex2i(chicken_position-790, -465);

    glEnd();
}
void chickentimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(200, chickentimer, 0);
    if (chicken_position > -960) {
        chicken_position +=  2.5;
    }
}
