/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

bool isSorted(int* A, int len){
	for (int i = 0; i < (len-1); i++)
		if (A[i] > A[i + 1])
			return false;
	return true;
}

void quickSort(int* A, int l, int r){
	int pivot, i, j, t;

	if (l < r){
		pivot = l;
		i = l;
		j = r;

		while (i < j){
			while (A[i] <= A[pivot] && i < r)
				i++;
			while (A[j] > A[pivot])
				j--;
			if (i < j){
				t = A[i];
				A[i] = A[j];
				A[j] = t;
			}
		}

		t = A[pivot];
		A[pivot] = A[j];
		A[j] = t;

		quickSort(A, l, j - 1);
		quickSort(A, j + 1, r);
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	if (A == 0 || len <= 0)
		return -1;

	if (isSorted(A, len) == false)
		quickSort(A, 0, len - 1);

	for (int i = 0; i < len; i += 3){
		if ((i + 1) == len)
			return A[i];
		if (A[i] != A[i + 1])
			return A[i];
	}

	return -1;
}
