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

bool isbn10_is_valid(const char *isbn)
{

    if (isbn == NULL || strlen(isbn) != 10)
        return false;

    for (int i = 0; i < 9; i++)
    {

        if (isbn[i] > '9' || isbn[i] < '0')
            return false;
    }

    if ((isbn[9] > '9' || isbn[9] < '0') && isbn[9] != 'X')
        return false;

    int total = 0;

    int sum = 0;

    for (int i = 0; i < 9; i++)
    {

        int digit = isbn[i] - '0';

        sum += digit * (10 - i);
    }

    int checkDigit = 0;

    if (isbn[9] == 'X')
    {
        checkDigit = 10 * 1;
    }
    else
    {
        checkDigit = isbn[9] - '0';
    }

    total = sum + checkDigit;

    if (total % 11 == 0)
        return true;

    return false;
}

bool isbn10_to_isbn13(const char *isbn10, char isbn13[14])
{

    if (isbn10 == NULL || isbn13 == NULL)
        return false;

    if (isbn10_is_valid(isbn10) == false)
        return false;

    isbn13[0] = '9';
    isbn13[1] = '7';
    isbn13[2] = '8';

    for (int i = 0; i < 9; i++)
    {

        isbn13[i + 3] = isbn10[i];
    }

    int sum = 0;

    for (int i = 0; i < 12; i++)
    {

        int digit = isbn13[i] - '0';

        if (i % 2 == 0)
        {
            sum += digit;
        }
        else
        {
            sum += 3 * digit;
        }
    }

    int checkDigit = (10 - (sum % 10)) % 10;

    char digitChar = '0' + checkDigit;

    isbn13[12] = digitChar;

    isbn13[13] = '\0';

    return true;
}

bool isbn_normalize(const char *input, char normalized[14])
{

    if (input == NULL || normalized == NULL)
        return false;

    char compact[14];

    int j = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {

        if (input[i] == ' ' || input[i] == '-')
            continue;

        if (j >= 13)
            return false;

        compact[j] = input[i];
        j++;
    }

    compact[j]='\0';

    if (j == 10)
{
   
    return isbn10_to_isbn13(compact,normalized);
    
}

    if(j==13){

        if(isbn13_is_valid(compact)){
            strcpy(normalized,compact);
            return true;
        }
            return false;

    }

    return false;

}