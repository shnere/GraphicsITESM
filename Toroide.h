/*
 *  Toroide.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef TOROIDE_H_
#define TOROIDE_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

class Toroide : public Objeto {
	private:
		GLdouble innerRadius;
		GLdouble outerRadius;
		GLint sides;
		GLint rings;
	public:
		Toroide(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uinnerRadius, GLdouble uouterRadius, GLint usides, GLint urings);
		void render();
};

#endif