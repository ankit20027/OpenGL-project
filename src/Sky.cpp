#include "fun.h"

void Sky(){
    glBegin(GL_QUADS);
    
    //dark blue color
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-960, 540);
    glVertex2i(960, 540);
    //light blue color
    glColor4f(0.53, 0.81, 0.98, 1.0);
    glVertex2i(960, 280);
    glVertex2i(-960, 280);
    
    glEnd();
}

float meghposition = 0.0;
void Megh(){

    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(meghposition+45, 450, 30, 200);
    DrawCircle(meghposition+45, 450, 30, 200);
    DrawCircle(meghposition+80, 465, 30, 200);
    DrawCircle(meghposition+120, 450, 30, 200);
    DrawCircle(meghposition+80, 450, 30, 200);
    
    DrawCircle(meghposition+225, 430, 20, 200);
    DrawCircle(meghposition+250, 440, 25, 200);
    DrawCircle(meghposition+275, 430, 20, 200);
    DrawCircle(meghposition+240, 418, 15, 200);
    DrawCircle(meghposition+260, 417, 15, 200);

    DrawCircle(meghposition+400, 450, 30, 200);
    DrawCircle(meghposition+440, 470, 30, 200);
    DrawCircle(meghposition+480, 450, 30, 200);
    DrawCircle(meghposition+440, 435, 25, 200);
    DrawCircle(meghposition+80, 450, 30, 200);
}
void meghtimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, meghtimer, 0);

    if (meghposition<960) {
        meghposition +=1.5;
    }
}
