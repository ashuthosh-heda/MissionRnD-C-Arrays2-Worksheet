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

bool isSorted(int *A, int len){
	for (int i = 0; i < (len - 1); i++)
		if (A[i] > A[i + 1])
			return false;
	return true;
}

void sort(int *A, int len){
	for (int i = 0; i < len - 1; i++){
		for (int j = i + 1; j < len; j++){
			if (A[i] < A[j]){
				int temp = A[i];
				A[i] = A[j];
				A[j] = temp;
			}
		}
	}
}

int findSingleOccurenceNumber(int *A, int len) {
	if (A == 0 || len <= 0)
		return -1;

	bool check = isSorted(A, len);

	if (check == false)
		sort(A, len);

	for (int i = 0; i < len; i = i + 3){
		if (A[i] != A[i + 1])
			return A[i];
	}

	return -1;
}