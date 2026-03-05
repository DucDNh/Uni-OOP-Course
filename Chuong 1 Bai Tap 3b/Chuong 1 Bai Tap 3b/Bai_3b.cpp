#include <iostream>

using namespace std;

class PhanSo {
	int tu, mau;
public:
	void nhap() {
		char gachcheo;
		cout << "Nhap phan so : ";
		cin >> tu >> gachcheo >> mau;
	}
	void xuat() {
		if (mau == 1)
			cout << tu << endl;
		else
			cout << tu << '/' << mau << endl;
	}
	bool operator> (PhanSo tem_ps) {
		int tem_tu1 = tu * tem_ps.mau, tem_tu2 = tem_ps.tu * mau;
		return (tem_tu1 > tem_tu2);
	}
};

int main() {
	PhanSo ps1, ps2;
	ps1.nhap();
	ps2.nhap();
	if (ps1 > ps2)
		ps1.xuat();
	else
		ps2.xuat();
	return 0;
}