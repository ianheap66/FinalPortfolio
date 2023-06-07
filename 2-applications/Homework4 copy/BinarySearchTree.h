
#ifndef BINARYSEARCHTREE_H_                   // "header guards"  
#define BINARYSEARCHTREE_H_                   // prevents double inclusion
#include "nullptr_emulation.h"



template<class T>
class BST {
    struct Node {
        T _x;
        Node *_parent;
        Node *_left;
        Node *_right;
    };
	int _n;
    Node _root;

public:

    // constructor
    BST();

    BST(T x);

    // destructor
    ~BST();

    // is x in the tree?
    bool isElement(T x);

    T* find(T x);

    Node* find_last(T x);

    bool add_child(T* p, Node* u);

    bool add(T x);

    bool bfs_traverse();

    T remove(T x);
    
    T remove_node(T u);

    T splice(T u);

    T new_node (T x);

    int size();

};

template <class T>
    T BST<T>::new_node(T x) {
    Node* newNode = new Node;
    newNode->_x = x;
    newNode->_parent = nullptr;
    newNode->_left = nullptr;
    newNode->_right = nullptr;
    return newNode;
}



//size
template<class T>
int BST<T>::size() {
    return _n;
}

template <class T>
BST<T>::BST() {
	_n = 0;
}

template <class T>
BST<T>::BST(T x) {
	_n = 0;
    _root.x = x;
    _root._parent = nullptr;
    _root._left = nullptr;
    _root._right = nullptr;
}

template <class T>
BST<T>::~BST(){}

template<class T>
bool BST<T>::isElement(T x) {
    Node * currentNode = &_root;
    while (currentNode != nullptr) {
        if (x < currentNode->_x) {
            currentNode = currentNode->_left;
        } else if (x > currentNode-> x) {
            currentNode = currentNode->_right;
        } else {
            return true;
        }
    }
    return false;
}

//remove_node
template<class T>
T BST<T>::remove_node (T u){

    Node* w;

    if (u->_left == nullptr || u->_right == nullptr){
        splice(u);
    }
    else{
        w = u->_right;
        while (w->_left != nullptr){
            w = w->_left;
        }
        u->_x = w->_x;
        splice(w);
    }
}


//splice
template <class T>
T BST<T>::splice(T u){
    Node* s;
    Node* r = _root;
    Node* p;

    if (u -> _left != nullptr){
    s = u ->_left;
}
    else{
        s = u->_right;
    }
    if (u == r){
        r = s;
        p = nullptr;
    }
    else{
        p = u->_parent;
        if (p->_left == u){
            p ->_left = s;
        }
        else{
            p->_right = s;
        }
    }
    if (s != nullptr){
        s->_parent = p;
    }
    _n = _n -1;
}



//add
template <class T>
bool BST<T>::add(T x){

Node* p = find_last(x);

return add_child(p, new_node(x));
}


//find 
template <class T>
T* BST<T>::find(T x){
 
 Node* w = &_root;
 Node* z = nullptr;

 while (w != nullptr){
    if(x < w->_x){
        z = w;
        w = w->_left;
    }
    else if (x > w->_x){
        w = w->_right;
    }
    else 
    return w->_x;
 }
 if (z ==nullptr){
    return nullptr;
 }
 return z->_x;
}

//add_child
template <class T>
bool BST <T>::add_child(T* p, Node* u){

if (p == nullptr){
    _root = u;
}
    else{
    if(u->_x < p->_x){
        p->_left = u;
    }
    
    else if (u ->_x > p->_x){
        p->_right = u;
    }

    else{
        return false;
    }

    u->_parent = p;
    _n = _n+1;
    }

return true;
}

//find last
template <class T>
typename BST<T>::Node* BST<T>::find_last(T x) {
    Node* w = &_root;
    Node* prev = nullptr;
    while (w != nullptr) {
        prev = w;
        if (x < w->_x) {
            w = w->_left;
        } else if (x > w->_x) {
            w = w->_right;
        } else {
            return w;
        }
    }
    return prev;
}

template <class T>
bool BST<T>:: bfs_traverse(){

Node * thisNode = &_root;
Node * prevNode = nullptr;
Node * nextNode = nullptr;

while(!(thisNode == &_root && prevNode == thisNode->_right)){
    if(prevNode == thisNode->_parent)
    {
        if(thisNode->_left != nullptr){
            nextNode = thisNode->_left;
        }else if(thisNode->_right != nullptr){
            nextNode = thisNode->_right;
        }else{
            nextNode = thisNode ->_parent;
        }
    } else if(prevNode == thisNode->_left){
        if(thisNode->_right != nullptr){
            nextNode = thisNode->_right;
        } else {
            nextNode = thisNode->_parent;
        }
    } else{
        nextNode = thisNode->_parent;
    }
    prevNode = thisNode;
    thisNode = nextNode;
}
return true;
}

#endif /*BINARYSEARCHTREE_H_*/
