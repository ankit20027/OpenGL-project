#include "fun.h"
/*
all: Scene
main:
	@g++ -o test Main.cpp -lGL -lglut -lGLU
	@./test

Scene:
	@g++ Main.cpp Animals.cpp Ground.cpp Hill.cpp Sky.cpp Nature.cpp Planets.cpp utils.cpp -o Scene -lGL -lglut -lGLU	
	@./Scene

*/
float clspeed = 0.0f;
float meghposition = 0.0;
void moontimer(int);
void meghtimer(int);
void chickentimer(int);
void appletimer(int);
int state;

float axisshift = 1.0;
void init(void){
    glClearColor(0,0,0,0);
    gluOrtho2D(-960.0, 960.0, -540.0, 540.0);    
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
    Moon();
    Megh();
    Ground();
    GroundCurve();
    Soil();
    GroundDownCurve();
    Tree();
    Cin();
    drawSnow();
    glFlush();
    glutSwapBuffers();
    
}
void key_inpt(int key, int x, int y) 
{
     switch (key) 
    {    
       case 27 :      break;
       case 100 : printf("GLUT_KEY_LEFT %d\n",key); 
       		  clspeed -= 0.5f;
         	  break;
       case 102: printf("GLUT_KEY_RIGHT %d\n",key);  
                 clspeed += 0.5f;
                 break;
       case 101: printf("GLUT_KEY_UP %d\n",key);  
       	              
       	         break;
       case 103: printf("GLUT_KEY_DOWN %d\n",key);  
       		 
       		 break;
    }

}
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
    if(meghposition < -1000.0f){
    	meghposition = 960.0f;
    	clspeed = 0.5f;
    }
    else if (meghposition<960) {
        meghposition += clspeed;
    }
    else
    	meghposition  = -1000.0f;
}
int main(int argc,char **argv){
    
    glutInit(&argc,argv);
    
    glutInitDisplayMode ( GLUT_RGB | GLUT_SINGLE );
    glutInitWindowPosition(200,200);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Village");
    init();
    glutDisplayFunc(Draw);
    // glutTimerFunc(0, suntimer,0);
    glutTimerFunc(0, moontimer,0);
    glutTimerFunc(0, meghtimer, 0);
    glutTimerFunc(0, chickentimer, 0);
    glutTimerFunc(0, appletimer, 0);
    glutSpecialFunc(key_inpt);
    glutMainLoop();
    return 0;

}
