#include <assert.h>
#include <string.h>
#include "book.h"

int main(void)
{

    Book *b1 = book_create("The Prince", 150);

    assert(b1 != NULL);

    assert(b1->total_pages == 150);

    assert(b1->quantity == 1);

    assert(b1->status == UNREAD);

    assert(strcmp(b1->title, "The Prince") == 0);

    book_destroy(b1);

    assert(book_create(NULL, 150) == NULL);

    assert(book_create("", 150) == NULL);

    assert(book_create("The Prince", 0) == NULL);

    assert(book_create("The Prince", -25) == NULL);

    book_destroy(NULL);

    char original[] = "Ruh Adam";
    
    Book *copy = book_create(original,248);

    assert(copy != NULL);

    assert(strcmp(copy->title,"Ruh Adam")==0);

    assert(copy->title != original);
   
    original[0]='Z';

    assert(strcmp(copy->title,"Ruh Adam")==0);

    book_destroy(copy);

    return 0;

}