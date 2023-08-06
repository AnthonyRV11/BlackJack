// Black_Jack.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Anthony Rodriguez Valverde
//Inicio: 28/11/2022
//Finalizado: 4/12/2022
//En este programa nos encontraremos con un blackjack(21) un juego de cartas que gira alrededor de conseguir 21 puntos 
//sin llegar a pasarse

#include <string>
#include <vector>
#include <iomanip>
#include <Windows.h>
#include "BlackJack1.h"
#include "BlackJack2.h"
#define color SetConsoleTextAttribute

int main()
{
	string jugador1 = "", jugador2 = "", jugador3 = "";
	int contador = 0, total = 51, opcionPorJugador = 0, contador12 = 0;
	int tamanioVectorJugador1 = 0, tamanioVectorJugador2 = 0, tamanioVectorJugador3 = 0;
	int sumatoria1 = 0, sumatoria2 = 0, sumatoria3 = 0;
	bool salir = true;
	vector <cartas> barajaCompleta(52);
	vector <cartas> barajaJugador1;
	vector <cartas> barajaJugador2;
	vector <cartas> barajaJugador3;

	llenarBaraja(barajaCompleta);
	CartasIniciales(barajaCompleta, barajaJugador2, barajaJugador3, barajaJugador1, total);
	tamanioVectorJugador1 = barajaJugador1.size();
	tamanioVectorJugador2 = barajaJugador2.size();
	tamanioVectorJugador3 = barajaJugador3.size();

	HANDLE colort = GetStdHandle(STD_OUTPUT_HANDLE);
	color(colort, 7);

	instrucciones();
	system("pause");
	system("cls");


	cout << "\tIngrese el nombre del primer jugador (Puedo agregarlo completo si desea): " << endl;
	getline(cin, jugador1);
	cout << "\tIngrese el nombre del segundo jugador (Puedo agregarlo completo si desea): " << endl;
	getline(cin, jugador2);
	cout << "\tIngrese el nombre del tercer jugador (Puedo agregarlo completo si desea): " << endl;
	getline(cin, jugador3);
	system("pause");
	system("cls");

	do {
		cout << "Turno del jugador: " << jugador1 << endl;
		menuINgame();
		mostrarJugador1(barajaJugador1, tamanioVectorJugador1);
		cin >> opcionPorJugador;
		switch (opcionPorJugador)
		{
		case 1:
			sacarCarta1(barajaJugador1, barajaCompleta, tamanioVectorJugador1, total);
			break;
		default:
			contador += 1;
			break;
		}
		system("pause");
		system("cls");


		cout << "Turno del jugador: " << jugador2 << endl;
		menuINgame();
		mostrarJugador2(barajaJugador2, tamanioVectorJugador2);
		cin >> opcionPorJugador;
		switch (opcionPorJugador)
		{
		case 1:
			sacarCarta2(barajaJugador2, barajaCompleta, tamanioVectorJugador2, total);
			break;
		default:
			contador += 1;
			break;
		}

		system("pause");
		system("cls");


		cout << "Turno del jugador: " << jugador3 << endl;
		menuINgame();
		mostrarJugador3(barajaJugador3, tamanioVectorJugador3);
		cin >> opcionPorJugador;
		switch (opcionPorJugador)
		{
		case 1:
			sacarCarta3(barajaJugador3, barajaCompleta, tamanioVectorJugador3, total);
			break;
		default:
			contador += 1;
			break;
		}
		system("pause");
		system("cls");


		if (contador == 3) {
			buscandoganador(barajaJugador1, barajaJugador2, barajaJugador3, tamanioVectorJugador1, tamanioVectorJugador2, tamanioVectorJugador3, sumatoria1, sumatoria2, sumatoria3);
			cout << "\tJugador 1: " << jugador1 << endl;
			cout << "\tResultado: " << sumatoria1 << endl;
			if (sumatoria1 > 21) {
				cout << "\tSe paso del 21 a conseguir perdiste!!!" << endl;
			}
			else {
				if (sumatoria1 == 21) {
					cout << "\tLogro los 21 puntos,FELICIDADES!!!" << endl;
				}
			}
			cout << endl;
			cout << "\tJugador 2: " << jugador2 << endl;
			cout << "\tResultado: " << sumatoria2 << endl;
			if (sumatoria2 > 21) {
				cout << "\tSe paso del 21 a conseguir perdiste!!!" << endl;
			}
			else {
				if (sumatoria2 == 21) {
					cout << "\tLogro los 21 puntos,FELICIDADES!!!" << endl;
				}
			}
			cout << endl;
			cout << "\tJugador 3: " << jugador3 << endl;
			cout << "\tResultado: " << sumatoria3 << endl;
			if (sumatoria3 > 21) {
				cout << "\tSe paso del 21 a conseguir perdiste!!!" << endl;
			}
			else {
				if (sumatoria3 == 21) {
					cout << "\tLogro los 21 puntos,FELICIDADES!!!" << endl;
				}
			}
			cout << endl;
			system("pause");
			system("cls");
			if (sumatoria1 <= 21 && sumatoria1 > sumatoria2 && sumatoria1 > sumatoria3) {
				cout << "\tEl ganador es el jugador 1: " << jugador1 << " FELICIDADES!!!" << endl;
			}
			else {
				if (sumatoria2 <= 21 && sumatoria2 > sumatoria1 && sumatoria2 > sumatoria3) {
					cout << "\tEl ganador es el jugador 2: " << jugador2 << " FELICIDADES!!!" << endl;
				}
				else {
					if (sumatoria3 <= 21 && sumatoria3 > sumatoria1 && sumatoria3 > sumatoria2) {
						cout << "\tEl ganador es el jugador 3: " << jugador3 << " FELICIDADES!!!" << endl;
					}
					else {
						cout << "\tTodos se pasaron de 21, PERDIERON!!!" << endl;
					}
				}
			}



			salir = false;
		}
		else {
			contador = 0;
		}


	} while (salir == true);

}

