#include <inttypes.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "phonebook_hash.h"

#define TEST_CYCLE 100
void init_phone_book(void)
{
	int i;
	for(i=0 ; i<MAX_PHONE_BOOK_CNT; i++)
		pb[i].pNext = &pb[i+1];
	
	pb[MAX_PHONE_BOOK_CNT-1].pNext = NULL;

	//first name in position of 1/3 array 
	strcpy(pb[MAX_PHONE_BOOK_CNT/3].LastName, PHONE_BOOK_NAME_1);
	set_hash(PHONE_BOOK_NAME_1, &pb[MAX_PHONE_BOOK_CNT/3]);

	
	//first name in position of 2/3 array 
        strcpy(pb[MAX_PHONE_BOOK_CNT*2/3].LastName, PHONE_BOOK_NAME_2);
	set_hash(PHONE_BOOK_NAME_2, &pb[MAX_PHONE_BOOK_CNT*2/3]);

	//first name in position of end array 
        strcpy(pb[MAX_PHONE_BOOK_CNT-1].LastName, PHONE_BOOK_NAME_3);
	set_hash(PHONE_BOOK_NAME_3, &pb[MAX_PHONE_BOOK_CNT-1]);
}

double time_of_find_name(char *Last)
{
	struct timespec t_start, t_end;
        uint64_t nsec1 = 0;
        uint64_t nsec2 = 0;
        uint64_t elapsed_nsec = 0;

        PhoneBook *pb_found;

        clock_gettime(CLOCK_MONOTONIC, &t_start);
        nsec1 = ((uint64_t)(t_start.tv_sec) * 1000000000LL + t_start.tv_nsec);

        pb_found = FindName_by_hash(Last);

        clock_gettime(CLOCK_MONOTONIC, &t_end);
        nsec2 = (uint64_t)(t_end.tv_sec) * 1000000000LL + t_end.tv_nsec;
        elapsed_nsec = nsec2 - nsec1;

        if(pb_found != NULL)
        {
                //printf("%s found ",Last);
        }
        else
                printf("%s not found\n",Last);

        //printf("used time :%.3f sec\n",(double)elapsed_nsec/1000000000.0);

        return (double)elapsed_nsec/1000000000.0;
}

int main()
{
	double time_used=0;
        double time_used_1=0, time_avg_1=0;
        double time_used_2=0, time_avg_2=0;
        double time_used_3=0, time_avg_3=0;
        int i;

        printf("============= Seraching PhoneBook Hash v1 ===========\n");
        printf("PhoneBook struc size : %ld, PhoneBook number : %d\n", sizeof(PhoneBook),MAX_PHONE_BOOK_CNT);
        printf("Total phonebook data size %ld(MB)\n\n", sizeof(pb)/1024/1024);

        init_phone_book();

        printf("1. %s locate in 1/3 of phonebook\n",PHONE_BOOK_NAME_1);
        for(i = 0; i< TEST_CYCLE ; i++)
        {
                time_used = time_of_find_name(PHONE_BOOK_NAME_1);
                //printf("(%d) %.9f\n",i+1,(double) time_used);
                time_used_1 += time_used;
        }
        time_avg_1 = time_used_1/TEST_CYCLE;
        printf("average seaching time: %.9f (s)\n\n",(double) time_avg_1);

        printf("2. %s locate in 2/3 of phonebook\n",PHONE_BOOK_NAME_2);
        time_used=0;
        for(i = 0; i< TEST_CYCLE ; i++)
        {
                time_used = time_of_find_name(PHONE_BOOK_NAME_2);
                //printf("(%d) %.9f\n",i+1,(double) time_used);
                time_used_2 += time_used;
        }
        time_avg_2 = time_used_2/TEST_CYCLE;
        printf("average seaching time: %.9f (s)\n\n",(double) time_avg_2);

        printf("3. %s locate in end of phonebook\n",PHONE_BOOK_NAME_3);
        time_used=0;
        for(i = 0; i< TEST_CYCLE ; i++)
        {
                time_used = time_of_find_name(PHONE_BOOK_NAME_3);
                //printf("(%d) %.9f\n",i+1,(double) time_used);
                time_used_3 += time_used;
        }
        time_avg_3 = time_used_3/TEST_CYCLE;
        printf("average seaching time: %.9f (s)\n\n",(double) time_avg_3);

        return 0;

}

