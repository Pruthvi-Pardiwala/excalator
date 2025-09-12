#include <iostream>
using namespace std;

class StackBase {
public:
    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void displayTop() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
    virtual ~StackBase() {}
};

class Stack : public StackBase {
private:
    int top;
    int size;
    int *arr;

public:
    Stack(int s) {
        size = s;
        arr = new int[size];
        top = -1;

    ~Stack() {
        delete[] arr;
    }

    void push(int value) override {
        if (isFull()) {
            cout << "Stack is Full! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    void pop() override {
        if (isEmpty()) {
            cout << "Stack is Empty! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    void displayTop() override {
        if (isEmpty()) {
            cout << "Stack is Empty!" << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    bool isEmpty() override {
        return (top == -1);
    }

    bool isFull() override {
        return (top == size - 1);
    }
};

int main() {
    int capacity;
    cout << "Enter stack size: ";
    cin >> capacity;

    Stack s(capacity);
    int choice, value;

    do {
        cout << "***********************************" << endl;
        cout << "             STACK MENU             " << endl;
        cout << "***********************************" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display Top" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Exit" << endl;
        cout << "***********************************" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.displayTop();
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is Empty." << endl;
                else
                    cout << "Stack is not Empty." << endl;
                break;

            case 5:
                if (s.isFull())
                    cout << "Stack is Full." << endl;
                else
                    cout << "Stack is not Full." << endl;
                break;

            case 6:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice! Try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
