#pragma once
#include <string>
#include <iostream>
namespace ListSpace {//пользовательский интерфейс
	using namespace std;
	class Node {
	public:
		Node();
		void push_back(const string& val);
		void output();
	    string pop();
		void sort();
		bool empty();
	private:
		Node(const string& val);
		string value;
		Node* next;
		Node* last;
	};
}