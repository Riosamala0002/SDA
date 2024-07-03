#include <iostream>
using namespace std;

#define MAX_SIZE 5 // Ukuran maksimum antrian

class Queue {
private:
    char items[MAX_SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return (front == 0 && rear == MAX_SIZE - 1) || (rear == (front - 1) % (MAX_SIZE - 1));
    }

    void enqueue(char value) {
        if (isFull()) {
            cout << "Antrian penuh, tidak dapat menambahkan elemen." << endl;
            return;
        }

        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % MAX_SIZE;
        }

        items[rear] = value;
    }

    char dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong, tidak ada elemen untuk dihapus." << endl;
            return '\0';
        }

        char removedItem = items[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        return removedItem;
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong." << endl;
            return;
        }

        cout << "Elemen dalam antrian: ";
        int i = front;
        do {
            cout << items[i] << " ";
            i = (i + 1) % MAX_SIZE;
        } while (i != (rear + 1) % MAX_SIZE);
        cout << endl;
    }
};

int main() {
    Queue queue;

    queue.enqueue('A');
    queue.enqueue('B');
    queue.enqueue('C');
    queue.enqueue('D');
    queue.enqueue('E');
    queue.enqueue('F');

    queue.display();

    cout << "Elemen yang dihapus: " << queue.dequeue() << endl;
    cout << "Elemen yang dihapus: " << queue.dequeue() << endl;

    queue.display();

    queue.enqueue('G');
    queue.enqueue('H');
    queue.enqueue('I');

    queue.display();

    return 0;
}