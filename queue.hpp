#include <iostream>
#include <array>

using namespace std;

template <typename T>
class Queue{
    private :
        array<T, 100> list;
        int size;
        int index;
        int input;

        void swap(T &a, T &b);
        void heapify(int size, int i);
        bool bSearch(T left, T right, T target);

    public :
        Queue(){
            this->size = 0;
            this->index = 0;
        }
        void enqueue(T item);
        T dequeue();
        void getIndex(int input);
        void print();
        int getSize();
        void sorting();
        void binarySearch(T target);
};

// IMPLEMENTATIONS
template <typename T>
void Queue<T>::enqueue(T item){
    this->list[this->size] = item;
    this->size++;
}

template <typename T>
T Queue<T>::dequeue(){
    if (this->size != 0){
        return this->list[this->index++];
    } else {
        cout << "There is nothing inside on the list !!" << endl;
    }
}

template <typename T>
void Queue<T>::getIndex(int input){
    this->input = input;
    if (this->size != 0){
        cout << this->list[this->input] << endl;
    } else {
        cout << "There is nothing inside on the list !!" << endl;
    }
}

template <typename T>
int Queue<T>::getSize(){
    return this->size;
}

template <typename T>
void Queue<T>::print(){
    for (int i = this->index; i < this->size; i++){
        cout << this->list[i] << " ";
    }
    cout << endl;
}