/*
 *  Prisma.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef PRISMA_H_
#define PRISMA_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"
#include "Matarial.h"
using namespace std;

class Prisma : public Objeto {
	private:
		GLint lados;
		GLdouble altura;
		GLdouble apotema;
	public:
		Prisma(Matarial *imt, GLdouble sep_v[], int urep, GLint ulados, GLdouble ualtura, GLdouble uapotema);
		void render();
		void poligono(GLint ilados, GLdouble iapotema, Matarial *imt);
};

#endif