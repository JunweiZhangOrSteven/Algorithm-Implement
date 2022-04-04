#include<iostream>
using namespace std;



void maxHeap(int arr[], int end) {
	int lastFather = (0 + end) % 2 != 0 ? (0 + end) / 2 : (0 + end) / 2 - 1;

	for (int father = lastFather; father >= 0; father--) {

		int left = father * 2 + 1;
		int right = father * 2 + 2;

		if (right <= end && arr[right] > arr[father]) {
			swap(arr[father], arr[right]);
		}
		if (arr[left] > arr[father]) {
			swap(arr[father], arr[left]);
		}

	}

}

void HeapSort(int arr[],int len) {

	

	for (int end = len - 1; end > 0; end--) {
		maxHeap(arr, end);

		swap(arr[0], arr[end]);


	}




}


int main() {
	int arr[] = { 0,4,3,6,3,5,9,3,2,6,11,13 };
	int len = sizeof(arr) / sizeof(arr[0]);

	HeapSort(arr, len);

}