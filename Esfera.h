/*
 *  Esfera.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/19/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef ESFERA_H_
#define ESFERA_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

class Esfera : public Objeto {
	private:
		GLdouble radius;
		GLint slices;
		GLint stacks;
	public:
		Esfera(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uradius, GLdouble uslices, GLdouble ustacks);
};

#endif