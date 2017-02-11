## Book
__Model for book structure__

Defined constants:
    * MAX\_AUTHOR\_LEN - used to check that author's name is not too long.
    * MAX\_TITLE\_LEN - used to check that the title name is not too long.
    * NUM\_BOOK\_PARAMS - defines number of elements contained by structure.
    * RENEW\_TIME - defines the renewal time of the book in months; at the University of Georgia Libraries, that time is 1 month.

Routines:
    * `Book* initBook(char *title, char *isbn, char *author, Date *checkin)` 
        * Returns a Book pointer to the created structure.
    * `int compare(Book *book, Book *book2)` 
        * Returns a integer indicating whether the book lexographically greater than the other book.
    * `bool valid_title(char *title)`
        * Returns a boolean value indicating whether the book's title is valid (e.g within a size limit).
    * `bool valid_isbn(char *isbn)` 
        * Returns a boolean value indicating whether the isbn is legitimate, according to mathematical rules.
    * `bool valid_author(char *author)`
        * Returns a boolean value indicating whether the book's author is valid (e.g within a size limit).
