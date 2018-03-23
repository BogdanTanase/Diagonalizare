#pragma once
#ifndef MATRICI_H
#define MATRICI_H

#include <vector>
using namespace std;

class Matrici {
private:
	int n;
	int m;
	bool diagonalizabila;
	vector<vector<int>>U;
	vector<vector<int>>A;
	vector<vector<int>>V;
	vector<vector<int>>D;

	void Tijo(int, int, int);
	void oTij(int, int, int);
	void Pijo(int, int);
	void oPij(int, int);
	int divide(int);
	void min(int);
	int minC(int);
	int minL(int);
	void proceseasa(int);
	int diagonalizeaza();
public:
	Matrici();
	void meniu();

};


#endif // !MATRICI_H
