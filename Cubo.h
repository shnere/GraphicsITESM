/*
 *  Cubo.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef CUBO_H_
#define CUBO_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

class Cubo : public Objeto {
	private:
		GLdouble lado;
	public:
		Cubo(Matarial *imt, GLdouble sep_v[], int urep, GLdouble ulado);
};

#endif