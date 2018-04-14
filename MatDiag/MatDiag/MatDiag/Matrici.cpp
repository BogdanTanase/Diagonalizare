#include "Matrici.h"
#include <iostream>
using namespace std;

Matrici::Matrici() {
	diagonalizabila = true;
	cout << "n=";
	cin >> n;
	cout << "m=";
	cin >> m;
	A.resize(n);
	U.resize(n);
	D.resize(n);
	V.resize(m);
	for (int i = 0; i < n; i++) {
		U[i].resize(n);
		A[i].resize(m);
		D[i].resize(m);
	}
	for (int i = 0; i < m; i++) {
		V[i].resize(m);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				U[i][j] = 1;
			}
			else {
				U[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << "A[" << i << "][" << j << "]=";
			cin >> A[i][j];
			D[i][j] = A[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			if (i == j) {
				V[i][j] = 1;
			}
			else {
				V[i][j] = 0;
			}
		}
	}
}

void Matrici::meniu() {
	int decizie = 11;
	int i, j, x;
	while (decizie != 10) {
		cout << "**Diagonalizatron V2.7 By Tanase Bogdan**\n";
		cout << "|=======================================|\n";
		cout << "| Tij*: 0 | *Tij: 1 | Pij*: 2 | *Pij: 3 |\n";
		cout << "|---------------------------------------|\n";
		cout << "|    U: 4 |    A: 5 |    V: 6 |    D: 7 |\n";
		cout << "|---------------------------------------|\n";
		cout << "| Diagonalizare:  8 |         | Exit:10 |\n";
		cout << "|=======================================|\n";
		cout << " Decizie :";
		cin >> decizie;
		switch (decizie) {
		case 0: {
			cin >> i;
			cin >> j;
			cin >> x;
			Tijo(i, j, x);
			break;
		}
		case 1: {
			cin >> i;
			cin >> j;
			cin >> x;
			oTij(i, j, x);
			break;
		}
		case 2: {
			cin >> i;
			cin >> j;
			Pijo(i, j);
			break;
		}
		case 3: {
			cin >> i;
			cin >> j;
			oPij(i, j);
			break;
		}
		case 4: {
			cout << "Matricea U:\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << U[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 5: {
			cout << "Matricea A:\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << A[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 6: {
			cout << " Matrcicea V:\n";
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					cout << V[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 7: {
			cout << " Matricea D:\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << D[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 8: {
			diagonalizeaza();
			break;
		}
		}
	}
}

void Matrici::Tijo(int i, int j, int x) {
	for (int a = 0; a < m; a++) {
		D[i][a] += D[j][a] * x;
	}
	for (int a = 0; a < n; a++) {
		U[i][a] += U[j][a] * x;
	}
}
void Matrici::oTij(int i, int j, int x) {
	for (int a = 0; a < n; a++) {
		D[a][j] += D[a][i] * x;
	}
	for (int a = 0; a < m; a++) {
		V[a][j] += V[a][i] * x;
	}
}
void Matrici::Pijo(int i, int j) {
	for (int a = 0; a < m; a++) {
		int tmp = D[i][a];
		D[i][a] = D[j][a];
		D[j][a] = tmp;
	}
	for (int a = 0; a < n; a++) {
		int tmp = U[j][a]; 
		U[j][a] = U[i][a];
		U[i][a] = tmp;
	}
}
void Matrici::oPij(int i, int j) {
	for (int a = 0; a < n; a++) {
		int tmp = D[a][j];
		D[a][j] = D[a][i];
		D[a][i] = tmp;
	}
	for (int a = 0; a < m; a++) {
		int tmp = V[a][j];
		V[a][j] = V[a][i];
		V[a][i] = tmp;
	}
}
int Matrici::divide(int k) {
	if (D[k][k] == 0) {
		return 3;
	}
	else {
		for (int i = k; i < n; i++) {
			if (D[i][k] % D[k][k] != 0) {
				return 1;
			}
		}
		for (int j = k; j < m; j++) {
			if (D[k][j] % D[k][k] != 0) {
				return 2;
			}
		}
		return 0;
	}

}//1 nu divide pe coloana , 2 nu divide pe linie , 3 e 0 , 0 ok
void Matrici::min(int k) {
	int is = k;
	int js = k;
	int min = D[k][k];
	if (min == 0) {
		min = 46340; // max int 
	}

	for (int i = k; i < n; i++) {
		for (int j = k; j < m; j++) {
			if (min * min > D[i][j] * D[i][j] && D[i][j] != 0 && min * min != D[i][j] * D[i][j]) {
				min = D[i][j];
				is = i;
				js = j;
			}
		}
	}
	if (is == k && js != k) {
		oPij(k, js);
	}
	if (is != k && js == k) {
		Pijo(k, is);
	}
	if (is != k && js != k) {
		oPij(k, js);
		Pijo(is, k);
	}
}
int Matrici::minL(int k) {
	int min = D[k][k + 1] % D[k][k];
	int js = k + 1;
	for (int j = k + 1; j < m; j++) {
		if ( min < D[k][j] % D[k][k] && D[k][j] != 0 && D[k][j] % D[k][k] != 0) {
			min = D[k][j] % D[k][k];
			js = j;
		}
	}
	return js;
}
int Matrici::minC(int k) {
	int min = D[k + 1][k] % D[k][k];
	int is = k + 1;
	for (int i = k + 1; i < n; i++) {
		if ( min < D[i][k] % D[k][k] && D[i][k] != 0 && D[i][k] % D[k][k] != 0) {
			min = D[i][k] % D[k][k];
			is = i;
		}
	}
	return is;
}
void Matrici::proceseasa(int k) {
	for (int i = k + 1; i < n; i++) {
		Tijo(i, k, (D[i][k] / D[k][k])*(-1));
	}
	for (int j = k + 1; j < m; j++) {
		oTij(k, j, (D[k][j] / D[k][k])*(-1));
	}
}
int Matrici::diagonalizeaza() {
	if (diagonalizabila == false) {
		cout << "Matrica este deja in forma diagonalizata";
		return 1;
	}
	else {
		diagonalizabila = false;
		int stop = n;
		if (m < n) {
			stop = m;
		}
		int caz = 11;
		for (int k = 0; k < stop; k++) {
			min(k);
			caz = divide(k);
			switch (caz) {
			case 0: {
				proceseasa(k);
				break;
			}
			case 1: { //coloana
				int i = minC(k);
				Tijo(i, k, (D[i][k] / D[k][k])*(-1));
				k--;
				break;
			}
			case 2: {//linie
				int j = minL(k);
				oTij(k, j, (D[k][j] / D[k][k])*(-1));
				k--;
				break;
			}
			case 3: {
				return 0;
				break;
			}
			}
		}
		return 0;
	}
}

