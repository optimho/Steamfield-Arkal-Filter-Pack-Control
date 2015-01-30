/*
  Blank Simple Project.c
  http://learn.parallax.com/propeller-c-tutorials 
*/
#include "simpletools.h"                      // Include simple tools

int main()                                    // Main function
{
  while(1)
  {
    
    high(23);
    high (22);
    high (21);
    high (5);
    pause (100);
    if (input(0)==1)
      {
        low (23);
        pause(500);
      }                               
  
      if (input(1)==1)
      {
        low (22);
        pause(500);
      }             
      
       if (input(2)==1)
      {
        low (21);
        pause(500);
      }     
      
       if (input(3)==1)
      {
        low (5);
        pause(500);
      }
      
      
       if (input(10)==1)
      {
        low (5);
        pause(500);
      }        
      
       if (input(11)==1)
      {
        low (5);
        pause(500);
      } 
      
       if (input(12)==1)
      {
        low (5);
        pause(500);
      } 
      
       if (input(13)==1)
      {
        low (5);
        pause(500);
      } 
      
       if (input(14)==1)
      {
        low (5);
        pause(500);
      } 
      
       if (input(15)==1)
      {
        low (5);
        pause(500);
      } 
      
       if (input(16)==1)
      {
        low (5);
        pause(500);
      } 
        
        if (input(17)==1)
      {
        low (5);
        pause(500);
      }               

  }
}