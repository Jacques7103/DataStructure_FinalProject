#include <iostream>
#include <array>

using namespace std;

#define MAX 100

template <typename T>
class Stack{
    public:
        array<T, MAX> items = {};
        int size;

        Stack() : size(0){};
        void add(T item);
        T pop();
        void print();
};

template <typename T>
void Stack<T>::add(T item){
    this->items[this->size] = item;
    this->size++;
}

template <typename T>
T Stack<T>::pop(){
    if (this->size == 0){
        cout << "Stack is Empty!" << endl;
        return 0;
    }

    --this->size;
    int lastitem = this->items[this->size];
    return lastitem;
}

template <typename T>
void Stack<T>::print(){
    for (int i = this->size - 1; i >= 0; i--){
        cout << this->items[i] << " ";
    }
    cout << endl;
}