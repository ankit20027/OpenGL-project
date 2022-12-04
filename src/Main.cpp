#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>


void suntimer(int);
void moontimer(int);
void meghtimer(int);
void boattimer(int);
void ducktimer(int);
void chickentimer(int);
void appletimer(int);
int state;

float axisshift = 1.0;
void init(void){
    glClearColor(0,0,0,0);
    gluOrtho2D(-960.0, 960.0, -540.0, 540.0);
    
}
void Halfcircle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<180;i++)
    {
        angle = i * (PI/-180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void quatercircle(GLfloat rx,GLfloat ry,GLfloat x,GLfloat y)//radius_x,radius_y,certre_position_x,centre_position_y
{
    int i=0;
    float angle;
    GLfloat PI = 3.1416;
    glBegin(GL_POLYGON);
    glVertex2f(x,y);
    for(i=0;i<180;i++)
    {
        angle = i * (PI/180); //conversion from degree to radian
        glVertex2f(x+(cos(angle)*rx),y+(sin(angle)*ry));
    }
    glEnd();
}

void DrawCircle(float cx, float cy, float r, int num_segments){

    glBegin(GL_TRIANGLE_FAN);

    for (int i = 0; i < num_segments; i++)

        {

        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);//get the current angle

        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component

        glVertex2f(x + cx, y + cy);//output vertex
        }

    glEnd();

    }

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


void Hill(){
   
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 1.0, 1.0 );
    glVertex2i(70, 434.5);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(210, 280);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-70, 280);
    glEnd();
    
   //Forest Green
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2i(-35.5, 390);
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glVertex2i(150, 280);
    glVertex2i(-150, 280);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(0,128,0);
    glVertex2i(160, 390);
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glVertex2i(270, 280);
    glVertex2i(10, 280);
    glEnd();
    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(30, 405, 10, 1000);
    DrawCircle(40, 405, 10, 1000);
    DrawCircle(50, 410, 12, 1000);
    DrawCircle(60, 405, 10, 1000);
    DrawCircle(70, 410, 12, 1000);
    DrawCircle(80, 405, 10, 1000);
    DrawCircle(90, 410, 12, 1000);
    DrawCircle(100, 405, 10, 1000);
    
    DrawCircle(-20, 412.5, 8, 1000);
    DrawCircle(-10, 415, 10, 1000);
    DrawCircle(0, 412.5, 8, 1000);
    
}

void Ground(){
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(-960, 280);
    glVertex2i(960, 280);
    glVertex2i(960, 200);
    glVertex2i(-960, 200);
    glEnd();

}
void GroundCurve(){
    glColor4f(0.17, 0.43, 0.17, 1.0);
    //first curves
//    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(-930, 220, 60, 1000);
    DrawCircle(-915, 215, 60, 1000);
    DrawCircle(-900, 210, 60, 1000);
    DrawCircle(-885, 205, 60, 1000);
    DrawCircle(-870, 200, 60, 1000);
    DrawCircle(-855, 195, 60, 1000);
    DrawCircle(-850, 194, 60, 1000);
    DrawCircle(-840, 193, 60, 1000);
    DrawCircle(-825, 191, 60, 1000);
    DrawCircle(-810, 189, 60, 1000);
    DrawCircle(-795, 187, 60, 1000);
    DrawCircle(-780, 185, 60, 1000);
    DrawCircle(-780, 184, 60, 1000);
    DrawCircle(-765, 183, 60, 1000);
    DrawCircle(-760, 182, 60, 1000);
    DrawCircle(-750, 181, 60, 1000);
    DrawCircle(-735, 179, 60, 1000);
    DrawCircle(-720, 177, 60, 1000);
    DrawCircle(-705, 176, 60, 1000);
    
    DrawCircle(-690, 175, 60, 1000);
    DrawCircle(-675, 175, 60, 1000);
    DrawCircle(-660, 175, 60, 1000);
    DrawCircle(-645, 175, 60, 1000);
    DrawCircle(-630, 175, 60, 1000);
    DrawCircle(-615, 175, 60, 1000);
    DrawCircle(-600, 175, 60, 1000);
    DrawCircle(-585, 175, 60, 1000);
    DrawCircle(-570, 175, 60, 1000);
    DrawCircle(-555, 175, 60, 1000);
    DrawCircle(-540, 175, 60, 1000);
    DrawCircle(-525, 175, 60, 1000);
    DrawCircle(-510, 175, 60, 1000);
    DrawCircle(-495, 175, 60, 1000);
    DrawCircle(-480, 175, 60, 1000);
    DrawCircle(-465, 175, 60, 1000);
    DrawCircle(-450, 175, 60, 1000);
    DrawCircle(-435, 175, 60, 1000);
    DrawCircle(-420, 175, 60, 1000);
    DrawCircle(-405, 175, 60, 1000);
    DrawCircle(-390, 175, 60, 1000);
    DrawCircle(-375, 175, 60, 1000);
    DrawCircle(-360, 175, 60, 1000);
    DrawCircle(-345, 175, 60, 1000);
    DrawCircle(-330, 175, 60, 1000);
    DrawCircle(-315, 175, 60, 1000);
    
//    glColor4f(1.00, 0.75, 1.00, 1.0);
    DrawCircle(-300, 175, 60, 1000);
    DrawCircle(-299, 176, 60, 1000);
    DrawCircle(-298, 177, 60, 1000);
    DrawCircle(-297, 178, 60, 1000);
    DrawCircle(-296, 179, 60, 1000);
    DrawCircle(-295, 180, 60, 1000);
    DrawCircle(-290, 185, 60, 1000);
    DrawCircle(-285, 175, 60, 1000);
    
    
//middle curve

    DrawCircle(-200, 215, 20, 1000);
    DrawCircle(-210, 210, 20, 1000);
    DrawCircle(-220, 200, 20, 1000);
    DrawCircle(-225, 190, 20, 1000);
    DrawCircle(-230, 180, 20, 1000);
    DrawCircle(-235, 170, 20, 1000);
    DrawCircle(-240, 160, 20, 1000);
    DrawCircle(-245, 150, 20, 1000);

// last curve

    DrawCircle(530, 238, 40, 1000);
    DrawCircle(535, 237, 40, 1000);
    DrawCircle(540, 236, 40, 1000);
    DrawCircle(545, 235, 40, 1000);
    DrawCircle(550, 234, 40, 1000);
    DrawCircle(555, 233, 40, 1000);
    DrawCircle(560, 232, 40, 1000);
    DrawCircle(565, 231, 40, 1000);
    DrawCircle(570, 230, 40, 1000);
    DrawCircle(575, 230, 40, 1000);
    DrawCircle(580, 230, 40, 1000);
    DrawCircle(585, 230, 40, 1000);
    DrawCircle(590, 230, 40, 1000);
    DrawCircle(595, 230, 40, 1000);
    DrawCircle(600, 230, 40, 1000);
    DrawCircle(605, 230, 40, 1000);
    DrawCircle(610, 230, 40, 1000);
    DrawCircle(615, 230, 40, 1000);
    DrawCircle(620, 230, 40, 1000);
    DrawCircle(625, 230, 40, 1000);
    DrawCircle(630, 230, 40, 1000);
    DrawCircle(635, 230, 40, 1000);
    DrawCircle(640, 230, 40, 1000);
    DrawCircle(645, 230, 40, 1000);
    DrawCircle(650, 230, 40, 1000);
    DrawCircle(655, 230, 40, 1000);
    DrawCircle(660, 230, 40, 1000);
    DrawCircle(665, 230, 40, 1000);
    DrawCircle(670, 230, 40, 1000);
    DrawCircle(675, 230, 40, 1000);
    DrawCircle(680, 230, 40, 1000);
    DrawCircle(685, 230, 40, 1000);
    DrawCircle(690, 230, 40, 1000);
    DrawCircle(695, 230, 40, 1000);
    DrawCircle(700, 230, 40, 1000);
    DrawCircle(705, 230, 40, 1000);
    DrawCircle(710, 230, 40, 1000);
    DrawCircle(715, 230, 40, 1000);
    DrawCircle(720, 230, 40, 1000);
    DrawCircle(725, 230, 40, 1000);
    DrawCircle(730, 230, 40, 1000);
    DrawCircle(735, 230, 40, 1000);
    DrawCircle(740, 230, 40, 1000);
    DrawCircle(745, 230, 40, 1000);
    DrawCircle(750, 230, 40, 1000);
    DrawCircle(755, 230, 40, 1000);
    DrawCircle(760, 230, 40, 1000);
    DrawCircle(765, 230, 40, 1000);
    
//    glColor4f(5.00, 1.75, 1.00, 1.0);
    DrawCircle(770, 228, 40, 1000);
    DrawCircle(773, 228, 40, 1000);
    DrawCircle(775, 228, 40, 1000);
    DrawCircle(778, 228, 40, 1000);
    DrawCircle(780, 228, 40, 1000);
    DrawCircle(783, 228, 40, 1000);
    DrawCircle(785, 228, 40, 1000);
    DrawCircle(788, 228, 40, 1000);
    DrawCircle(790, 228, 40, 1000);
    DrawCircle(793, 228, 40, 1000);
    DrawCircle(795, 228, 40, 1000);
    DrawCircle(798, 228, 40, 1000);
    DrawCircle(800, 228, 40, 1000);
    
//    glColor4f(1.00, 0.75, 1.00, 1.0);
    DrawCircle(805, 228, 40, 1000);
    DrawCircle(810, 228, 40, 1000);
    DrawCircle(815, 228, 40, 1000);
    DrawCircle(820, 228, 40, 1000);
    DrawCircle(825, 228, 40, 1000);
    DrawCircle(830, 228, 40, 1000);
    DrawCircle(835, 228, 40, 1000);
    DrawCircle(840, 228, 40, 1000);
    DrawCircle(845, 228, 40, 1000);
    DrawCircle(850, 228, 40, 1000);
    DrawCircle(855, 228, 40, 1000);
    DrawCircle(860, 228, 40, 1000);
    DrawCircle(865, 228, 40, 1000);
    
//    glColor4f(1.00, 0.75, 1.00, 1.0);
    DrawCircle(870, 229, 40, 1000);
    DrawCircle(871, 227, 40, 1000);
    DrawCircle(872, 227, 40, 1000);
    DrawCircle(873, 227, 40, 1000);
    DrawCircle(874, 227, 40, 1000);
    DrawCircle(875, 227, 40, 1000);
    DrawCircle(880, 227, 40, 1000);
    DrawCircle(885, 226, 40, 1000);
    DrawCircle(890, 225, 40, 1000);
    DrawCircle(895, 224, 40, 1000);
    DrawCircle(900, 223, 40, 1000);
    DrawCircle(905, 222, 40, 1000);
    DrawCircle(910, 221, 40, 1000);
    DrawCircle(915, 220, 40, 1000);
    DrawCircle(920, 219, 40, 1000);
    DrawCircle(925, 218, 40, 1000);
    DrawCircle(930, 217, 40, 1000);
    DrawCircle(935, 216, 40, 1000);
    DrawCircle(936, 216, 40, 1000);
    DrawCircle(937, 216, 40, 1000);
    DrawCircle(938, 216, 40, 1000);
    DrawCircle(939, 216, 40, 1000);
    DrawCircle(940, 215, 40, 1000);
    DrawCircle(945, 215, 40, 1000);
    DrawCircle(950, 215, 40, 1000);
    DrawCircle(955, 215, 40, 1000);
    DrawCircle(960, 215, 40, 1000);
    DrawCircle(965, 215, 40, 1000);
   

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
void GroundDownCurve(){
    glColor4f(0.17, 0.43, 0.17, 1.0);
//    DrawCircle(-950, -259, 60, 200);

    
    //first curves

    DrawCircle(-960, -259, 60, 1000);
    
    DrawCircle(-940, -264, 60, 1000);
    DrawCircle(-920, -269, 60, 1000);
    DrawCircle(-900, -274, 60, 1000);
    DrawCircle(-880, -279, 60, 1000);
    DrawCircle(-860, -284, 60, 1000);
    DrawCircle(-840, -289, 60, 1000);
    DrawCircle(-820, -294, 60, 1000);
    
    DrawCircle(-815, -296, 60, 1000);
    DrawCircle(-810, -297, 60, 1000);
    DrawCircle(-805, -298, 60, 1000);
    
    DrawCircle(-800, -299, 60, 1000);
    DrawCircle(-780, -299, 60, 1000);
    DrawCircle(-760, -299, 60, 1000);
    DrawCircle(-740, -299, 60, 1000);
    DrawCircle(-720, -299, 60, 1000);
    DrawCircle(-700, -299, 60, 1000);
    
    DrawCircle(-680, -299, 60, 1000);
    DrawCircle(-660, -299, 60, 1000);
    DrawCircle(-640, -299, 60, 1000);
    DrawCircle(-620, -299, 60, 1000);
    DrawCircle(-600, -299, 60, 1000);
    
    DrawCircle(-595, -297, 60, 1000);
    DrawCircle(-590, -296, 60, 1000);
    DrawCircle(-585, -295, 60, 1000);
    
    DrawCircle(-580, -294, 60, 1000);
    
    
    // first soil
    glColor4f(0.97, 0.70, 0.44, 1.0);
//    DrawCircle(-560, -245, 40, 1000);
    DrawCircle(-535, -240, 40, 1000);
    DrawCircle(-520, -230, 40, 1000);
    DrawCircle(-500, -225, 40, 1000);
    DrawCircle(-480, -220, 40, 1000);
    DrawCircle(-455, -215, 40, 1000);
    
//    glColor4f(5.0, 0.43, 0.17, 1.0);
    glColor4f(0.17, 0.43, 0.17, 1.0);
    glBegin(GL_QUADS);

    glVertex2i(-500, -294);

    glVertex2i(-250, -250);

    glVertex2i(-249, -310);

    glVertex2i(-589, -359);

    
//    glColor4f(1.00, 0.75, 1.00, 1.0);
    DrawCircle(-570, -289, 60, 1000);
    DrawCircle(-520, -259, 60, 1000);
    DrawCircle(-500, -254, 60, 1000);
    DrawCircle(-480, -249, 60, 1000);
    DrawCircle(-460, -244, 60, 1000);
    DrawCircle(-440, -239, 60, 1000);
    DrawCircle(-430, -234, 60, 1000);
    
    DrawCircle(-410, -234, 60, 1000);
    DrawCircle(-390, -234, 60, 1000);
    DrawCircle(-370, -234, 60, 1000);
    DrawCircle(-350, -234, 60, 1000);
    DrawCircle(-330, -234, 60, 1000);
    DrawCircle(-310, -234, 60, 1000);
    DrawCircle(-290, -234, 60, 1000);
    
    DrawCircle(-280, -239, 60, 1000);
    DrawCircle(-275, -241, 60, 1000);
    DrawCircle(-270, -244, 60, 1000);
    DrawCircle(-265, -247, 60, 1000);
    DrawCircle(-260, -249, 60, 1000);

//        glColor4f(0.17, 0.43, 0.17, 1.0);
    glBegin(GL_QUADS);

    glVertex2i(400, -174);

    glVertex2i(-279, -174);

    glVertex2i(-249, -310);

    glVertex2i(400, -310);
    DrawCircle(-260, -249, 60, 1000);


// last curve
    DrawCircle(410, -205, 40, 1000);
    DrawCircle(430, -200, 40, 1000);
    DrawCircle(450, -195, 40, 1000);
    DrawCircle(470, -190, 40, 1000);
    DrawCircle(490, -185, 40, 1000);
    DrawCircle(510, -180, 40, 1000);
    DrawCircle(530, -175, 40, 1000);
    DrawCircle(550, -170, 40, 1000);
    DrawCircle(570, -165, 40, 1000);
    DrawCircle(400, -269, 40, 1000);
    DrawCircle(410, -259, 40, 1000);
    DrawCircle(420, -249, 40, 1000);
    DrawCircle(450, -219, 40, 1000);
    DrawCircle(470, -204, 40, 1000);
    DrawCircle(490, -199, 40, 1000);
    DrawCircle(510, -194, 40, 1000);
    DrawCircle(530, -189, 40, 1000);
    DrawCircle(550, -184, 40, 1000);
    DrawCircle(570, -179, 40, 1000);
    
    DrawCircle(570, -165, 40, 1000);
    DrawCircle(575, -165, 40, 1000);
    DrawCircle(580, -165, 40, 1000);
    DrawCircle(585, -165, 40, 1000);
    DrawCircle(590, -165, 40, 1000);
    DrawCircle(595, -165, 40, 1000);
    DrawCircle(600, -165, 40, 1000);
    DrawCircle(605, -165, 40, 1000);
    DrawCircle(610, -165, 40, 1000);
    DrawCircle(615, -165, 40, 1000);
    DrawCircle(620, -165, 40, 1000);
    DrawCircle(625, -165, 40, 1000);
    DrawCircle(630, -165, 40, 1000);
    DrawCircle(635, -165, 40, 1000);
    DrawCircle(640, -165, 40, 1000);
    DrawCircle(645, -165, 40, 1000);
    DrawCircle(650, -165, 40, 1000);
    DrawCircle(655, -165, 40, 1000);
    DrawCircle(660, -165, 40, 1000);
    DrawCircle(665, -165, 40, 1000);
    DrawCircle(670, -165, 40, 1000);
    DrawCircle(675, -165, 40, 1000);
    DrawCircle(680, -165, 40, 1000);
    DrawCircle(685, -165, 40, 1000);
    DrawCircle(690, -165, 40, 1000);
    DrawCircle(695, -165, 40, 1000);
    DrawCircle(700, -165, 40, 1000);
    DrawCircle(705, -165, 40, 1000);
    DrawCircle(710, -165, 40, 1000);
    DrawCircle(715, -165, 40, 1000);
    DrawCircle(720, -165, 40, 1000);
    DrawCircle(725, -165, 40, 1000);
    DrawCircle(730, -165, 40, 1000);
    DrawCircle(735, -165, 40, 1000);
    DrawCircle(740, -165, 40, 1000);
    DrawCircle(745, -165, 40, 1000);
    DrawCircle(750, -165, 40, 1000);
    DrawCircle(755, -165, 40, 1000);
    DrawCircle(760, -165, 40, 1000);
    DrawCircle(765, -165, 40, 1000);
//
//    glColor4f(5.00, 1.75, 1.00, 1.0);
    DrawCircle(770, -165, 40, 1000);
    DrawCircle(773, -164, 40, 1000);
    DrawCircle(775, -163, 40, 1000);
    DrawCircle(778, -162, 40, 1000);
    DrawCircle(780, -161, 40, 1000);
    DrawCircle(783, -159, 40, 1000);
    DrawCircle(785, -158, 40, 1000);
    DrawCircle(788, -157, 40, 1000);
    DrawCircle(790, -156, 40, 1000);
    DrawCircle(793, -155, 40, 1000);
    DrawCircle(795, -154, 40, 1000);
    DrawCircle(798, -153, 40, 1000);
    DrawCircle(800, -152, 40, 1000);
//
//    glColor4f(1.00, 0.75, 1.00, 1.0);
    DrawCircle(805, -152, 40, 1000);
    DrawCircle(810, -152, 40, 1000);
    DrawCircle(815, -152, 40, 1000);
    DrawCircle(820, -152, 40, 1000);
    DrawCircle(825, -152, 40, 1000);
    DrawCircle(830, -152, 40, 1000);
    DrawCircle(835, -152, 40, 1000);
    DrawCircle(840, -152, 40, 1000);
    DrawCircle(845, -152, 40, 1000);
    DrawCircle(850, -152, 40, 1000);
    DrawCircle(855, -152, 40, 1000);
    DrawCircle(860, -152, 40, 1000);
    DrawCircle(865, -152, 40, 1000);

//    glColor4f(8.00, 0.75, 1.00, 1.0);
    DrawCircle(870, -152, 40, 1000);
    DrawCircle(871, -152, 40, 1000);
    DrawCircle(872, -152, 40, 1000);
    DrawCircle(873, -152, 40, 1000);
    DrawCircle(874, -152, 40, 1000);
    DrawCircle(875, -152, 40, 1000);
    DrawCircle(880, -152, 40, 1000);
    
    DrawCircle(885, -151, 40, 1000);
    DrawCircle(890, -150, 40, 1000);
    DrawCircle(895, -149, 40, 1000);
    DrawCircle(900, -148, 40, 1000);
    DrawCircle(905, -147, 40, 1000);
    DrawCircle(910, -146, 40, 1000);
    DrawCircle(915, -145, 40, 1000);
    DrawCircle(920, -144, 40, 1000);
    DrawCircle(925, -143, 40, 1000);
    DrawCircle(930, -142, 40, 1000);
    
    DrawCircle(935, -141, 40, 1000);
    DrawCircle(936, -141, 40, 1000);
    DrawCircle(937, -141, 40, 1000);
    DrawCircle(938, -141, 40, 1000);
    DrawCircle(939, -141, 40, 1000);
    DrawCircle(940, -140, 40, 1000);
    DrawCircle(945, -140, 40, 1000);
    DrawCircle(950, -140, 40, 1000);
    DrawCircle(955, -140, 40, 1000);
    DrawCircle(960, -140, 40, 1000);
    DrawCircle(965, -140, 40, 1000);

    glEnd();
}

void River(){
    glBegin(GL_QUADS);
    
    //dark blue color
    glColor3ub(65,105,225);

    glVertex2i(-960, 200);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(960, 200);
    //light blue color
        glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(960, -300);
    glColor4f(0.00, 0.75, 1.00, 1.0);
    glVertex2i(-960, -300);
    
    glEnd();
}

void Soil(){
   
    glBegin(GL_QUADS);
    glColor4f(0.97, 0.70, 0.44, 1.0);
    glVertex2i(-960, -300);
    glVertex2i(960, -150);
    glVertex2i(960, -540);
    glVertex2i(-960, -540);
    glEnd();
    
}

float sun_position = 470;
void Sun(){

    glColor3d(255,255,0);
    DrawCircle(400, sun_position, 50, 1000);

}
float moon_position = 710;
void Moon()
{

    glColor3f(1.0, 1.0, 1.0 );
    DrawCircle(400, moon_position, 50, 1000);
    
}


float boat_position = 0.0;
void Boat(){

    //boat up side
//sail
    glBegin(GL_QUADS);
    glColor3ub(255,99,71);
    glVertex2i(boat_position-720, 200);
    glVertex2i(boat_position-500, 200);
    glVertex2i(boat_position-580, 50);
    glVertex2i(boat_position-720, 50);
    //boat roof
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(139,69,19);
    glVertex2i(boat_position-800, 50);
    glVertex2i(boat_position-500, 50);
    glVertex2i(boat_position-450, -20);
    glVertex2i(boat_position-750, -20);
    glEnd();
    //boat roof traingle
    glBegin(GL_TRIANGLES);
    glColor3ub(0,0,0);
    glVertex2i(boat_position-800, 50);
    glVertex2i(boat_position-750, -20);
    glVertex2i(boat_position-850, -20);

    glEnd();
    
//boat down side
    glColor3ub(0,0,0);//Forest Green

    glBegin(GL_QUADS);

    glVertex2i(boat_position-900, -20);

    glVertex2i(boat_position-400, -20);
    glVertex2i(boat_position-500, -80);

    glVertex2i(boat_position-800, -80);

    glEnd();

    

}


void Grass(){
//    glColor4f(0.17, 0.43, 0.17, 1.0);
    glColor3ub(0,128,0);
    DrawCircle(-950, 285, 20, 200);
    DrawCircle(-910, 290, 30, 200);
    DrawCircle(-870, 290, 30, 200);
    DrawCircle(-830, 285, 25, 200);
    DrawCircle(-790, 285, 20, 200);
    DrawCircle(-750, 290, 30, 200);
    DrawCircle(-710, 290, 30, 200);
    DrawCircle(-670, 285, 20, 200);
    DrawCircle(-630, 290, 30, 200);
    DrawCircle(-590, 285, 25, 200);
    DrawCircle(-550, 285, 20, 200);
    DrawCircle(-520, 285, 15, 200);
    DrawCircle(-490, 285, 20, 200);
    DrawCircle(-450, 290, 30, 200);
    DrawCircle(-410, 290, 30, 200);
    
    DrawCircle(-370, 285, 20, 200);
    DrawCircle(-330, 290, 30, 200);
    DrawCircle(-290, 290, 30, 200);
    DrawCircle(-250, 285, 25, 200);
    DrawCircle(-210, 285, 20, 200);
    DrawCircle(-170, 290, 30, 200);
    DrawCircle(-130, 290, 30, 200);
    DrawCircle(-90, 285, 20, 200);
    DrawCircle(-50, 290, 30, 200);
    DrawCircle(-10, 285, 25, 200);
    DrawCircle(30, 285, 20, 200);
    DrawCircle(60, 285, 15, 200);
    DrawCircle(100, 285, 20, 200);
    DrawCircle(140, 290, 30, 200);
    DrawCircle(180, 290, 30, 200);
    
    
    DrawCircle(220, 285, 20, 200);
    DrawCircle(260, 290, 30, 200);
    DrawCircle(300, 290, 30, 200);
    DrawCircle(340, 285, 25, 200);
    DrawCircle(380, 285, 20, 200);
    DrawCircle(420, 290, 30, 200);
    DrawCircle(460, 290, 30, 200);
    DrawCircle(500, 285, 20, 200);
    DrawCircle(540, 290, 30, 200);
    DrawCircle(580, 285, 25, 200);
    DrawCircle(620, 285, 20, 200);
    DrawCircle(640, 285, 15, 200);
    DrawCircle(660, 285, 20, 200);
    DrawCircle(700, 290, 30, 200);
    DrawCircle(740, 290, 30, 200);
    DrawCircle(780, 290, 30, 200);
    
    DrawCircle(800, 285, 20, 200);
    DrawCircle(840, 290, 30, 200);
    DrawCircle(880, 290, 30, 200);
    DrawCircle(920, 285, 25, 200);
    DrawCircle(960, 285, 20, 200);
    DrawCircle(1000, 290, 30, 200);

}
float apple_position = 0.0;
void Tree(){
//top side
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(750.5,50.5);
    glVertex2f(630.5,120.5);
    glVertex2f(630.5,70.5);
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19.5);
    glVertex2f(750.5,50.5);
    glVertex2f(800.5,1.5);
    glVertex2f(850.5,90.5);
    glVertex2f(850.5,130.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(750.5,50.5);
    glVertex2f(800.5,1.5);
    glEnd();
    
    //middle side
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2f(700.5,1.5);
    glVertex2f(700.5,-400.5);
    glVertex2f(750.5,-450.5);
    glVertex2f(800.5,-400.5);
    glVertex2f(800.5,1.5);
    glEnd();
    
    glBegin(GL_TRIANGLES);
    glColor3ub(139,69,19);
    glVertex2f(600,-30);
    glVertex2f(700.5,-100);
    glVertex2f(700.5,-50);
    glEnd();

    //down side
        glBegin(GL_POLYGON);
        glColor3ub(139,69,19);
        glVertex2f(700.5,-400.5);
        glVertex2f(800.5,-400.5);
        glVertex2f(850.5,-425.5);
        glVertex2f(650.5,-425.5);
        glEnd();

    
    //tree leaf
    glColor3ub(50,205,50);
    DrawCircle(600, 50, 70, 1000);
    DrawCircle(650, 150, 90, 1000);
    DrawCircle(550, 130, 90, 1000);
    
    DrawCircle(850, 200, 90, 1000);
    DrawCircle(700, 210, 100, 1000);
    
    DrawCircle(900, 50, 70, 1000);
    DrawCircle(950, 150, 90, 1000);
    DrawCircle(850, 130, 90, 1000);
    
    //apple
    glColor3ub (139,0,0);
    DrawCircle(900,207,20,1000);
    DrawCircle(900,80,20,1000);
    DrawCircle(800,200,20,1000);
    DrawCircle(800,100,20,1000);
    DrawCircle(700,apple_position +250,20,1000);
    DrawCircle(700,180,20,1000);
    DrawCircle(550,195,20,1000);
    
    DrawCircle(500 ,apple_position + 107,20,1000);
    
    DrawCircle(650,107,20,1000);
    DrawCircle(600,20,20,1000);

    
}

void House(){
    
    //down side
    
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);
    glVertex2i(300.0,-500.0);
    glVertex2i(300,-530.5);
    glVertex2i(950,-530.5);
    glVertex2i(900,-500.0);

    glEnd();
    
    
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(139,69,19);
    glVertex2i(50,-400.0);
    glVertex2i(20,-425.5);

    glVertex2i(300,-530.5);
    glVertex2i(300,-500.0);

    glEnd();
    
    // middle left side
    
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(205,133,63);
    glVertex2i(175,-150);
    
    glVertex2i(50,-250.0);
    glVertex2i(50,-400.0);
    
    glVertex2i(300,-500.0);
    glVertex2i(300,-250.0);
    glEnd();
    
    //window
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128,135,32);
    glVertex2i(200,-355.0);
    glVertex2i(200,-300.0);
    glVertex2i(130,-300.0);
    glVertex2i(130,-350.0);

    glEnd();
    
    
    //middle front side
    
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(184,134,11);
    glVertex2i(900,-500.0);
    glVertex2i(900,-250.0);
    glVertex2i(300,-250.0);
    glVertex2i(300,-500.0);


    glEnd();
    
    //door
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(0,0,0);
    glVertex2i(650,-500.0);
    glVertex2i(650,-350.0);
    glVertex2i(550,-350.0);
    glVertex2i(550,-500.0);

    glEnd();
    
    //door left side
    
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
    glColor3ub(128,135,32);
    glVertex2i(597.5,-480.0);
    glVertex2i(597.5,-380.0);
    glVertex2i(550,-350.0);
    glVertex2i(550,-500.0);

    glEnd();
    
    
    //door right side
    glBegin(GL_POLYGON);
    glColor3ub(128,135,32);
    glVertex2i(650,-500.0);
    glVertex2i(650,-350.0);
    
    glVertex2i(602.5,-380.0);
    glVertex2i(602.5,-480.0);

    glEnd();
    
    // up side front
    
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2i(950,-300.0);
    glVertex2i(800,-150.0);
    glVertex2i(170,-150.0);
    glVertex2i(350,-300.0);

    glEnd();

    //up side back
    glBegin(GL_POLYGON);
    glColor3ub(139,69,19);
    glVertex2i(50,-250.0);
    glVertex2i(220,-150.0);
    glVertex2i(170,-150.0);
    glVertex2i(0,-250.0);
    
    glEnd();
    
    
}

void Bush(){
    
    //bush 1
    glColor3ub (0,100,0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex2i(900,-140);//middle
    glVertex2i(900,-107);
    glVertex2i(900,-140);//left
    glVertex2i(875,-120);
    glVertex2i(900,-140);//right
    glVertex2i(925,-120);
    glVertex2i(900,-140);//ground left
    glVertex2i(875,-141);
    glVertex2i(900,-140);//ground right
    glVertex2i(925,-141);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(900,-107,5,1000);
    DrawCircle(875,-120,5,1000);
    DrawCircle(925,-120,5,1000);
    glEnd();
    
    
    //bush 2
    
    glColor3ub (0,100,0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex2i(600,-140);//middle
    glVertex2i(600,-107);
    glVertex2i(600,-140);//left
    glVertex2i(575,-120);
    glVertex2i(600,-140);//right
    glVertex2i(625,-120);
    glVertex2i(600,-140);//ground left
    glVertex2i(575,-141);
    glVertex2i(600,-140);//ground right
    glVertex2i(625,-141);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(600,-107,5,1000);
    DrawCircle(575,-120,5,1000);
    DrawCircle(625,-120,5,1000);
    glEnd();
    
//    bush 3
    glColor3ub (0,100,0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex2i(-900,-240);//middle
    glVertex2i(-900,-207);
    glVertex2i(-900,-240);//left
    glVertex2i(-875,-220);
    glVertex2i(-900,-240);//right
    glVertex2i(-925,-220);
    glVertex2i(-900,-240);//ground left
    glVertex2i(-875,-241);
    glVertex2i(-900,-240);//ground right
    glVertex2i(-925,-241);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(-900,-207,5,1000);
    DrawCircle(-875,-220,5,1000);
    DrawCircle(-925,-220,5,1000);
    glEnd();
    
    //bush 4
    glColor3ub (0,100,0);
    glLineWidth(2.0f);
    glBegin(GL_LINES);

    glVertex2i(-500,-210);//middle
    glVertex2i(-500,-177);
    glVertex2i(-500,-210);//left
    glVertex2i(-475,-190);
    glVertex2i(-500,-210);//right
    glVertex2i(-525,-190);
    glVertex2i(-500,-210);//ground left
    glVertex2i(-475,-211);
    glVertex2i(-500,-210);//ground right
    glVertex2i(-525,-211);
    glEnd();
    glColor3ub (139,0,0);
    DrawCircle(-500,-177,5,1000);
    DrawCircle(-475,-190,5,1000);
    DrawCircle(-525,-190,5,1000);
    glEnd();
    
}
float duck_position = 0.0;

void WaterDuck(){
    //head
    glColor3ub(139,69,19);//brown
    DrawCircle(duck_position-580, -105, 20, 1000);
    glColor3f(0.0f, 0.0f, 0.0f);//Black
    DrawCircle(duck_position-580, -100, 4, 1000);
    // lips
//    glColor3ub (0,100,0);
    glColor3ub(139,69,19);//brown
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    //up
    glVertex2i(duck_position-563,-104);
    glVertex2i(duck_position-549,-109);
    //down
    glVertex2i(duck_position-563,-109);
    glVertex2i(duck_position-549,-109);
    glEnd();
//gola
    glBegin(GL_POLYGON);
    glVertex2i(duck_position-600.5,-95);
    glVertex2i(duck_position-564.5,-105);
    glVertex2i(duck_position-574.5,-141.5);
    glVertex2i(duck_position-605.5,-131.5);
    glEnd();
    DrawCircle(duck_position-594.5, -150, 22, 1000);
    
    glBegin(GL_POLYGON);
    glVertex2i(duck_position-665.5,-150);
    glVertex2i(duck_position-614.5,-139);
    
    glVertex2i(duck_position-584.5,-171.5);

    glVertex2i(duck_position-655.5,-170);
    glEnd();
//    glColor3f(0.0f, 0.0f, 0.0f);
    
    //body
    Halfcircle(80, 40, duck_position-654.5, -150.5);
}
float chicken_position = 0.0 ;
void Chichen(){
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
void Cin(){
    glColor3ub(139,69,19);
    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(100,-50);//middle
    glVertex2i(100,-400);
    glEnd();
    glColor3ub(184,134,11);
    quatercircle(220, 300, 100, -370.5);
    
    glColor3ub(139,69,19);
    glLineWidth(20.0f);
    glBegin(GL_LINES);
    glVertex2i(-135,-370);//middle
    glVertex2i(320,-370);
    glEnd();
}


void Draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    Sky();
    Hill();
    Sun();
    Moon();
    Grass();
    Megh();
    Ground();
    River();
    WaterDuck();
    GroundCurve();
    Soil();
    GroundDownCurve();
    Boat();
    Tree();
    Cin();
    House();
    Bush();
    Chichen();


    glFlush();
    glutSwapBuffers();
    
}

void moontimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, moontimer, 0);
    if (moon_position>240) {
        moon_position -=1;

    }
}

void suntimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, suntimer, 0);
    if (sun_position>240) {
        sun_position -=1;
    }
}
void meghtimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/60, meghtimer, 0);

    if (meghposition<960) {
        meghposition +=1.5;
    }
}


void chickentimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(200, chickentimer, 0);
    if (chicken_position>-960) {
        chicken_position +=2.5;
    }
}

void boattimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(0, boattimer, 0);
    if (boat_position>-960) {
        boat_position +=5;
    }
}

void ducktimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(100, ducktimer, 0);
    if (duck_position>-960) {
        duck_position +=2;
    }
}

void appletimer(int)
{
    glutPostRedisplay();
    glutTimerFunc(100, appletimer, 0);
    if (apple_position<300) {
        apple_position -=50;
    }
}


int main(int argc,char **argv){
    
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Village");
    init();
    glutDisplayFunc(Draw);
    glutTimerFunc(0, suntimer,0);
    glutTimerFunc(0, moontimer,0);
    glutTimerFunc(0, meghtimer, 0);
    glutTimerFunc(0, boattimer, 0);
    glutTimerFunc(0, ducktimer, 0);
    glutTimerFunc(0, chickentimer, 0);
    glutTimerFunc(0, appletimer, 0);
    glutMainLoop();
    return 0;

}


