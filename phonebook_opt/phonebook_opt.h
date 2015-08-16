#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <strings.h>

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
} PB_Misc;

typedef struct __PHONE_BOOK_ENTRY {
    char LastName[MAX_LAST_NAME_SIZE];
    struct __PHONE_BOOK_ENTRY *pNext;
    PB_Misc *pMisc;
} PhoneBook;

PhoneBook *FindName(char Last[], PhoneBook *pHead) {
    while (pHead != NULL) {
        if (strcasecmp(Last, pHead->LastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

#endif //PHONEBOOK_H
