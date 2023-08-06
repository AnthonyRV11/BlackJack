#pragma once
#include <iostream> //Llamamos las librerias que vamos a necesitar
#include "BlackJack2.h"
#include <time.h>
using namespace std;
void instrucciones() { //Funcion para crear las instrucciones del juego
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\tBIENVENIDOS AL BLACKJACK (21)" << endl;
	cout << "\tINSTRUCCIONES: " << endl;
	cout << "\tAcontinuacion se le solicitara los nombres de los jugadores." << endl;
	cout << "\tEl juego les repartira 2 cartas a cada uno." << endl;
	cout << "\tSi llega a pasarse de 21 puntos el jugador pierde." << endl;
	cout << "\tSi alguno le toca el as el juego decidira su valor en la partida." << endl;
	cout << "\tPor ronda cada jugador decidira si tomar o no otra carta." << endl;
	cout << "\tSi consiguen los 21 puntos ganan, y si no ganara el que tiene el valor mas cercano." << endl;
	cout << "\tEn el momento que ninguno desee tomar alguna se terminara y revisara los masos de cada uno." << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\tTabla de puntos:" << endl;
	cout << "\tEn la baraja cada carta num\202rica vale sus respectivos puntos." << endl;
	cout << "\tCada carta con dibujo (J, Q, K) tiene un valor de 10." << endl;
	cout << "\tEl As vale 1 u 11  puntos." << endl;
	cout << "\tMucha suerte a cada uno, y sobre todo disfrutenlo!!!" << endl;
	cout << "----------------------------------------------------------------------------------------------------------------------" << endl;
}

//***********************************************************************************************



void llenarBaraja(std::vector<cartas>& barajaCompleta) {
	std::string corazones = "\3", diamantes = "\4", treboles = "\5", picas = "\6";
	int v = 1;

	for (int i = 0; i < 52; i++) {
		barajaCompleta[i].numero = v;

		if (i % 13 == 0) {
			barajaCompleta[i].signo = "A";
		}
		else if (i % 13 >= 1 && i % 13 <= 9) {
			barajaCompleta[i].signo = std::to_string(i % 13 + 1);
		}
		else if (i % 13 == 10) {
			barajaCompleta[i].signo = "J";
		}
		else if (i % 13 == 11) {
			barajaCompleta[i].signo = "Q";
		}
		else if (i % 13 == 12) {
			barajaCompleta[i].signo = "K";
		}

		if (i >= 0 && i < 13) {
			barajaCompleta[i].signo += corazones;
		}
		else if (i >= 13 && i < 26) {
			barajaCompleta[i].signo += diamantes;
		}
		else if (i >= 26 && i < 39) {
			barajaCompleta[i].signo += treboles;
		}
		else if (i >= 39 && i < 52) {
			barajaCompleta[i].signo += picas;
		}

		v++;
		if (v == 14) {
			v = 1;
		}
	}
}
//***********************************************************************************************


void CartasIniciales(vector <cartas> barajaCompleta, vector <cartas>& barajaJugador1, vector <cartas>& barajaJugador2, vector <cartas>& barajaJugador3, int& total) {
	int num = 0, contador = 0; //Funcion para asignarle de forma aleatoria al usuario las cartas
	cartas lleno;
	srand(time(NULL));

	for (int i = 0; i < 2; i++) {
		num = rand() % total;
		lleno = barajaCompleta[num];
		barajaCompleta.erase(barajaCompleta.begin() + num);
		barajaJugador1.insert(barajaJugador1.begin(), lleno);
		total -= 1;
	}

	for (int i = 0; i < 2; i++) {
		num = rand() % total;
		lleno = barajaCompleta[num];
		barajaCompleta.erase(barajaCompleta.begin() + num);
		barajaJugador2.insert(barajaJugador2.begin(), lleno);
		total -= 1;
	}

	for (int i = 0; i < 2; i++) {
		num = rand() % total;
		lleno = barajaCompleta[num];
		barajaCompleta.erase(barajaCompleta.begin() + num);
		barajaJugador3.insert(barajaJugador3.begin(), lleno);
		total -= 1;
	}

}

//***********************************************************************************************

void menuINgame() { //Menu dentro del juego para que el usuario pueda pasar o tomar otra carta
	cout << "\t1.Para sacar otra carta." << endl;
	cout << "\t2.Para pasar de turno." << endl;
}

//***********************************************************************************************

void mostrarJugador1(vector <cartas> barajaJugador1, int tamanio1) { //Funcion que toma el primer vector dinamico y lo recorre para mostrarle las cartas al usuario
	cout << "\tSu baraja: " << endl;

	cout << endl;
	for (int i = 0; i < tamanio1; i++) {
		cout << "[" << barajaJugador1[i].numero << " | " << barajaJugador1[i].signo << "]" << "   ";
	}

}

void mostrarJugador2(vector <cartas> barajaJugador2, int tamanio2) {//Funcion que toma el segundo vector dinamico y lo recorre para mostrarle las cartas al usuario
	cout << "\tSu baraja: " << endl;

	cout << endl;
	for (int i = 0; i < tamanio2; i++) {
		cout << "[" << barajaJugador2[i].numero << " | " << barajaJugador2[i].signo << "]" << "   ";
	}

}

void mostrarJugador3(vector <cartas> barajaJugador3, int tamanio3) { //Funcion que toma el tercer vector dinamico y lo recorre para mostrarle las cartas al usuario
	cout << "\tSu baraja: " << endl;

	cout << endl;
	for (int i = 0; i < tamanio3; i++) {
		cout << "[" << barajaJugador3[i].numero << " | " << barajaJugador3[i].signo << "]" << "   ";
	}

}

//***********************************************************************************************


void sacarCarta1(vector <cartas>& barajaJugador1, vector <cartas>& barajaCompleta, int& tamanioVectorJugador1, int& total) {
	int num = 0;  //Funcion para poder sacar una carta
	cartas ingresando;
	srand(time(NULL));

	num = rand() % total;
	total -= 1;

	ingresando = barajaCompleta[num];
	barajaCompleta.erase(barajaCompleta.begin() + num);
	barajaJugador1.insert(barajaJugador1.begin(), ingresando);

	tamanioVectorJugador1 = barajaJugador1.size();

	cout << "\tLa carta que te toco es: " << endl;

	cout << "[" << barajaJugador1[0].numero << "|" << barajaJugador1[0].signo << "]" << endl;

}

void sacarCarta2(vector <cartas>& barajaJugador2, vector <cartas>& barajaCompleta, int& tamanioVectorJugador2, int& total) {
	int num = 0; //Funcion para sacar una carta
	cartas ingresando;
	srand(time(NULL));

	num = rand() % total;
	total -= 1;

	ingresando = barajaCompleta[num];
	barajaCompleta.erase(barajaCompleta.begin() + num);
	barajaJugador2.insert(barajaJugador2.begin(), ingresando);

	tamanioVectorJugador2 = barajaJugador2.size();

	cout << "\tLa carta que te toco es: " << endl;

	cout << "[" << barajaJugador2[0].numero << "|" << barajaJugador2[0].signo << "]" << endl;

}

void sacarCarta3(vector <cartas>& barajaJugador3, vector <cartas>& barajaCompleta, int& tamanioVectorJugador3, int& total) {
	int num = 0; //Funcion para poder sacar una carta
	cartas ingresando;
	srand(time(NULL));

	num = rand() % total;
	total -= 1;

	ingresando = barajaCompleta[num];
	barajaCompleta.erase(barajaCompleta.begin() + num);
	barajaJugador3.insert(barajaJugador3.begin(), ingresando);

	tamanioVectorJugador3 = barajaJugador3.size();

	cout << "\tLa carta que te toco es: " << endl;

	cout << "[" << barajaJugador3[0].numero << "|" << barajaJugador3[0].signo << "]" << endl;

}

//***********************************************************************************************

void buscandoganador(vector <cartas> barajaJugador1, vector <cartas> barajaJugador2, vector <cartas> barajaJugador3, int tamanio1, int tamanio2, int tamanio3, int& sumatoria1, int& sumatoria2, int& sumatoria3) {
	int AS = 0;


	for (int i = 0; i < tamanio1; i++) {
		if (barajaJugador1[i].numero == 1) {
			cout << "Jugador 1, digita que valor desea su AS si 1.(SU VALOR SERIA 1) o 2.(SU VALOR SERIA 11)" << endl;
			cin >> AS;
			system("cls");
			switch (AS)
			{
			case 1:

				sumatoria1 += 1;
			default:
				sumatoria1 += 11;
				break;
			}
		}
		else {
			if (barajaJugador1[i].numero > 10) {
				sumatoria1 += 10;
			}
			else {
				sumatoria1 += barajaJugador1[i].numero;
			}
		}


	}

	for (int i = 0; i < tamanio2; i++) {
		if (barajaJugador2[i].numero == 1) {
			cout << "Jugador 1, digita que valor desea su AS si 1.(SU VALOR SERIA 1) o 2.(SU VALOR SERIA 11)" << endl;
			cin >> AS;
			system("cls");
			switch (AS)
			{
			case 1:

				sumatoria2 += 1;
			default:
				sumatoria2 += 11;
				break;
			}
		}
		else {
			if (barajaJugador2[i].numero > 10) {
				sumatoria2 += 10;
			}
			else {
				sumatoria2 += barajaJugador2[i].numero;
			}
		}


	}


	for (int i = 0; i < tamanio3; i++) {
		if (barajaJugador3[i].numero == 1) {
			cout << "Jugador 1, digita que valor desea su AS si 1.(SU VALOR SERIA 1) o 2.(SU VALOR SERIA 11)" << endl;
			cin >> AS;
			system("cls");
			switch (AS)
			{
			case 1:

				sumatoria3 += 1;
			default:
				sumatoria3 += 11;
				break;
			}
		}
		else {
			if (barajaJugador3[i].numero > 10) {
				sumatoria3 += 10;
			}
			else {
				sumatoria3 += barajaJugador3[i].numero;
			}
		}


	}
	//Esta ultima funcion hace una sumatoria de todas las cartas si se encuentra un as le hace la pregunta al usuario de su valor y se modifica para compararse en el main el ganador
}