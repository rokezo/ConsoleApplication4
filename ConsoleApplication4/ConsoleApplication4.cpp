#include <iostream>
#include <cmath>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    else {
        return 31;
    }
}

int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;
    if (year1 == year2 && month1 == month2) {
        return std::abs(day2 - day1);
    }
    if (year1 == year2) {
        for (int i = month1 + 1; i < month2; ++i) {
            days += daysInMonth(i, year1);
        }
        days += daysInMonth(month1, year1) - day1 + day2;
    }
    else {
        for (int i = month1 + 1; i <= 12; ++i) {
            days += daysInMonth(i, year1);
        }
        days += daysInMonth(month1, year1) - day1;
        for (int i = year1 + 1; i < year2; ++i) {
            days += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 1; i < month2; ++i) {
            days += daysInMonth(i, year2);
        }
        days += day2;
    }
    return days;
}

template<typename T>
double average(const T arr[], int size) {
    if (size == 0)
        return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum / size;
}

template<typename T>
void countElements(const T arr[], int size, int& positive, int& negative, int& zero) {
    positive = 0;
    negative = 0;
    zero = 0;

    for (int i = 0; i < size; ++i) {
        if (arr[i] > 0)
            positive++;
        else if (arr[i] < 0)
            negative++;
        else
            zero++;
    }
}

int main() {

    std::cout << "Days between dates: " << daysBetweenDates(1, 1, 2023, 1, 1, 2024) << std::endl;

    int intArr[] = { 1, -2, 3, 0, -4, 5 };
    double doubleArr[] = { -1.1, 2.2, 0, 3.3, -4.4, 0 };
    int intPositive, intNegative, intZero;
    int doublePositive, doubleNegative, doubleZero;
    int intSize = sizeof(intArr) / sizeof(int);
    int doubleSize = sizeof(doubleArr) / sizeof(double);
    std::cout << "Average of intArr: " << average(intArr, intSize) << std::endl;
    std::cout << "Average of doubleArr: " << average(doubleArr, doubleSize) << std::endl;

    countElements(intArr, intSize, intPositive, intNegative, intZero);
    countElements(doubleArr, doubleSize, doublePositive, doubleNegative, doubleZero);
    std::cout << "For intArr:" << std::endl;
    std::cout << "Positive elements: " << intPositive << std::endl;
    std::cout << "Negative elements: " << intNegative << std::endl;
    std::cout << "Zero elements: " << intZero << std::endl;
    std::cout << "For doubleArr:" << std::endl;
    std::cout << "Positive elements: " << doublePositive << std::endl;
    std::cout << "Negative elements: " << doubleNegative << std::endl;
    std::cout << "Zero elements: " << doubleZero << std::endl;

    return 0;
}
