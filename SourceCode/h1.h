#ifndef _H1
#define _H1
#include<iostream>
#include<ostream>
#include<vector>
#include<string>
#include<stack>
class polynomial {
	friend std::ostream & operator<<(std::ostream &out, polynomial obj);
public:
	std::vector<double> x;
	polynomial() {};
	polynomial(const polynomial &x1);
	polynomial(std::vector<double>& v);
	polynomial operator+(const double& x1);
	polynomial operator+(const polynomial& x1);
	polynomial operator-(const polynomial& x1);
	polynomial operator*(const polynomial& x1);
	polynomial operator*(const double& x1);
	polynomial operator/(const double& x1);
	polynomial& operator=(polynomial x1);
	polynomial pow(int n);
	double& operator[](int i);
	double f(double x);
};
void ex1_1();
void ex1_2();
void ex1_3();
void ex1_4();
void ex1_5();
void ex1_6();
void ex1_7();
void ex2_1();
void ex2_2();
void ex2_3();
void ex2_4();
void ex2_5();
void ex2_6();
void ex2_7();
void ex2_8();
void ex2_9();
void ex2_10();
std::vector<double> SolveEquation(std::vector<polynomial> v, double e=0.001);//高斯消元法
double distance(double a[], double b[], int len);
#endif
