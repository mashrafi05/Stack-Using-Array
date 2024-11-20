#include <iostream>
using namespace std;

int stacksize = 10;

struct stack {
    int *arr;
    int top;
    int cnt;

    stack(int d) {
        arr = new int[d];
        top = -1;
        cnt = 0;
    }

    void push(int d);
    int sizee();
    bool emptyy();
    int topElement();
    int pop();
};

void stack::push(int d) {
    if (sizee() < stacksize) {
        arr[++top] = d;
        cnt++;
        cout << "Pushed " << d << " into the stack\n";
    } else {
        cout << "Overflow\n";
    }
}

int stack::sizee() {
    return cnt;
}

bool stack::emptyy() {
    return top == -1;
}

int stack::topElement() {
    if (emptyy()) {
        cout << "Stack is empty\n";
        return -1;
    }
    return arr[top];
}

int stack::pop() {
    if (emptyy()) {
        cout << "Underflow\n";
        return -1;
    } else {
        int poppedData = arr[top--];
        cnt--;
        return poppedData;
    }
}

int main() {
    stack st(10);

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.topElement() << endl;
    cout << "Current size: " << st.sizee() << endl;

    cout << "Popping: " << st.pop() << endl;
    cout << "Top element after pop: " << st.topElement() << endl;

    cout << "Is stack empty? " << (st.emptyy() ? "Yes" : "No") << endl;

    delete[] st.arr;

    return 0;
}
