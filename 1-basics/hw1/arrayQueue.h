#include "utils.h"

template<class T>               // this code uses Prof. Ackles's code as a skeleton and added sections from the textbook
class ArrayQueue {
    protected:                    // Can only be accessed by 'friend' classes; will see more about this soon 
        // underscores are convention to show that these are member variables
        int _n;                  // number of elements
        T *_a;                   // backing array
        int _size;               // total size of array, NOT number of elements
        int _first = 0;          // position of first element
        void resize();           // protected resize op
    public:
        // Constructor
        ArrayQueue(int n);

        // Destructor
        ~ArrayQueue();

        // Get & Set operations
        T get(int i);
        T set(int i, T x);

        // Add at specified place, add at top of stack
        void add(int i, T x);

        bool enqueue(T x);
 
        T remove(int i);
        int dequeue();
        
        // push and pop operations for stack-like behavior 
       void push(T x);
        T pop();

        // Empty the stack 
        void clear();

        // --- Below this point are helpful functions ---
        // not necessary parts of the data structure, but helpful for working with the class
        int getSize();
        void display();
};
template<class T>
int dequeue() { 
            T x = _a[_first];
            _first = ((_first + 1)%_size);
            _n = _n-1;
            if (_size>=(3*_n)){resize()}
            return x
        }
template<class T>
        bool enqueue(T x) {
            if ((_n+1)> _size){resize()}
            _a[(_first+_n)%_size] = x;
            _n=_n+1; 
            return true;
            }

//  Constructor and Destructor
//      for the constructor, we initialize a new array as the "backing array"
//      these constructors/destructors can be identical for any array-based implementation
template<class T>
ArrayQueue<T>::ArrayQueue(int size) {
    _a = new T[size];
    _size = size; 
    _n = 0;
}

// default destructor just trashes everything
template<class T>
ArrayQueue<T>::~ArrayQueue() {}

// resize operation creates a new array twice the size of the original (or length 1 if the original array is empty)
// book: 2.1.2
template<class T>
void ArrayQueue<T>::resize() {
    T * b = new T[max(1, 2*_n)];
    for (int i = 0; i < _n; i++) {
        b[i] = _a[(_first+i)%_size];
    }     
    _first = 0;
    _a = b;
    _size = max(1, 2*_n);
}

// get & set operations
// book: 2.1.1
template<class T>
T ArrayQueue<T>::get(int i) {
    return _a[i];
}

template<class T>
T ArrayQueue<T>::set(int i, T x) {
    T y = _a[i];
    _a[i] = x;
    return y;
}

// add operation
// book: 2.1.1
template<class T>
void ArrayQueue<T>::add(int i, T x) {
    // resize if array is too small to fit 
    if (_n + 1 > _size) {
        resize();
    }
    // shift all elements of the array that were to the right of index i one space to the right to make room for the new element
    for (int j = _n; j > i; j--) {
        _a[j] = _a[j-1];
    }
    // insert the new element 
    _a[i] = x;
    // increase the array element count
    _n++;
}

// remove operation
// book: 2.1.1 
template<class T>
T ArrayQueue<T>::remove(int i) {
    // get the original element at the index being removed
    T x = _a[i];
    // shift all elements of the array that are to the right of index i one space to the left to overwrite the original element
    for (int j = i; j < _n - 1; j++) {
        _a[j] = _a[j+1];
    }
    // decrease the array element count
    _n--;
    // resize if array is too large for the data 
    if (_size >= 3 * _n) {
        resize();
    }
    // original element in case we want it
    return x;
}

// push and pop wrappers for stack-like functionality
// notice how these do not rewrite the add and remove functions, but merely call these general functions for a specific case
// See pg 37 for additional explanation
template<class T>
void ArrayQueue<T>::push(T x) {
    add(_n, x);
}

//template<class T>
//T ArrayStack<T>::pop() {
//    return remove(_n - 1);
//}


// Clear out the stack 
template<class T>
void ArrayQueue<T>::clear() {
    _n = 0;                    // no more elements 
    T *b = new T[1];           // create new, single-element, empty array
    _a = b;                    // overwrite existing array
}


// --- Little helper functions --- 
template<class T>
int ArrayQueue<T>::getSize() {
    return _size;
}

template<class T>
void ArrayQueue<T>::display() {
    std::cout << "[";
    for (int i = 0; i < _n; i++) {
        std::cout << " " << _a[i];
    }
    for (int j = _n; j < _size; j++) {
        std::cout << " -";
    }
    std::cout << " ]" << std::endl;
}