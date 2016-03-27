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
int compare(char *arrDate, int day, int mon, int year)
{
	int arrYear = (((arrDate[6] - '0') * 1000) + ((arrDate[7] - '0') * 100) + ((arrDate[8] - '0') * 10) + (arrDate[9] - '0'));
	if (arrYear>year)
		return 1;
	else if (arrYear<year)
		return 0;
	int arrMon = (((arrDate[3] - '0') * 10) + (arrDate[4] - '0'));
	if (arrMon<mon)
		return 1;
	else if (arrMon<mon)
		return 0;
	int arrDay = (((arrDate[0] - '0') * 10) + (arrDate[1] - '0'));
	if (arrDay>day)
		return 1;
	else if (arrDay < day)
		return 0;
	else
		return 0;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len < 1)
		return -1;

	int result = 0;
	int day = (((date[0] - '0') * 10) + (date[1] - '0'));
	int mon = (((date[3] - '0') * 10) + (date[4] - '0'));
	int year = (((date[6] - '0') * 1000) + ((date[7] - '0') * 100) + ((date[8] - '0') * 10) + (date[9] - '0'));
	for (int i = 0; i < len; i++)
	{
		result += compare(Arr[i].date, day, mon, year);
	}
	return result;
}
