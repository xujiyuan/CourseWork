
#include <iostream>

namespace ods {

template<class H>
class DataStructureTester {
protected:
    H list;
    //array<int> t;
public:
    int *a;
//    ~DataStructureTester(){
//        delete a;
//    }
    int DoRandomAdd(int n);
    int DoSequentialAdd(int start, int end, int step);
    int DoRandomFind(int n);
    int DoSequentialRemove(int start, int end, int step);
    int DoSequentialFind(int start, int end, int step);
    int DoRandomRemove(int n);
    
};
    
//template<class H>
//    DataStructureTester<H>::DataStructureTester(){
//
//    }

template<class H>
int DataStructureTester<H>::DoRandomAdd(int n) {
      a = new int[n];
    clock_t start = clock();
    
      int i=0;
      while (i<n){
          int ran = std::rand();
          list.add(ran);
          a[i] = ran;
          i++;
      }
         clock_t end = clock();
         int difference = (int)(end-start);
    
    return difference;

  }
    

template<class H>
int DataStructureTester<H>:: DoSequentialAdd(int start, int end, int step) {
        clock_t start_time = clock();
        
        while(start<end){
            list.add(start);
            start += step;
           // std::cout<<"i am here" << start << std::endl;
        }
        clock_t end_time = clock();
        int diff = (int)(end_time-start_time);
    
       return diff;

    }
    
template<class H>
int DataStructureTester<H>::DoSequentialRemove(int start, int end, int step){
    clock_t start_time = clock();

        while (start < end) {
            list.remove(start);
            start += step;
        }
    
    clock_t end_time = clock();
    int diff = (int)(end_time-start_time);

        return diff;
    }
    

    
template<class H>
int DataStructureTester<H>::DoRandomRemove(int n){
    clock_t start = clock();
    int max = list.size();
    int i=0;
    while (i<n && i<max){
        list.remove(a[i]);
        i++;
    }
    clock_t end = clock();
    int difference = (int)(end - start);
    
    return difference;
    
        return 0;
}
    
    
template<class H>
int DataStructureTester<H>::DoSequentialFind(int start, int end, int step){
    clock_t start_time = clock();
    
    
        while(start<end){
            list.find(start);
            start += step;
           //std::cout<<"i am here" << start << std::endl;

        }
    
    clock_t end_time = clock();
    int diff = (int)(end_time-start_time);
    
        return diff;
    }
    
template<class H>
int DataStructureTester<H>::DoRandomFind(int n){
    clock_t start = clock();
    int max = list.size();
    int i=0;
    while (i<n && i<max){
        list.find(a[i]);
        i++;
    }
        clock_t end = clock();
    int difference = (int)(end - start);
    
    return difference;
}
    

}
