#include "book.h"
#include <stdlib.h>
#include <string.h>

Book *book_create(const char *title, int32_t total_pages){

    if(title == NULL || title[0] == '\0')
        return NULL;

    if(total_pages<=0)
        return NULL;

    Book *b1 = malloc(sizeof(Book));

    if(b1 == NULL)
        return NULL;

    b1->title = NULL;
    b1->author = NULL;

    b1->title = malloc(strlen(title)+1);

    if(b1->title == NULL){

        free(b1);
        return NULL;

    }
      
    strcpy(b1->title,title);
    

    b1->book_id=0;
    b1->isbn[0]='\0';
    b1->total_pages=total_pages;
    b1->quantity=1;
    b1->status=UNREAD;



    return b1;

}

void book_destroy(Book *book){

    if(book == NULL)
        return;

    free(book->title);
    free(book->author);
    free(book);

}