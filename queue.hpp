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

template <typename T>
void Queue<T>::sorting(){
    if (this->size != 0){
        for (int i = this->size / 2 - 1; i >= 0; i--){
            heapify(size, i);
        }

        for (int i = this->size - 1; i >= 0; i--){
            swap(this->list[0], this->list[i]);
            heapify(i, 0);
        }
    } else {
        cout << "There is nothing inside the queue !!" << endl;
    }
}

template <typename T>
void Queue<T>::heapify(int size, int i){
    int largest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if (this->list[leftChild] > this->list[largest] && leftChild < size){
        largest = leftChild;
    }

    if (this->list[rightChild] > this->list[largest] && rightChild < size){
        largest = rightChild;
    }

    if (largest != i){
        swap(this->list[i], this->list[largest]);
        heapify(size, largest);
    }
}

template <typename T>
void Queue<T>::swap(T &a, T &b){
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
bool Queue<T>::bSearch(T left, T right, T target){
    if (right >= left){
        int mid = (left + right) / 2;
        if (target == this->list[mid]){
            return true;
        }
        else if (target < this->list[mid]){
            return bSearch(left, mid - 1, target);
        }
        else if (target > this->list[mid]){
            return bSearch(mid + 1, right, target);
        }
    }
    return false;
}

template <typename T>
void Queue<T>::binarySearch(T target){
    T find = bSearch(0, this->size, target);
    if (find == true){
        cout << target << " is inside the queue !!" << endl;
    } else {
        cout << target << " isn't on the queue !!" << endl;
    }
}