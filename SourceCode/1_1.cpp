#include"h1.h"
#include<iomanip>
using namespace std;
void ex1_1() {
	cout << "理论上等价的两个函数√x*(√(x+1)-√x),√x/(√(x+1)+√x)" << endl;
	cout << "当x从1递增时误差的变化：" << endl;
	for (long long  x = 1; x <= pow(10,14); x *= 10) {
		double diff = sqrt(x + 1) - sqrt(x);
		double sum = sqrt(x + 1) + sqrt(x);
		cout << setprecision(18);
		double f1 = sqrt(x)*(sqrt(x + 1) - sqrt(x));
		double f2 = sqrt(x)/(sqrt(x + 1) + sqrt(x));
		cout << "At x= " << x << ",f1(x)=" << f1 << ",f2=" << f2 << endl;
	}
}