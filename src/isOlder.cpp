/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int ConvertInt(char *cp){
	int temp = 0;
	for (int i = 0; cp[i] != '\0'; i++)
	{
		temp += cp[i] - '0';
		temp *= 10;
	}
	return temp / 10;
}
int isOlder(char *first, char *second) {
	char year1[10], year2[10];
	char month1[10], month2[10];
	char date1[10], date2[10];

	for (int i = 5, j = 0; i < 9; i++, j++){
		year1[j] = first[i];
		year2[j] = second[i];
	}

	year1[4] = '\0';
	year2[4] = '\0';

	month1[0] = first[4];
	month1[1] = first[5];
	month1[2] = '\0';

	month2[0] = second[4];
	month2[1] = second[5];
	month2[2] = '\0';

	date1[0] = first[0];
	date1[1] = first[1];
	date1[2] = '\0';

	date2[0] = second[0];
	date2[1] = second[1];
	date2[2] = '\0';


	// check year 
	if (ConvertInt(year1) < ConvertInt(year2)) return 1;
	else return 2;

	//check month
	if (ConvertInt(month1) < ConvertInt(month2)) return 1;
	else return 2;


	//check date
	if (ConvertInt(date1) < ConvertInt(date2)) return 1;
	else return 2;


	return 0;
}
