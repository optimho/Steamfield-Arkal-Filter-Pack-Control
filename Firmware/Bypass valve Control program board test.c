/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools
int TimeOut=0;                                // Global


int main()                                    // Main function
{
int run=1;
int FieldInput1=input(0);                    //24v ac Input
int FieldInput2=input(1);                    //24v ac Input
int FieldInput3=input(2);                    //24v ac Input
int HighDiff=input(3);                    //5v dc Input
int Reset=input(4);                          //Reset control
const BypassEnable=5;
const FilterBlocked=22;
const Filterbypassed=21;
const RunOk=23;
int TestInput1=input(14);                    //Test Input 1 (flushing filter 1) Dip switch 5
int TestInput2=input(15);                    //Test Input 2 (flushing filter 2) Dip switch 6
int TestInput3=input(16);                    //Test input 3 (flushing filter 3) Dip switch 7
int TestHighDiff=input(17);                  //Test input High Diff Dip switch 8
int TestReset=input(12);                     //Test Reset   Dip switch 3

  
  while(run==1) //Dip swith 1 is on runs a test rouetien
  {
    while(input(10)==1)                         // Test application 
      {
    
       high(Filterbypassed);
       high(RunOk);
       high(FilterBlocked);
       high(BypassEnable);
       pause (100);
       if (input(0)==1)
         {
           low (Filterbypassed);
           pause(500);
         }                               
  
         if (input(1)==1)
         {
           low (RunOk);
           pause(500);
         }             
      
         if (input(2)==1)
         {
           low (FilterBlocked);
           pause(500);
         }     
      
          if (input(3)==1)
         {
           low (BypassEnable);
           pause(500);
         }
      
           
          if (input(11)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
      
          if (input(12)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
      
          if (input(13)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
         
          if (input(14)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
       
          if (input(15)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
      
          if (input(16)==1)
         {
           low (BypassEnable);
           pause(500);
         } 
        
           if (input(17)==1)
         {
           low (BypassEnable);
           pause(500);
         }
      
          if (input(4)==1)
         {
           low (BypassEnable);
           low (FilterBlocked);
           low (RunOk);
           low (Filterbypassed);
           pause(500);
         }                

     }
     while(input(10)==0) // Dip Switch 1 is off
     {
       low(Filterbypassed);
       low(RunOk);
       low(FilterBlocked);
       low(BypassEnable);
       
       high(RunOk);
       
       if (input(4)==1 || input(17)==1)
       {
       
        //filter is blocked check for flushing
        //flash filter LED while blockage is still trying to be cleared
       
        high(FilterBlocked);
        pause(500);
        low(FilterBlocked);
        pause(500); 
       }         
      
       else 
       {
        low(FilterBlocked);
       }          
     }    
  }  
 }