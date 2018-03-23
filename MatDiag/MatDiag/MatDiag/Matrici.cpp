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

}