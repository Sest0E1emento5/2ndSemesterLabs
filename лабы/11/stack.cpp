#include <iostream>

struct Node {
	char* key;
	Node* next;
};

struct Stack {
	int size;
	Node* head_node;
};

Node* createNode(const char* key);
void push(Stack& stack, const char* key);
void pop(Stack& stack);
void deleteNode(Stack& stack, const char* key);
void addNodesBefore(Stack& stack, int pos, int k);
void deleteStack(Stack& stack);

int main() {
	Stack stack;
	stack.size = 0;
	stack.head_node = nullptr;

	push(stack, "Node 1");
	push(stack, "Node 2");
	push(stack, "Node 3");

	std::cout << "Initial stack: ";
	printStack(stack);

	deleteNode(stack, "Node 2");
	std::cout << "Stack after deleting 'Node 2': ";
	printStack(stack);

	addNodesBefore(stack, 2, 2);
	std::cout << "Stack after adding 2 nodes before position 2: ";
	printStack(stack);

	deleteStack(stack);

	return 0;
}


Node* createNode(const char* key) {
	Node* newNode = new Node;
	int len = 0;
	const char* temp = key;
	// Вычисляем длину строки ключа
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

void push(Stack& stack, const char* key) {
	Node* newNode = createNode(key);
	newNode->next = stack.head_node;
	stack.head_node = newNode;
	stack.size++;
}

void pop(Stack& stack) {
	if (stack.head_node == nullptr) {
		std::cout << "Stack is empty\n";
		return;
	}
	Node* temp = stack.head_node;
	stack.head_node = stack.head_node->next;
	delete[] temp->key;
	delete temp;
	stack.size--;
}

void printStack(Stack& stack) {
	Node* current = stack.head_node;
	while (current != nullptr) {
		std::cout << current->key << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void deleteNode(Stack& stack, const char* key) {
	Node* current = stack.head_node;
	Node* prev = nullptr;

	while (current != nullptr) {
		if (strcmp(current->key, key) == 0) {
			if (prev == nullptr) {
				stack.head_node = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete[] current->key;
			delete current;
			stack.size--;
			return;
		}
		prev = current;
		current = current->next;
	}

	std::cout << "Element not found in stack\n";
}

void addNodesBefore(Stack& stack, int pos, int k) {
	if (pos <= 1) {
		std::cout << "Invalid position\n";
		return;
	}

	Node* current = stack.head_node;
	Node* prev = nullptr;
	int count = 1;

	while (current != nullptr && count < pos) {
		prev = current;
		current = current->next;
		count++;
	}

	for (int i = 0; i < k; i++) {
		Node* newNode = createNode("New Node");
		newNode->next = current;

		if (prev == nullptr) {
			stack.head_node = newNode;
		}
		else {
			prev->next = newNode;
		}
		prev = newNode;
		stack.size++;
	}
}

void deleteStack(Stack& stack) {
	while (stack.head_node != nullptr) {
		Node* temp = stack.head_node;
		stack.head_node = stack.head_node->next;
		delete[] temp->key;
		delete temp;
	}
	stack.size = 0;
}
