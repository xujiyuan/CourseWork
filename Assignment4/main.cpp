#include <iostream>

#include "BinaryTree.h"
#include "BinarySearchTree.h"

bool testPart1();
bool testPart2();
bool testPart3();
bool testPart4();


using namespace std;
using namespace ods;


int main() {
    
    BinaryTree<BSTNode1<int>> BTree;
    
    cout << "test result part 1:" << testPart1() << endl;
    cout << "test result part 2:" << testPart2() << endl;
    cout << "test result part 3:" << testPart3() << endl;
    cout << "test result part 4:" << testPart4() << endl;
    
    return 0;
}

bool testPart1(){
    BinarySearchTree<BSTNode1<int>, int> tree;
    
    tree.add(1);
    tree.add(2);
    tree.add(3);
    tree.add(4);
    tree.add(5);
    tree.add(11);
    tree.add(12);
    tree.add(13);
    tree.add(14);
    tree.add(15);
    
    if(tree.size() == 10 && tree.height() == tree.height2()){
        return true;
    }
    else return false;
}

bool testPart2(){
    
    bool result = false;
    BinarySearchTree<BSTNode1<int>, int> tree1;
    
    tree1.add(2);
    tree1.add(3);
    tree1.add(1);

   // cout << "is balanced result:" << tree1.isBalanced()<<endl;
    
    BinarySearchTree<BSTNode1<int>, int> tree2;
    
    tree2.add(2);
    tree2.add(3);
    tree2.add(4);

   // cout << "is balanced result:" << tree2.isBalanced()<<endl;
    
    if(tree1.isBalanced()==true && tree2.isBalanced()==false){
        result = true;
    }
    
    return result;
}

bool testPart3(){
    
    BinarySearchTree<BSTNode1<int>, int> tree1;
    
    tree1.add(2);
    tree1.add(3);
    tree1.add(1);
    
   // cout << tree1.getNode(2)->x << endl;
    
    if(tree1.getNode(2)->x == 2)
    return true;
    
    else return false;
    
}

bool testPart4(){
    
    BinarySearchTree<BSTNode1<int>, int> tree1;
    
    tree1.add(2);
    tree1.add(3);
    tree1.add(1);
    tree1.add(4);
    tree1.add(5);
    tree1.add(6);
    
    
    DLList<int> dl = tree1.getLE(5);
    
    if(dl.size() == 4){
        return true;
    }
    
    return false;
}
