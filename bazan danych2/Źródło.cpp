

using namespace std;
#include<iostream>		
#include<string>			
#include<fstream>
#include <vector>

struct Sklepzbronia
{
	string Nazwa;
	string Kraj;
	string Producent;
	float Waga;
	float Kaliber;
};


void dodaj()
{
	Sklepzbronia* P = new Sklepzbronia;
	string Nazwa;
	string Kraj;
	string Producent;
	float Waga = 0;
	float Kaliber =0;
	cout << "Witaj dodaj Nazwe ,Kraj ,Producenta ,Wage , Kaliber broni" << endl;
	cin >> Nazwa;
	P-> Nazwa = Nazwa;
	cin >> Kraj;
	P->Kraj = Kraj;
	P->Producent = Producent;
	cin >> Producent;
	P->Waga = Waga;
	cin >> Waga;
	P->Kaliber = Kaliber;
	cin >> Kaliber;
	system("CLS");
	fstream Uchwyt3;
	Uchwyt3.open("BazaDanych.txt", ios::app);
	Uchwyt3 << Nazwa<< " ";
	Uchwyt3 << Kraj<<" ";
	Uchwyt3 << Producent<<" ";
	Uchwyt3 << Waga<<" ";
	Uchwyt3 << Kaliber<<'\n';
}


void wyswietl()
{
	fstream Uchwyt;
	Uchwyt.open("BazaDanych.txt");
	string Odczyt;
	while(getline(Uchwyt , Odczyt))
	{
		cout << Odczyt <<endl;
	}
	Uchwyt.close();
}
void znajdz()
{
	int i=0;
	string ZmiennaX;
	cout << "Wprowadz nazwe broni, ktora chcesz wyswietlic" << endl;
	cin >> ZmiennaX;
	fstream Uchwyt;
	Uchwyt.open("BazaDanych.txt", ios::in);
	string Odczyt;
	system("CLS");
	if (Uchwyt.is_open())
	{
		while (getline(Uchwyt, Odczyt))
		{
			if (Odczyt.find(ZmiennaX) != string::npos)
				cout << Odczyt << endl;			
		}
		Uchwyt.close();
	}	
	Uchwyt.close();
}

void usun()
{
	int i = 0;
	string X;
	cout << "Wprowadz nazwe broni, ktora chcesz usunac";
	cin >> X;
	fstream Uchwyt1;
	fstream Uchwyt2;
	Uchwyt1.open("BazaDanych.txt");
	Uchwyt2.open("Usuwanie.txt", ios::out|ios::trunc);
	string Odczyt;
	system("CLS");
	while (getline(Uchwyt1, Odczyt))
	{
		
		
		if (Odczyt.find(X) == string::npos)
		{
			Uchwyt2 << Odczyt << endl;
		}

			
		
	}
	Uchwyt1.close();
	Uchwyt2.close();
		rename("BazaDanych.txt", "Temp.txt");
		rename("Usuwanie.txt", "BazaDanych.txt");
		rename("Temp.txt", "Usuwanie.txt");
}

void menu()
{
	cout << "Wybierz polecenie" << '\n';
	cout << "Dodaj element - (Nacisnij '1')" << '\n';
	cout << "Usun element - (Nacisnij '2')" << '\n';
	cout << "Wyswietl elementy - (Nacisnij '3')" << '\n';
	cout << "Znajdz - (Nacisnij '4')" << '\n';
	cout << "Zakoncz - (Nacisnij '0')" << '\n';
}

int main(void)
{	
	bool run = true;
	int wybor;
	while (run)
	{
		menu();
		cout << "Wybierz operacje" << endl;
		cin >> wybor;
		system("CLS");
		switch (wybor)
		{
		case 1:

			dodaj();
			break;

		case 2:

			usun();
			break;

		case 3:

			wyswietl();
			break;
		case 4:

			znajdz();
			break;

		case 5:
			run = false;
			system("CLS");
			break;
		default:
			cout << "Wybrano niepoprawna operacje" << endl;
		}
		char temp;
		cout << "Klikniecie przenosi do MENU" << endl;
		cin >> temp;
		system("CLS");
	}
	
	
	return 0;
}