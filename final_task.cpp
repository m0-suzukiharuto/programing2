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
	cout << p << "の約数は\n";
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
	cout << "の" << vec.size() << "個である。\n";
	if (vec.size() == 2) 
		cout << "よって" << p << "は素数である。\n";
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
	cout << "正の整数を半角で２つ入力してください。\n";
	cin >> n;
	cin >> m;
	while ((n < 1 || m < 1) || cin.fail()) {
		if (cin.fail()) {
			cin.clear();
			cin.ignore(100, '\n');
			cout << "半角でない数字、又は数字でない文字が入力されました。入力し直してください。\n";
			cin >> n;
			cin >> m;
		}
		else if (n < 1 || m < 1) {
			cout << "適当でない値が入力されました。正の整数を入力してください。\n";
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
	cout << n << "と" << m << "の公約数は\n";
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
	cout << "の" << vcd.size() << "個である。\n";
	if (vcd.size() == 1) 
		cout << "これより" << n << "と" << m << "は互いに素である。\n";
	cout << endl;

	v.clear();
	vn.clear();
	vm.clear();
	vcd.clear();

re:
	cout << "まだ調べたい場合は'continue'と入力してください。\n終了する場合は'end'と入力してください。\n";
	cin >> S;
	if (S == "continue") goto start;
	else if (S == "end") goto end;
	cout << "不適な入力です。\n";
	goto re;
end:
	cout << "終了\n";
}