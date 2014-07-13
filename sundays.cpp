/* Written by Maajid Nazrulla.
Last updated 12/7/2014. Project Euler Problem 19.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage() {
	printf("Please rerun the program with a number as an input.\n");
	printf("The program computes the sum of all multiples of 3 or 5 below the supplied number.");
}

class Date {
  int day, month, year, since_1_1_1900;
  
public:

  Date (int d, int m, int y) {
    day = d;
    month = m;
    year = y;
  }
  int convert_month(char* month_str) {
    if (!month_str) {
      return 0;
    }
    if (!strcmp(month_str, "January") || !strcmp(month_str, "Jan") || !strcmp(month_str, "jan")){
      return 1;
    }
    if (!strcmp(month_str, "February") || !strcmp(month_str, "Feb")  || !strcmp(month_str, "feb")) {
      return 2;
    }
    if (!strcmp(month_str, "March") || !strcmp(month_str, "Mar") || !strcmp(month_str, "mar")) {
      return 3;
    }
    if (!strcmp(month_str, "April") || !strcmp(month_str, "Apr") || !strcmp(month_str, "apr")) {
      return 4;
    }
    if (!strcmp(month_str, "May") || !strcmp(month_str, "may")) {
      return 5;
    }
    if (!strcmp(month_str, "June") || !strcmp(month_str, "Jun") || !strcmp(month_str, "jun")) {
      return 6;
    }
    if (!strcmp(month_str, "July") || !strcmp(month_str, "Jul") || !strcmp(month_str, "jul")){
      return 7;
    }
    if (!strcmp(month_str, "August") || !strcmp(month_str, "Aug")  || !strcmp(month_str, "aug")) {
      return 8;
    }
    if (!strcmp(month_str, "September") || !strcmp(month_str, "Sep") || !strcmp(month_str, "sep")) {
      return 9;
    }
    if (!strcmp(month_str, "October") || !strcmp(month_str, "Oct") || !strcmp(month_str, "oct")) {
      return 10;
    }
    if (!strcmp(month_str, "November") || !strcmp(month_str, "Nov") || !strcmp(month_str, "nov")) {
      return 11;
    }
    if (!strcmp(month_str, "December") || !strcmp(month_str, "Dec") || !strcmp(month_str, "dec")) {
      return 12;
    }
  }

  int days_in_month(char* month_str, int year) {
    if (convert_month(month_str) == 9 || convert_month(month_str) == 4 || convert_month(month_str) == 6 || convert_month(month_str) == 11) {
      return 30;
    }
    if ((convert_month(month_str) == 2) && is_leap(year)) {
      return 29;
    }
    if (convert_month(month_str) == 2) {
      return 28;
    }
    else {
      return 31
    }
  }

  bool is_leap(int year) {
    if ( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
      return true;
    }
    return false;
  }

  int days_since_1900(Date date) {
    int year = date.year;
    int month = date.month;
    int days = date.day;
    if (month == 1 && year == 1900) {
      return days - 1;
    }
    if (month == 1) {
      date.year -= 1;
      date.month = 12;
      date.day = 31;
      return days + days_since_1900(date);
    }
    else {
      date.month -= 1;
      date.day = (days_in_month(date.month, year));
      return days + days_since_1900(date);
    }
  }
}

  void convert_days_to_date(int days) {
    date = Date(1, 1, 1900)
    if (days == 0) {
      return date;
    }
    if (days < 31) {
      date.day = days;
      return date;
    }
    

  }


  char* date_to_day(Date date) {
    day_ptr = calloc(8, 1);
    if (!day_ptr) {
      exit(1);
    }
    if (days_since_1900(date) % 7 == 6) {
      strcpy(day_ptr, "Monday");
      return day_ptr;
    }
  }

}  dmy;

int main(int argc, char* argv[]) {
	
}
