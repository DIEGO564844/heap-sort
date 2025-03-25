#include <stdio.h>

void creat(int arr[],int i,int length);
void swap(int* arr1, int* arr2);
void px(int* arr,int length);

int main() {
	int arr[9] = {4, 7, 5, 3, 9, 10, 12, 8, 0};
	int length = sizeof(arr) / sizeof(arr[0]);
	px(arr, length);
	for (int i = 0; i < length; i++) {
		printf("%d ", arr[i]);
	}
}

void creat(int arr[], int i,int length)
{
	int lager = i;
	int lson = 2 * i + 1;
	int rson = 2 * i + 2;
	if (lson < length && arr[lson] > arr[lager]) {
		lager = lson;
	}
	if (rson < length && arr[rson] > arr[lager]) {
		lager = rson;
	}
	if (lager != i) {
		swap(&arr[i], &arr[lager]);
	}
	if (lager == i) {
		return;
	}
	else {
		creat(arr, lager, length);
	}
}

void swap(int* arr1, int* arr2)
{
	int t = *arr1;
	*arr1 = *arr2;
	*arr2 = t;
}

void px(int* arr,int length)
{
	for (int i = length / 2 - 1; i >=0; i--) {
		creat(arr, i, length);
	}
	for (int i = length -1; i >0; i--) {
		swap(&arr[0], &arr[i]);
		creat(arr, 0, i);
	}
}

