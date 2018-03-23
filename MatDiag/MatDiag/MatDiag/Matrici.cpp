#include "Matrici.h"
#include <iostream>
using namespace std;

Matrici::Matrici() {
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
		cout << "|=================================|\n";
		cout << "| Tijo- 0 oTij- 1 Pijo- 2 oPij- 3 |\n";
		cout << "|    U- 4    A- 5    V- 6    D- 7 |\n";
		cout << "|=================================|\n";
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
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					cout << U[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 5: {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << A[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 6: {
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < m; j++) {
					cout << V[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 7: {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << D[i][j] << " ";
				}
				cout << "\n";
			}
			break;
		}
		case 8: {
			break;
		}
		case 9: {
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
		U[a][j] += U[a][i] * x;
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
		int tmp = U[a][j]; 
		U[a][j] = U[a][i];
		U[a][i] = tmp;
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
	int is, ij;
	int min = D[k][k];

}
void Matrici::proceseasa(int k) {

}
void Matrici::diagonalizeaza() {

}
