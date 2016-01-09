/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int dateCompare1(char* date1, char* date2){
	if (date1[2] != '-' || date1[5] != '-' || date2[2] != '-' || date2[5] != '-')
		return -2;

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

	//Loop to compare Dates
	for (int i = 0; i < 2; i++){
		if (date2[i] > date1[i])
			return -1;
		if (date2[i] < date1[i])
			return 1;
	}

	return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (Arr == 0 || date == 0)
		return -1;
	if (len <= 0)
		return -1;

	int cmp;
	int i;

	for (i = 0; i < len; i++){
		cmp = dateCompare1(Arr[i].date, date);
		if (cmp == 0 || cmp == -1) //Equal or lesser Date.
			continue;
		else if (cmp == -2) //Invalid Date
			return -1;
		else
			break;
	}

	return len - i;
}
