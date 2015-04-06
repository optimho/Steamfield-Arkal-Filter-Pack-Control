

//#include <time.h>
//#include <sys/time.h>
//#include <simpletools.h>
#include <TimeFile.h>

#define BUFFERLEN 10
//time_t now;


int timeNow(void)
{
 // time_t now;
 now = time(NULL);
 // printf("%s", asctime(localtime(&now)));
 // printf("%i \n", now);
  return now;
}
  
  
void printtime(void)
{
  now = time(NULL);
 printf("%i", &now);
  return asctime(localtime(&now));
}

int getdst(void)
{
  int rc = 0;
  printf("Use daylight savings time [y/n] ?");
  fflush(stdout);
  rc = (getchar() == 'y') ? 1 : 0;
  getchar();
  return rc;
}

int prompttime(char *prompt)
{
  int rc = 0;
  char *endp;
  char buffer[BUFFERLEN];
  do {
    printf("Enter %s: ",prompt);
    fflush(stdout);

    fgets(buffer,BUFFERLEN,stdin);
    fflush(stdin);

    rc = strtol(buffer, &endp, 10);

    if(endp == buffer)
    {
      if('\n' == *endp)
      {
        rc = 0;
        break;
      }
      printf("Invalid entry \"%c....\" Please enter a number.\n", *endp);
    }
  } while(endp == buffer);
  return rc;
}

void settime(void) // set time virtual RTC  
{
  struct timeval tv;   
  struct tm t;

  t.tm_isdst = 0;        //getdst();
  t.tm_year = 1968-1900; //prompttime("Year")-1900;
  t.tm_mon = 11-1;  //prompttime("Month")-1;
  t.tm_mday = 11;   //prompttime("Day of the month");
  t.tm_hour = 12;   //prompttime("Hour");
  t.tm_min = 0;     //prompttime("Minute");
  t.tm_sec = 0;     //prompttime("Second");
  tv.tv_sec = mktime(&t);
  settimeofday(&tv, 0);
 // printf("Set time all done.\n");
}

int recordEvent()
{
  int a=indexer();
  currentEventTime[a]=timeNow();
  return indexer();
}


/* How many items in the array, count any non zero entries*/
int indexer()
{
int i=0;

while (currentEventTime[i]!=0)
 {
  i++;
 }
 
return i;
 
}
  

/*Filter through the EventTime array and remove events that are older than a value in seconds */
void reducer(period) 
{
  
  int interval=period;
  int currentTime = timeNow();
  int Events=100;
  int i=0;

  
  while (currentEventTime[i]!=0)
  {
    

    i++;
  }
      i=0;
      
  if ((currentTime-interval>currentEventTime[0]) && (currentEventTime[0]>0))
  {
  shiftArray(indexer());
  }    
 
    
}  



shiftArray(int numberOfElements)
{
 
  for (int i=1; i<=numberOfElements; i++)
  
{

  currentEventTime[i-1]=currentEventTime[i];
}

 
}
  
int sequenceCheck(flush1, flush2, flush3)
{

if ((flush1==1) && (gv_sequence==0))
    {
      
      gv_sequence=1;
      return gv_sequence;
      
    }
    
else if ((flush2==1) && (gv_sequence==1))
    {
      
      gv_sequence=2;
      return gv_sequence;
    }
        
else if ((flush3==1) && (gv_sequence==2))
    {
      gv_sequence=3;
      return gv_sequence;
    }
        
else 
    {
      gv_sequence=0;
      return gv_sequence;
    }        
      
}

/*  ********************void clear records **************************************/
void clrEvents()
{
  int i=0;

while (currentEventTime[i]!=0)
 {
  currentEventTime[i]=0;
  i++;
 }
  
  
}

  