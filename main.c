#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "phonebook.h"

    int main()
    {
        load_data();
        printf("Loading from file");
        for(int i=0;i<2;i++)
        {
            secDelay(1);
            printf(".");
        }
        printf("\nContacts loaded successfully!");
        secDelay(2);

        main_menu();

    }
