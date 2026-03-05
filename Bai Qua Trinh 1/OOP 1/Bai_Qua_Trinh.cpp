#include <iostream>
#include <string>

using namespace std;

class HocSinh {
	string ma_HS, ho_Ten;
	double d_toan, d_van, d_ly, d_hoa, d_tb;
public :
	void nhap_thong_tin() {
		cout << "Nhap ma hoc sinh : ";
		cin >> ma_HS;
		cout << "Nhap ho va ten : ";
		cin.ignore();
		getline(cin, ho_Ten);
		cout << "Nhap diem toan : ";
		cin >> d_toan;
		cout << "Nhap diem van : ";
		cin >> d_van;
		cout << "Nhap diem ly : ";
		cin >> d_ly;
		cout << "Nhap diem hoa : ";
		cin >> d_hoa;
		d_tb = (d_toan + d_van + d_ly + d_hoa) / 4.0;
	}
	void xuat_thong_tin() {
		cout << "Thong tin cua " << ho_Ten << " : " << endl;
		cout << "Ma Hoc Sinh : " << ma_HS << endl;
		cout << "Diem Toan : " << d_toan << endl;
		cout << "Diem Van : " << d_van << endl;
		cout << "Diem Ly : " << d_ly << endl;
		cout << "Diem Hoa : " << d_hoa << endl;
		cout << "Diem trung binh : " << d_tb << endl;
	}
};

int main() {
	HocSinh hocsinh1;
	hocsinh1.nhap_thong_tin();
	hocsinh1.xuat_thong_tin();
	return 0;
}