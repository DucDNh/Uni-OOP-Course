#include <iostream>

using namespace std;

int gcd(int a, int b) {
	a = abs(a); 
	b = abs(b);
	while (a != 0 && b != 0) {
		if (a >= b)
			a %= b;
		else
			b %= a;
		if (a == 0)
			return b;
		else
			return a;
	}
}

class Phanso {
	int tu, mau;
public :
	void nhap() {
		char gachcheo;
		cout << "Nhap phan so : ";
		cin >> tu >> gachcheo >> mau;
	}
	void rut_gon() {
		int ucnn = gcd(tu, mau);
		tu /= ucnn;
		mau /= ucnn;
	}
	void xuat() {
		if (mau == 1)
			cout << tu << endl;
		else
			cout << tu << '/' << mau << endl;
	}
};

int main() {
	Phanso ps1;
	ps1.nhap();
	ps1.rut_gon();
	ps1.xuat();
	return 0;
}