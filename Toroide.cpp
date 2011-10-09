/*
 *  Toroide.cpp
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
#include "Toroide.h"
using namespace std;

Toroide::Toroide(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uinnerRadius, GLdouble uouterRadius, GLint usides, GLint urings)
	: Objeto(imt, sep_v, urep) {
		innerRadius = uinnerRadius;
		outerRadius = uouterRadius;
		sides = usides;
		rings = urings;
}

void Toroide::render() {
	glPushMatrix();
	
	glShadeModel(material->getShadeMode());
	Color color = material->getColor();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(separacion_v[0],separacion_v[1],separacion_v[2]);
	
	
	//funcion prisma, toroide, cono, etc
	if(material->getLineMode() == GL_LINE_LOOP || material->getLineMode() == GL_LINE_STRIP){
		glutWireTorus(innerRadius, outerRadius, sides, rings);
	}else {
		glutSolidTorus(innerRadius, outerRadius, sides, rings);
	}
	
	glPopMatrix();

}