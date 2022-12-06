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
    // Sun();
    Moon();
    // Grass();
    Megh();
    Ground();
    // River();
    // WaterDuck();
    GroundCurve();
    Soil();
    GroundDownCurve();
    // Boat();
    Tree();
    Cin();
    // House();
    // Bush();
    Chicken();
    glFlush();
    glutSwapBuffers();
    
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
    glutMainLoop();
    return 0;

}
