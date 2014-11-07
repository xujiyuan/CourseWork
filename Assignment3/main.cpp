//
//  main.cpp
//  Assignment3
//
//  Created by xuj4 on 10/20/14.
//  Copyright (c) 2014 Jimmy. All rights reserved.
//

#include <iostream>
#include "ChainedHashTable.h"
#include "LinearHashTable.h"
using namespace ods;


int main(int argc, const char * argv[])
{
    
    
    ChainedHashTable<int> st;
    
    for(int i=0; i< 10 ; i++){
        st.add(i);
    }
    
    cout << "Load factor is:  " << st.returnlf() << endl;
    cout << "size of the table is: " << st.size() << endl;
    cout << "Length of the table is: " << st.length() << endl;
    cout << "length of the longest array is: " << st.GetLongestList() << endl;
    
    //test setting load factor
    st.SetLocalFactor(10);
    
    for(int j=0; j< 500 ; j++){
        st.add(j);
    }
    
    cout << "Load factor is:  " << st.returnlf() << endl;
    cout << "size of the table is: " << st.size() << endl;
    cout << "Length of the table is: " << st.length() << endl;
    cout << "length of the longest array is: " << st.GetLongestList() << endl;
    
    
    /**
     * Test LinearHashTable
     **/
    
    LinearHashTable<int> lh;
    
    for(int k=0; k< 10 ; k++){
        cout << "add result " << lh.add(k) << endl;
        cout << "Get value for Ks: " << lh.find(k) << endl;
    }
    
    cout << "size of the LH table is: " << lh.size() << endl;
   // cout << "Length of the LH table is: " << lh.length() << endl;
    
//    for (int g=0; g< 10;g++){
//        cout << "Get value for Ks: " << lh.find(g) << endl;
//    }
//    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

