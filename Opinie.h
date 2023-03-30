#pragma once
#include <string>
#include "Vector.h"
#include "wsk.h"
#include <fstream>
class Opinia
{
public:

	std::string recenzja;
	int ocena;

	Opinia() {};
	~Opinia() {};
	Opinia(std::string, int);
};

Opinia::Opinia(std::string a, int b)
{
	std::fstream plik("opinie.txt", std::ios::app);
	recenzja = a;
	ocena = b;

	plik << "\nOpinia: " << recenzja << "\n";
	plik << "Ocena: "<< ocena << "/10\n";
	plik.close();
	
}