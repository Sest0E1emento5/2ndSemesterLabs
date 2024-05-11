#include <iostream>

struct Node {
	char* key;
	Node* prev = nullptr;
	Node* next = nullptr;
};

struct List {
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
};

Node* createNode(const char* key);
void deleteNode(List& list, const char* key);
void addNodesBefore(List& list, int pos, int k);
void printList(List& list);
void deleteList(List& list);
int main() {
	setlocale(LC_ALL, "Rus");
	List list;
	list.head_node = createNode("Яблоко");
	list.tail_node = list.head_node;
	list.tail_node->next = createNode("Банан");
	list.tail_node->next->prev = list.tail_node;
	list.tail_node = list.tail_node->next;
	list.tail_node->next = createNode("Апельсин");
	list.tail_node->next->prev = list.tail_node;
	list.tail_node = list.tail_node->next;

	std::cout << "Initial list: ";
	printList(list);

	deleteNode(list, "Банан");
	std::cout << "Список после удаления 'Банан': ";
	printList(list);

	addNodesBefore(list, 2, 2);
	std::cout << "Лист после добавления двух новых элементов перед 2: ";
	printList(list);

	deleteList(list);

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
	newNode->prev = nullptr;
	newNode->next = nullptr;
	return newNode;
}

void deleteNode(List& list, const char* key) {
	Node* current = list.head_node;

	while (current != nullptr) {
		if (strcmp(current->key, key) == 0) {
			if (current->prev == nullptr) {
				list.head_node = current->next;
			}
			else {
				current->prev->next = current->next;
			}
			if (current->next != nullptr) {
				current->next->prev = current->prev;
			}
			if (current == list.tail_node) {
				list.tail_node = current->prev;
			}
			delete[] current->key;
			delete current;
			break;
		}
		current = current->next;
	}
}

void addNodesBefore(List& list, int pos, int k) {
	if (pos <= 1) {
		std::cout << "Invalid position\n";
		return;
	}

	Node* current = list.head_node;
	Node* prev = nullptr;
	int count = 1;

	while (current != nullptr && count < pos) {
		prev = current;
		current = current->next;
		count++;
	}

	for (int i = 0; i < k; i++) {
		Node* newNode = createNode("НовыйУзел");
		newNode->prev = prev;
		newNode->next = current;

		if (prev == nullptr) {
			list.head_node = newNode;
		}
		else {
			prev->next = newNode;
		}
		if (current != nullptr) {
			current->prev = newNode;
		}
		else {
			list.tail_node = newNode;
		}
		prev = newNode;
	}
}

void printList(List& list) {
	Node* current = list.head_node;
	while (current != nullptr) {
		std::cout << current->key << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void deleteList(List& list) {
	Node* current = list.head_node;
	while (current != nullptr) {
		Node* temp = current;
		current = current->next;
		delete[] temp->key;
		delete temp;
	}
	list.head_node = nullptr;
	list.tail_node = nullptr;
}