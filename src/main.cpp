/**
 * @file main.cpp
 * @brief This is Homework 15-Sorting for CPTR 227.
 * @details This is implementation of Heap Sorting.
 * @author Brandon Yi
 * @date 4/19/2021
 * 
 */

#include <iostream>

using namespace std;

class heapsort {
    public:
        static const int alength = 20;
        int a[alength] = {21,37,426,0,1212,49,814,100,61,3,76,30,705,84,1995,98,12,25,7,55};
        int n = 20;

        int left(int i) {
            return 2*i + 1;
        }
        int right(int i) {
            return 2*i + 2;
        }
        int parent(int i) {
            return (i-1)/2;
        }

        int compare (int x,int y) {
            if (x < y)
                return -1;
            else if (x > y)
                return 1;
            else 
                return 0;   
        }

        void myswap(int i,int p) {
            int temp;
            temp = a[i];
            a[i] = a[p];
            a[p] = temp;
        }

        void trickleDown(int i) {
            do {
                int j = -1;
                int r = right(i);
                if (r < n && compare(a[r], a[i]) < 0) {
                    int l = left(i);
                    if (compare(a[l], a[r]) < 0) {
                        j = l;
                    } else {
                        j = r;
                    }
                } else {
                    int l = left(i);
                    if (l < n && compare(a[l], a[i]) < 0) {
                        j = l;
                    }
                }
                if (j >= 0) myswap(i, j);
                i = j;
            } while (i >= 0);
        }

        void BinaryHeap() {
            n = alength;
            for (int i = n/2-1; i >= 0; i--) {
                trickleDown(i);
            }
        }

        void reverse() {
        for (int i =0; i < alength/2; i++)
            myswap(i,(alength-i-1));
        }

        void sort() {
            BinaryHeap();
            while (n > 1) {
                myswap(--n, 0);
                trickleDown(0);
            }
            reverse();
        }

        void print() {
        for (int i = 0; i < alength; i++)
            std::cout << a[i] << " ";
        std::cout << endl; 
        }
};


int main() {
    heapsort h;
    cout << "This is before sorting" << endl;
    h.print();
    h.sort();
    cout << "This is after sorting" << endl;
    h.print();
}