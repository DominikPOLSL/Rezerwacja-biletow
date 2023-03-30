#include "Vector.h"
#include "Bilet.h"
#include "Opinie.h"
#include <fstream>
#include <iostream>
#include "wsk.h"


enum wybor { rezerwuj = 0, anuluj = 1, wypisz = 2, sortuj = 3, opinia=4,zakoncz = 5 };
int Bilet::id;


std::istream& operator>>(std::istream& is, wybor& wybrano)
{
	std::string name = "";
	is >> name;

	if (name == "rezerwuj")
		wybrano = rezerwuj;
	else if (name == "anuluj")
		wybrano = anuluj;
	else if (name == "wypisz")
		wybrano = wypisz;
	else if (name == "sortuj")
		wybrano = sortuj;
	else if (name == "opinia")
		wybrano = opinia;
	else if (name == "zakoncz")
		wybrano = zakoncz;

	name = "";
	return is;
}

int main()
{
		std::string opiniaZmienna;
		wybor a;
		int b = NULL;
		std::string tekst[4];
		std::fstream plik("dane.txt", std::ios::in);
		Vector<Bilet>bilety = {};
		Vector<Opinia>recenzje = {};


		//ODCZYT BILETOW DO KUPIENIA
		while (!plik.eof())
		{
			for (int i = 0; i < 4; i++)
			{
				plik >> tekst[i];
			}
			Bilet nowy(tekst[0], tekst[1], tekst[2], tekst[3]);
			bilety.push(nowy);
		}
		plik.close();		


	while(true)
	{



		//POSIADANE BILETY
		Vector<Bilet>zarezerwowane = {};
		plik.open("zarezerwowane.txt", std::ios::in);
		Bilet::id = 0;
		while (!plik.eof())
		{
			for (int i = 0; i < 4; i++)
			{
				plik >> tekst[i];
			}
			Bilet nowy(tekst[0], tekst[1], tekst[2], tekst[3]);
			zarezerwowane.push(nowy);
		}
		plik.close();




		system("CLS");
		std::cout << "Dostepne bilety: \n\n\n";
		for (int i = 0; i < bilety.size()-1; i++)
		{
			bilety.get(i).wypisz();
			std::cout << std::endl;
		}




		std::cout << "\n\nDostepne komedny:     rezerwuj, anuluj, wypisz, sortuj, opinia ";
		std::cin >> a;
		switch (a)
		{
			case rezerwuj: 
			{
				std::cout << "Wybierz ID biletu: ";
				std::cin >> b;
				bilety.get(b - 1).rezerwuj();
				break;
			}
			case anuluj:
			{
				anulowanie(zarezerwowane);
				break;
			}
			case wypisz:
			{
				wypiszF(zarezerwowane);
				break;
			}
			case sortuj:
			{
				sorotwanieF(bilety);
				break;
			}
			case opinia:
			{
				std::cout << "Dodaj opinie: ";
				std::cin.ignore();
				getline(cin, opiniaZmienna);
				std::cout << "Ocen w skali 1-10: ";
				std::cin >> b;
				Opinia nowa(opiniaZmienna, b);
				break;
			}
			case zakoncz:
			{
				return 0;
			}
			default:
				std::cout << "Wpisz poprawne polecenie"; getchar(); getchar(); break;
			}
	}
	return 0;
}