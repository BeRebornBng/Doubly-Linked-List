#include "list.h"
namespace ListSpace{
	Node* head;//начало цепи
	Node* tail;//конец цепи
	Node* p;//для поэлементного вытаскивания элементов в функции pop
	//по правилу "Первым зашёл, последним вышел"
}
ListSpace::Node::Node()
{ 
	next=nullptr; 
	last=nullptr;
}
ListSpace::Node::Node(const string& val):value(val){}
void ListSpace::Node::push_back(const string& val)
{
	Node* node = new Node(val);
	if (head==nullptr) {
		head = node;//начальный элемент списка
		tail = node;//конечный элемент списка
	}
	else {
		node->last = tail;
		tail->next = node;
		tail = node;
		p = tail;
	}
}
std::string ListSpace::Node::pop() {
	if (head == nullptr) {
		return "Стек пуст";
	}
	else if (p == head) {
		Node temp(head->value);
		head = nullptr;
		tail = nullptr;
		return temp.value;
	}
	else {
		string s = p->value;
		Node* node = p;
		p = p->last;
		node = nullptr;
		return s;
	}
}
void ListSpace::Node::output() {
	cout << "В правильном порядке\n";
	Node* node = head;
	while (node != tail->next) {
		cout << node->value << " ";
		node = node->next;
	}
	cout << '\n';
	cout << "В обратном порядке\n";
	node = tail;
	while (node != head->last) {
		cout << node->value << " ";
		node = node->last;
	}
	cout << '\n';
}
void ListSpace::Node::sort(){
	Node* node_head = head;
	Node* node_tail = tail;
	while (node_head != node_tail) {
		string temp;
		temp = node_head->value;
		node_head->value = node_tail->value;
		node_tail->value = temp;
		node_head = node_head->next;
		node_tail = node_tail->last;
		if (node_head->next == node_tail) {
			temp = node_head->value;
			node_head->value = node_tail->value;
			node_tail->value = temp;
			break;
		}
	}
}
bool ListSpace::Node::empty() {
	return (!head);
}