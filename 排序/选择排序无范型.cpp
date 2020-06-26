#include <iostream>
#include <algorithm>
using namespace std;
void swap(int * a,int *b);
void selectionSort(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		int  minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		swap(arr[i], arr[minIndex]);

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

void swap(int * a,int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a[10] = { 10,9,0,73,2,76,90,78,90,23 };
	selectionSort(a, 10);
	return 0;
}