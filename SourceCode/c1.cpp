#include"h1.h"
using namespace std;
polynomial::polynomial(const polynomial &x1) {
	this->x = x1.x;
}
polynomial::polynomial(vector<double>& v) {
	this->x = v;
}
polynomial polynomial::operator+(const polynomial& x1) {
	polynomial temp;
	int size = this->x.size();
	int size2 = x1.x.size();
	if (size > size2) {
		for (int i = 0; i < size2; i++) {
			temp.x.push_back(this->x[i] + x1.x[i]);
		}
		for (int i = size2; i < size; i++) {
			temp.x.push_back(this->x[i]);
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			temp.x.push_back(this->x[i] + x1.x[i]);
		}
		for (int i = size; i < size2; i++) {
			temp.x.push_back(x1.x[i]);
		}
	}
	return temp;
}
polynomial polynomial::operator+(const double& x1) {
	int size = this->x.size();
	vector<double> v(size);
	for (int i = 0; i < size; i++) {
		v[i] = this->x[i];
	}
	if(size!=0)
		v[0] += x1;
	else v.push_back(x1);
	polynomial temp(v);
	return temp;
}
polynomial polynomial::operator-(const polynomial& x1) {
	polynomial temp;
	int size = this->x.size();
	int size2 = x1.x.size();
	if (size > size2) {
		for (int i = 0; i < size2; i++) {
			temp.x.push_back(this->x[i] - x1.x[i]);
		}
		for (int i = size2; i < size; i++) {
			temp.x.push_back(this->x[i]);
		}
	}
	else {
		for (int i = 0; i < size; i++) {
			temp.x.push_back(this->x[i] - x1.x[i]);
		}
		for (int i = size; i < size2; i++) {
			temp.x.push_back(-x1.x[i]);
		}
	}
	return temp;
}
polynomial polynomial::operator*(const polynomial& x1) {
	int size = this->x.size();
	int size2 = x1.x.size();
	vector<double> v(size+size2-1);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size2; j++) {
			v[i + j] += this->x[i] * x1.x[j];
		}
	}
	polynomial temp(v);
	return temp;
}
polynomial polynomial::operator*(const double& x1) {
	int size = this->x.size();
	vector<double> v(size);
	for (int i = 0; i < size; i++) {		
		v[i] = this->x[i] * x1;
	}
	polynomial temp(v);
	return temp;
}
polynomial polynomial::operator/(const double& x1) {
	if (x1 == 0) {
		cout << "数除以0!" << endl;
		abort();
	}
	int size = this->x.size();
	vector<double> v(size);
	for (int i = 0; i < size; i++) {
		v[i] = this->x[i] / x1;
	}
	polynomial temp(v);
	return temp;
}
polynomial& polynomial::operator=(polynomial x1) {
	polynomial temp(x1.x);
	this->x = x1.x;
	return temp;
}
double polynomial:: f(double x){
	double res = 0;
	int size = this->x.size();
	for (int i = 0; i < size; i++) {
		res += std::pow(x,i)*this->x[i];
	}
	return res;
}
ostream & operator<<(ostream &out, polynomial obj){
	int size = obj.x.size();
	if (size == 0) return out;
	out << obj.x[size - 1] << "*x^" << size - 1;
	for (int i = size - 2; i >= 0; i--) {
		if (obj.x[i] >= 0) {
			out << '+';
		}
		out << obj.x[i]<<"*x^"<<i;
	}
    return out;
 }
polynomial polynomial::pow(int n) {
	polynomial temp;
	temp.x.push_back(1);
	for (int i = 0; i < n; i++) {
		temp = temp * (*this);
	}
	return temp;
}
double& polynomial:: operator[](int i) {
	return this->x[i];
}
vector<double> SolveEquation(vector<polynomial> v, double e) {
	int size = v.size();
	vector<double> res(size);
	for (int k = 0; k < size-1; k++) {
		if (abs(v[k][k]) <= e) {
			cout << "求解失败" << endl;
			return res;
		}
		else {
			for (int i = k + 1; i < size; i++) {
				double t = v[i][k] / v[k][k];
				v[i][size] = v[i][size] - t * v[k][size];
				for (int j = k + 1; j < size; j++) {
					v[i][j] = v[i][j] - t * v[k][j];
				}
			}
		}
	}
	if (abs(v[size - 1][size - 1]) <= e) {
		cout << "求解失败" << endl;
		return res;
	}
	else {
		res[size - 1] = v[size - 1][size]/v[size-1][size-1];
		for (int i = size - 2; i >= 0; i--) {
			double sum = 0;
			for (int j = i + 1; j < size; j++) {
				sum += v[i][j] * res[j];
			}
			res[i] = (v[i][size] - sum) / v[i][i];
		}
	}
	return res;
}
double distance(double a[], double b[], int len) {
	double sum = 0;
	for (int i = 0; i < len; i++) {
		sum += (a[i] - b[i])*(a[i] - b[i]);
	}
	return sqrt(sum);
}