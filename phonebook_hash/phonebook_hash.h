#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <strings.h>

#define MAX_LAST_NAME_SIZE 16
typedef struct __PHONE_BOOK_ENTRY {
    char LastName[MAX_LAST_NAME_SIZE];
    char FirstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_ENTRY *pNext;
} PhoneBook;

#define PHONE_BOOK_NAME_1 "Darren"
#define PHONE_BOOK_NAME_2 "Jason"
#define PHONE_BOOK_NAME_3 "Eric"

#define MAX_PHONE_BOOK_CNT 20000000//200000000
PhoneBook pb[MAX_PHONE_BOOK_CNT];
uintptr_t hash[MAX_PHONE_BOOK_CNT]={0};

PhoneBook *FindName(char Last[], PhoneBook *pHead) {
    while (pHead != NULL) {
        if (strcasecmp(Last, pHead->LastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

// JS Hash Function
unsigned int JSHash(char *str)
{
    unsigned int hash = 1315423911;

    while (*str)
    {
        hash ^= ((hash << 5) + (*str++) + (hash >> 2));
    }

    return (hash & 0x7FFFFFFF);
}

int set_hash(char *str, PhoneBook *pPB)
{
        unsigned int hs_bin=0,addr=0;
        if(str == NULL || pPB == NULL)
                return -1;

        addr = hs_bin = JSHash(str) % MAX_PHONE_BOOK_CNT;

        //check if collision
        while(hash[addr] != 0 && addr < MAX_PHONE_BOOK_CNT)
        {
                addr++;
                if( (addr == MAX_PHONE_BOOK_CNT) && hs_bin !=0)
                        addr = 0; //back to addr 0 for searching empty
                else if(addr == hs_bin) //the buffer full
                        return -2;
        }

        hash[addr] = (uintptr_t)pPB; //the hash table store the LastName address.

        return 0;
}


PhoneBook *FindName_by_hash(char Last[]){
	unsigned int hs_bin=0,addr=0;
	PhoneBook *pPB=NULL;

	addr = hs_bin = JSHash(Last) % MAX_PHONE_BOOK_CNT;

	if(hash[hs_bin] == 0)
		return NULL; //LastName not found

	pPB = (PhoneBook *)hash[addr];

	//collision case
	while( (strcasecmp(Last, (const char*)pPB->LastName) != 0) && addr < MAX_PHONE_BOOK_CNT)
	{
		addr++;
		if( (addr == MAX_PHONE_BOOK_CNT) && hs_bin !=0)
                        addr = 0; //back to addr 0 for searching LastName
                else if(addr == hs_bin) //the buffer full
                        return NULL; //LastName not found
		pPB = (PhoneBook *)hash[addr];
	}

	return pPB;
}

#endif //PHONEBOOK_H
