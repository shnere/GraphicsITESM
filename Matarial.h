/*
 *  Matarial.h
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/18/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#ifndef MATARIAL_H_
#define MATARIAL_H_

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct color {
	GLfloat r;
	GLfloat g;
	GLfloat b;
}Color;

class Matarial {
	private:
		Color colorMaterial;
		int LineMode;
		int ShadeMode;
	
	public:
		Matarial(GLfloat r, GLfloat g, GLfloat b, int LineMode, int ShadeMode);
		Color getColor();
		int getLineMode();
		int getShadeMode();
		void setColor(GLfloat r, GLfloat g, GLfloat b);
		void setLineMode(int LineMode);
		void setShadeMode(int ShadeMode);
};

#endif