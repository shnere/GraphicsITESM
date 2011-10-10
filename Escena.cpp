/*
 *  Escena.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "Objeto.h"
#include "Esfera.h"
#include "Cono.h"
#include "Cubo.h"
#include "Prisma.h"
#include "Toroide.h"
#include "Matarial.h"
#include "Escena.h"

// Frames por segundo
int fps			= 30;
// Duracion de un frame en milisegundos
int frametime	= 1000/fps;
// Angulo que define el campo de vision respecto al eje y (field of vision)
GLfloat fovy	= 30.0;
// Traslacion camara
GLfloat yview	= 0.0;
GLfloat xview	= 0.0;
GLfloat zview	= -10.0;
// Rotacion camara
GLfloat xrotview= 0.0;
GLfloat yrotview= 0.0;
GLfloat zrotview= 0.0;
// Deltas de traslacion y rotacion
GLfloat dtran	= 0.1;
GLfloat drtran	= 0.9;

// Tamano de la pantalla
int currWidth	= 100;
int currHeight	= 100;
// Pausar o reproducir la animación
bool pausa		= false;


/*
 * Genero Matariales
 */

Matarial mat01(1.0,1.0,0.0,GL_LINE_LOOP		, GL_SMOOTH);
Matarial mat02(1.0,0.0,0.0,GL_LINE_STRIP	, GL_FLAT);
Matarial mat03(0.5,1.0,0.5,GL_TRIANGLE_FAN	, GL_SMOOTH);
Matarial mat04(0.0,1.0,0.0,GL_LINE_LOOP		, GL_SMOOTH);
Matarial mat05(1.0,0.0,1.0,GL_TRIANGLE_FAN	, GL_SMOOTH);

GLdouble separacionV01[] = {-1.0,0.0,0.0};
GLdouble separacionV02[] = {0.0,1.0,0.0};
GLdouble separacionV03[] = {1.0,1.0,1.0};
GLdouble separacionV04[] = {1.0,2.0,0.0};
GLdouble separacionV05[] = {2.0,1.0,0.0};


/*
 * Genero Objetos
 */

Esfera	esfera01(&mat01,separacionV01	, 1, 0.6, 50	,50);
Toroide toroide02(&mat02,separacionV02	, 1, 0.6, 0.4	,20	,20);
Cono	cono03(&mat03,separacionV03		, 1, 0.5, 1	,20	,20);
Prisma	prisma04(&mat04,separacionV04	, 1, 5	, 0.6	,0.5);
Cubo	cubo05(&mat05,separacionV05		, 1, 0.2);


// Función Init
void init(int left,int top,int width,int height,char* title) {
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(left,top);
	glutInitWindowSize(width,height);
	glutCreateWindow(title);
	glClearColor(1.0,1.0,1.0,1.0);
	
	// Guardo Tamaños Actuales
	currWidth	= width;
	currHeight	= height;
}


// Función Render
void render(){	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	// Render de los objetos en Escena AQUI
	/*
	esfera01.render();
	toroide02.render();
	cono03.render();
	
	 
	cubo05.render();
	*/
	prisma04.render();
	
	glutSwapBuffers();	
}

void idle(void){
	// Control de Frames por Segundo
	static long time = glutGet(GLUT_ELAPSED_TIME);
	if ((!pausa) && ((glutGet(GLUT_ELAPSED_TIME)-time) > frametime)){
		glLoadIdentity();
		
		/*
		esfera01.idle();
		toroide02.loop();
		cono03.doubleloop();
		
		cubo05.loop();
		*/
		prisma04.loop();
		
		
		glutPostRedisplay();
		time	=	glutGet(GLUT_ELAPSED_TIME);
	}
	
}

void redimensiona(int width,int height) {
	// Activa matriz de transformaciones para Projection (Camara)  
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy,(GLdouble)width/(GLdouble)height,1.0,20.0); 
	glTranslatef(xview,yview,zview);
	glRotatef(xrotview,1.0,0.0,0.0);
	glRotatef(yrotview,0.0,1.0,0.0);
	glRotatef(zrotview,0.0,0.0,1.0);
	glViewport(0,0,width,height);
	
	// Activa matriz de transformaciones para Model-View
	glMatrixMode(GL_MODELVIEW);
	
	// Guardo Tamaños Actuales
	currWidth	= width;
	currHeight	= height;
}

void ilumina(){
	// Define los parámetros de intensidad y color de la luz
	GLfloat glfLightAmbient[]	= {0.1,0.1,0.1,1.0}; 
	GLfloat glfLightDiffuse[]	= {1.2,1.2,1.2,1.0}; 
	GLfloat glfLightSpecular[]	= {0.9,0.9,0.9,1.0};
	
	// Define una fuente de luz direccional
	GLfloat glfLightPosition[]	= {0.0,0.0,2.0,0.0};
	
	// Activa los parámetros definidos
	glLightfv(GL_LIGHT0,GL_AMBIENT	,glfLightAmbient);
	glLightfv(GL_LIGHT0,GL_DIFFUSE	,glfLightDiffuse);
	glLightfv(GL_LIGHT0,GL_SPECULAR	,glfLightSpecular);
	glLightfv(GL_LIGHT0,GL_POSITION	,glfLightPosition);
	
	// Habilita la iluminacion en general 
	glEnable(GL_LIGHTING);
	
	// Habilita la fuente de luz definida, siendo la primera y unica es GL_LIGTH0
	glEnable(GL_LIGHT0);
	
	// Determina el ocultamiento de las caras de los polígonos que no están de frente a la camara
	glEnable(GL_CULL_FACE);
	
	// Selecciona el modo de sombreado
	// Se selecciona por objeto
	
	// Para que nos respete el color
	glEnable(GL_COLOR_MATERIAL);
	
}


void keyboardSpec(int key,int x,int y){
	switch(key){
		case GLUT_KEY_UP:
			yview+=dtran;
			redimensiona(currWidth,currHeight);
			break;
		case GLUT_KEY_DOWN:
			yview-=dtran;
			redimensiona(currWidth,currHeight);
			break;
		case GLUT_KEY_HOME:
			zview+=dtran;
			redimensiona(currWidth,currHeight);
			break;
		case GLUT_KEY_END:
			zview-=dtran;
			redimensiona(currWidth,currHeight);
			break;
		case GLUT_KEY_LEFT:
			xview-=dtran;
			redimensiona(currWidth,currHeight);
			break;
		case GLUT_KEY_RIGHT:
			xview+=dtran;
			redimensiona(currWidth,currHeight);
			break;
	}
}

void keyboard(unsigned char key,int x,int y){
	// Definir Acciones
	switch (key) {
		case 'p':case 'P':
			// Pause
			if (!pausa) {
				pausa = true;
			}
			break;
		case 'c':case 'C':
			// Continue
			if (pausa) {
				pausa = false;
			}
			break;
		case 'x':
			// RotateX
			xrotview += drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 'y':
			// RotateY
			yrotview += drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 'z':
			// RotateZ
			zrotview += drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 'X':
			// RotateX
			xrotview -= drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 'Y':
			// RotateY
			yrotview -= drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 'Z':
			// RotateZ
			zrotview -= drtran;
			redimensiona(currWidth,currHeight);
			break;
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

int main( int argc, char **argv) {
	glutInit(&argc,argv);
	init(100,100,800,600,"Proyecto Parcial 02");
	glutDisplayFunc(render);
	glutIdleFunc(idle);
	glutReshapeFunc(redimensiona);
    glutSpecialFunc(keyboardSpec);
	glutKeyboardFunc(keyboard);	
	ilumina();
	
	// Aqui defino Movimientos de objetos, etc
	/*
	Movimientos mov01(0.0, 0, 0.005, 0.005 ,0.000,fps,10);
	Movimientos mov02(0.0, 0, 0.005, 0.000 ,0.005,fps,10);
	Movimientos mov03(0.0, 1, 0.105, 0.005 ,0.005,fps,50);
	Movimientos mov04(0.0, 2, 0.003, 0.003 ,0.000,fps,10);
	Movimientos mov05(0.2, 3, 0.000, 0.005 ,0.005,fps,10);
	
	esfera01.addMovimiento(&mov01);
	toroide02.addMovimiento(&mov02);
	cono03.addMovimiento(&mov03);
	prisma04.addMovimiento(&mov04);
	cubo05.addMovimiento(&mov05);
	*/
	glutMainLoop();
	return 0;
}










