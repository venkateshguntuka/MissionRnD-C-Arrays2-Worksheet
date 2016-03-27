/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int isLesser(char *arr1Date, char *arr2Date)
{
	int day1 = (((arr1Date[0] - '0') * 10) + (arr1Date[1] - '0'));
	int mon1 = (((arr1Date[3] - '0') * 10) + (arr1Date[4] - '0'));
	int year1 = (((arr1Date[6] - '0') * 1000) + ((arr1Date[7] - '0') * 100) + ((arr1Date[8] - '0') * 10) + (arr1Date[9] - '0'));
	int day2 = (((arr2Date[0] - '0') * 10) + (arr2Date[1] - '0'));
	int mon2 = (((arr2Date[3] - '0') * 10) + (arr2Date[4] - '0'));
	int year2 = (((arr2Date[6] - '0') * 1000) + ((arr2Date[7] - '0') * 100) + ((arr2Date[8] - '0') * 10) + (arr2Date[9] - '0'));
	if (year1>year2)
		return 2;
	else if (year1<year2)
		return 1;
	else if (mon1>mon2)
		return 2;
	else if (mon1<mon2)
		return 1;
	else if (day1>day2)
		return 2;
	else if (day1<day2)
		return 1;
	else
		return 0;

}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *result = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int i = 0, j = 0, z = 0,flag=0;
	while (i < ALen&&j < BLen)
	{
		flag = isLesser(A[i].date, B[j].date);
		if (flag==1)
			result[z++] = A[i++];
		else if (flag==2)
			result[z++] = B[j++];
		else//the dates are equal,store them twice in result
		{
			result[z++] = A[i++];
			result[z++] = B[j++];
		}
	}
	while (i < ALen)
	{
		result[z++] = A[i++];
	}
	while (j < BLen)
	{
		result[z++] = B[j++];
	}
	return result;
}
