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

Esfera::Esfera(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uradius, GLdouble uslices, GLdouble ustacks) : 
	Objeto::Objeto(*imt, sep_v, urep) {
		radius = uradius;
		slices = uslices;
		stacks = ustacks;
}

void Objeto::render(){
	
}


