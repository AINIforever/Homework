#pragma once
class Polynomial;
class Term {
	friend Polynomial;
public:
	double coef;
	int exp;
};

class Polynomial {
public:
	Polynomial() { this->terms = 0; this->capacity = 100; termArray = new Term[this->capacity]; }
	Polynomial(const  Polynomial & poly);
	~Polynomial() { delete[] termArray; }
	friend Polynomial operator + (Polynomial & pa, Polynomial & pb);
	friend Polynomial operator * (Polynomial & pa, Polynomial & pb);
	Polynomial& operator = (const Polynomial & poly);
	void addTerm(double coef, int exp);
	void inputPoly();
	void outputPoly();
	Term *termArray;
	int capacity;
	int terms;
};
