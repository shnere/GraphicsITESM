/*
 *  Cubo.cpp
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
#include "Cubo.h"
using namespace std;

Cubo::Cubo(Matarial *imt, GLdouble sep_v[], int urep, GLdouble ulado)
: Objeto(imt, sep_v, urep){
	lado = ulado;
}

void Cubo::render() {
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
	
	if (material->getLineMode() == GL_LINE_LOOP || material->getLineMode() == GL_LINE_STRIP) {
		glutWireCube(lado);
	} else {
		glutSolidCube(lado);
	}
	
	glPopMatrix();
}