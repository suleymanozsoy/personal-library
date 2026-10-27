#include <assert.h>
#include <string.h>
#include "book.h"

int main(void)
{

    Book *b1 = book_create("The Prince", NULL, 150,NULL);

    assert(b1 != NULL);

    assert(b1->author == NULL);

    assert(b1->total_pages == 150);

    assert(b1->quantity == 1);

    assert(b1->status == UNREAD);

    assert(strcmp(b1->title, "The Prince") == 0);

    book_destroy(b1);

    Book *emptyAuthor = book_create("The Prince", "", 150,NULL);

    assert(emptyAuthor != NULL);

    assert(emptyAuthor->author == NULL);

    book_destroy(emptyAuthor);

    assert(book_create(NULL, NULL, 150, NULL) == NULL);

    assert(book_create("", NULL, 150, NULL) == NULL);

    assert(book_create("The Prince", NULL, 0, NULL) == NULL);

    assert(book_create("The Prince", NULL, -25, NULL) == NULL);

    book_destroy(NULL);

    char original[] = "Ruh Adam";

    Book *copy = book_create(original, NULL, 248,NULL);

    assert(copy != NULL);

    assert(strcmp(copy->title, "Ruh Adam") == 0);

    assert(copy->title != original);

    original[0] = 'Z';

    assert(strcmp(copy->title, "Ruh Adam") == 0);

    book_destroy(copy);

    char orgnl[] = "Hüseyin Nihal Atsız";

    Book *copy2 = book_create("Ruh Adam", orgnl, 248,NULL);

    assert(copy2 != NULL);

    assert(strcmp(copy2->author, "Hüseyin Nihal Atsız") == 0);

    assert(copy2->author != orgnl);

    orgnl[0] = 'M';

    assert(strcmp(copy2->author, "Hüseyin Nihal Atsız") == 0);

    book_destroy(copy2);

    Book *isbnBook = book_create("Deli Kurt", "Nihal Atsız", 384, "0-306-40615-2");

    assert(isbnBook != NULL);

    assert(strcmp(isbnBook->isbn, "9780306406157") == 0);

    // ISBN10 to ISBN-13

    Book *book10 = book_create(
        "The Prince", NULL, 150, "0306406152");

    assert(book10 != NULL);
    assert(strcmp(book10->isbn, "9780306406157") == 0);

    book_destroy(book10);

    // Already ISBN-13 has entered

    Book *book13 = book_create(
        "The Prince", NULL, 150, "9780306406157");

    assert(book13 != NULL);
    assert(strcmp(book13->isbn, "9780306406157") == 0);

    book_destroy(book13);

    // ISBN is NULL

    Book *noIsbn = book_create(
        "The Prince", NULL, 150, NULL);

    assert(noIsbn != NULL);
    assert(noIsbn->isbn[0] == '\0');

    book_destroy(noIsbn);

    // ISBN is an empty string

    Book *emptyIsbn = book_create(
        "The Prince", NULL, 150, "");

    assert(emptyIsbn != NULL);
    assert(emptyIsbn->isbn[0] == '\0');

    book_destroy(emptyIsbn);

    // Unvalid ISBN

    Book *invalidIsbn = book_create(
        "The Prince", NULL, 150, "12345");

    assert(invalidIsbn == NULL);

    book_destroy(isbnBook);

    return 0;
}