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