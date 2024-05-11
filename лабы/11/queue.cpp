#include <iostream>

struct Node {
	char* key;
	Node* next;
};

struct Queue {
	int size;
	Node* head_node;
	Node* tail_node;
};

Node* createNode(const char* key);
void enqueue(Queue& queue, const char* key);
void dequeue(Queue& queue);
void printQueue(Queue& queue);
void deleteNode(Queue& queue, const char* key);
void addNodesBefore(Queue& queue, int pos, int k);
void deleteQueue(Queue& queue);

int main() {
	Queue queue;
	queue.size = 0;
	queue.head_node = nullptr;
	queue.tail_node = nullptr;

	enqueue(queue, "Node 1");
	enqueue(queue, "Node 2");
	enqueue(queue, "Node 3");

	std::cout << "Initial queue: ";
	printQueue(queue);

	deleteNode(queue, "Node 2");
	std::cout << "Queue after deleting 'Node 2': ";
	printQueue(queue);

	addNodesBefore(queue, 2, 2);
	std::cout << "Queue after adding 2 nodes before position 2: ";
	printQueue(queue);

	deleteQueue(queue);

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

void enqueue(Queue& queue, const char* key) {
	Node* newNode = createNode(key);
	if (queue.head_node == nullptr) {
		queue.head_node = newNode;
	}
	else {
		queue.tail_node->next = newNode;
	}
	queue.tail_node = newNode;
	queue.size++;
}

void dequeue(Queue& queue) {
	if (queue.head_node == nullptr) {
		std::cout << "Queue is empty\n";
		return;
	}
	Node* temp = queue.head_node;
	queue.head_node = queue.head_node->next;
	delete[] temp->key;
	delete temp;
	queue.size--;
}

void printQueue(Queue& queue) {
	Node* current = queue.head_node;
	while (current != nullptr) {
		std::cout << current->key << " ";
		current = current->next;
	}
	std::cout << std::endl;
}

void deleteNode(Queue& queue, const char* key) {
	Node* current = queue.head_node;
	Node* prev = nullptr;

	while (current != nullptr) {
		if (strcmp(current->key, key) == 0) {
			if (prev == nullptr) {
				queue.head_node = current->next;
			}
			else {
				prev->next = current->next;
			}
			if (current == queue.tail_node) {
				queue.tail_node = prev;
			}
			delete[] current->key;
			delete current;
			queue.size--;
			return;
		}
		prev = current;
		current = current->next;
	}

	std::cout << "Element not found in queue\n";
}

void addNodesBefore(Queue& queue, int pos, int k) {
	if (pos <= 1) {
		std::cout << "Invalid position\n";
		return;
	}

	Node* current = queue.head_node;
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
			queue.head_node = newNode;
		}
		else {
			prev->next = newNode;
		}
		if (current == nullptr) {
			queue.tail_node = newNode;
		}
		prev = newNode;
		queue.size++;
	}
}

void deleteQueue(Queue& queue) {
	while (queue.head_node != nullptr) {
		Node* temp = queue.head_node;
		queue.head_node = queue.head_node->next;
		delete[] temp->key;
		delete temp;
	}
	queue.tail_node = nullptr;
	queue.size = 0;
}