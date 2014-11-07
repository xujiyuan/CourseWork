/*
 * LinearHashTable.h
 *
 *  Created on: 2011-12-16
 *      Author: morin
 */

#ifndef LINEARHASHTABLE_H_
#define LINEARHASHTABLE_H_
#include <climits>
#include <iostream>
using namespace std;
#include "array.h"
namespace ods {

extern unsigned int tab[4][256];

template<class T>
class LinearHashTable {

	static const int w = 32;
	static const int r = 8;
	int n;   // number of values in T
	int q;   // number of non-null entries in T
	int d;   // t.length = 2^d
	T null, del;
	void resize();
	int hash(T x) {
        //awesome hashing function!
        return x%(t2.length+t.length);
	}
    
    int hash2(T x){
        return 1 + (hash(x) % (t2.length+t.length-1));
    }
	// Sample code for the book only -- never use this
	/*
	int idealHash(T x) {
		return tab[hashCode(x) >> w-d];
	}
	*/


public:
    array<T> t;
    array<T> t2;
	// FIXME: get rid of default constructor
	LinearHashTable();
	LinearHashTable(T null, T del);
	virtual ~LinearHashTable();
	bool add(T x);
	bool addSlow(T x);
	T remove(T x);
	T find(T x);
	int size() { return n; }
	void clear();
	// FIXME: yuck
	void setNull(T null) { this->null = null; t.fill(null); }
	void setDel(T del) { this->del = del; }
    int length() {
        return t.length+t2.length;
    }
};

/*
template<>
LinearHashTable<int>::LinearHashTable() : t(2, INT_MIN) {
	null = INT_MIN;
	del = INT_MIN + 1;
	n = 0;
	q = 0;
	d = 1;
}
*/

/**
 * FIXME: Dangerous - leaves null and del uninitialized
 */
template<class T>
LinearHashTable<T>::LinearHashTable() : t(2),t2(2){
/*
	this->null = null;
	this->del = del;
*/
	n = 0;
	q = 0;
	d = 1;
}


template<class T>
LinearHashTable<T>::LinearHashTable(T null, T del) : t(2, null),t2(2, null) {
	this->null = null;
	this->del = del;
	n = 0;
	q = 0;
	d = 1;
}

template<class T>
LinearHashTable<T>::~LinearHashTable() {
}

template<class T>
void LinearHashTable<T>::resize() {
	d = 1;
	while ((1<<d) < 3*n) d++;
	array<T> tnew(1<<d, null);
    array<T> tnew2(1<<d, null);

	q = n;
	// insert everything into tnew
	for (int k = 0; k < t.length; k++) {
		if (t[k] != null && t[k] != del) {
			int i = hash(t[k]), j = 0;
            
            if(i<t.length){
                while (tnew[i] != null)
                    
                    i = (hash(t[k])+ j++*hash2(t[k])) % (tnew.length+tnew2.length);
                tnew[i] = t[k];
            }
            
            else {
                while (tnew2[i] != null)
                    
                i = (hash(t[k])+ j++*hash2(t[k])) % (tnew.length+tnew2.length);
                if( i>t.length) i = i -t.length;
                
                tnew2[i] = t2[k];
                
            }

		}
	}
	t = tnew;
    

    
    
}

template<class T>
void LinearHashTable<T>::clear() {
	n = 0;
	q = 0;
	d = 1;
	array<T> tnew(2, null);
    array<T> tnew2(2, null);

	t = tnew;
    t2 = tnew2;
}

template<class T>
bool LinearHashTable<T>::add(T x) {
	if (find(x) != null) return false;
	if (2*(q+1) > t.length+t2.length) resize();   // max 50% occupancy
    
	int i = hash(x), j = 0;
    
    if(i<t.length){
    
	while (t[i] != null && t[i] != del)
		 i = (hash(x)+ j++*hash2(x)) % (t.length+t2.length);
       
    cout << "returned i  from double hash is: " << i << endl;
	if (t[i] == null) q++;
	n++;
        if (i<t.length){
    
	t[i] = x;
    cout << "what is my t[i] " << t[i] << endl;
    }
    
    }
    
    else {
        i = i-t.length;
        
        while (t2[i] != null && t2[i] != del)
            i = (hash(x)+ j++*hash2(x)) % (t.length+t2.length);
        cout << "returned i  from double hash is: " << i << endl;
        if (t2[i] == null) q++;
        n++;
        if(i>t.length){
        t2[i-t.length] = x;
        }
        cout << "what is my t2[i] " << t2[i] << endl;
        
    }
    
    
    
    
    
	return true;
}

template<class T>
T LinearHashTable<T>::find(T x) {
    int i = hash(x), j = 0;
    if(i<t.length){
	while (t[i] != null && t[i] != del){
        i = (hash(x)+ j++*hash2(x)) % (t.length+t2.length);
        if(t[i] == x) return t[i];
    }
    }
    
    else {
        i = hash(x)-t.length;
       	while (t2[i] != null && t2[i] != del){
            i = (hash(x)+ j++*hash2(x)) % (t.length+t2.length);
            i = i-t.length;
            if(t2[i] == x) return t2[i];
        }
    }
    return null;

}

template<class T>
T LinearHashTable<T>::remove(T x) {
	int i = hash(x);
	while (t[i] != null) {
		T y = t[i];
		if (y != del && x == y) {
			t[i] = del;
			n--;
			if (8*n < t.length) resize(); // min 12.5% occupancy
			return y;
		}
		i = (i == t.length-1) ? 0 : i + 1;  // increment i
	}
	return null;
}

template<class T>
bool LinearHashTable<T>::addSlow(T x) {
	if (2*(q+1) > t.length) resize();   // max 50% occupancy
	int i = hash(x);
	while (t[i] != null) {
			if (t[i] != del && x.equals(t[i])) return false;
			i = (i == t.length-1) ? 0 : i + 1; // increment i
	}
	t[i] = x;
	n++; q++;
	return true;
}


} /* namespace ods */
#endif /* LINEARHASHTABLE_H_ */
