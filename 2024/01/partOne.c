#include <stdio.h>
#include <stdlib.h>

// best by test
void insertionSort(int arr[], int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];	
		int j = i - 1;

		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

int main(void) {
	FILE* fh;
	int list1[1000];
	int list2[1000];
	int n1, n2;

	fh = fopen("input.txt", "r");

	if (fh == NULL) {
		printf("file does not exist\n");
		exit(1);
	}

	int ln = 1;
	while (fscanf(fh, "%d %d", &n1, &n2) != EOF) {
		list1[ln - 1] = n1;
		list2[ln - 1] = n2;
		ln++;
	}
	ln--;
	insertionSort(list1, ln);
	insertionSort(list2, ln);

	int totalDistance = 0;
	int l1, l2;
	for (int i = 0; i < ln; i++) {
		l1 = list1[i];
		l2 = list2[i];
		totalDistance += (l1 < l2) ? l2 - l1 : l1 - l2;
	}

	printf("totalDistance: %d\n", totalDistance);

	return 0;
}

