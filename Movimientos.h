/*
 *  Movimientos.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef MOVIMIENTOS_H_
#define MOVIMIENTOS_H_

#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Movimientos {
	private:
		GLfloat x;
		GLfloat y;
		GLfloat z;
		GLfloat r;
		int movid;
		GLfloat deltas[3];
		int fps;
		int tiempo;
		int framemax;
		int contador_frames;
		double theta;
		double alpha;
		double gama;

	public:
		Movimientos(GLfloat ir, int imov, GLfloat idx,GLfloat idy,GLfloat idz, int ifps, int itiempo);
		GLfloat getX();
		void setX(GLfloat x);
		GLfloat getY();
		void setY(GLfloat y);
		GLfloat getZ();
		void setZ(GLfloat z);
		void move();
		void idle();
		void setContador(int cont);
		void loop();
		void doubleloop();
};

#endif;