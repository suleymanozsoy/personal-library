#include <assert.h>
#include <stddef.h>
#include "isbn.h"

int main(void){

        assert(isbn13_is_valid("9780110002224") == true);

        assert(isbn13_is_valid("9791032900017")==true);

        assert(isbn13_is_valid("9780110002225") == false);

        assert(isbn13_is_valid("1234567890128")==false);

        assert(isbn13_is_valid("97801100022")==false);

        assert(isbn13_is_valid("978011000222A")==false);

        assert(isbn13_is_valid(NULL)==false);

        assert(isbn13_is_valid("97801100022240") == false);

        assert(isbn13_is_valid("")==false);


    return 0;
}