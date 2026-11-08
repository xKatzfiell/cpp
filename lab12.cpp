/*
 * This program asks the user to enter a date in MM/DD/YYYY format.
 * It checks whether the entered date is valid.
 * If the date is valid, it calculates and displays its day of the year.
 * Otherwise, it displays an error message.
 */

#include <iostream>
#include <string>
#include <iomanip>

// Declare the functions defined after main.
int calculateDay(int month, int day, int year);
bool isValidDate(int month, int day, int year, int daysInMonth);
void printErrorMessage(int month, int day, int year);

/*
 * Checks whether the given year is a leap year.
 * Parameter: year (int) is the year to check.
 * Returns: true (bool) if the year is a leap year; otherwise, false.
 */

bool isLeapYear(int year)
{
    bool leapYear{0}; // Stores whether the year is a leap year.

    // Years divisible by 400 are leap years.
    if (year % 400 == 0)
    {
        leapYear = true;
    }
    // Other leap years are divisible by 4 but not by 100.
    else if (year % 4 == 0 && year % 100 != 0)
    {
        leapYear = true;
    }

    return leapYear;
}

/*
 * Reads a date from the user and checks whether it is valid.
 * Parameters: month, day, and year (int references) store the input.
 * Input: a date in MM/DD/YYYY format.
 * Output: an input prompt and an error message if the date is invalid.
 * Returns: true (bool) if the date is valid; otherwise, false.
 */
bool getValidDate(int& month, int& day, int& year)
{
    int daysInMonth{};  // Stores the number of days in the month.

    // Read the month, day, and year, skipping the separators.
    std::cout << "Enter a date [MM/DD/YYYY]: ";
    std::cin >> month;
    std::cin.ignore();
    std::cin >> day;
    std::cin.ignore();
    std::cin >> year;
    std::cout << "\n";

    // Set the number of days for months with 31 days.
    if (month == 1 || month == 3 || month == 5 ||
        month == 7 || month == 8 || month == 10 || month == 12)
    {
        daysInMonth = 31;
    }

    // Set the number of days for months with 30 days.
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        daysInMonth = 30;
    }

    // February has 29 days in a leap year.
    else if (month == 2 && isLeapYear(year))
    {
        daysInMonth = 29;
    }

    // Use 28 days otherwise; invalid months are rejected below.
    else
    {
        daysInMonth = 28;
    }

    // Check the date using the calculated number of days.
    return isValidDate(month, day, year, daysInMonth);
}

/*
 * Finds the name of the given month.
 * Parameter: month (int) is the month number.
 * Returns: the month name (std::string), or an empty string
 * if the month number is invalid.
 */
std::string getMonthName(int month)
{
    std::string monthName;  // Stores the name of the month.

    // Match the month number with its name.
    switch (month)  
    {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "";
            break;
    }

    return monthName;
}

int main()
{
    
    // Define the variables used to store the entered date.
    int month{};    // Stores the month number.
    int day{};      // Stores the day of the month.
    int year{};     // Stores the year.

    // Calculate and display the result if the entered date is valid.
    if (getValidDate(month, day, year))
    {
        // Calculate the date's position within the year.
        int dayOfYear = calculateDay(month, day, year);

        // Print the month name, day, day of the year, and year.
        // Display the year with at least four digits.
        std::cout << getMonthName(month) << " " << day
                  << " is day " << dayOfYear
                  << " of " << std::setfill('0') << std::setw(4)
                  << year << ".\n";
    }

    return 0;
}

/*
 * Calculates the day of the year for a valid date.
 * Parameters: month, day, and year (int) represent the date.
 * Returns: the day of the year (int), starting with 1 on January 1.
 */
int calculateDay(int month, int day, int year)
{
    // Start with the number of days in the current month so far.
    int dayOfYear{day};


    // Add the days in all months before the entered month.
    // The missing break statements intentionally allow execution
    // to continue through the following cases until case 1.
    switch (month)
    {
        case 12:
            dayOfYear += 30;    // Add November's days.
        case 11:
            dayOfYear += 31;    // Add October's days.
        case 10:
            dayOfYear += 30;    // Add September's days.
        case 9:
            dayOfYear += 31;    // Add August's days.
        case 8:
            dayOfYear += 31;    // Add July's days.
        case 7:
            dayOfYear += 30;    // Add June's days.
        case 6:
            dayOfYear += 31;    // Add May's days.
        case 5:
            dayOfYear += 30;    // Add April's days.
        case 4:
            dayOfYear += 31;    // Add March's days.
        case 3:
            dayOfYear += 28;    // Add February's days before adjustment.
        case 2:
            dayOfYear += 31;    // Add January's days.
        case 1:
            break;
    }

    // Include February 29 if the date is after February in a leap year.
    if (month > 2 && isLeapYear(year))
    {
        ++dayOfYear;
    }

    return dayOfYear;
}

/*
 * Displays an error message for an invalid date.
 * Parameters: month, day, and year (int) represent the entered date.
 * Output: an error message showing the date with leading zeros.
 * Return type: void.
 */
void printErrorMessage(int month, int day, int year)
{
    // Display the month and day with at least two digits,
    // and the year with at least four digits.
    std::cout << "Error: " << std::setfill('0')
              << std::setw(2) << month << "/"
              << std::setw(2) << day << "/"
              << std::setw(4) << year
              << " is not a valid date.\n";

    return;
}

/*
 * Checks whether the date values are within the allowed ranges.
 * Parameters: month, day, and year (int) represent the date.
 *             daysInMonth (int) is the maximum day for the month.
 * Output: an error message if the date is invalid.
 * Returns: true (bool) if the date is valid; otherwise, false.
 */
bool isValidDate(int month, int day, int year, int daysInMonth)
{
    bool validDate{1};  // Stores whether the date is valid.

    // Reject invalid months, days, and nonpositive years.
    if (month <= 0 || month > 12 ||
        day <= 0 || day > daysInMonth || year <= 0)
    {
        // Display the invalid date and update its validity.
        printErrorMessage(month, day, year);
        validDate = false;
    }

    return validDate;
}