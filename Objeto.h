/*
 *  Objeto.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/18/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */
#ifndef OBJETO_H_
#define OBJETO_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matarial.h"
using namespace std;

class Objeto {
	protected:
		Matarial *material;
		GLdouble *separacion_v;
		int repeticiones;
	public:
		Objeto(Matarial *imt, GLdouble sep_v[], int rep);
		Matarial getMaterial();
		GLdouble getSeparacion_v();
		int getRepeticiones();
		void setMaterial(Matarial *imt);
		void setSeparacion_v(GLdouble sep_v[]);
		void setRepeticiones(int rep);
		virtual void render();
		// virtual void repiteObjeto();
};

#endif
