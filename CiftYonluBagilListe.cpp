#include "Dugum.h"
#include "CiftYonluBagilListe.h"
#include <iostream>
using namespace std;


void::CiftYonluBagilListe::Ekle(int* sayilar,int boyut) 
{
	listeOrta = new Dugum(sayilar[0]);
	for (int i = 1;i < boyut;i++) 
	{
		if (i > boyut / 2) 
		{
			Dugum* son = listeOrta;
			while (son->next != NULL) 
			{
				son = son->next;
			}
			Dugum* yeniDugum = new Dugum(sayilar[i]);
			yeniDugum->prev = son;
			son->next = yeniDugum;

		}
		else 
		{
			Dugum* ilk = listeOrta;
			while (ilk->prev != NULL) 
			{
				ilk = ilk->prev;
			}
			Dugum* yeniDugum = new Dugum(sayilar[i]);
			yeniDugum->next = ilk;
			ilk->prev = yeniDugum;
		}
	}
	Dugum* ilk = listeOrta;
	Dugum* son = listeOrta;
	while (ilk->prev!= NULL && son->next != NULL) 
	{
		ilk = ilk->prev;
		son = son->next;
	}
	son->next = ilk;
	ilk->prev = son;

}
void::CiftYonluBagilListe::Yazdir() 
{
	Dugum* ilk = listeOrta;
	Dugum * son = listeOrta;
	while (ilk->prev != son) 
	{
		ilk = ilk->prev;
		son = son->next;
	}
	Dugum* iter = ilk;
	while (iter->next!=ilk) 
	{
		std::cout << iter->veri<<" ";
		iter = iter->next;
	}
	cout << iter->veri;
}
void::CiftYonluBagilListe::Caprazla(CiftYonluBagilListe** liste, int boyut)
{
	CiftYonluBagilListe* kListe = liste[0];
	CiftYonluBagilListe* bListe = liste[0];
	for (int i = 1;i < boyut;i++)
	{
		if (kListe->listeOrta->veri > liste[i]->listeOrta->veri)
		{
			kListe = liste[i];
		}
		if (bListe->listeOrta->veri < liste[i]->listeOrta->veri)
		{
			bListe = liste[i];
		}
	}

	Dugum* kListeNext = kListe->listeOrta->next;
	Dugum* kListePrev = kListe->listeOrta->prev;


	kListe->listeOrta->prev = bListe->listeOrta->prev;
	kListe->listeOrta->next = bListe->listeOrta->next;
	kListe->listeOrta->prev->next = kListe->listeOrta;
	kListe->listeOrta->next->prev = kListe->listeOrta;



	bListe->listeOrta->prev = kListePrev;
	bListe->listeOrta->next = kListeNext;
	bListe->listeOrta->prev->next = bListe->listeOrta;
	bListe->listeOrta->next->prev = bListe->listeOrta;

	Dugum* ilk = kListe->listeOrta->prev;
	Dugum* son = kListe->listeOrta->next;

	for (int i = 0;ilk->prev != son;i++)
	{
		ilk = ilk->prev;
		son = son->next;
	}
	Dugum* temp = ilk;
	do {

		Dugum* next = temp->next;
		Dugum* prev = temp->prev;
		temp->prev = next;
		temp->next = prev;
		temp = next;

	} while (temp != ilk);
	ilk = ilk->next;

	ilk = bListe->listeOrta->prev;
	son = bListe->listeOrta->next;

	for (int i = 0;ilk->prev != son;i++)
	{
		ilk = ilk->prev;
		son = son->next;
	}
	temp = ilk;
	do {

		Dugum* next = temp->next;
		Dugum* prev = temp->prev;
		temp->prev = next;
		temp->next = prev;
		temp = next;

	} while (temp != ilk);
	ilk = ilk->next;

	cout << "En Buyuk Liste Orta Dugum Adres   :" << bListe->listeOrta<<endl;
	cout << "En Buyuk Liste Degerler  :" << endl;
	bListe->Yazdir();
	cout << endl;
	cout << "En Kucuk Liste Orta Dugum Adres   :" << kListe->listeOrta<<endl;
	cout << "En Kucuk Liste Degerler  :" << endl;
	kListe->Yazdir();


}