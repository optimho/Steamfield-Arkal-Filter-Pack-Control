
/*
 *
 *SteamFileldController.c 
 *
 *Main listing 
Steamfield Controller Firmware
controls the bypass valve, opens if the flush cycles are to numerous.
  
  
functions recordEvent( period) this function will return the amount of operations preformed in a specified period in seconds
The function is a low speed function and cannot really handle inputs at a frequency less than 1 second.   
*/


#include <TimeFile.h>
#define period 90    // This is the period that the amount of flush starts are counted
#define diffAlarm 10    // This is the period that initiates a diff Alarm
#define flushValve 26          //
#define highDiff 1       //
#define filter1 2         //define the micro processor pin usage
#define filter2 3         //
#define filter3 4         //
#define clear 5           // Reset input
#define FilterStarts 5

char *timeOfEvent;
int i=0;
int placeHolder1=0;
int placeHolder2=0;
int placeHolder3=0;
int diffState=0;      // Time differential pressure became high
int diffTime=0;
int currentTime=0;    // The amount of seconds since the last time reset or switch on
int amountOfEvents=0; // amount of flush operations recorded in a specified period 



int main()
{

 print("********************************* \n");
 print("********************************* \n"); 
 print("*******   Steamfield        *****\n");
 print("**** Arkal filter controller  ***\n");
 print("****    Contact Energy       **** \n"); 
 print("********************************* \n");
 print("******   Michael              *** \n");
 print("******   Rick                 *** \n"); 
 print("******   Grant                *** \n");
 print("********************************* \n");
 print("**** 15-03-2015 version 1.0    ** \n");
 print("********************************* \n");
 print("                                  \n"); 
 print("                                  \n");
 
 pause(1000);
 
 
 

 for(;;)
  {
 
 int diff = input(highDiff);
 int flush_1 = input(filter1);
 int flush_1_old;
 int flush_2 = input(filter2);
 int flush_2_old;
 int flush_3 = input(filter3);
 int flush_3_old;
 int clr = input(clear);

 
    currentTime=timeNow();   // the time now is currentTime

    

    
 /* This section is to determine if a flush cycle has been completed. 
  * ************************************************************************/    
    if (placeHolder2 != sequenceCheck(flush_1, flush_2, flush_3))
    {
    //print(" Flush sequence complete %d \n", sequenceCheck(flush_1, flush_2, flush_3));
    }    
    placeHolder2=sequenceCheck(flush_1, flush_2, flush_3);
   
    
    
 /* Prints to terminal some program information 
  * ************************************************************************/    
    if (placeHolder1 != indexer())
    {
    print("number of filter starts %d per %d seconds - filter %d %d %d \n", indexer(), period, flush_1, flush_2 ,flush_3);
    
    }    
    placeHolder1=indexer();
    
    
    //printf("amount of triggers per period %i \n", amountOfEvents);    
   // printf("Seconds since last reset %i \n",currentTime);
   // print("diff Pressure = %d\n", diff); 
   // print("flush 1 = %d\n", flush_1); 
   // print("flush 2 = %d\n", flush_2); 
   // print("flush 3 = %d\n", flush_3); 
   // print("Diff High since = %d \n", diffState); 
   // print("************************ \n");
    //print("                         \n");    
 

    
/* This section is to determine if a flush has been initiated. 
  * ************************************************************************/ 
   if ((flush_1 > flush_1_old) || (flush_2 > flush_2_old) || (flush_3 > flush_3_old))
   {
    amountOfEvents=recordEvent();
   }     
    
    flush_1_old=flush_1;
    flush_2_old=flush_2;
    flush_3_old=flush_3;
    
  
    /* This section is to determine how long the high diff alarm has been active. 
     * ************************************************************************/ 

   if ((diff==1) && (diffState==0))  //If there is a high diff and there is not currently a high diff already then save the time 
     { 
    diffState = currentTime;
    //diffTime = diffState;           // That the diff went high
    
      }  
         
  else if ((diff==1) && (diffState>0))  //If there is a high diff and there is not currently a high diff already then save the time 
     { 
    diffTime = currentTime-diffState;           // That the diff went high
    
      }      
  else if ((diff==0)&& (diffState>0) )   // If the diff clears and the diff was high consider that the high diff to have cleared.
      {
    diffTime = 0;
    diffState = 0;
                        // 
      }     
     
     
  /* This program segment alarms if the filter starts per time period is exceeded. */

  if (placeHolder1>FilterStarts)
  {
  high(flushValve);
  }  

  /* This code segment is the Reset part that resets all counters 
   * **************************************************************
   * **************************************************************/

  if (clr==1)
  {
  clrEvents();
  low(flushValve);
  }  
  
 /********************************************************************
  ****************************************************************/
  
  /* Print to terminal if DIFF pressure is high. 
  * ************************************************************************/    
    if ((diffTime > diffAlarm))
    {
    print("diff Alarm %d \n",currentTime );
    pause(1000);
    }    
    placeHolder3=diff;
           
     
     /* This section of the code is to zero the clock periodially so that you do not get any math mathmatical errors if the clock rolls over to zero.
     /* This decison to zero the clock is only made when all variables are in the zero state past some time in the future . 
      * Diff pressure is reset and there has been no flush cycles in the last period and the time is > than 1000000 seconds
     * *********************************************************************************************************************************************/
    
    if ((diff==0) && (diffState==0) && (currentTime>1000000) && (amountOfEvents==0))
    {
     settime();
    }
    
    
   /* This code must be called regularly to make sure that only the events within the specified period are recorded -- this filter also put 
    * a reasonable processor overhead so it is good to call it once per main loop period so that each loop iterates at the same speed.
    **********************************************************************************************************************************************/
    
    reducer(period);    //in a period
          
  }
  return 0;  
}




