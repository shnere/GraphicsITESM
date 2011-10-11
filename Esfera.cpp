/*
 *  Esfera.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/19/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Esfera.h"
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

Esfera::Esfera(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uradius, GLdouble uslices, GLdouble ustacks) 
	: Objeto(imt, sep_v, urep) {
		radius = uradius;
		slices = uslices;
		stacks = ustacks;
}

void Esfera::render(){
	glPushMatrix();
	
	// ITERATOR de Movimientos
	vector<Movimientos>::iterator itr;
	for(itr = mov.begin(); itr != mov.end(); itr++){
		(*itr).move();
	}	
	
	// Aplico Shade Model
	glShadeModel(material->getShadeMode());
	// Aplico el Color del Elemento
	Color color = material->getColor();
	glColor3f(color.r, color.g, color.b);
	
	// Aplico la separación
	glTranslatef(separacion_v[0], separacion_v[1], separacion_v[2]);
	
	if (material->getLineMode() == GL_LINE_LOOP || material->getLineMode() == GL_LINE_STRIP) {
		glutWireSphere(radius, slices, stacks);
	} else {
		glutSolidSphere(radius, slices, stacks);
	}

	glPopMatrix();
}