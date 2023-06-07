#ifndef DLLIST_H_                   // "header guards"  
#define DLLIST_H_                   // prevents double inclusion

template<class T>
class DLList {
    struct Node {
        T _x;
        Node *_next;
        Node *_prev;
    };

	Node dummy;
	int _n;

protected:

    Node* getNode(int i);
    Node* addBefore(Node *w, T x);
 
    void removeNode(Node *w);

public:

    // Constructor
    DLList();

    // Destructor
    ~DLList();

    T get(int i);
    T set(int i, T x);

    // add 
    void add(int i, T x);

    // remove
    T remove(int i);

    int find(T x);

    void display();
};

template <class T>
DLList<T>::DLList() {
	_n = 0;
    dummy._next = &dummy;
    dummy._prev = &dummy;
}

template <class T>
DLList<T>::~DLList(){}


template <class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
    Node *u = new Node;         // initialize a new node and create u as a pointer to that node
    u->_x = x;
    u->_prev = w->_prev;          // set the new node's 'previous' value to the existing node's 'previous' value
    u->_next = w;                // set the new node's 'next' value to the existing node 
    u->_next->_prev = u;          // whatever the next node's 'previous' value was, it should now be u 
    u->_prev->_next = u;          // whatever the previous node's 'next' value was, it should now be u
    _n++;
    return u;                   // return the pointer to the new node     
}

template <class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
    Node* p;            // create a new pointer to a node
    if (i < _n/2) {
        p = dummy._next;                 // set the pointer to point to the head
        for (int j = 0; j < i; j++) {
            p = p->_next;                // walk along until we get to location i
        }
    } else {
        p = &dummy;                     // get the address of the dummy node
        for (int j = _n; j > i; j--) {
            p = p->_prev;                // walk backwards from the tail
        }
    }
    return p;                       // notice that this returns a pointer to the node
}

template<class T>
void DLList<T>::removeNode(Node *w) {
	w->_prev->_next = w->_next;            // chain the previous node's 'next' to w's 'next', skipping w
	w->_next->_prev = w->_prev;            // chain the next node's 'previous' to w's 'previous', skipping w
	_n--;
}

template<class T>
T DLList<T>::get(int i) {
    return getNode(i)->_x;
}

template<class T>
T DLList<T>::set(int i, T x) {
	Node* u = getNode(i);
	T y = u->_x;
	u->_x = x;
	return y;
}

template<class T>
void DLList<T>::add(int i, T x) {
    addBefore(getNode(i), x);
}

template<class T>
T DLList<T>::remove(int i) {
	Node *w = getNode(i);
	T x = w->_x;
	removeNode(w);
	return x;
}

template<class T>
int DLList<T>::find(T x) {
    Node *u = dummy._next;
    for (int i = 0; i < _n; i++) {
        if (x == u->_x) {
            return i;
        }
        u = u->_next;
    }
    return -1;
}

template<class T>
void DLList<T>::display() {
    for (int i = 0; i < _n; i++) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}


#endif /*DLLIST_H_*/