#include <iostream>
#include <string>

#include "cTime.h"
#include "cDato.h"
#include "cTablaHash.h"

unsigned int nuevoprimo_main(unsigned int Num);

#define	sup	1000000			//Valor superior del random
#define inf	1			//Valor inferior del random
#define M 200000			//Tamanio de la tabla hash

#define FC 1		//Factor de carga para el cual redimensionar 
#define B 0.98			//Constante de proporcionalidad de los  elementos a insertar, M=(BETA * N)

using namespace std;

int main()
{
	unsigned int N;
	N = B * M;

	unsigned int primo = nuevoprimo_main(M);

	cTablaHash TablaHash1(FC, M, primo);
	cTime T1, T2, T3;


	 
	T2.start();

	for (unsigned int i = 0; i<N; i++)
	{
		int Numero = rand() % (sup - inf + 1) + inf;
		cDato *NuevoDato = new cDato(Numero);
		TablaHash1.Insertar(NuevoDato);
	}

	T2.stop();

	int RegistroMedido = rand() % (sup - inf + 1) + inf;
	cDato *NuevoRegistro = new cDato(RegistroMedido);

	T1.start();

	TablaHash1.Insertar(NuevoRegistro);

	T1.stop();

	system("cls");

	cout << "La demora para insertar un elemento, cuando ya habia  " << N << " elementos fue de " << T1.getMicroseconds() <<"microsegundos"<< endl;
	//cout<<"El tiempo que tarde en redimensionar y rehashear es  "<<TablaHash1.get_Tiempo()<<" milisegundos"<<endl;

	system("pause");




	return 0;
}

unsigned int nuevoprimo_main(unsigned int Num)
{
	unsigned int i = 2;
	unsigned int p = Num;
	while (i != p)
	{
		for (i; i < p; i++)
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