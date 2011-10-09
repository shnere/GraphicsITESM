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


