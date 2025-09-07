#include<iostream>
#include <string>
using namespace std;
void push(int stack[],int &top,int maxstack,int item){
    if(top==maxstack){
        cout<<"The stack is full"<<endl;
        return;
    }
    top=top+1;
    cout<<"enter the number to be added "<<endl;
    cin>>item;
    stack[top]=item;
}
int pop(int stack[],int &top,int maxstack,int item){
    if(top==-1){
        cout<<"The stack is empty"<<endl;
        return -1;
    }
    item=stack[top];
    top=top-1;
    return item;
}
void display(int stack[], int top) {
    if (top == -1) {
        cout << "Stack is empty." << endl;
        return;
    }
    cout << "Stack contents: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
}
void peek(int stack[],int &top,int maxstack,int item){
    cout<<"The top is:"<<stack[top];
}
int main(){
     int maxstack;
    cout << "Enter maximum stack size: ";
    cin >> maxstack;

    int *stack = new int[maxstack];
    int top = -1;

    int choice, item;

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n2. Pop\n3. Display\n4.peek\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                push(stack, top, maxstack, item);
                break;

            case 2:
                item = pop(stack, top,maxstack,item);
                if (item != -1)
                    cout << "Popped item: " << item << endl;
                break;

            case 3:
                display(stack, top);
                break;

            case 4:
            peek( stack, top, maxstack, item);
            break;

            case 5:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice, try again." << endl;
        }

    } while (choice != 5);

    delete[] stack;  
    return 0;
}

