// ѡ������.cpp : �������̨Ӧ�ó������ڵ㡣

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
using namespace std;

template<typename T>
void swap(T *a ,T *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

template<typename T>
void selectionSort(T arr[] ,int n){
	for (int i = 0; i < n; i++) {
		int  minIndex = i;

		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		swap(arr[i], arr[minIndex]);

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i];
		cout << endl;
	}
}


int main() {
	//float a[10] = { 10.1,9.3,0,73.0,2.7,76.1,90.9,78.0,90.1,23.8 };
	Student a[4] = { {5,"abv"},{0,"abv"},{5,"abv"},{5,"abv"} };
	selectionSort(a, 4);
	system("pause");
	return 0;
}

