#ifndef CIFTYONLUBAGILLISTE_H
#define CIFTYONLUBAGILLISTE_H
#include "Dugum.h"

class CiftYonluBagilListe
{
public:
	void Yazdir();
	void Ekle(int*,int);
	static void Caprazla(CiftYonluBagilListe**,int);
	Dugum* listeOrta;

};


#endif