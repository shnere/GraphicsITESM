/*
 *  Matarial.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 9/18/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/GLUT.h>
#include <stdio.h>
#include <stdlib.h>
#include "Matarial.h"
using namespace std;

Matarial::Matarial(GLfloat r, GLfloat g, GLfloat b, int LMode, int SMode){
	colorMaterial.r = r;
	colorMaterial.g = g;
	colorMaterial.b = b;
	LineMode		= LMode;
	ShadeMode		= SMode;
}

Color Matarial::getColor(){
	return colorMaterial;
}

int Matarial::getLineMode(){
	return LineMode;
}

int Matarial::getShadeMode(){
	return ShadeMode;
}

void Matarial::setLineMode(int mode){
	LineMode = mode;
}

void Matarial::setShadeMode(int mode){
	ShadeMode = mode;
}

void Matarial::setColor(GLfloat r, GLfloat g, GLfloat b){
	colorMaterial.r = r;
	colorMaterial.g = g;
	colorMaterial.b = b;
}