#ifndef DLLIST_H_               //I tried to go through the test without looking at the solution and work through it but my way of doing it is not the exact same so I am not sure if it works
#define DLLIST_H_

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

    DLList();

    ~DLList();

    T get(int i);
    T set(int i, T x);

    void add(int i, T x);

    T remove(int i);

    void display();
};

template <class T>
DLList<T>::DLList() {
	_n = 0;
    dummy._prev = &dummy;
    dummy._next = &dummy;
}

template <class T>
DLList<T>::~DLList(){}

template <class T>
typename DLList<T>::Node* DLList<T>::addBefore(Node *w, T x) {
    Node *u = new Node;
    u->_x = x;
    u->_prev = w->_prev;
    u->_next = w;
    u->_next->_prev = u;
    u->_prev->_next = u;
    _n++;
    return u;
}

template <class T>
typename DLList<T>::Node* DLList<T>::getNode(int i) {
    Node* p;
    if (i < _n/2) {
        p = dummy._next;
        for (int j = 0; j < i; j++) {
            p = p->_next;
        }
    } else {
        p = &dummy;
        for (int j = _n; j > i; j--) {
            p = p->_prev;
        }
    }
    return p;
}

template<class T>
void DLList<T>::removeNode(Node *w) {
	w->_prev->_next = w->_next;
	w->_next->_prev = w->_prev;
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
void DLList<T>::display() {
    for (int i = 0; i < _n; i++) {
        std::cout << get(i) << " ";
    }
    std::cout << std::endl;
}


#endif /*DLLIST_H_*/