#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int> &q) {
    if (q.size() % 2 != 0) {
        cout << "Queue must have an even number of elements." << endl;
        return;
    }

    stack<int> s;
    int halfSize = q.size() / 2;

    // Step 1: Push first half into stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back elements from stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half elements to back
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Again push first half into stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave stack and queue
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }
}

void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    int n, element;

    cout << "Enter the number of elements (must be even): ";
    cin >> n;

    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> element;
        q.push(element);
    }

    cout << "Original queue: ";
    printQueue(q);

    interleaveQueue(q);

    cout << "Interleaved queue: ";
    printQueue(q);

    return 0;
}
