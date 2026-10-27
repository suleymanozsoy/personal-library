#ifndef BOOK_H
#define BOOK_H
#include <stdint.h>

typedef enum
{

    UNREAD,
    READİNG,
    FINISHED

} reading_status;

typedef struct
{

    int64_t book_id;

    char isbn[14];

    char *title;

    char *author;

    int32_t total_pages;

    int32_t quantity;

    reading_status status;

} Book;

Book *book_create(const char *title, const char *author, int32_t total_pages, const char *isbn);

void book_destroy(Book *book);

#endif