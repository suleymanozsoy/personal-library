#include <assert.h>
#include <string.h>
#include "book.h"

int main(void)
{

    Book *b1 = book_create("The Prince", NULL, 150);

    assert(b1 != NULL);

    assert(b1->author == NULL);

    assert(b1->total_pages == 150);

    assert(b1->quantity == 1);

    assert(b1->status == UNREAD);

    assert(strcmp(b1->title, "The Prince") == 0);

    book_destroy(b1);

    Book *emptyAuthor = book_create("The Prince", "", 150);

    assert(emptyAuthor != NULL);

    assert(emptyAuthor->author == NULL);

    book_destroy(emptyAuthor);

    assert(book_create(NULL, NULL, 150) == NULL);

    assert(book_create("", NULL, 150) == NULL);

    assert(book_create("The Prince", NULL, 0) == NULL);

    assert(book_create("The Prince", NULL, -25) == NULL);

    book_destroy(NULL);

    char original[] = "Ruh Adam";

    Book *copy = book_create(original, NULL, 248);

    assert(copy != NULL);

    assert(strcmp(copy->title, "Ruh Adam") == 0);

    assert(copy->title != original);

    original[0] = 'Z';

    assert(strcmp(copy->title, "Ruh Adam") == 0);

    book_destroy(copy);

    char orgnl[] = "Hüseyin Nihal Atsız";

    Book *copy2 = book_create("Ruh Adam", orgnl, 248);

    assert(copy2 != NULL);

    assert(strcmp(copy2->author, "Hüseyin Nihal Atsız") == 0);

    assert(copy2->author != orgnl);

    orgnl[0] = 'M';

    assert(strcmp(copy2->author, "Hüseyin Nihal Atsız") == 0);

    book_destroy(copy2);

    return 0;
}