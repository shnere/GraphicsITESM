/*
 *  Objeto.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/18/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

Objeto::Objeto(Matarial *imt, GLdouble sep_v[], int rep) {
	material = imt;
	separacion_v = sep_v;
	repeticiones = rep;
}

Matarial Objeto::getMaterial() {
	return *material;
}

GLdouble Objeto::getSeparacion_v() {
	return *separacion_v;
}

int Objeto::getRepeticiones() {
	return repeticiones;
}

void Objeto::setMaterial(Matarial *imt) {
	material = imt;
}

void Objeto::setSeparacion_v(GLdouble sep_v[]) {
	separacion_v = sep_v;
}

void Objeto::setRepeticiones(int rep) {
	repeticiones = rep;
}