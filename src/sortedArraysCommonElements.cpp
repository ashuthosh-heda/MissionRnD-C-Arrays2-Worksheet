/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int dateCompare3(char* date1, char* date2){
	if (date1[2] != '-' || date1[5] != '-' || date2[2] != '-' || date2[5] != '-')
		return -2;  //Invalid Date

	//Loop to compare Years
	for (int i = 6; i < 10; i++){
		if (date2[i] > date1[i])
			return -1;
		if (date2[i] < date1[i])
			return 1;
	}

	//Loop to compare months
	for (int i = 3; i < 5; i++){
		if (date2[i] > date1[i])
			return -1;
		if (date2[i] < date1[i])
			return 1;
	}

	//Loop to compare Date
	for (int i = 0; i < 2; i++){
		if (date2[i] > date1[i])
			return -1;
		if (date2[i] < date1[i])
			return 1;
	}

	return 0;
}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || (ALen <= 0 && BLen <= 0))
		return NULL;

	struct transaction *merged = (struct transaction*) calloc(ALen+BLen, sizeof(struct transaction));

	int cmp = 0;
	int i = 0, j = 0, k = 0;
	while (i < ALen && j < BLen){
		cmp = dateCompare3(A[i].date, B[j].date);
		if (cmp == -2)
			return NULL;
		if (cmp == 0){
			merged[k] = A[i];
			k++;
		}
		i++;
		j++;
	}

	if (k == 0)
		return NULL;

	return merged;
}