/*
    defs.c 
    Copyright © 2014 John Alexandher

    This is the header file for the WorkLog.c file.
*/


#include "WorkLog.h"

/*-----FUNCTIONS-----*/

void primary(int workout, int num){
    int weight = 0; 
    int sets = 0;
    int reps = 0;
    int limit = workout + num;
    char uniform = 'a';
    char weightOption = 'a';
    FILE *log;

    log = fopen("files/log.txt", "a");

    if (!log)
        printf("ERROR: The file 'log.txt' could not be opened.");

    /* This initializes all the exercises. */
    char *exercise[] = {"Military Press", "Chin-Ups", "Sit-Ups", "Dips", \
                        "Deadlift", "Shrugs", "Good Mornings", \
                        "Bench Press", "Dumbbell Incline", "Pull-Ups", "Dips", \
                        "Squat", "Calf Raise", "Rows", "Leg Raises"};

    system("date +'\%D \%A' >> files/log.txt");

    /* This loops through the entire workout. */
    while (workout < limit){
            fprintf(log, "\n\t%s:\n", exercise[workout]);

        /* This loops until there is no more data for the specific exercise. */
        while (weightOption != 'n' && weightOption != 'N'){
            printf("%s weight: ", exercise[workout]);
            scanf("%d", &weight);
            printf("%s sets: ", exercise[workout]);
            scanf("%d", &sets);

            if (sets > 1){
                getchar();
                printf("Uniform Reps? (y/n): ");
                scanf("%c", &uniform);
            }
            else
                uniform = 'n';

            /* This processes sets with varying reps. */
            if ('y' != uniform && 'Y' != uniform){
                int setNumber = 0;

                while (setNumber < sets){
                    printf("%s set %d reps: ", exercise[workout], (setNumber + 1));
                    scanf("%d", &reps);
                    fprintf(log, "\t%dX%dX%d\n", weight, 1, reps);

                    ++setNumber;
                }
            }
            /* This processes sets with the same number of reps. */
            else{
                printf("%s reps: ", exercise[workout]);
                scanf("%d", &reps);
                fprintf(log, "\t%dX%dX%d\n", weight, sets, reps);
            }

            getchar();
            printf("Different weight? ");
            scanf("%c", &weightOption);
        }    

        weightOption = 'a';
        ++workout;
    }

        fprintf(log, "\n");
        fclose(log);
}


void add(void){
    int week = 0;
    char day = 'a';
    FILE *var;

    var = fopen("files/variables.txt", "r+");

    if (!var)
        printf("ERROR: The file 'variables.txt' could not be opened.");


    /* Grab the variable definitions from the variable.txt file. */
    fscanf(var, "%d%c", &week, &day);


    /* This updates the day. */
    switch (day){
        case 'm': day = 't';
                  break;
        case 't': day = 'w';
                  break;
        case 'w': day = 'r';
                  break;
        case 'r': day = 'f';
                  break;
        case 'f': day = 's';
                  break;
        case 's': day = 'u';
                  break;
        case 'u': day = 'm';
                  ++week;
                  break;
        default:  day = 'a';
    }

    /* This updates the week. */
    if (week > 4)
        week = 1;

    /* This updates the definitions file. */
    rewind(var);
    fprintf(var, "%d%c", week, day);


    /* This updates the workout log. */
    switch (day){
        //substitute MON for 0.
        case 'm': primary(0, 4);
                  break;
        //substitute TUE for 4.
        case 't': primary(4, 3);
                  break;
        case 'w': 
                  break;
        //substitute THU for 7.
        case 'r': primary(7, 4);
                  break;
        //substitute FRI for 11.
        case 'f': primary(11, 4);
                  break;
        case 's': 
                  break;
        default: printf("ERROR: invalid variable definitions.\n");
    }
    
    fclose(var);
}


void display(void){
    //int percents[] = {65, 75, 85, 95, 40, 50, 60, 70, 80, 90};
    //char *exercises[] = {"Military Press", "Chin-Ups", "Sit-Ups", "Dips"};

    printf("Week 1-\n\n");
    printf("\t\tMonday\n\n");
    printf("\tMilitary Press\n");
    printf("   Sets\t\tWeight\n");
    printf("Warm-up\n");
    printf("65%% X 5\n");
    printf("75%% X 5\n");
    printf("85%% X 5\n\n");
    printf("\tChin-Ups\n");
    printf("   Sets\t\tWeight\n");
    printf("     3\t\tNone\n\n");
    printf("\tSit-Ups\n");
    printf("   Sets\t\tWeight\n");
    printf("     5\t\tNone\n\n");
    printf("\tDips\n");
    printf("   Sets\t\tWeight\n");
    printf("    3-5\t\tNone\n\n");
}

