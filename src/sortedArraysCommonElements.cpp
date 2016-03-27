/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
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
int isEqual(char *arr1Date, char *arr2Date)
{
	int equalFlag = 1;
	for (int i = 0; arr1Date[i] != '\0'&&arr1Date[i] != '\0'; i++)
	{
		if (arr1Date[i] != arr2Date[i])
		{
			equalFlag = 0;
			return equalFlag;
		}
	}
	return equalFlag;
}
struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL || ALen < 0 || BLen < 0)
		return NULL;
	int len = ALen, j = 0, equalFlag;
	if (ALen > BLen)
		len = BLen;
	struct transaction *result = (struct transaction *)malloc(sizeof(struct transaction)*len);
	for (int i = 0; i < len; i++)
	{
		equalFlag = isEqual(A[i].date, B[i].date);
		if (equalFlag == 1)
		{
			result[j] = A[i];
			j++;
		}
	}
	if (j > 0)
		return result;
	free(result);
	return NULL;

}