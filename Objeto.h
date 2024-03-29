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
#include <vector>
#include "Matarial.h"
#include "Movimientos.h"
using namespace std;

class Objeto {
	protected:
		Matarial *material;
		GLdouble *separacion_v;
		int repeticiones;
		vector<Movimientos> mov;
	public:
		Objeto(Matarial *imt, GLdouble sep_v[], int rep);
		Matarial getMaterial();
		GLdouble getSeparacion_v();
		int getRepeticiones();
		void setMaterial(Matarial *imt);
		void setSeparacion_v(GLdouble sep_v[]);
		void setRepeticiones(int rep);
		void addMovimiento(Movimientos *Movimiento);
		void idle();
		void loop();
		void doubleloop();
		
		//virtual void render();
		// virtual void repiteObjeto();
};

#endif
