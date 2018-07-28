#include <iostream>
#include "poly.h"
using namespace std;


Polynomial::Polynomial(const  Polynomial & poly) {
	this->terms = 0;
	this->capacity = poly.capacity;
	termArray = new Term[this->capacity];
	for (int i = 0; i < poly.terms; i++)
		addTerm(poly.termArray[i].coef, poly.termArray[i].exp);
}

Polynomial operator+(Polynomial & pa, Polynomial & pb)
{
	Polynomial pc;
	int posA = 0, posB = 0;
	while (posA < pa.terms && posB < pb.terms) {
		if (pa.termArray[posA].exp == pb.termArray[posB].exp) {
			pc.addTerm(pa.termArray[posA].coef + pb.termArray[posB].coef, pa.termArray[posA].exp);
			posA++;
			posB++;
		}
		else if(pa.termArray[posB].exp < pb.termArray[posB].exp){
			pc.addTerm(pb.termArray[posB].coef, pb.termArray[posB].exp);
			posB++;
		}
		else {
			pc.addTerm(pa.termArray[posA].coef, pa.termArray[posA].exp);
			posA++;
		}
	}
	while (posA < pa.terms) {
		pc.addTerm(pa.termArray[posA].coef, pa.termArray[posA].exp);
		posA++;
	}
	while (posB < pb.terms) {
		pc.addTerm(pb.termArray[posB].coef, pb.termArray[posB].exp);
		posB++;
	}
	cout << "Their addtion is:" << endl;
	return pc;
}

Polynomial operator*(Polynomial & pa, Polynomial & pb)
{
	Polynomial pc;
	for (int i = 0; i < pa.terms; i++) {
		for (int j = 0; j < pb.terms; j++) {
			pc.addTerm(pa.termArray[i].coef*pb.termArray[j].coef, pa.termArray[i].exp+pb.termArray[j].exp);
		}
	}
	cout << "Their multiple is:" << endl;
	return pc;
}



Polynomial& Polynomial::operator=(const Polynomial & poly)
{
	
	for (int i = 0; i < poly.terms; i++) {
		termArray[i].coef = poly.termArray[i].coef;
		termArray[i].exp = poly.termArray[i].exp;
	}
	terms = poly.terms;
	capacity = poly.capacity;
	return *this;
}

void Polynomial::addTerm(double coef, int exp) {
	int index = 0;
	while (index < terms && exp < termArray[index].exp)
		index++;
	if (exp == termArray[index].exp) {
		termArray[index].coef += coef;
		if (termArray[index].coef == 0) {
			for (int j = index; j < terms - 1; j++)
				termArray[j] = termArray[j + 1];
			terms--;
		}
	}
	else {
		for (int j = terms-1; j>index-1; j--)
			termArray[j + 1] = termArray[j];
		termArray[index].coef = coef;
		termArray[index].exp = exp;
		terms++;
	}
}

void Polynomial::inputPoly()
{
	int n;
	cout << "What is the number of your Polynomial's terms? " << endl;
	cin >> n;
	double *coefs = new double[n];
	int *exps = new int[n];

	cout << "Please enter the coefs of your Polynomial:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> coefs[i];
	}
	cout << "Please enter the exps of your Polynomial:" << endl;
	for (int i = 0; i < n; i++) {
		cin >> exps[i];
	}
	for (int i = 0; i < n; i++) {
		addTerm(coefs[i],exps[i]);
	}

}

void Polynomial::outputPoly()
{
	for (int i = 0; i < terms-1; i++) {
		cout << termArray[i].coef<<"x^"<< termArray[i].exp<<"+";
	}
	cout << termArray[terms - 1].coef << "x^" << termArray[terms - 1].exp << endl;
}

int main() {
	Polynomial ah, bh, ch;

	ah.inputPoly();
	ah.outputPoly();
	bh.inputPoly();
	bh.outputPoly();

	ch = ah * bh;
	ch.outputPoly();

	system("pause");
	return 0;
}

