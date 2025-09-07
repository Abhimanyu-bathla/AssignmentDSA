#include <iostream>
#include <string>

using namespace std;


void push(char stack[], int &top, char item) {
    top = top + 1;
    stack[top] = item;
}


char pop(char stack[], int &top) {
    char item = stack[top];
    top = top - 1;
    return item;
}


void reverseString(string &s) {
    int n = s.length();
    if (n == 0) {
        return; 
    }

   
    char *stack = new char[n];
    int top = -1;

    
    for (int i = 0; i < n; i++) {
        push(stack, top, s[i]);
    }

   
    for (int i = 0; i < n; i++) {
        s[i] = pop(stack, top);
    }

  
    delete[] stack;
}

int main() {
    string input_str;
    cout << "Enter the string to reverse: ";
    
    getline(cin, input_str);

    cout << "Original string: " << input_str << endl;

    reverseString(input_str);

    cout << "Reversed string: " << input_str << endl;

    return 0;
}
