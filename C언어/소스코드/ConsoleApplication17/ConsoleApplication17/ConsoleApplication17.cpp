// ConsoleApplication17.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>

using namespace std;


bool xor(bool a, bool b);

int main() {

	bool p, q;
	cout << "Enter P (0 or 1): ";
	cin >> p;
	cout << "Enter Q (0 or 1): ";
	cin >> q;
	cout << "P AND Q: " << (p && q) << '\n';
	cout << "P OR Q: " << (p || q) << '\n';
	cout << "P XOR Q: " << xor (p, q) << '\n';
	return 0;
}

bool xor(bool a, bool b) {
	return (a || b) && !(a&&b);
}
