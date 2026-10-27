#include "book.h"
#include <stdlib.h>
#include <string.h>
#include "isbn.h"

Book *book_create(const char *title, const char *author, int32_t total_pages, const char *isbn)
{

    if (title == NULL || title[0] == '\0')
        return NULL;

    if (total_pages <= 0)
        return NULL;

    char normalized_isbn[14] = {0};

    if (isbn != NULL && isbn[0] != '\0')
    {
        if (!isbn_normalize(isbn, normalized_isbn))
            return NULL;
    }

    Book *b1 = malloc(sizeof(Book));

    if (b1 == NULL)
        return NULL;

    b1->title = NULL;
    b1->author = NULL;

    b1->title = malloc(strlen(title) + 1);

    if (b1->title == NULL)
    {

        free(b1);
        return NULL;
    }

    strcpy(b1->title, title);

    b1->book_id = 0;
    b1->isbn[0] = '\0';
    b1->total_pages = total_pages;
    b1->quantity = 1;
    b1->status = UNREAD;

    if (author != NULL && author[0] != '\0')
    {

        b1->author = malloc(strlen(author) + 1);

        if (b1->author == NULL)
        {
            book_destroy(b1);
            return NULL;
        }

        strcpy(b1->author, author);
    }

    strcpy(b1->isbn,normalized_isbn);

    return b1;
}

void book_destroy(Book *book)
{

    if (book == NULL)
        return;

    free(book->title);
    free(book->author);
    free(book);
}