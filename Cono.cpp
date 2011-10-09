/*
 *  Cono.cpp
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
#include "Cono.h"
using namespace std;


Cono::Cono(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uradius, GLdouble uheight, GLint uslices, GLint ustacks)
	: Objeto(imt, sep_v, urep){
		radius = uradius;
		height = uheight;
		slices = uslices;
		stacks = ustacks;
}