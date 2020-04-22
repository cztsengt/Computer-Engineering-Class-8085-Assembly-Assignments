//Name: Caleb Tseng-THam
//Teacher: Mr. Wong
//Date: November 27, 2014
/* A calculation game where a user inputs two positive integers,
and then must calculate the sum of them.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Declaration Section
int choice;
int num1;
int num2;
int answer;

//Function title
void title()
{
     system("cls");
     printf("\n%32sCalculation Game\n","");
}

//Function pauseProgram
void pauseProgram()
{
     printf("\nPress any key to continue...");
     getchar();
}

//Function intro
void intro()
{
     title();
     printf("\nThis program will test your math abilities.");
     pauseProgram();
}


//Function mainMenu
void mainMenu()
{
     title();
     printf("\n1. Play Game\n");
     printf("\n2. Exit\n");
     printf("\nEnter  1 or 2:");
     scanf("%d",&choice); 
     if(choice>=3 || choice <= 0) // Checks if choice is either 1 or 2
     {
                  printf("\nSorry, you must enter either 1 or 2! Please try again.\n"); 
                  pauseProgram();
     }
     getchar();
}

//Function userInput 
void userInput()
{
     do // loop so that user can stay within "do..for" loop in main program.
     {
     title();
     printf("\nPlease enter positive numbers only!\n");
     printf("\nEnter a number ");
     scanf("%d",&num1);
     if (num1 <=0) // Checks if number is not positive to display error message
              { 
                printf("\nSorry, you must enter a positive value! Please try again."); 
                pauseProgram();
                getchar();
              }
        }while (num1 <=0); // Will only exit loop when number is positive
        do 
        {
               printf("\nEnter another number ");
               scanf("%d",&num2);
               if (num2 <=0) // Checks if number is not positive to display error message
               {
                  printf("\nSorry, you must enter a positive value! Please try again."); 
                  pauseProgram();
                  getchar();
                  title(); // Recreation of previous user input 
                  printf("\nPlease enter positive numbers only!\n");
                  printf("\nEnter a number %d\n",num1); 
                  }
        }while (num2 <=  0); // Will only exit loop when number is positive
        printf("\nWhat is %d + %d? ",num1,num2);
     scanf("%d",&answer);
}

//Function display
void display()
{
     title();
     if (answer==(num1+num2)) 
     {
        printf ("\nWow! you got the right answer!\n");
        getchar();
        }
     else
     {
         printf ("\nHmmm...maybe we should review this math concept again!\n");
         getchar();
         }
         pauseProgram();
}

//Function goodbye
void goodbye()
{
     title();
     printf("\nThis program is written by:\n");
     printf("\nCaleb Tseng-Tham\n");
     printf("\nFor further information call:\n");
     printf("\n1-800-123-4567");
     getchar();
}

//Main Program
int main ()
{
    intro();
 do // Loops so that user will not reach goodbye untill they chose to
 { 
         mainMenu(); 
         if (choice == 1)
         {
                    userInput();
                    display();
         }
 }
 while(choice != 2);
 goodbye(); 
}
