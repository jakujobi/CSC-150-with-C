//This program will pause the screen until the user presses the enter key

#include <stdio.h>

void pause ( void );

int main(void)
{
 /*
 //Does not work!!
  while (1)
  {
    printf("La di da, I'm doing an iteration...\n");
    printf("Press Enter to continue\n");
    while (getchar()!='\n');

    printf ("Hiya");
  }
    */

//This Inline version works
printf("Press enter to continue\n");
char enter = 0;
while (enter != '\r' && enter != '\n')
{
    enter = getchar(); 
}
printf("Thank you for pressing enter\n");



//    pause();
    return 0; /* not actually needed, since execution never gets here */
}


/*
//This 2nd version of the pause function works
void pause ( void )
{
  printf("Press Enter to continue\n");
  while (getchar()!='\n');
}
*/


/*
//This 3rd version of the pause function works
void pause ( void )
{
  printf ("Press enter to continue...");
  fflush (stdout);
  getchar();
  return;
}
*/

//Works!!!!!!