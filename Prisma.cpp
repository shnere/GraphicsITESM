/*
 *  Prisma.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
#include "Prisma.h"
using namespace std;

Prisma::Prisma(Matarial *imt, GLdouble sep_v[], int urep, GLint ulados, GLdouble ualtura, GLdouble uapotema)
	: Objeto(imt, sep_v, urep) {
		lados = ulados;
		altura = ualtura;
		apotema = uapotema;
}

void Prisma::poligono(GLint ilados, GLdouble iapotema, Matarial *imt) {
	GLfloat angulo = 0.0;
	GLfloat delta = (2*3.1416) / ilados; 
	GLfloat limite = (2*3.1416);
	GLfloat x, y;
	
	glBegin(material->getLineMode()); 
	while (angulo < limite) {
		x = iapotema * cos(angulo);
		y = iapotema * sin(angulo);
		glVertex3f(x, y,0.0);
		angulo += delta;
	}
	glEnd();
	
}

void Prisma::render() {
	glPushMatrix();
	
	// ITERATOR de Movimientos
	vector<Movimientos>::iterator itr;
	for(itr = mov.begin(); itr != mov.end(); itr++){
		(*itr).move();
	}	
	
	glShadeModel(material->getShadeMode());
	Color color = material->getColor();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(separacion_v[0], separacion_v[1], separacion_v[2]);
	
	GLfloat angulo = 0.0;
	GLfloat delta = (2*3.1416) / lados; 
	GLfloat limite = (2*3.1416);
	GLfloat x, y;
	
	
		glPushMatrix();
		poligono(lados, apotema, material);
		glPopMatrix();
		
		glBegin(material->getLineMode());
		while (angulo < limite) {
			x = apotema * cos(angulo);
			y = apotema * sin(angulo);
			glVertex3f(x, y, 0.0);
			glVertex3f(x, y, altura);
			angulo += delta;
		}
		glEnd();
		
		glPushMatrix();
		glTranslatef(0.0, 0.0, altura);
		poligono(lados, apotema, material);
		glPopMatrix();
	
	glPopMatrix();

}


