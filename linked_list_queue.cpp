#import <iostream>
#import <cstdlib>
using namespace std;

template<typename T>
class Queue {

  private:
    struct Node {
      T data;
      Node *next;
      Node *prev;
    };
    Node *head;
    Node *tail;
    int size;

  public:
    Queue();
    ~Queue();
    void enqueue(T item);
    void dequeue();
    void peek();
};

template <typename T>
Queue<T>::Queue() {
  head = NULL;
  tail = NULL;
  size = 0;
}

template <typename T>
Queue<T>::~Queue() {
  Node *node = head;
  while (node != NULL) {
    Node *next_node = node->next;
    delete node;
    node = next_node;
  }
  head = NULL;
  tail = NULL;
}

template <typename T>
void Queue<T>::enqueue(T item) {
  Node *node = new Node;
  node->data = item;
  node->prev = NULL;
  if (head == NULL && tail == NULL) {
    node->next = NULL;
    head = tail = node;
  } else {
    node->next = head;
    head->prev = node;
    head = node;
  }
  size ++;
}

template <typename T>
void Queue<T>::dequeue() {
  if (tail != NULL) {
    if (tail->prev == NULL) {
      delete tail;
      head = NULL;
      tail = NULL;
    } else {
      Node *new_tail = tail->prev;
      new_tail->next = NULL;
      delete tail;
      tail = new_tail;
    }
    size --;
  } else {
    cout << "No items currently in queue" << endl;
  }
}

template <typename T>
void Queue<T>::peek() {
  if (head != NULL && tail != NULL) {
    cout << "First in queue is: " << tail->data << endl;
    cout << "Last in queue is: " << head->data << endl;
  } else {
    cout << "There is currently nothing in the queue" << endl;
  }
}

int main(int argc, char* argv[]) {
  Queue<char*> queue;
  for (int i = 1; i < argc; i ++) {
    queue.enqueue(argv[i]);
  }
  queue.dequeue();
  queue.peek();
}
