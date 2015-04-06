#include <time.h>
#include <sys/time.h>
#include <simpletools.h>

#define TRUE 1
#define FALSE 0
#define FAIL 0



time_t now;
int gv_sequence;   // Global variable for the sequence function

volatile int currentEventTime[1000];
int *addr;


int timeNow(void);  /* The time now is the time since the epoch which is 1 January 00:00:00 1970 */
void shiftArray(int numberOfElements);  /* Rapidly shift all the elements of an array by one/*/

volatile struct timeStruct{
    int hour;
    int min;
    int sec;
}EventTime[10]; 

void printtime(void);
int getdst(void);
int prompttime(char *prompt);
void settime(void);
void starts_per_hour( int i);     

 

int recordEvent();                    /* inserts a time event onto an array and returns an integer of the amount of events per 
                                                period  in seconds */
int indexer();                 /* counts how many entries are in the array */
void reducer(int period);             /* keeps all entries current within the last period period is in seconds */
int totSec(int i);                    /* calculates the total amount of seconds in EventTime[x] */

int sequenceCheck(int flush1,int flush2,int flush3);              /* Returns True if a flush cycle is complete, that means that
                                         Filter1 then filter 2 then after that filter 3 */

void clrEvents();                             /* Clears all records back to zero .*/