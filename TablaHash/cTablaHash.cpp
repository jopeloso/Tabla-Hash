#include "cTablaHash.h"

#include <math.h>
cTablaHash::cTablaHash(void)
{
}

cTablaHash::cTablaHash(float factor_carga, unsigned int tama�o, unsigned int primo)
{
	this->factor_carga = factor_carga;
	cant_actual = 0;
	this->tama�o = tama�o;
	cant_maxima = factor_carga*tama�o;
	this->primo = primo;
	Tiempo = 0;

	Datos = new cDato*[tama�o];

	for (unsigned int i = 0; i<tama�o; i++)
	{
		Datos[i] = NULL;
	}

}

cTablaHash::~cTablaHash(void)
{
	delete Datos;
}

unsigned int cTablaHash::Hash(unsigned int Num)
{
	return Num % primo;
}

unsigned int cTablaHash::ReHash(unsigned int Num, unsigned int Colisiones)
{
	return (Num + Colisiones*Colisiones) % primo;
}

void cTablaHash::Redimensionar(unsigned int NuevoTama�o)
{
	T.start();
	cDato **Aux = new cDato*[tama�o];

	for (int i = 0; i<tama�o; i++)
	{
		Aux[i] = NULL;
	}

	for (int i = 0; i<tama�o; i++)
	{
		Aux[i] = Datos[i];
	}

	for (int i = 0; i<tama�o; i++)
	{
		Datos[i] = NULL;
	}

	delete Datos;

	Datos = new cDato*[NuevoTama�o];

	for (int i = 0; i<NuevoTama�o; i++)
	{
		Datos[i] = NULL;
	}

	

	primo = nuevoprimo(NuevoTama�o);

	for (int i = 0; i<cant_actual; i++)
	{
		if (Aux[i] != NULL)
		{
			int Pos_Nueva = 0;
			Pos_Nueva = Hash(Aux[i]->get_Num());
			Datos[Pos_Nueva] = Aux[i];
			Aux[i] = NULL;
		}
	}

	delete Aux;

	tama�o = NuevoTama�o;
	cant_maxima = factor_carga*NuevoTama�o;

	T.stop();

	Tiempo = T.getMiliseconds();

	return;

}



void cTablaHash::Insertar(cDato *D)
{


	if ((cant_actual + 1)>cant_maxima)
	{
		Redimensionar(tama�o * 2);
	}

	unsigned int Pos = Hash(D->get_Num());
	unsigned int Colisiones = 0;

	if (Datos[Pos] == NULL)
	{
		Datos[Pos] = D;
		cant_actual++;
		return;
	}
	else

	while (Datos[Pos] != NULL)
	{
		Colisiones++;
		Pos = ReHash(D->get_Num(), Colisiones);
	}

	
	Datos[Pos] = D;
	cant_actual++;
	return;
}

void cTablaHash::Eliminar(unsigned int Num)
{
	unsigned int Pos_Buscada;
	unsigned int i = 0;
	Pos_Buscada = Hash(Num);

	if (Datos[Pos_Buscada]->get_Num() == Num)
	{
		Datos[Pos_Buscada]->Borrar();
		Datos[Pos_Buscada]->set_Num(0);
		return;
	}


	while ((Datos[Pos_Buscada]->get_Num() == 0 && Datos[Pos_Buscada]->get_Bit() == 1) || (Datos[Pos_Buscada]->get_Num() != 0 && Datos[Pos_Buscada]->get_Num() != Num))
	{
		i++;
		Pos_Buscada = ReHash(Num, i);
	}

	if (Datos[Pos_Buscada] == NULL)
	{
		cout << "No se encontro el dato que desea eliminar" << endl;
		return;
	}

	Datos[Pos_Buscada]->Borrar();
	Datos[Pos_Buscada]->set_Num(0);
	return;

}

unsigned int cTablaHash::Buscar(unsigned int Num)
{
	unsigned int Pos_Buscada;
	unsigned int i = 0;
	Pos_Buscada = Hash(Num);

	if (Datos[Pos_Buscada]->get_Num() == Num)
	{
		return Pos_Buscada;
	}

	while ((Datos[Pos_Buscada]->get_Num() == 0 && Datos[Pos_Buscada]->get_Bit() == 1) || (Datos[Pos_Buscada]->get_Num() != 0 && Datos[Pos_Buscada]->get_Num() != Num))
	{
		i++;
		Pos_Buscada = ReHash(Num, i);
	}

	if (Datos[Pos_Buscada] == NULL)
	{
		cout << "El elemento que busca no esta en la tabla" << endl;
		return -1;
	}

	return Pos_Buscada;
}

cDato* cTablaHash::Quitar(unsigned int Num)
{
	unsigned int Pos_Buscada;
	unsigned int i = 0;
	cDato *D;
	Pos_Buscada = Hash(Num);

	if (Datos[Pos_Buscada]->get_Num() == Num)
	{
		D = Datos[Pos_Buscada];
		Datos[Pos_Buscada]->Borrar();
		Datos[Pos_Buscada]->set_Num(0);
		return D;
	}


	while ((Datos[Pos_Buscada]->get_Num() == 0 && Datos[Pos_Buscada]->get_Bit() == 1) || (Datos[Pos_Buscada]->get_Num() != 0 && Datos[Pos_Buscada]->get_Num() != Num))
	{
		i++;
		Pos_Buscada = ReHash(Num, i);
	}

	if (Datos[Pos_Buscada] == NULL)
	{
		cout << "No se ha encontrado el dato que desea eliminar" << endl;
		return	NULL;				
	}

	D = Datos[Pos_Buscada];
	Datos[Pos_Buscada]->Borrar();
	Datos[Pos_Buscada]->set_Num(0);
	return D;

}



unsigned int cTablaHash::nuevoprimo(unsigned int Num)
{
	unsigned int i = 2;
	unsigned int p = Num;
	while (i != p)
	{
		for (i; i<p; i++)
		{
			if (p%i == 0)
			{
				break;
			}
		}
		if (i == p)
		{
			break;
		}
		p--;
		i = 2;
	}
	return p;
}
