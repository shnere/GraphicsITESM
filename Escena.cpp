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
// Tamano de la pantalla
int currWidth	= 100;
int currHeight	= 100;
// Pausar o reproducir la animación
bool pausa		= false;

Matarial mat01(1.0,1.0,0.0,GL_LINE_LOOP, GL_FLAT);

GLdouble separacionV01[] = {-1.0,0.0,0.0};

Esfera	esfera01(&mat01,separacionV01, 1, 0.6,50,50);


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
	
	// Aplicar Transformaciones AQUI
	
	// Creacion de los objetos en Escena AQUI
	esfera01.render();
	
	glutSwapBuffers();	
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


int main( int argc, char **argv) {
	glutInit(&argc,argv);
	init(100,100,800,600,"Proyecto Parcial 01");
	glutDisplayFunc(render);
	//glutIdleFunc(idle);
	glutReshapeFunc(redimensiona);
    //glutSpecialFunc(keyboardSpec);
	//glutKeyboardFunc(keyboard);	
	//ilumina();
	
	glutMainLoop();
	return 0;
}










