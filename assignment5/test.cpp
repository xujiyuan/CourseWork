//============================================================================
// Name        : hw5.cpp
// Author      : Pierre
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "ChainedHashTable.h"
#include "DataStructureTester.h"
#include "LinearHashTable.h"
#include "BinarySearchTree.h"
#include "RedBlackTree.h"

using namespace std;
using namespace ods;

int main() {
    
    int test1_ra_average;
    int test1_rf_average;
    int test1_rd_average;
    int test1_sa_average;
    int test1_sf_average;
    int test1_sd_average;
    
    int test2_ra_average;
    int test2_rf_average;
    int test2_rd_average;
    int test2_sa_average;
    int test2_sf_average;
    int test2_sd_average;
    
    int test3_ra_average;
    int test3_rf_average;
    int test3_rd_average;
    int test3_sa_average;
    int test3_sf_average;
    int test3_sd_average;
    
    int test4_ra_average;
    int test4_rf_average;
    int test4_rd_average;
    int test4_sa_average;
    int test4_sf_average;
    int test4_sd_average;
    
    int i=0;
    int factor = 20;
    
    cout << "===== Print report for BinarySearchTree ====="<< endl;
    
    while(i<factor){
        DataStructureTester<BinarySearchTree<BSTNode1<int>,int>> test1;
        test1_ra_average += test1.DoRandomAdd(50000);
        test1_rf_average += test1.DoRandomFind(50000);
        test1_rd_average += test1.DoRandomRemove(50000);
        test1_sa_average += test1.DoSequentialAdd(1,50000,1);
        test1_sf_average += test1.DoSequentialFind(1,50000,1);
        test1_sd_average += test1.DoSequentialRemove(1,50000,1);
        
        i++;
    }
    
    cout << "1. Average Time processing RandomAdd is: " << test1_ra_average/factor << endl;
    cout << "2. Average Time processing RandomFind is: " << test1_rf_average/factor << endl;
    cout << "3. Average Time processing RandomRemove is: " << test1_rd_average/factor << endl;
    cout << "4. Average Time processing DoSequentialAdd is: " << test1_sa_average/factor << endl;
    cout << "5. Average Time processing DoSequentialFind is: " << test1_sf_average/factor << endl;
    cout << "6. Average Time processing DoSequentialRemove is: " << test1_sd_average/factor << endl;
    
    i=0;
    cout << "===== Print report for RedBlackTree ====="<< endl;
    
    while(i<factor){
        DataStructureTester<RedBlackTree<RedBlackNode1<int>,int> > test2;
        test2_ra_average += test2.DoRandomAdd(50000);
        test2_rf_average += test2.DoRandomFind(50000);
        test2_rd_average += test2.DoRandomRemove(50000);
        test2_sa_average += test2.DoSequentialAdd(1,50000,1);
        test2_sf_average += test2.DoSequentialFind(1,50000,1);
        test2_sd_average += test2.DoSequentialRemove(1,50000,1);
        
        i++;
    }
    
    cout << "1. Average Time processing RandomAdd is: " << test2_ra_average/factor << endl;
    cout << "2. Average Time processing RandomFind is: " << test2_rf_average/factor << endl;
    cout << "3. Average Time processing RandomRemove is: " << test2_rd_average/factor << endl;
    cout << "4. Average Time processing DoSequentialAdd is: " << test2_sa_average/factor << endl;
    cout << "5. Average Time processing DoSequentialFind is: " << test2_sf_average/factor << endl;
    cout << "6. Average Time processing DoSequentialRemove is: " << test2_sd_average/factor << endl;
    
    i=0;
    
    cout << "===== Print report for LinearHashTable ====="<< endl;
    
    while(i<factor){
        DataStructureTester<LinearHashTable<int>> test3;
        test3_ra_average += test3.DoRandomAdd(50000);
        test3_rf_average += test3.DoRandomFind(50000);
        test3_rd_average += test3.DoRandomRemove(50000);
        test3_sa_average += test3.DoSequentialAdd(1,50000,1);
        test3_sf_average += test3.DoSequentialFind(1,50000,1);
        test3_sd_average += test3.DoSequentialRemove(1,50000,1);
        
        i++;
    }
    
    cout << "1. Average Time processing RandomAdd is: " << test3_ra_average/factor << endl;
    cout << "2. Average Time processing RandomFind is: " << test3_rf_average/factor << endl;
    cout << "3. Average Time processing RandomRemove is: " << test3_rd_average/factor << endl;
    cout << "4. Average Time processing DoSequentialAdd is: " << test3_sa_average/factor << endl;
    cout << "5. Average Time processing DoSequentialFind is: " << test3_sf_average/factor << endl;
    cout << "6. Average Time processing DoSequentialRemove is: " << test3_sd_average/factor << endl;
    
    
    i=0;
    
    cout << "===== Print report for ChainedHashTable ====="<< endl;
    
    while(i<factor){
        DataStructureTester<ChainedHashTable<int> > test4;
        test4_ra_average += test4.DoRandomAdd(50000);
        test4_rf_average += test4.DoRandomFind(50000);
        test4_rd_average += test4.DoRandomRemove(50000);
        test4_sa_average += test4.DoSequentialAdd(1,50000,1);
        test4_sf_average += test4.DoSequentialFind(1,50000,1);
        test4_sd_average += test4.DoSequentialRemove(1,50000,1);
        
        i++;
    }
    
    
    cout << "1. Average Time processing RandomAdd is: " << test4_ra_average/factor << endl;
    cout << "2. Average Time processing RandomFind is: " << test4_rf_average/factor << endl;
    cout << "3. Average Time processing RandomRemove is: " << test4_rd_average/factor << endl;
    cout << "4. Average Time processing DoSequentialAdd is: " << test4_sa_average/factor << endl;
    cout << "5. Average Time processing DoSequentialFind is: " << test4_sf_average/factor << endl;
    cout << "6. Average Time processing DoSequentialRemove is: " << test4_sd_average/factor << endl;


	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}



