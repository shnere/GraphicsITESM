/*
 *  Cono.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef CONO_H_
#define CONO_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

class Cono : public Objeto {
	private:
		GLdouble radius;
		GLdouble height;
		GLint slices;
		GLint stacks;
	public:
		Cono(Matarial *imt, GLdouble sep_v[], int urep, GLdouble uradius, GLdouble uheight, GLint uslices, GLint ustacks);
};

#endif