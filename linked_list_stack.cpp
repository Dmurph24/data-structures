#import <iostream>
#import <cstdlib>
using namespace std;

template<typename T>
class Stack {
  private:
    struct Node {
      T data;
      Node *next;
    };
    Node *head;

  public:
    Stack();
    ~Stack();
    void push(T item);
    void pop();
    void peek();
};

template<typename T>
Stack<T>::Stack() {
	head = NULL;
}

template<typename T>
Stack<T>::~Stack() {
	Node *node = head;
	while (node != NULL) {
		Node *tmp = node;
		node = node->next;
		delete tmp;
		tmp = NULL;
	}
}

template<typename T>
void Stack<T>::push(T item) {
	Node *node = new Node;
	node->data = item;
	node->next = head;
	head = node;
}

template<typename T>
void Stack<T>::pop() {
	if (head != NULL) {
		Node *tmp = head;
		head = head->next;
		delete tmp;
	}
}

template<typename T>
void Stack<T>::peek() {
	if (head != NULL) {
		cout << "Top of stack: " << head->data << endl;
	} else {
		cout << "Nothing is in the stack!" << endl;
	}
}

int main(int argc, char *argv[]) {
	Stack<char*> stack;
	for (int i = 1; i < argc; i ++) {
		stack.push(argv[i]);
	}
	stack.pop();
	stack.peek();
  return 0;
}
