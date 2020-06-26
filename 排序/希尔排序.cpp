// 希尔排序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define num 100

//插入排序的实现

void insert_sort(int * a,int len) {

	int temp;

	for (int i = 1; i < len; i++) {
		temp = a[i];
		int y;
		for ( y = i - 1; y >= 0;y-- ) {
			if (a[y] > temp) {

				a[y+1] = a[y];

			}
			else {
				break;
			}
				
		}

			a[y+1] = temp;
	}
}

void print(int* a, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d  ", a[i]);
	}
	printf("\n");
}


void  shell_sort(int *a, int len) {

	int step = len / 2;
	

	while (step >= 1) { //步数不断较小,直到1为止


		//步数进行分组
		for (int z = len - step; z < len; z++ ) {

			int temp;


			// 使用插入排序对每个分组进行排序
			for (int i = step; i < len;) {
				temp = a[i];
				int y;
				for (y = i - step; y >= 0; ) {
					if (a[y] > temp) {

						a[y + step] = a[y];

					}
					else {
						break;
					}
					y = y - step;
				}

				a[y + step] = temp;

				i = i + step;
			}

		}
		
			step = step - 1;
	}

}



void  shell_sorts(int *a, int len) {

	int step = len / 2;


	while (step >= 1) { //步数不断较小,直到1为止


						//步数进行分组
		//for (int i = len - step; i < len; i++) {

			int temp;


			// 使用插入排序对每个分组进行排序
			for (int i = step; i < len;i++) {
				temp = a[i];
				int y;
				for (y = i - step; y >= 0; ) {
					if (a[y] > temp) {

						a[y + step] = a[y];

					}
					else {
						break;
					}
					y = y - step;
				}

				a[y + step] = temp;

			}

		

		step = step/2;
	}

}




int main()
{
	int a[num] = {9,66,54,33,-5,78,123,0,8,73};

	shell_sort(a, 10);

	print(a, 10);

	while (1);
    return 0;
}

