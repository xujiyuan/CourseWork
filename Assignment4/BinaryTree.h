/*
 * BinaryTree.h
 *
 *  Created on: 2011-11-28
 *      Author: morin
 */

#ifndef BINARYTREE_H_
#define BINARYTREE_H_
#include <cstdlib>
#include <cmath>

#include "ArrayDeque.h"

namespace ods {

template<class N>
class BTNode {
public:
	N *left;
	N *right;
	N *parent;
    int preOrderNumber, inOrderNumber, postOrderNumber;
	BTNode() {
		left = right = parent = NULL;
	}
};


template<class Node>
class BinaryTree {
protected:
	Node *r;    // root node
	Node *nil;  // null-like node
	virtual int size(Node *u);
    virtual bool isBalanced(Node *u);
	virtual int height(Node *u);
	virtual void traverse(Node *u);
public:
	virtual ~BinaryTree();
	BinaryTree();
	BinaryTree(Node *nil);
	virtual void clear();
	virtual int depth(Node *u);
	virtual int size();
	virtual int size2();
	virtual int height();
    virtual int height2();
	virtual void traverse();
	virtual void traverse2();
	virtual void bfTraverse();
    virtual bool isBalanced();
};

class BTNode1 : public BTNode<BTNode1> { };


template<class Node>
BinaryTree<Node>::~BinaryTree() {
	clear();
}
    
template<class Node>
bool BinaryTree<Node>::isBalanced(){
    
   // std::cout << "balance result: " << isBalanced(r) << std::endl;

    return isBalanced(r);
        
}
template<class Node>
bool BinaryTree<Node>::isBalanced(Node* u){
    
    if (u == nil)
        return 1;
    /* Get the height of left and right sub trees */
    
    int l = size(u->left);
    int r = size(u->right);
    

    if(abs(l - r) > 1){
        return 0;
    }
    else {
        //std::cout << "l-r larger smaller than 1" << std::endl;

        return isBalanced(u->left) && isBalanced(u->right);
    }
    
}
    

template<class Node>
void BinaryTree<Node>::clear() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
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
		if (next == u->parent)
			delete u;
		u = next;
	}
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree(Node *nil) {
	this->nil = nil;
	r = nil;
}

template<class Node>
BinaryTree<Node>::BinaryTree() {
	nil = NULL;
	r = nil;
}


template<class Node>
int BinaryTree<Node>::depth(Node *u) {
	int d = 0;
	while (u != r) {
		u = u->parent;
		d++;
	}
	return d;
}

template<class Node>
int BinaryTree<Node>::size() {
	return size(r);
}

template<class Node>
int BinaryTree<Node>::size(Node *u) {
	if (u == nil) return 0;
	return 1 + size(u->left) + size(u->right);
}

template<class Node>
int BinaryTree<Node>::size2() {
		Node *u = r, *prev = nil, *next;
		int n = 0;
		while (u != nil) {
			if (prev == u->parent) {
				n++;
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
		return n;
	}
    
template<class Node>
int BinaryTree<Node>::height2() {
    Node *u = r, *prev = nil, *next;
    int maxHeight = 0;
    int n = 0;
    while (u != nil) {
        if (prev == u->parent) {
            
            if (u->left != nil) {
                n++;
                next = u->left;
            }
            else if (u->right != nil){
                next = u->right;
                n++;
            }
            else {
                n--;
                next = u->parent;
            }
        } else if (prev == u->left) {
            if (u->right != nil) next = u->right;
            else{
                n--;
                next = u->parent;
            }
        } else {
            n--;
            next = u->parent;
        }
        prev = u;
        u = next;
        
        if(n>maxHeight){
            maxHeight = n;
        }
    }
    return maxHeight;
}
    
    


template<class Node>
int BinaryTree<Node>::height() {
	return height(r);
}

template<class Node>
int BinaryTree<Node>::height(Node *u) {
	if (u == nil) return -1;
	return 1 + max(height(u->left), height(u->right));
}

template<class Node>
void BinaryTree<Node>::traverse() {
	traverse(r);
}

template<class Node>
void BinaryTree<Node>::traverse(Node *u) {
		if (u == nil) return;
		traverse(u->left);
		traverse(u->right);
}
    
    

template<class Node>
void BinaryTree<Node>::traverse2() {
	Node *u = r, *prev = nil, *next;
	while (u != nil) {
		if (prev == u->parent) {
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
}

template<class Node>
void BinaryTree<Node>::bfTraverse() {
	ArrayDeque<Node*> q;
	if (r != nil) q.add(q.size(),r);
	while (q.size() > 0) {
		Node *u = q.remove(q.size()-1);
		if (u->left != nil) q.add(q.size(),u->left);
		if (u->right != nil) q.add(q.size(),u->right);
	}
}


} /* namespace ods */
#endif /* BINARYTREE_H_ */
