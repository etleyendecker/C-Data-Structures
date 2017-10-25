// Author: Emily Leyendecker
// Date: 01-30-17
//
/* <The purpose of the program is to take the user's number input and displays
    1. amount in coinage(quarters, dimes, nickels, pennies)
    2. amount in time (months, days, hours, minutes, seconds)
    3. separates digits and displays english words
    4. result of armstrong number test
    5. factorial of given number
    6. all prime numbers leading up to given number
    7. hailstone sequence > */

#include <iostream>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

void money_calc(int);
void age_calc(int);
void digit_separator(int);
void digit_to_word(int);
void armstrong_display(int);
void factorial_calc(int);
bool prime_calc(int);
void prime_list(int);
void hailstone_sequence(int);

/********************************************************
 money_calc() funtion takes in user input int and uses it
 calculates coin amount in quarters, dimes, nickels, and
 pennies. Does not return anything but outputs results.
********************************************************/
void money_calc(int num)
{
    const int QUARTER = 4, // quarters per dollar
              DIME = 10, // dimes per dollar
              NICKEL = 20, // nickels per dollar
              PENNY = 100; // pennies per dollar

    cout << "\nCurrency Calculation" << endl << endl;
    cout << "$" << num << "	is equivalent to:" << endl << endl;

    cout << left
         << setw(6) << (num * QUARTER) << "quarter/s" << endl
         << setw(6) << (num * DIME) << "dime/s" << endl
    	 << setw(6) << (num * NICKEL) << "nickel/s" << endl
         << setw(6) << (num * PENNY) << "cent/s" << endl << endl;
}

/*******************************************************
 age_calc() takes in user input num and calculates total
 months, days, hours, minutes, and seconds as if num were
 in years
*******************************************************/
void age_calc(int num)
{
    const int MONTHS = 12, // months per year
              DAYS = 365, // days per year
              HOURS = 8760, // hours per year
              MINUTES = 525600; // minutes per year
    const long long int SECONDS = 31536000; // seconds per year

    cout << "\nAge Calculation" << endl << endl;

    cout << "Assuming that you are " << num << " years old, then"
         << endl << endl;

    cout << left
         << "You are " <<  (num * MONTHS) << " months old" << endl
         << "You are " << (num * DAYS) << " days old" << endl
   	     << "You are approximately " << (num * HOURS) << " hours old"
   	     << endl
	     << "You are approximately " << (num * MINUTES) << " minutes old"
	     << endl
	     << "You are approximately " << (num * SECONDS) << " seconds old"
	     << endl << endl;
}

/**********************************************************************
 digit_separator() takes in user input int and separates the num into
 individual digits. Also uses digit_to_word() function to display digit
 translated to english
***********************************************************************/
void digit_separator(int num)
{
    int first, second, third; /* first = 1st digit, second = 2nd digit
                                 third = 3rd digit */
    first = num/100 % 10;
    second = num/10 % 10;
    third = num % 10;

    cout << "\nSeparating digits for the integer " << num << endl;
    if(first == 0)
    {
        if(second == 0)
        {
            cout << third << endl;
            digit_to_word(third);
            cout << endl << endl;
        }
        else
        {
            cout << second << "  " << third << endl;
            digit_to_word(second);
            digit_to_word(third);
            cout << endl << endl;
        }
    }
    else
    {
        cout << first << "  " << second << "  " << third << endl;
        digit_to_word(first);
        digit_to_word(second);
        digit_to_word(third);
        cout << endl << endl;
    }
}

/*************************************************************
 digit_to_word() takes integer i and displays the english word
**************************************************************/
void digit_to_word(int i)
{
    switch(i)
    {
        case 0: cout << "Zero  ";
            break;
        case 1: cout << "One  ";
            break;
        case 2: cout << "Two  ";
            break;
        case 3: cout << "Three  ";
            break;
        case 4: cout << "Four  ";
            break;
        case 5: cout << "Five  ";
            break;
        case 6: cout << "Six  ";
            break;
        case 7: cout << "Seven  ";
            break;
        case 8: cout << "Eight  ";
            break;
        case 9: cout << "Nine  ";
            break;
    }
}

/**************************************************************************
 armstrong_calc() takes in user input num and determines if the sum of the
 cubes of the individual digits is equal to num
***************************************************************************/
void armstrong_calc(int num)
{
    int y, z; // divides num into digits
    int armstrong; // total of digit cubes

    if (num >= 10)
    {
        z = num % 10;
        y = num / 10;

        if (num > 100)
        {
            y = y % 10;
            int x = 1;
        }
    }

    armstrong = (y * y * y) + (z * z * z);

    if (num >= 100)
    {
        armstrong = armstrong + 1;
    }

    if (num == armstrong)
    {
        cout << "\n" << num << " is an Armstrong number." << endl << endl;
    }
    else
    {
        cout << "\n" << num << " is not an Armstrong number." << endl << endl;
    }
}

/*********************************************************************
 factorial_calc() takes in user input num and calculates the factorial
**********************************************************************/
void factorial_calc(int num)
{
    unsigned long long int factNum = 1; /* running factorial total of numbers
                                           less than 66 (int cant hold data */
    long double bigFact = 1; /* running factorial total of numbers greater
                                than 65 */

    for (int i = 1; i <= num; i++)
    {
        factNum *= i;
        bigFact *= i;
    }
    cout << "\nFactorial of " <<  num << " = ";
    if(num < 66)
        cout << factNum << endl << endl;
    else
        cout << bigFact << endl << endl;
}

/****************************************************************
 bool prime_calc() takes an int x and returns true if x is prime,
 false otherwise.
*****************************************************************/
bool prime_calc(int x)
{
    for(int i = 2; i < x; i++)
    {
        if(x % i == 0)
            return false;
    }
    return true;
}

/************************************************************************
 prime_list() takes user input num and displays if num is a prime number,
 then displays all prime numbers before num
*************************************************************************/
void prime_list(int num)
{
    cout << "\n" << num << " number is ";

    if(!prime_calc(num))
        cout << "not prime." << endl;
    else
        cout << "prime." << endl;

    cout << "\nAll prime numbers between 1 and " << num << " are" << endl;

    for(int i = 1; i < num; i++)
    {
        if(prime_calc(i)==true)
            cout << i << " number is prime" << endl;
    }

    cout << endl;
}

/******************************************************************
 hailstone_sequence() takes in user input num and
 displays sequence until final number is 1, with the following rule
 for the next number: even = num/2, odd = (3num)+1
*******************************************************************/
void hailstone_sequence(int num)
{
    cout << "\nThe sequence of hailstone starting at " << num << " is" << endl;
    cout << num << " ";

    while (num != 1)
    {
        if (num % 2 == 0)
        {
            num = num/2;
            cout << "  " << num;
        }
        else if (num % 2 != 0)
        {
            num = 3 * num + 1;
            cout << "  " << num;
        }
    }
    cout << endl << endl;
}

int main ()
{
    int num; // number between 0 and 200 input by the user
    char ans; // y or n response to continuing the program

    cout << "Welcome to My APP." << endl;
    cout << "This APP  accepts an integer from the keyboard." << endl;
    cout << "The  APP  Calculates and Displays the Following   :"
         << endl << endl;

    cout << "1. Assuming that The integer represents a $$ amount , then"
         << endl
         << "   the number of quarters, dimes, nickels, and pennies" << endl
         << "   will be calculated and displayed" << endl << endl;

    cout << "2. Assuming that The integer represents person's Age"
         << " in years then ," << endl
         << "   Number of months, days, hours, minutes,"
         << " and seconds for the person" << endl
         << "   will be calculated and displayed" << endl << endl;

    cout << "3. The numbers will be separated into its individual digits."
         << endl
         << "   Then each digit of the integer will be displayed  in English."
         << endl << endl;

    cout << "4. Indicate whether or not the integer is an arm strong number."
         << endl << endl;

    cout << "5. The factorial of the integer will be calculated and displayed"
         << endl << endl;

    cout << "6. Indicate whether or not the integer is prime. Then," << endl
         << "   All the prime numbers between 1 and that number will also be"
         << endl << "   displayed." << endl << endl;

    cout << "7. The hailstone sequence starting at n will be calculated and"
         << endl << "   displayed" << endl << endl;

    do
    {
        do
        {
            cout << "\nEnter a Positive integer Number > 0 and < 200 --->     ";
            cin >> num;

            if(num < 1 || num > 200)
                cout << "\nError *** Number must be > 0 and < 200" << endl;
        } while (num < 1 || num > 200);

        money_calc(num);

        age_calc(num);

        digit_separator(num);

        armstrong_calc(num);

        factorial_calc(num);

        prime_list(num);

        hailstone_sequence(num);

        do
        {
            cout << "\nWould you like to try for another number?" << endl;
            cout << "Enter y || Y for yes or n || N for no  ---> ";
            cin >> ans;
            ans = toupper(ans);

            if(ans != 'Y' &&  ans != 'N')
                cout << "\nError *** Invalid choice - Must be Y || y || N || n"
                     << endl;

        } while(ans != 'Y' && ans != 'N');

    } while (ans != 'N');
        cout << "\nThis APP is originally developed by Emily Leyendecker"
             << endl << endl;

    return 0;

}

