/*
 * BinarySearchTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <climits>
#include <cmath>
#include "BinaryTree.h"
#include "utils.h"
#include "DLList.h"
using namespace std;

namespace ods {

template<class Node, class T>
class BSTNode : public BTNode<Node> {
public:
	T x;
};

/**
 * A binary search tree class.  The Node parameter should be a subclass
 * of BSTNode<T> (or match it's interface)
 */
template<class Node, class T>
class BinarySearchTree : public BinaryTree<Node> {
protected:
	using BinaryTree<Node>::r;
	using BinaryTree<Node>::nil;
	int n;
	T null;
//    array<int> numbers;
	virtual Node *findLast(T x);
	virtual bool addChild(Node *p, Node *u);
	virtual void splice(Node *u);
	virtual void remove(Node *u);
	virtual void rotateRight(Node *u);
	virtual void rotateLeft(Node *u);
	virtual bool add(Node *u);
    
    
public:
	BinarySearchTree();
	BinarySearchTree(T null);
    virtual Node* getNode(T x);
	virtual ~BinarySearchTree();
	virtual bool add(T x);
	virtual bool remove(T x);
	virtual T find(T x);
	virtual T findEQ(T x);
	virtual int size();
	virtual void clear();
    virtual void preOrder(Node *u, int& counter);
    virtual void preOrder();
    virtual void inOrder(Node *u, int& counter);
    virtual void inOrder();
    virtual void postOrder(Node *u, int& counter);
    virtual void postOrder();
    virtual DLList<T> getLE(T x);

};
    
    //pre root -> left -> right
    //in left -> root -> right
    //post left -> right-> root
    
//void preOrder(Node* u, int& counter){
//}
    
    
    //question 4 start with traversal function 

template<class T>
class BSTNode1 : public BSTNode<BSTNode1<T>, T> { };

template<class T>
class BinarySearchTree1 : public BinarySearchTree<BSTNode1<T>, T> {
public:
	BinarySearchTree1();
};


/*
 * FIXME: Why doesn't this work?
template<class Node>
BinarySearchTree<Node,int>::BinarySearchTree()  {
	this->null = INT_MIN;
	n = 0;
}
*/
    



template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree() {
	this->null = (T)NULL;  // won't work for non-primitive types
	n = 0;
}


template<class Node, class T>
BinarySearchTree<Node,T>::BinarySearchTree(T null) {
	this->null = null;
	n = 0;
}

template<class Node, class T>
    DLList<T> BinarySearchTree<Node,T>::getLE(T x){
        DLList<T> dl;
        
        Node *u = r, *prev = nil, *next;
//        while (u->left != nil){
//             u = u->left;
//        }
        
        while (u != nil && u->x <x) {
            if (prev == u->parent) {
                dl.add(u->x);
                if (u->left != nil) next = u->left;
                else if (u->right != nil) next = u->right;
                else next = u->parent;
            } else if (prev == u->left) {
                if (u->right != nil) next = u->right;
                else next = u->parent;
            } else {
                next = u->parent;
            }
            prev = u;
            u = next;
        }
        
        return dl;
    }
    
//    template<class Node>
//    void BinaryTree<Node>::traverse2() {
//        Node *u = r, *prev = nil, *next;
//        while (u != nil) {
//            if (prev == u->parent) {
//                if (u->left != nil) next = u->left;
//                else if (u->right != nil) next = u->right;
//                else next = u->parent;
//            } else if (prev == u->left) {
//                if (u->right != nil) next = u->right;
//                else next = u->parent;
//            } else {
//                next = u->parent;
//            }
//            prev = u;
//            u = next;
//        }
//    }
    
template<class Node, class T>
Node* BinarySearchTree<Node,T>::getNode(T x) {
    
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return w;
    
}

template<class Node, class T>
Node* BinarySearchTree<Node,T>::findLast(T x) {
	Node *w = r, *prev = nil;
	while (w != nil) {
		prev = w;
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w;
		}
	}
	return prev;
}

template<class Node, class T>
T BinarySearchTree<Node,T>::findEQ(T x) {
	Node *w = r;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return null;
}
    
    
/**
* Modifications for CSE 274 homework4
**/
template<class Node, class T>
void BinarySearchTree<Node,T>::preOrder(Node *u, int& counter){
    if (u == nil) return;
    u->preOrderNumber = counter++;
    preOrder(u->left,counter);
    preOrder(u->right, counter);
    
}
    
template<class Node, class T>
void BinarySearchTree<Node,T>::preOrder(){
    int counter = 1;
    preOrder(r,counter);
    
}
    
template<class Node, class T>
void BinarySearchTree<Node,T>::inOrder(Node *u, int& counter){
    if (u == nil) return;
    inOrder(u->left,counter);
    u->inOrderNumber = counter++;
    inOrder(u->right, counter);
        
}
    
template<class Node, class T>
void BinarySearchTree<Node,T>::inOrder(){
    int counter = 1;
    inOrder(r,counter);
        
}
   
template<class Node, class T>
void BinarySearchTree<Node,T>::postOrder(Node *u, int& counter){
    if (u == nil) return;
    postOrder(u->left,counter);
    postOrder(u->right, counter);
    u->postOrderNumber = counter++;
    
}
    
template<class Node, class T>
void BinarySearchTree<Node,T>::postOrder(){
    int counter = 1;
    postOrder(r,counter);
        
}
    

template<class Node, class T>
T BinarySearchTree<Node,T>::find(T x) {
	Node *w = r, *z = nil;
	while (w != nil) {
		int comp = compare(x, w->x);
		if (comp < 0) {
			z = w;
			w = w->left;
		} else if (comp > 0) {
			w = w->right;
		} else {
			return w->x;
		}
	}
	return z == nil ? null : z->x;
}

template<class Node, class T>
BinarySearchTree<Node,T>::~BinarySearchTree() {
	// nothing to do - BinaryTree destructor does cleanup
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::addChild(Node *p, Node *u) {
		if (p == nil) {
			r = u;              // inserting into empty tree
		} else {
			int comp = compare(u->x, p->x);
			if (comp < 0) {
				p->left = u;
			} else if (comp > 0) {
				p->right = u;
			} else {
				return false;   // u.x is already in the tree
			}
			u->parent = p;
		}
		n++;
		return true;
	}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(T x) {
	Node *p = findLast(x);
	Node *u = new Node;
	u->x = x;
	return addChild(p, u);
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::add(Node *u) {
	Node *p = findLast(u->x);
	return addChild(p, u);
}

template<class Node, class T>
void BinarySearchTree<Node, T>::splice(Node *u) {
	Node *s, *p;
	if (u->left != nil) {
		s = u->left;
	} else {
		s = u->right;
	}
	if (u == r) {
		r = s;
		p = nil;
	} else {
		p = u->parent;
		if (p->left == u) {
			p->left = s;
		} else {
			p->right = s;
		}
	}
	if (s != nil) {
		s->parent = p;
	}
	n--;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::remove(Node *u) {
	if (u->left == nil || u->right == nil) {
		splice(u);
		delete u;
	} else {
		Node *w = u->right;
		while (w->left != nil)
			w = w->left;
		u->x = w->x;
		splice(w);
		delete w;
	}
}

template<class Node, class T>
bool BinarySearchTree<Node, T>::remove(T x) {
	Node *u = findLast(x);
	if (u != nil && compare(x, u->x) == 0) {
		remove(u);
		return true;
	}
	return false;
}

template<class Node, class T> inline
int BinarySearchTree<Node, T>::size() {
	return n;
}

template<class Node, class T> inline
void BinarySearchTree<Node, T>::clear() {
	BinaryTree<Node>::clear();
	n = 0;
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateLeft(Node *u) {
	Node *w = u->right;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->right = w->left;
	if (u->right != nil) {
		u->right->parent = u;
	}
	u->parent = w;
	w->left = u;
	if (u == r) { r = w; r->parent = nil; }
}

template<class Node, class T>
void BinarySearchTree<Node, T>::rotateRight(Node *u) {
	Node *w = u->left;
	w->parent = u->parent;
	if (w->parent != nil) {
		if (w->parent->left == u) {
			w->parent->left = w;
		} else {
			w->parent->right = w;
		}
	}
	u->left = w->right;
	if (u->left != nil) {
		u->left->parent = u;
	}
	u->parent = w;
	w->right = u;
	if (u == r) { r = w; r->parent = nil; }
}



/*
template<class T>
BinarySearchTree1<T*>::BinarySearchTree1() : BinarySearchTree<BSTNode1<T*>, T*>(NULL) {
}
*/

template<class T>
BinarySearchTree1<T>::BinarySearchTree1()  {
}


} /* namespace ods */
#endif /* BINARYSEARCHTREE_H_ */
