#ifndef CTABLAHASH_H
#define CTABLAHASH_H

#include "cTime.h"
#include "cDato.h"   
#include <string>
#include <iostream>

using namespace std;
#pragma once

class cTablaHash
{
private:

	cDato **Datos;
	unsigned int cant_actual;
	float factor_carga;
	float cant_maxima;
	unsigned int tamaño;
	unsigned int primo;
	float Tiempo;
	cTime T;

public:

	cTablaHash(void);
	cTablaHash(float factor_carga, unsigned int tamaño, unsigned int primo);
	~cTablaHash(void);

	unsigned int Hash(unsigned int Num);
	unsigned int ReHash(unsigned int Num, unsigned int Colisiones);	

	void Redimensionar(unsigned int NuevoTamaño);							

	void Insertar(cDato *D);
	void Eliminar(unsigned int Num);
	unsigned int Buscar(unsigned int Num);
	unsigned int HashRedimensionar(unsigned int Num);
	cDato* Quitar(unsigned int Num);
	unsigned int nuevoprimo(unsigned int Num);
	//--------------------------------------------------

	


	float get_factor_carga(){ return factor_carga; }
	
	unsigned int get_tamaño(){ return tamaño; }
	unsigned int get_cant_actual(){ return cant_actual; }
	unsigned int get_primo(){ return primo; }
	float get_Tiempo(){ return Tiempo; }
};

#endif