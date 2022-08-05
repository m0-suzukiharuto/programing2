#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


class Divisor {
	int X;
	int Y;
public:
	void divisor(int N) { X = N; }
	int getdivisor() { return X; }
	void common_divisor(int N) { Y = N; }
	int getcommon_divisor() { return Y; }
};


void v_d(int p, vector<Divisor>& vec) {
	cout << p << "�̖񐔂�\n";
	int q = 0;
	for (int i = 1; i <= p; ++i) {
		if (p % i == 0) {
			vec.emplace_back();
			vec[q].divisor(i);
			cout << vec[q].getdivisor() << ",";
			++q;
		}
	}
	cout << endl;
	cout << "��" << vec.size() << "�ł���B\n";
	if (vec.size() == 2) 
		cout << "�����" << p << "�͑f���ł���B\n";
}


int main() {
	vector<int>v;
	vector<Divisor>vn;
	vector<Divisor>vm;
	vector<Divisor>vcd;
	int n;
	int m;
	string S;

start:
	cout << "���̐����𔼊p�łQ���͂��Ă��������B\n";
	cin >> n;
	cin >> m;
	while ((n < 1 || m < 1) || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "���p�łȂ������A���͐����łȂ����������͂���܂����B���͂������Ă��������B\n";
			cin >> n;
			cin >> m;
		}
		else {
			cout << "�K���łȂ��l�����͂���܂����B���̐�������͂��Ă��������B\n";
			cin >> n;
			cin >> m;
		}
	}

	v_d(n, vn);
	cout << endl;

	v_d(m, vm);
	cout << endl;

	for (int j = 0; j < vn.size(); ++j) 
		v.push_back(vn[j].getdivisor());

	int a = 0;
	cout << n << "��" << m << "�̌��񐔂�\n";
	for (int k = 0; k < vm.size(); ++k) {
		int target = vm[k].getdivisor();
		auto pos = find(v.cbegin(), v.cend(), target);
		if (pos != v.cend()) {
			vcd.emplace_back();
			vcd[a].common_divisor(target);
			cout << vcd[a].getcommon_divisor() << ",";
			++a;
		}
	}
	cout << endl;
	cout << "��" << vcd.size() << "�ł���B\n";
	if (vcd.size() == 1) 
		cout << "������" << n << "��" << m << "�݂͌��ɑf�ł���B\n";
	cout << endl;

	v.clear();
	vn.clear();
	vm.clear();
	vcd.clear();

re:
	cout << "�܂����ׂ����ꍇ��'continue'�Ɠ��͂��Ă��������B\n�I������ꍇ��'end'�Ɠ��͂��Ă��������B\n";
	cin >> S;
	if (S == "continue") goto start;
	else if (S == "end") goto end;
	cout << "�s�K�ȓ��͂ł��B\n";
	goto re;
end:
	cout << "�I��\n";
}