#include <iostream>

using namespace std;

//Singly-Linked Node class used for StackList and QueueList
class Node {
    public:
    int val;
    Node* next;

    Node(int value, Node* next_node = NULL) {
        val = value;
        next = next_node;
    }
};

class StackList {
    Node* head;

    public:
    StackList() {
        head = NULL;
    }

    void push(int val) {
        if (head == NULL) {
            head = new Node(val);
        }
        else {
            head = new Node(val, head);
        }
    }

    int pop() {
        if (head == NULL) {
            return -1;
        }

        Node* temp = head;
        int value = temp->val;
        head = head->next;

        delete temp;
        return value;
    }

    int peek() {
        if (head == NULL) {
            return -1;
        }
        return head->val;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void print() {
        Node* curr = head;
        if (curr == NULL) {
            cout << "[ ]" << endl;
            return;
        }

        while(curr->next != NULL) {
            cout << "[" << curr->val << "] ";
            curr = curr->next;
        }
        cout << "[" << curr->val << "] " << endl;
    }
};

class StackArray {
    int* array; //The array itself
    int count; //Counts how many elements are in the stack

    public:

    StackArray() {
        array = new int[8];
        count = 0; 
    }

    void push(int val) {
        array[count++] = val;
    }

    //Doesn't 'delete' an element, but rather removes it from the scope
    int pop() {
        if (count == 0) {
            return -1;
        }
        --count;
        return array[count];
    }

    int peek() {
        if (count == 0) {
            return -1;
        }
        return array[count - 1];
    }

    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << "[" << array[i] << "] ";
        }
        cout << endl;
    }
};

class QueueList {
    Node* head;
    Node* tail;

    public:

    QueueList() {
        head = NULL;
        tail = NULL;
    }

    void enqueue(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        }
        else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }

    int dequeue() {
        if (head == NULL) {
            return -1;
        }

        Node* temp = head;
        int value = temp->val;
        head = head->next;

        delete temp;
        return value;
    }

    int peek() {
        if (head == NULL) {
            return -1;
        }
        return head->val;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void print() {
        Node* curr = head;
        if (curr == NULL) {
            cout << "[ ]" << endl;
            return;
        }

        while(curr->next != NULL) {
            cout << "[" << curr->val << "] ";
            curr = curr->next;
        }
        cout << "[" << curr->val << "] " << endl;
    }
};

class QueueArray {
    int* array;
    int count;

    public:

    QueueArray() {
        array = new int[8]{};
        count = 0;
    }

    void enqueue(int val) {
        array[count++] = val;
    }

    int dequeue() {
        if (count == 0) {
            return -1;
        }
        
        int temp = array[0];
        for (int i = 0; i < count - 1; i++) {
            array[i] = array[i + 1];
        }
        count--;

        return temp;
    }

    int peek() {
        if (count == 0) {
            return -1;
        }
        return array[0];
    }

    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << "[" << array[i] << "] ";
        }
        cout << endl;
    }
};

class DequeList {
    struct NodeDouble {
        int val;
        NodeDouble* next = NULL;
        NodeDouble* prev = NULL;
    };
    
    NodeDouble* head;
    NodeDouble* tail;

    public:

    DequeList() {
        head = NULL;
        tail = NULL;
    }

    void push_back(int val) {
        if (head == NULL) {
            head = new NodeDouble{val};
            tail = head;
        }
        else {
            tail->next = new NodeDouble{val, NULL, tail};
            tail = tail->next;
        }
    }

    void push_front(int val) {
        if (head == NULL) {
            head = new NodeDouble{val};
            tail = head;
        }
        else {
            head->prev = new NodeDouble{val, head};
            head = head->prev;
        }
    }

    int pop_back() {
        if (head == NULL) {
            return -1;
        }

        NodeDouble* temp = tail;
        int value = temp->val;
        tail = tail->prev;
        tail->next = NULL;

        delete temp;
        return value;        
    }

    int pop_front() {
        if (head == NULL) {
            return -1;
        }

        NodeDouble* temp = head;
        int value = temp->val;
        head = head->next;

        delete temp;
        return value;
    }

    int front() {
        if (head == NULL) {
            return -1;
        }
        return head->val;
    }

    int back() {
        if (head == NULL) {
            return -1;
        }
        return tail->val;
    }

    bool isEmpty() {
        if (head == NULL) {
            return true;
        }
        return false;
    }

    void print() {
        NodeDouble* curr = head;
        if (curr == NULL) {
            cout << "[ ]" << endl;
            return;
        }

        while(curr->next != NULL) {
            cout << "[" << curr->val << "] ";
            curr = curr->next;
        }
        cout << "[" << curr->val << "] " << endl;
    }
};

class DequeArray {
    int* array;
    int count;

    public:

    DequeArray() {
        array = new int[8]{};
        count = 0;
    }

    void push_front(int val) {
        for (int i = count; i > 0; i--) {
            array[i] = array [i - 1];
        }
        array[0] = val;
        count++;
    }

    void push_back(int val) {
        array[count++] = val;
    }

    int pop_front() {
        if (count == 0) {
            return -1;
        }
        
        int temp = array[0];
        for (int i = 0; i < count - 1; i++) {
            array[i] = array[i + 1];
        }
        count--;

        return temp;
    }

    int pop_back() {
        if (count == 0) {
            return -1;
        }
        return array[--count];
    }

    int front() {
        if (count == 0) {
            return -1;
        }
        return array[0];
    }

    int back() {
        if (count == 0) {
            return -1;
        }

        return array[count - 1];
    }

    bool isEmpty() {
        if (count == 0) {
            return true;
        }
        return false;
    }

    void print() {
        for (int i = 0; i < count; i++) {
            cout << "[" << array[i] << "] ";
        }
        cout << endl;
    }
};

int main() {
    cout << boolalpha;

    StackList stackL;

    cout << "StackList:" << endl;
    cout << "isEmpty: " << stackL.isEmpty() << endl;
    cout << "Pushing 8 and 12" << endl;
    stackL.push(8);
    stackL.push(12);
    cout << "isEmpty: " << stackL.isEmpty() << endl;
    cout << "Peek: " << stackL.peek() << endl;
    cout << "Popping 3 times: " << stackL.pop() << " " << stackL.pop() << " " << stackL.pop() << endl;
    cout << "Pushing 4 and 5" << endl;
    stackL.push(4);
    stackL.push(5);
    cout << "Print: ";
    stackL.print();
    cout << endl;

    StackArray stackA;

    cout << "StackArray:" << endl;
    cout << "isEmpty: " << stackA.isEmpty() << endl;
    cout << "Pushing 8 and 12" << endl;
    stackA.push(8);
    stackA.push(12);
    cout << "isEmpty: " << stackA.isEmpty() << endl;
    cout << "Peek: " << stackA.peek() << endl;
    cout << "Popping 3 times: " << stackA.pop() << " " << stackA.pop() << " " << stackA.pop() << endl;
    cout << "Pushing 4 and 5" << endl;
    stackA.push(4);
    stackA.push(5);
    cout << "Print: ";
    stackA.print();
    cout << endl;

    QueueList queueL;

    cout << "Queue List: \n";
    cout << "isEmpty: " << queueL.isEmpty() << endl;
    cout << "Enqueue 37 and 9 \n";
    queueL.enqueue(37);
    queueL.enqueue(9);
    cout << "isEmpty: " << queueL.isEmpty() << endl;
    cout << "Peek: " << queueL.peek() << endl;
    cout << "Dequeue 3 times: " << queueL.dequeue() << " " << queueL.dequeue() << " " << queueL.dequeue() << endl;
    cout << "Enqueue 6 and 7\n";
    queueL.enqueue(6);
    queueL.enqueue(7);
    cout << "Print: ";
    queueL.print();
    cout << endl;

    QueueArray queueA;

    cout << "Queue Array: \n";
    cout << "isEmpty: " << queueA.isEmpty() << endl;
    cout << "Enqueue 37 and 9 \n";
    queueA.enqueue(37);
    queueA.enqueue(9);
    cout << "isEmpty: " << queueA.isEmpty() << endl;
    cout << "Peek: " << queueA.peek() << endl;
    cout << "Dequeue 3 times: " << queueA.dequeue() << " " << queueA.dequeue() << " " << queueA.dequeue() << endl;
    cout << "Enqueue 6 and 7\n";
    queueA.enqueue(6);
    queueA.enqueue(7);
    cout << "Print: ";
    queueA.print();
    cout << endl;

    DequeList dequeL;

    cout << "Deque List:\n";
    cout << "isEmpty: " << dequeL.isEmpty() << endl;
    cout << "Push back 3 and 4\n";
    dequeL.push_back(3);
    dequeL.push_back(4);
    cout << "isEmpty: " << dequeL.isEmpty() << endl;
    cout << "Front: " << dequeL.front() << endl;
    cout << "Back: " << dequeL.back() << endl;
    cout << "Push front 2 and 1\n";
    dequeL.push_front(2);
    dequeL.push_front(1);
    cout << "Front: " << dequeL.front() << endl;
    cout << "Back: " << dequeL.back() << endl;
    cout << "Pop back twice: " << dequeL.pop_back() << " " << dequeL.pop_back() << endl;
    cout << "Pop front three times: " << dequeL.pop_front() << " " << dequeL.pop_front() << " " << dequeL.pop_front() << endl;
    cout << "Push front 7 and 9\n";
    dequeL.push_front(7);
    dequeL.push_front(9);
    cout << "Print: ";
    dequeL.print();
    cout << endl;

    DequeArray dequeA;

    cout << "Deque Array:\n";
    cout << "isEmpty: " << dequeA.isEmpty() << endl;
    cout << "Push back 3 and 4\n";
    dequeA.push_back(3);
    dequeA.push_back(4);
    cout << "isEmpty: " << dequeA.isEmpty() << endl;
    cout << "Front: " << dequeA.front() << endl;
    cout << "Back: " << dequeA.back() << endl;
    cout << "Push front 2 and 1\n";
    dequeA.push_front(2);
    dequeA.push_front(1);
    cout << "Front: " << dequeA.front() << endl;
    cout << "Back: " << dequeA.back() << endl;
    cout << "Pop back twice: " << dequeA.pop_back() << " " << dequeA.pop_back() << endl;
    cout << "Pop front three times: " << dequeA.pop_front() << " " << dequeA.pop_front() << " " << dequeA.pop_front() << endl;
    cout << "Push front 7 and 9\n";
    dequeA.push_front(7);
    dequeA.push_front(9);
    cout << "Print: ";
    dequeA.print();
    cout << endl;
}