#include <cstdio>   
#include <iostream>   
#include <cstdlib>   
#include <climits>   
#include <string>   
#include <vector>   
using namespace std;   
   
class IndexMinPQ{   
public:   
    IndexMinPQ(){   
        N = 0;   
        maxN = 11;   
    }   
   
    void insert(int i, string key) {   
        N++;   
        qp[i] = N;   
        pq[N] = i;   
        keys[i] = key;   
        swim(N);   
    }   
   
    int delMin() {   
        int min = pq[1];   
        exch(1, N--);   
        sink(1);   
        qp[min] = -1;            // delete   
        keys[pq[N+1]] = "";    // to help with garbage collection   
        pq[N+1] = -1;            // not needed   
        return min;   
    }   
   
private:   
    int maxN;        // maximum number of elements on PQ   
    int N;           // number of elements on PQ   
    int pq[11];        // binary heap using 1-based indexing   
    int qp[11];        // inverse of pq - qp[pq[i]] = pq[qp[i]] = i   
    string keys[11];      // keys[i] = priority of i   
   
    bool greater(int i, int j) {   
        return keys[pq[i]]>keys[pq[j]];   
    }   
   
    void exch(int i, int j) {   
        int swap = pq[i];   
        pq[i] = pq[j];   
        pq[j] = swap;   
        qp[pq[i]] = i;   
        qp[pq[j]] = j;   
    }   
   
    void swim(int k)  {   
        while (k > 1 && greater(k/2, k)) {   
            exch(k, k/2);   
            k = k/2;   
        }   
    }   
   
    void sink(int k) {   
        while (2*k <= N) {   
            int j = 2*k;   
            if (j < N && greater(j, j+1)) j++;   
            if (!greater(k, j)) break;   
            exch(k, j);   
            k = j;   
        }   
    }   
};   
   
   
int main()   
{   
    string str[10] = { "it", "was", "the", "best", "of", "times", "it", "was", "the", "worst" };   
    IndexMinPQ pq;   
    for(int i=1;i<=10;i++)   
        pq.insert(i,str[i-1]);   
    for(int i=1;i<=10;i++){   
       int j = pq.delMin();   
       cout<<j<<' '<<str[j-1]<<endl;   
    }   
    return 0;   
}   
