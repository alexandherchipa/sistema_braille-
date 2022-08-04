/*#ifdef __APPLE__
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <GLUT/glut.h>
#else
# include <GL/gl.h>
# include <GL/glu.h>
# include <GL/glut.h>
#endif*/
# include <iostream>
# include "GL/glut.h"
# include <cmath>


using namespace std;
int ancho=1200, alto=600,tu=-1;
char CL[12]{"Como se Lee"};
char CE[16]{"Como se Escribe"};
char PR[8]{"BRAILE"};
char EX[25]{"Presione esc para salir."};
char A[2]{ 'A' };
char B[2]{ 'B' };
char C[2]{ 'C' };
char D[2]{ 'D' };
char E[2]{ 'E' };
char F[2]{ 'F' };
char G[2]{ 'G' };
char H[2]{ 'H' };
char I[2]{ 'I' };
char J[2]{ 'J' };
char K[2]{ 'K' };
char L[2]{ 'L' };
char M[2]{ 'M' };
char N[2]{ 'N' };
char O[2]{ 'O' };
char P[2]{ 'P' };
char Q[2]{ 'Q' };
char R[2]{ 'R' };
char S[2]{ 'S' };
char T[2]{ 'T' };
char U[2]{ 'U' };
char V[2]{ 'V' };
char W[2]{ 'W' };
char X[2]{ 'X' };
char Y[2]{ 'Y' };
char Z[2]{ 'Z' };
void inline drawString(char* CE) {
	unsigned int i;
	for(i=0;i< strlen(CE);i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,CE[i]);
	}
}

void escribeletra(){
	glRasterPos3f(-585,260,0);
	drawString(EX);
	glRasterPos3f(-50,200,0);
	drawString(PR);
	glRasterPos3f(300,110,0);
	drawString(CL);
	glRasterPos3f(-450,110,0);
	drawString(CE);
	glRasterPos3f(0,30,0);
	if(tu == 0){
		drawString(A);
	}else if(tu == 1){
		drawString(B);
	}else if(tu == 2){
		drawString(C);
	}else if(tu == 3){
		drawString(D);
	}else if(tu == 4){
		drawString(E);
	}else if(tu == 5){
		drawString(F);
	}else if(tu == 6){
		drawString(G);
	}else if(tu == 7){
		drawString(H);
	}else if(tu == 8){
		drawString(I);
	}else if(tu == 9){
		drawString(J);
	}else if(tu == 10){
		drawString(K);
	}else if(tu == 11){
		drawString(L);
	}else if(tu == 12){
		drawString(M);
	}else if(tu == 13){
		drawString(N);
	}else if(tu == 14){
		drawString(O);
	}else if(tu == 15){
		drawString(P);
	}else if(tu == 16){
		drawString(Q);
	}else if(tu == 17){
		drawString(R);
	}else if(tu == 18){
		drawString(S);
	}else if(tu == 19){
		drawString(T);
	}else if(tu == 20){
		drawString(U);
	}else if(tu == 21){
		drawString(V);
	}else if(tu == 22){
		drawString(W);
	}else if(tu == 23){
		drawString(X);
	}else if(tu == 24){
		drawString(Y);
	}else if(tu == 25){
		drawString(Z);
	}
}
void PintaPixel(int x,int y, float r,float g,float b){//Funcion pinta pincel
	glPointSize(2);//Tamañó del pixel
	glColor3f(r,g,b);
	glBegin(GL_POINTS);//Funcion de graficacion de OpenGL
	glVertex2f(x,y);//Coordenadas
	glEnd();//Fin de la funcion graficacion
	//glFlush();
 }
void PintaLinea(int x1,int x2,int y1, int y2, int r, int g,int b){
	glColor3f(r,g,b);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2d(x1,x2);
	glVertex2d(y1,y2);
	glEnd();
	glFlush();
}
void circunferencia(int xc, int yc, int xp, int yp, int center, int p, int r, int g, int b){
	if(center >=0 && p>=0){//condicional para entrar al metodo
		int rad=20,dx,dy,x=0,y;//variable de la funcion
		float det;
		dx= abs(xp-xc);//Hallar el valor del delta x
		dy= abs(yp-yc);//Hallar el valor del delta x
		rad= sqrt(pow(dx, 2)+pow(dy,2));
		det =5/4-rad;
		y=rad;
		while(x<=y){
			PintaPixel(x+xc,y+yc,r,g,b);//grafica el primer octante
			PintaPixel(x+xc,-y+yc,r,g,b);//grafica el segundo octante
			PintaPixel(-x+xc,y+yc,r,g,b);//grafica el tercer octante
			PintaPixel(-x+xc,-y+yc,r,g,b);//grafica el cuarto octante
			PintaPixel(y+xc,x+yc,r,g,b);//grafica el quinto octante
			PintaPixel(y+xc,-x+yc,r,g,b);//grafica el sexto octante
			PintaPixel(-y+xc,x+yc,r,g,b);//grafica el setimo octante
			PintaPixel(-y+xc,-x+yc,r,g,b);//grafica el octavo octante
			x++;//sumar al contador;
			if (det <= 0)//condicion
				det += 2* x + 1;//actializar det
			else{//si no
				y--;//disminuir y;
				det +=(2*x)-(2*y)+1;//actualizar y
			}
		}
	}
	
	glFlush();
}
void recuadros(){
	PintaLinea(-480,-262,-260,-262,0,1,0);
	PintaLinea(-480,92,-480,-264,0,1,0);
	PintaLinea(-482,92,-260,92,0,1,0);
	PintaLinea(-260,92,-260,-264,0,1,0);
	
	PintaLinea(480,-262,260,-262,1,0,0);
	PintaLinea(480,92,480,-264,1,0,0);
	PintaLinea(482,92,260,92,1,0,0);
	PintaLinea(260,92,260,-264,1,0,0);
}
void circulos(){
	circunferencia(420,30,390,50,1,1,1,0,0);//D(1)se llama a la funcion para dibujar el circulo
	circunferencia(420,-80,390,-60,1,1,1,0,0);//D(2)
	circunferencia(420,-190,390,-170,1,1,1,0,0);//D(3)
	circunferencia(320,30,290,50,1,1,1,0,0);//D(4)
	circunferencia(320,-80,290,-60,1,1,1,0,0);//D(5)
	circunferencia(320,-190,290,-170,1,1,1,0,0);//D(6)
	
	circunferencia(-420,30,-390,50,1,1,0,1,0);//I(7)se llama a la funcion para dibujar el circulo
	circunferencia(-420,-80,-390,-60,1,1,0,1,0);//I(8)
	circunferencia(-420,-190,-390,-170,1,1,0,1,0);//I(9)
	circunferencia(-320,30,-290,50,1,1,0,1,0);//I(10)
	circunferencia(-320,-80,-290,-60,1,1,0,1,0);//I(11)
	circunferencia(-320,-190,-290,-170,1,1,0,1,0);//I(12)
}
void figurabase(){
	escribeletra();
	circulos();
	recuadros();
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);//limpia la pantalla
	glColor3f(0.25,0.866,0.77);
	glFlush();
	escribeletra();
	circulos();
	recuadros();
}
void rellenocirculo1(){
	for(float a=390; a<=419;a++){
		for(float b=50;b>=29;b--){
			circunferencia(420,30,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo2(){
	for(float a=390; a<=419;a++){
		for(float b=-60;b>=-79;b--){
			circunferencia(420,-80,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo3(){
	for(float a=390; a<=419;a++){
		for(float b=-170;b>=-189;b--){
			circunferencia(420,-190,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo4(){
	for(float a=290; a<=319;a++){
		for(float b=50;b>=29;b--){
			circunferencia(320,30,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo5(){
	for(float a=290; a<=319;a++){
		for(float b=-60;b>=-79;b--){
			circunferencia(320,-80,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo6(){
	for(float a=290; a<=319;a++){
		for(float b=-170;b>=-189;b--){
			circunferencia(320,-190,a,b,1,1,1,0,0);
			glFlush();
		}
	}
}
void rellenocirculo7(){
	for(float a=-450; a<=-421;a++){
		for(float b=50;b>=29;b--){
			circunferencia(-420,30,a,b,1,1,0,1,0);
			glFlush();
		}
	}
}
void rellenocirculo8(){
	for(float a=-450; a<=-421;a++){
		for(float b=-60;b>=-79;b--){
			circunferencia(-420,-80,a,b,1,1,0,1,0);
			glFlush();
		}
	}
}
void rellenocirculo9(){
	for(float a=-450; a<=-421;a++){
		for(float b=-170;b>=-189;b--){
			circunferencia(-420,-190,a,b,1,1,0,1,0);
			glFlush();
		}
	}
	
}
void rellenocirculo10(){
	for(float a=-350; a<=-321;a++){
		for(float b=50;b>=29;b--){
			circunferencia(-320,30,a,b,1,1,0,1,0);
			glFlush();
		}
	}
}
void rellenocirculo11(){
	for(float a=-350; a<=-321;a++){
		for(float b=-60;b>=-79;b--){
			circunferencia(-320,-80,a,b,1,1,0,1,0);
			glFlush();
		}
	}
}
void rellenocirculo12(){
	for(float a=-350; a<=-321;a++){
		for(float b=-170;b>=-189;b--){
			circunferencia(-320,-190,a,b,1,1,0,1,0);
			glFlush();
		}
	}
}

void teclado(unsigned char tecla,int x,int y){//enviamos como parametro la letra que deseemos
	switch(tecla){
	case 'a':
		tu=0;
		display();
		rellenocirculo10();
		rellenocirculo4();
		break;
	case 'b':
		tu=1;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo4();
		rellenocirculo5();
		break;
	case 'c':
		tu=2;
		display();
		rellenocirculo10();
		rellenocirculo7();
		rellenocirculo4();
		rellenocirculo1();
		break;	case 'd':
		tu=3;
		display();
		rellenocirculo10();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo1();
		rellenocirculo2();
		break;
	case 'e':
		tu=4;
		display();
		rellenocirculo10();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo2();
		break;
	case 'f':
		tu=5;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo7();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo1();
		break;
	case 'g':
		tu=6;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo1();
		rellenocirculo2();
		break;
	case 'h':
		tu=7;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo2();
		break;
	case 'i':
		tu=8;
		display();
		rellenocirculo11();
		rellenocirculo7();
		rellenocirculo5();
		rellenocirculo1();
		break;
	case 'j':
		tu=9;
		display();
		rellenocirculo11();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo5();
		rellenocirculo1();
		rellenocirculo2();
		break;
	case 'k':
		tu=10;
		display();
		rellenocirculo10();
		rellenocirculo12();
		rellenocirculo4();
		rellenocirculo6();
		break;
	case 'l':
		tu=11;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo6();
		break;
	case 'm':
		tu=12;
		display();
		rellenocirculo10();
		rellenocirculo12();
		rellenocirculo7();
		rellenocirculo4();
		rellenocirculo6();
		rellenocirculo1();
		break;
	case 'n':
		tu=13;
		display();
		rellenocirculo10();
		rellenocirculo12();
		rellenocirculo7();
		rellenocirculo4();
		rellenocirculo6();
		rellenocirculo1();
		break;
	case 'o':
		tu=14;
		display();
		rellenocirculo10();
		rellenocirculo12();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo6();
		rellenocirculo2();
		break;
	case 'p':
		tu=15;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo7();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo1();
		break;
	case 'q':
		tu=16;
		display();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo1();
		rellenocirculo2();
		break;
	case 'r':
		tu=17;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo8();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo2();
		break;
	case 's':
		tu=18;
		display();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo7();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo1();
		break;
	case 't':
		tu=19;
		display();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo1();
		rellenocirculo2();
		break;
	case 'u':
		tu=20;
		display();
		rellenocirculo10();
		rellenocirculo12();
		rellenocirculo9();
		rellenocirculo4();
		rellenocirculo6();
		rellenocirculo3();
		break;
	case 'v':
		tu=21;
		display();
		rellenocirculo10();
		rellenocirculo11();
		rellenocirculo12();
		rellenocirculo9();
		rellenocirculo4();
		rellenocirculo5();
		rellenocirculo6();
		rellenocirculo3();
		break;
	case 'w':
		tu=22;
		display();
		rellenocirculo11();
		rellenocirculo7();
		rellenocirculo8();
		rellenocirculo9();
		rellenocirculo5();
		rellenocirculo1();
		rellenocirculo2();
		rellenocirculo3();
		break;
	case 'x':
		tu=23;
		display();
		rellenocirculo10();
		rellenocirculo7();
		rellenocirculo12();
		rellenocirculo9();
		rellenocirculo4();
		rellenocirculo1();
		rellenocirculo6();
		rellenocirculo3();
		break;
	case 'y':
		tu=24;
		display();
		rellenocirculo10();
		rellenocirculo7();
		rellenocirculo12();
		rellenocirculo8();
		rellenocirculo9();
		rellenocirculo4();
		rellenocirculo1();
		rellenocirculo6();
		rellenocirculo2();
		rellenocirculo3();
		break;
	case 'z':
		tu=25;
		display();
		rellenocirculo10();
		rellenocirculo8();
		rellenocirculo12();
		rellenocirculo9();
		rellenocirculo4();
		rellenocirculo2();
		rellenocirculo6();
		rellenocirculo3();
		break;
	case ' ':
		display();
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
	escribeletra();
}
int main (int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE || GLUT_RGB);
	glutInitWindowSize(ancho, alto);
	glutInitWindowPosition(10,10);
	glutCreateWindow("Sistema Braille");
	gluOrtho2D(-(ancho/2),ancho/2,-(alto/2),alto/2);
	glutDisplayFunc(figurabase);
	glutKeyboardFunc(teclado);
	glClearColor(0,0,0,0);
	glutSwapBuffers();
	glutMainLoop();
	return 0;
}

