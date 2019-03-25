#include "cDato.h"

cDato::cDato(void)
{
	Num = 0;
	BitB= 0;
}

cDato::cDato(int Num)
{
	this->Num = Num;
	BitB = 0;
}

cDato::~cDato(void)
{
}

void cDato::Borrar()
{
	Num = 0;
	BitB = 1;
	return;
}

void cDato::desBorrar()
{
	BitB = 0;
	return;
}