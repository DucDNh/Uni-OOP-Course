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
	}
	if (a == 0)
		return b;
	else
		return a;
}

class phanso {
	int tu, mau;
public:
	void nhap() {
		char gachcheo;
		cout << "Nhap phan so : ";
		cin >> tu >> gachcheo >> mau;
	}
	void rut_gon() {
		if (mau == 0) return;
		int ucnn = gcd(tu, mau);
		tu /= ucnn;
		mau /= ucnn;
	}
	void xuat() {
		int tem_tu = abs(tu), tem_mau = abs(mau);
		if (tu * mau < 0) cout << '-';
		if (tem_mau == 1)
			cout << tem_tu << endl;
		else
			cout << tem_tu << '/' << tem_mau << endl;
	}
	phanso operator+ (phanso ps) {
		phanso tem_ps;
		tem_ps.tu = (tu * ps.mau) + (ps.tu * mau);
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator- (phanso ps) {
		phanso tem_ps;
		tem_ps.tu = tu * ps.mau - ps.tu * mau;
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator* (phanso ps) {
		phanso tem_ps;
		tem_ps.tu = tu * ps.tu;
		tem_ps.mau = mau * ps.mau;
		tem_ps.rut_gon();
		return tem_ps;
	}
	phanso operator/ (phanso ps) {
		phanso tem_ps;
		tem_ps.tu = tu * ps.mau;
		tem_ps.mau = mau * ps.tu;
		tem_ps.rut_gon();
		return tem_ps;
	}
	bool zero_check() {
		return (mau == 0);
	}
};

int main() {
	phanso ps1, ps2;
	ps1.nhap();
	ps2.nhap();
	phanso ps_tong = ps1 + ps2, ps_hieu = ps1 - ps2, ps_tich = ps1 * ps2, ps_thuong = ps1 / ps2;
	cout << "Tong 2 Phan So : ";
	ps_tong.xuat();
	cout << "Hieu 2 Phan So : ";
	ps_hieu.xuat();
	cout << "Tich 2 Phan So : ";
	ps_tich.xuat();
	if (ps_thuong.zero_check())
		cout << "Ko the thuc hien phep chia !" << endl;
	else {
		cout << "Thuong 2 Phan So : ";
		ps_thuong.xuat();
	}
	return 0;
}