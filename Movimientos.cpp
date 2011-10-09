/*
 *  Movimientos.cpp
 *  Fase 2
 *
 *  Created by Sergio Báez on 10/6/11.
 *  Copyright 2011 ITESM-CQ. All rights reserved.
 *
 */

#include <GLUT/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Movimientos.h"

Movimientos::Movimientos(GLfloat ir, int imov, GLfloat idx,GLfloat idy,GLfloat idz, int ifps, int itiempo) {
	x		= 0;
	y		= 0;
	z		= 0;
	r		= ir;
	movid		= imov;
	deltas[0]	= idx;
	deltas[1]	= idy;
	deltas[2]	= idz;
	fps		= ifps;
	tiempo	= itiempo;
	framemax= ifps * itiempo;
	contador_frames = 0;
	theta		= 0;
	alpha		= 0;
	gama		= 0;
}

GLfloat Movimientos::getX(){
	return x;
}

void Movimientos::setX(GLfloat ix){
	x =ix;
}

GLfloat Movimientos::getY(){
	return y;
}

void Movimientos::setY(GLfloat iy){
	y = iy;
}

GLfloat Movimientos::getZ(){
	return z;
}

void Movimientos::setZ(GLfloat iz){
	z = iz;	
}

void Movimientos::setContador(int cont){
	contador_frames = cont;
}

void Movimientos::move(){
	switch (movid) {
			//translacion
		case 0:
			glTranslatef(x, y, z);
			break;
			//rotacion
		case 1:
			glRotatef(x, 1.0, 0.0, 0.0);
			glRotatef(y, 0.0, 1.0, 0.0);
			glRotatef(z, 0.0, 0.0, 1.0);
			break;
			//escalamiento
		case 2:
			glScalef(x, y, z);
			break;
			//traslacion en circulo
		case 3:
			//TODO Algoritmo circunferencia
			glTranslatef(x, y, z);
			break;
	}	
}

void Movimientos::idle(){
	if(contador_frames < framemax){
		switch(movid){
				//translacion //rotacion //escalamiento
			case 0: case 1: case 2:
				x += deltas[0];
				y += deltas[1];
				z += deltas[2];
				break;
				
				//traslacion en circulo
			case 3:
				
				if (deltas[2] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					y = r * (cos(theta) + sin(theta));
				}
				if (deltas[1] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					z = r * (cos(gama) + sin(gama));
				}
				if (deltas[0] == 0) {
					y = r * (cos(theta) - sin(theta));
					z = r * (cos(gama) + sin(gama));
				}
				
				alpha   += deltas[0];
				theta	+= deltas[1];
				gama	+= deltas[2];
				
		}
		contador_frames++;
	}
}

void Movimientos::loop(){
	if(contador_frames < framemax){
		switch(movid){
				//translacion //rotacion //escalamiento
			case 0: case 1: case 2:
				x += deltas[0];
				y += deltas[1];
				z += deltas[2];
				break;
				
				//traslacion en circulo
			case 3:
				
				if (deltas[2] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					y = r * (cos(theta) + sin(theta));
				}
				if (deltas[1] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					z = r * (cos(gama) + sin(gama));
				}
				if (deltas[0] == 0) {
					y = r * (cos(theta) - sin(theta));
					z = r * (cos(gama) + sin(gama));
				}
				
				alpha   += deltas[0];
				theta	+= deltas[1];
				gama	+= deltas[2];
				
		}
		contador_frames++;
	} else {
		setX(0.0);
		setY(0.0);
		setZ(0.0);
		setContador(0);
	}
	
	
}

void Movimientos::doubleloop(){
	if(contador_frames < framemax){
		switch(movid){
				//translacion //rotacion //escalamiento
			case 0: case 1: case 2:
				x += deltas[0];
				y += deltas[1];
				z += deltas[2];
				break;
				//traslacion en circulo
			case 3:
				//TODO Algoritmo circunferencia
				if (deltas[2] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					y = r * (cos(theta) + sin(theta));
				}
				if (deltas[1] == 0) {
					x = r * (cos(alpha) - sin(alpha));
					z = r * (cos(gama) + sin(gama));
				}
				if (deltas[0] == 0) {
					y = r * (cos(theta) - sin(theta));
					z = r * (cos(gama) + sin(gama));
				}
				
				alpha   += deltas[0];
				theta	+= deltas[1];
				gama	+= deltas[2];
				break;		
		}
		contador_frames++;
	} else {
		if (contador_frames < (framemax * 2)) {
			switch(movid){
					//translacion //rotacion //escalamiento
				case 0: case 1: case 2:
					x -= deltas[0];
					y -= deltas[1];
					z -= deltas[2];
					break;
					//traslacion en circulo
				case 3:
					//TODO Algoritmo circunferencia
					if (deltas[2] == 0) {
						x = r * (cos(alpha) - sin(alpha));
						y = r * (cos(theta) + sin(theta));
					}
					if (deltas[1] == 0) {
						x = r * (cos(alpha) - sin(alpha));
						z = r * (cos(gama) + sin(gama));
					}
					if (deltas[0] == 0) {
						y = r * (cos(theta) - sin(theta));
						z = r * (cos(gama) + sin(gama));
					}
					
					alpha   += deltas[0];
					theta	+= deltas[1];
					gama	+= deltas[2];
					break;
			}
			contador_frames++;
		} else {
			contador_frames = 0;
		}
	}		
}