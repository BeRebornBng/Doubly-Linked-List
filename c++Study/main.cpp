#include "list.h"
#include <iostream>

using namespace std;
int main() {
	setlocale(LC_ALL, "RUSSIAN");
	using Node = ListSpace::Node;
	Node node;
	node.push_back("Hi");
	node.push_back("my");
	node.push_back("name");
	node.push_back("is");
	node.push_back("Bakit");
	cout << "������� ��� ������ ��������\n";
	node.output();
	cout << "�������� �������� ����� ����� pop: \n";
	for (int i = 0; i < 5; ++i) {
		cout << node.pop() << " ";
	}
	cout << "\n����� ���� ������ ���� ������, �������� ��� ���������� ������� ��� ���� ��������.\n";
	cout << node.pop() << '\n';
	if (!node.empty()) {
		node.output();
		node.sort();
		node.output();
	}
	else {
		cout << "���������!\n";
	}
}