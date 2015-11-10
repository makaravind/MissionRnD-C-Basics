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
	int dec = 0;
	for (int i = 0; cp[i] != '\0'; i++){
		dec = dec * 10 + (cp[i] - '0');
	}
	return dec;
}
int CheckLeapYear(int year){
	if (year % 400 == 0)
		return 1;
	else if (year % 100 == 0)
		return -1;
	else if (year % 4 == 0)
		return 1;
	else
		return -1;

}
int Invalid(char *x, char *y,int year,int mon,int day,int year2,int mon2,int day2){
	// cheacking day
	if (day > 31 || day2 > 31 || day <= 0 || day2 <= 0) return 0;
	//month
	else if (mon > 12 || mon2 > 12 || mon == 0 || mon2 == 0) return 0;
	
	if (mon == 2 && day == 29){
		if (CheckLeapYear(year) == -1) 
		return 0;
	}
	else if (mon2 == 2 && day2 > 29) {
		if (CheckLeapYear(year2) == -1)
			return 0;
	}

	// checking year
	if ( year <= 0 || year2 <= 0) return 0;
	
	// check string 
	if (x == "" || y == "") return 0;

	return 1;
}
int isOlder(char *first, char *second) {
	char year1[10], year2[10];
	char month1[10], month2[10];
	char date1[10], date2[10];

	year1[0] = first[6];
	year1[1] = first[7];
	year1[2] = first[8];
	year1[3] = first[9];
	year1[4] = '\0';

	year2[0] = second[6];
	year2[1] = second[7];
	year2[2] = second[8];
	year2[3] = second[9];
	year2[4] = '\0';

	month1[0] = first[3];
	month1[1] = first[4];
	month1[2] = '\0';

	month2[0] = second[3];
	month2[1] = second[4];
	month2[2] = '\0';

	date1[0] = first[0];
	date1[1] = first[1];
	date1[2] = '\0';

	date2[0] = second[0];
	date2[1] = second[1];
	date2[2] = '\0';

	int decyear1 = ConvertInt(year1);
	int decyear2 = ConvertInt(year2);
	int decmon1 = ConvertInt(month1);
	int decmon2 = ConvertInt(month2);
	int decdate1 = ConvertInt(date1);
	int decdate2 = ConvertInt(date2);

	if (Invalid(year1, year2, decyear1, decmon1, decdate1, decyear2, decmon2, decdate2) != 0)
	{
		// check year 
		if (decyear1 < decyear2) return 1;
		else if (decyear1 > decyear2) return 2;

		//check month
		if (decmon1 < decmon2) return 1;
		else if (decmon1 > decmon2)  return 2;


		//check date
		if (decdate1 < decdate2) return 1;
		else if (decdate1 > decdate2) return 2;


		return 0;
	}
	else
		return -1;

}