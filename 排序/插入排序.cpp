#include <iostream>
#include <algorithm>

using namespace std;
template <typename T>
void insertionSort(T arr[], int n) {

	for (int i = 1; i < n; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[i] < arr[j]) {
				swap(arr[i],arr[j-1])
			}
			else {
				break;
			}
		}
	}

}
