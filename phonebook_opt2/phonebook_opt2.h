#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <strings.h>

#define MAX_PHONE_BOOK_CNT 20000000//200000000
#define MAX_LAST_NAME_SIZE 16

typedef struct __PHONE_BOOK_MISC {
    char FirstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
//    struct __PHONE_BOOK_ENTRY *pNext;
} PB_Misc;

typedef struct __PHONE_BOOK_ENTRY {
    char LastName[MAX_LAST_NAME_SIZE];
    PB_Misc *pMisc;
} PhoneBook;

PhoneBook *FindName(char Last[], PhoneBook *pHead) {
    int i;
    for (i=0 ; i<MAX_PHONE_BOOK_CNT; i++) {
        if (strcasecmp(Last, pHead[i].LastName) == 0)
            return &pHead[i];
    }
    return NULL;
}

#endif //PHONEBOOK_H
