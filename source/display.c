void display(void){
    printf("Week %d-\n\n", week);

    switch (weekday){
        case 'm': day = "Monday";
                  break;
        case 't': day = "Tuesday";
                  break;
        case 'w': day = "Wednesday";
                  break;
        case 'r': day = "Thursday";
                  break;
        case 'f': day = "Friday";
                  break;
        case 's': day = "Saturday";
                  break;
        case 'u': day = "Sunday";
                  break;
        default: break;
    }

    printf("\t\t%s\n\n", day);
    printf(
}
