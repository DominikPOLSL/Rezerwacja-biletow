#pragma once
#include <string>
#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>


class Bilet
{
	public:
		std::string kierunek;
		std::string data;
		std::string klasa;
		float cena;
		int licznik;
		static int id;

		void rezerwuj();
		void wypisz();

		Bilet(std::string, std::string, std::string, std::string);
		Bilet() {};
		~Bilet() {};

};

Bilet::Bilet(std::string a, std::string b, std::string c, std::string d)
{
	licznik = ++id;
	kierunek = a;
	data = b;
	cena = std::stof(c);
	klasa = d;
	
}
void Bilet::rezerwuj()
{
	std::fstream plik("zarezerwowane.txt", std::ios::app);
	std::cout << "\n\nZarezerwowano bilet";
	std::cout << "\nKierunek: " << kierunek;
	std::cout << "\nData: " << data;
	std::cout << "\nKlasa: " << klasa;
	
	plik << kierunek << "\n";
	plik << data << "\n";
	plik << cena << "\n";
	plik << klasa << "\n";

	plik.close();
	getchar(); getchar();
}

void Bilet::wypisz()
{
	std::cout << "\nID: " << licznik;
	std::cout << "\nKierunek: " << kierunek;
	std::cout << "\nData: " << data;
	std::cout << "\nCena: " << cena << "PLN";
	std::cout << "\nKlasa: " << klasa;
}


void anulowanie(Vector<Bilet>&zarezerwowane)
{

	std::fstream plik("zarezerwowane.txt", std::ios::out);
	std::string id;

	system("CLS");
	int licznik = 1;
	std::cout << "Posiadane bilety: ";

	for (int i = 0; i < zarezerwowane.size() - 1; i++)
	{
		std::cout << "\n\n" << licznik;
		std::cout << "\n" << zarezerwowane.get(i).kierunek;
		std::cout << "\n" << zarezerwowane.get(i).data;
		std::cout << "\n" << zarezerwowane.get(i).cena << "PLN";
		std::cout << "\n" << zarezerwowane.get(i).klasa;
		licznik++;
	}

	std::cout << "\n\nWybierz ID biletu ktory chcesz anulowac lub wroc ";
	std::cin >> id;


	if (id == "wroc")
		goto koniec;
	else
	{
		std::cout << "\n\nAnulowano bilet";
		zarezerwowane.erase(std::stoi(id) - 1);

		for (int i = 0; i < zarezerwowane.size() - 1; i++)
		{
			plik << zarezerwowane.get(i).kierunek << "\n";
			plik << zarezerwowane.get(i).data << "\n";
			plik << zarezerwowane.get(i).cena << "\n";
			plik << zarezerwowane.get(i).klasa << "\n";
		}
	}


	koniec:
	plik.close();
	getchar(); getchar();

}


void wypiszF(Vector<Bilet>&zarezerwowane)
{
	system("CLS");
	int licznik = 1;
	std::cout << "Posiadane bilety: ";
	for (int i = 0; i < zarezerwowane.size()-1; i++)
	{
		std::cout << "\n\n"<<licznik;
		std::cout << "\n"<< zarezerwowane.get(i).kierunek;
		std::cout << "\n" << zarezerwowane.get(i).data;
		std::cout << "\n" << zarezerwowane.get(i).cena << "PLN";
		std::cout << "\n" << zarezerwowane.get(i).klasa;
		licznik++;
	}

	std::cout << "\n\nWcisznij dowolny przycisk aby powrocic";
	getchar(); getchar();

}


void sorotwanieF(Vector<Bilet>& bilety)
{

	std::string slowo;
	std::cout << "Po czym sortowac? cena, data, kierunek\n";
	std::cin >> slowo;

	if (slowo == "cena")
	{
		auto lambda = [](const Bilet& a, const Bilet& b) { return (a.cena < b.cena); };
		std::sort(bilety.begin(), bilety.end(), lambda);
	}
	else if (slowo == "data")
	{
		auto lambda = [](const Bilet& a, const Bilet& b) { return (a.data < b.data); };
		std::sort(bilety.begin(), bilety.end(), lambda);
	}
	else if (slowo == "kierunek")
	{
		auto lambda = [](const Bilet& a, const Bilet& b) { return (a.kierunek < b.kierunek); };
		std::sort(bilety.begin(), bilety.end(), lambda);
	}

}