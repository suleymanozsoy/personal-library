#include "isbn.h"
#include <string.h>

bool isbn13_is_valid(const char *isbn)
{

    if (isbn == NULL || strlen(isbn) != 13)
        return false;

    for (int i = 0; i < 13; i++)
    {

        if (isbn[i] < '0' || isbn[i] > '9')
            return false;
    }

    if (isbn[0] != '9' || isbn[1] != '7')
        return false;

    if (isbn[2] != '8' && isbn[2] != '9')
        return false;

    int sum = 0;

    for (int i = 0; i < 12; i++)
    {

        int digit = isbn[i] - '0';

        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            sum += digit * 3;
        }
    }

    int checkDigit = (10 - (sum % 10)) % 10;

    int checkDigitISBN = isbn[12] - '0';

    return checkDigit == checkDigitISBN;
}