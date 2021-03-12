#include <iostream>
#include <fstream>
#include <string>
#include "CiftYonluBagilListe.h"
using namespace std;

int main() 
{
	ifstream dosya;
	dosya.open("Sayilar.txt");
	string satir;
	int satirSayisi = 0;
	while (!dosya.eof()) 
	{
		getline(dosya, satir);
		if (satir != "") 
		{
			satirSayisi++;
		}
	}
	dosya.close();
	dosya.open("Sayilar.txt");
	CiftYonluBagilListe** listeler = new CiftYonluBagilListe *[satirSayisi];
	satirSayisi = 0;
	while (!dosya.eof()) 
	{
		getline(dosya, satir);
		int sayiCount = 0;
		for (int i = 0;i < satir.length();i++)
		{
			if (satir[i] == ' ') 
			{
				sayiCount++;
			}
		}
		int *sayilar=new int[sayiCount+1];
		string newSayi = "";
		sayiCount = 0;
		for (int i = 0;i < satir.length();i++) 
		{
			if (satir[i] != ' ') 
			{
				newSayi = newSayi + satir[i];
				if (i == satir.length() - 1)
				{
					sayilar[sayiCount] = atoi(newSayi.c_str());
					newSayi = "";
					sayiCount++;
				}
			}
			else 
			{
				int sayi = atoi(newSayi.c_str());
				sayilar[sayiCount] = sayi;
				sayiCount++;
				newSayi = "";
			}
		}
		CiftYonluBagilListe *liste = new CiftYonluBagilListe();
		liste->Ekle(sayilar, sayiCount);
		listeler[satirSayisi] = liste;
		satirSayisi++;
	}
	CiftYonluBagilListe::Caprazla(listeler,satirSayisi);

	for (int i = 0;i < satirSayisi;i++) 
	{
		delete[] listeler[i];
		listeler[i] = NULL;
	}
	delete[] listeler;
	return 0;
}

