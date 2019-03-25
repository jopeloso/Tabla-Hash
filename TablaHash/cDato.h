#pragma once
#ifndef CDATO_H
#define CDATO_H

#include <iostream>
#include <string>

using namespace std;

#pragma once
class cDato
{
private:

	int Num;
	bool BitB;

public:

	cDato(void);
	cDato(int Num);
	~cDato(void);

	void Borrar();
	void desBorrar();

	int get_Num(){ return Num; }
	void set_Num(int n){ Num = n; }
	bool get_Bit(){ return BitB; }
	

};

#endif