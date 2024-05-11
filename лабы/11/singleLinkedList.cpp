#include <iostream>
using namespace std;

struct Node {
	char* key;
	Node* next = nullptr;
};

struct List {
	Node* head_node = nullptr;
};

Node* createNode(const char* key);
void deleteNode(List& list, const char* key);
void addNodesBefore(List& list, int pos, int k);
void printList(List& list);

int main() {
	setlocale(LC_ALL, "Rus");
	List list;
	list.head_node = createNode("Яблоко");
	list.head_node->next = createNode("Банан");
	list.head_node->next->next = createNode("Аппельсин");

	cout << "Получившийся список: ";
	printList(list);

	deleteNode(list, "Банан");
	cout << "Список после удаления 'Банан': ";
	printList(list);

	addNodesBefore(list, 2, 2);
	cout << "список после добавления двух элементов перед вторым в имеющемся списке: ";
	printList(list);
	return 0;
}

Node* createNode(const char* key) {
	Node* newNode = new Node;
	int len = 0;
	const char* temp = key;
	while (*temp != '\0') {
		len++;
		temp++;
	}
	newNode->key = new char[len + 1];
	for (int i = 0; i < len; i++) {
		newNode->key[i] = key[i];
	}
	newNode->key[len] = '\0';
	newNode->next = nullptr;
	return newNode;
}

void deleteNode(List& list, const char* key) {
	Node* current = list.head_node;
	Node* prev = nullptr;

	while (current != nullptr) {
		if (strcmp(current->key, key) == 0) {
			if (prev == nullptr) {
				list.head_node = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete[] current->key;
			delete current;
			break;
		}
		prev = current;
		current = current->next;
	}
}

void addNodesBefore(List& list, int pos, int k) {
	Node* current = list.head_node;
	Node* prev = nullptr;
	int count = 1;

	while (current != nullptr && count < pos) {
		prev = current;
		current = current->next;
		count++;
	}

	for (int i = 0; i < k; i++) {
		Node* newNode = createNode("Новый_узел");
		newNode->next = current;

		if (prev == nullptr) {
			list.head_node = newNode;
		}
		else {
			prev->next = newNode;
		}
		prev = newNode;
	}
}

void printList(List& list) {
	Node* current = list.head_node;
	while (current != nullptr) {
		cout << current->key << " ";
		current = current->next;
	}
	cout << std::endl;
}
