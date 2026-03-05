#include <iostream>

using namespace std;

int max_days(int monthh, int yearr) {
	if (monthh == 2) {
		if ((yearr % 400 == 0) || (yearr % 4 == 0 && yearr % 100 != 0)) {
			return 29;
		}
		else {
			return 28;
		}
	}
	else if (monthh == 1 || monthh == 3 || monthh == 5 || monthh == 7 || monthh == 8 || monthh == 10 || monthh == 12) {
		return 31;
	}
	else {
		return 30;
	}
}

class Date {
	int day, month, year;
public :
	void nhap() {
		char a, b;
		cout << "Nhap ngay/thang/nam : ";
		cin >> day >> a >> month >> b >> year;
	}
	void xuat() {
		cout << day << '/' << month << '/' << year;
	}
	Date next_date() {
		Date tem_date;
		tem_date.day = day + 1;
		tem_date.month = month;
		tem_date.year = year;
		if (tem_date.day > max_days(month, year)) {
			tem_date.day = 1;
			tem_date.month++;
			if (tem_date.month > 12) {
				tem_date.month = 1;
				tem_date.year++;
			}
		}
		return tem_date;
	}
};

int main() {
	Date ngay_hien_tai;
	ngay_hien_tai.nhap();
	Date ngay_tiep_theo = ngay_hien_tai.next_date();
	cout << "Ngay tiep theo cua ngay da nhap la : ";
	ngay_tiep_theo.xuat();
	return 0;
}