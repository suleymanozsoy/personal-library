#ifndef ISBN_H
#define ISBN_H
#include <stdbool.h>

bool isbn13_is_valid(const char *isbn);

bool isbn10_is_valid(const char *isbn);

bool isbn10_to_isbn13(const char *isbn10, char isbn13[14]);

bool isbn_normalize(const char *input, char normalized[14]);


#endif