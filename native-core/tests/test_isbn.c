#include <assert.h>
#include <stddef.h>
#include <string.h>
#include "isbn.h"

int main(void)
{

    // ISBN13 tests

    assert(isbn13_is_valid("9780110002224") == true);

    assert(isbn13_is_valid("9791032900017") == true);

    assert(isbn13_is_valid("9780110002225") == false);

    assert(isbn13_is_valid("1234567890128") == false);

    assert(isbn13_is_valid("97801100022") == false);

    assert(isbn13_is_valid("978011000222A") == false);

    assert(isbn13_is_valid(NULL) == false);

    assert(isbn13_is_valid("97801100022240") == false);

    assert(isbn13_is_valid("") == false);

    // ISBN10 tests

    assert(isbn10_is_valid("0306406152") == true);

    assert(isbn10_is_valid("080442957X") == true);

    assert(isbn10_is_valid("0306406153") == false);

    assert(isbn10_is_valid("0306406") == false);

    assert(isbn10_is_valid("080442957A") == false);

    assert(isbn10_is_valid("030A406152") == false);

    assert(isbn10_is_valid(NULL) == false);

    assert(isbn10_is_valid("") == false);

    // ISBN10 to ISBN13 tests

    char result[14];

    assert(isbn10_to_isbn13("0306406152", result) == true);

    assert(strcmp(result, "9780306406157") == 0);

    assert(isbn13_is_valid(result) == true);

    assert(isbn10_to_isbn13("080442957X", result) == true);

    assert(strcmp(result, "9780804429573") == 0);

    assert(isbn13_is_valid(result) == true);

    assert(isbn10_to_isbn13("0306406153", result) == false);

    assert(isbn10_to_isbn13("030640615", result) == false);

    assert(isbn10_to_isbn13(NULL, result) == false);

    assert(isbn10_to_isbn13("0306406152", NULL) == false);

    assert(isbn10_to_isbn13("08044X957X", result) == false);

    assert(isbn10_to_isbn13("080442957x", result) == false);

    char normalized[14];

    assert(isbn_normalize("0-306-40615-2", normalized) == true);

    assert(strcmp(normalized, "9780306406157") == 0);

    assert(isbn_normalize("0306406152", normalized) == true);

    assert(strcmp(normalized, "9780306406157") == 0);

    assert(isbn_normalize("9780306406157", normalized) == true);

    assert(strcmp(normalized, "9780306406157") == 0);

    assert(isbn_normalize("978-0-306-40615-7", normalized) == true);

    assert(strcmp(normalized, "9780306406157") == 0);

    assert(isbn_normalize("0 306 40615 2", normalized) == true);

    assert(strcmp(normalized, "9780306406157") == 0);

    assert(isbn_normalize("9780306406159", normalized) == false);

    assert(isbn_normalize("12345678901234", normalized) == false);

    assert(isbn_normalize(NULL, normalized) == false);

    assert(isbn_normalize("", normalized) == false);

    assert(isbn_normalize("0306406152", NULL) == false);

    return 0;
}