#include "utils.h"
template<class T>               // this code uses Prof. Ackles's code as a skeleton and added sections from the textbook
class ArrayStack {
    protected:                    // Can only be accessed by 'friend' classes; will see more about this soon 
        // underscores are convention to show that these are member variables
        int _n;                  // number of elements
        T *_a;                   // backing array
        int _size;               // total size of array, NOT number of elements
        void resize();           // protected resize op
        int _first = 0;
    public:
        // Constructor
        ArrayStack(int n);

        // Destructor
        ~ArrayStack();

        // Get & Set operations
        T get(int i);
        T set(int i, T x);

        // Add at specified place, add at top of stack
        void add(int i, T x);
        void add(T x) { add(_n, x); }

        // Remove at specified place 
        T remove(int i);
        
        // push and pop operations for stack-like behavior 
        void push(T x);
        T pop();

        // Empty the stack 
        void clear();

        // --- Below this point are some helpful functions ---
        // not necessary parts of the data structure, but helpful for working with the class
        int getSize();
        void display();
};

//  Constructor and Destructor
//      for the constructor, we initialize a new array as the "backing array"
//      these constructors/destructors can be identical for any array-based implementation
template<class T>
ArrayStack<T>::ArrayStack(int size) {
    _a = new T[size];
    _size = size; 
    _n = 0;
}

// default destructor just trashes everything
template<class T>
ArrayStack<T>::~ArrayStack() {}

// resize operation creates a new array twice the size of the original (or length 1 if the original array is empty)
// book: 2.1.2
template<class T>
void ArrayStack<T>::resize() {
    T * b = new T[max(1, 2*_n)];
    for (int i = 0; i < _n; i++) {
        b[i] = _a[i];
    }     
    _a = b;
    _size = max(1, 2*_n);
}

// get & set operations
// book: 2.1.1
template<class T>
T ArrayStack<T>::get(int i) {
    return _a[(i+_first)%_size];
}

template<class T>
T ArrayStack<T>::set(int i, T x) {
    T y = _a[(i+_first)%_size];
    _a[(i+_first)%_size] = x;
    return y;
}

// add operation
// book: 2.1.1
template<class T>
void ArrayStack<T>::add(int i, T x) {
    // resize if array is too small to fit 
    if (_n + 1 > _size) {
        resize();
    }
    if (i<(_n/2)){
        _first = ((_first-1)%_size)
        for (int j = 0; j < i; j++) {
        _a[(_first+j)%_size] = _a[(_first+j-1)%_size];
    }
    }
    else {
        for (int j = _n; j > i; j--) {
        _a[(_first+j)%_size] = _a[(_first+j-1)%_size];
    }
    }
    // insert the new element 
    _a[(_first+i)%_size] = x;
    // increase the array element count
    _n++;
}

// remove operation
// book: 2.1.1 
template<class T>
T ArrayStack<T>::remove(int i) {
    // get the original element at the index being removed
    T x = _a[(_first+i)%_size];
    if (i<(_n/2)){
        for (int j = i; j > 0; j--) {
            _a[(_first +j)%_size] = _a[(_first +j-1)%_size];
        }
        _first = ((_first+1)%_size)
    }
    else {
        for (int j = i; j < _n - 1; j++) {
            _a[(_first+j)%_size] = _a[(_first+j+1)%_size];
        }
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
void ArrayStack<T>::push(T x) {
    add(_n, x);
}

template<class T>
T ArrayStack<T>::pop() {
    return remove(_n - 1);
}


// Clear out the stack 
template<class T>
void ArrayStack<T>::clear() {
    _n = 0;                    // no more elements 
    T *b = new T[1];           // create new, single-element, empty array
    _a = b;                    // overwrite existing array
}


// --- Little helper functions --- 
template<class T>
int ArrayStack<T>::getSize() {
    return _size;
}

template<class T>
void ArrayStack<T>::display() {
    std::cout << "[";
    for (int i = 0; i < _n; i++) {
        std::cout << " " << _a[i];
    }
    for (int j = _n; j < _size; j++) {
        std::cout << " -";
    }
    std::cout << " ]" << std::endl;
}