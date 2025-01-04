#include<iostream>
#include<cmath>
#include<iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
string add(string a, string b) {
	short a1[600] = { 0 }, b1[600] = { 0 }, cous[600] = { 0 };
	int maxs = max(a.size(), b.size());
	//存取 a1
	for (int i = 0; i < a.size();i++) {
		a1[i] = a[a.size() - 1 - i] - '0';
	}
	//存取 a2
	for (int i = 0; i < b.size();i++) {
		b1[i] = b[b.size() - 1 - i] - '0';
	}
	//累加
	for (int i = 0; i < maxs;i++) {
		cous[i] += a1[i] + b1[i];
		cous[i + 1] = cous[i] / 10;
		cous[i] = cous[i] % 10;
	}
	//去零
	while (cous[maxs] == 0 && maxs > 0) maxs--;
	//和并
	string ct;
	for (int i = maxs; i >= 0;i-- ) {
		ct += cous[i] + '0';
	}
	return ct;
}
int main() {
	string a,b;
	cin >> a >> b;
	cout << add(a, b);
	return 0;
}
