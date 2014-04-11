/* 
    WorkLog
    Copyright © 2014 John Alexandher

    This program is meant to log my workouts. It simply writes out the
    provided information to an external file.
*/


#include "WorkLog.h"

int main(void)
{
    int exit = 1;  /* This is used to control the main loop. */
    int option = 0;  /* This stores the menu option */
    int check = 0;

    /* This is the main loop. */
    while (exit){
         /* Display the Main Menu: */
        printf("----------------------------------------\n");
        printf("                WorkLog:\n");
        printf("\n  1)  Enter Data\n");
        printf("\n  2)  View Data\n");
        printf("\n  3)  Exit");
        printf("\n\n\n\n\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch (option){
            case 1: add();  /* Jump to the add function. */ 
                    break; 
            case 2: display();  /* Jump to the display function. */
                    break;
            case 3: exit = 0;  /* This will cause the program to end. */
                    break;
            default: break;  /* This will just return to the beginning of the loop. */
        } 

        /* DEBUG */
        exit = 0;
    }


    return 0;
}

