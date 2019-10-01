#ifndef SELECTION_SEARCH_HPP
#define SELECTION_SEARCH_HPP

/*
    quick_search
    ----------------
    returns the kth smallest element in an unsorted array

    time_complexity
    ----------------
    O(n) average

    space_complexity
    ----------------
    O(1)
*/

#include <vector>
#include <random>

// swaps elements i and j in array
template <typename T>
void swap(std::vector<T>& arr, const int i, const int j) {
    T temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
    rearranges array around random pivot element v
    elements smaller than v come first, 
    then elements equal to v, and after,
    elements greater than v
*/
template <typename T>
int partition(std::vector<T>& arr, int l, int r) {
    int v = arr[std::rand() % arr.size()];
    int i = l;
    for(int j = l; j <= r - 1; j++) {
        if(arr[j] <= v) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, i, r);
    return i;
}

/*
    recursively looks at a subarray depending on sub sizes
    and returns the index of the kth smallest element
    returns -1 if something goes wrong
*/
template <typename T>
int quick_search(std::vector<T>& arr, int k, int l, int r) {
    if(k > 0 && k <= r - l - 1) {
        int pos = partition(arr, l, r);

        if(pos - l == k - 1) return arr[pos];
        else if(pos - l > k - 1) return partition(arr, k, l, pos-1);
        else return partition(arr, k-pos+l-1, pos+1, r);
    }
    return -1;
}

#endif
