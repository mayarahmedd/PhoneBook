
typedef struct date
{
    int day;
    int month;
    int year;


} date;
typedef struct
{

    char  last_name [100];
    char first_name [100];
    date birth_date;
    char email[100];
    char telephone_num [100];
    char address[100];



} phonebook;
phonebook book[1000];
int count=0;

int strValidation (char *str) //checks that the string contains only letters and numbers.returns 0 if invalid, 1 if valid.
{
    int i=0;
   while(i<strlen(str))
    {
        if(!((str[i] >= 65 && str[i]<=90)||(str[i] >= 97 && str[i] <=122) || (str[i] >= 48 && str[i] <= 57)))
            return 0;
            i++;
    }
    if (i==strlen(str))
    return 1;

}
int birthdateValidate (int day, int month, int year) //returns 0 if invalid, 1 if valid.
{
    if (month > 12 || year > 2019 || month < 1 || year <1800)
        return 0;
    else if ( (year%4) == 0 && month == 2)
    {
       //if(month == 2)
      // {
           if(!(day >= 1 && day<= 29))
              return 0;
            else
                return 1;

       //}
    }
    else if (month == 2)
    {
        if(!(day >= 1 && day<= 28))
              return 0;
        else
            return 1;
    }

    else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        if (!(day >= 1 && day <= 31))
            return 0;
        else
            return 1;
    }
    else if ((month == 4 || month == 6 || month == 9 || month  == 11))
    {
       if (!(day >= 1 && day< 31))
            return 0;
        else
            return 1;
    }
    else
        return 1;


}
int emailValidation (char* email)//returns 0 if invalid, 1 if valid.
{
    float dot=0,at=0;
    for (int i = 0; i<strlen(email); i++)
    {
        if(email[i] == '.')
            dot += 1;
        if(email[i]== '@')
            at += 1;
        if (email[i] == 32)
            return 0;

    }
    if (at == 1 && dot >=1)
        return 1;
    else
        return 0;

}
int numValidation (char *str) //checks that the phone number contains only numbers and hasn't been saved before.returns 0 if valid 1 if invalid and 2 in case of duplication
{
    int j,i=0;
   while(i<strlen(str))
    {
        if(!( (str[i] >= 48 && str[i] <= 57)))
            return 1;
            i++;
    }
    for( j = 0; j < count; j++)
    {
       if(strcasecmp(book[j].telephone_num,str)==0){
            return 2;}

    }

    if (i==strlen(str)&& j==count)
    return 0;

    }

void secDelay(int t) //Delays a period of time in seconds
{
    t*=1000;
    clock_t start=clock();
    while(clock()<start+t);
}
void main_menu()
{
        system("cls");
        int x ;
        char y;
        int sort;
        //while (1)
        {
            printf("If you want to \n\nsearch the directory choose 1 \n"
                   "Add choose 2\n"
                   "Delete choose 3\n"
                   "Modify choose 4\n"
                   "Save choose 5\n"
                   "Print all choose 6\n"
                   "Exit choose 7\n");
            scanf("%d",&x);

            switch (x)
            {

            case 1:
                multi_search();
                break;

            case 2:
                add ();
                break;

            case 3:
                delete_phonebook();
                break;

            case 4:
                modify();
                break;

            case 5:
                save();
                printf("Saving");
                for(int t=0; t<2; t++)
                {
                    secDelay(1);
                   printf(".");
                }
                printf("\nsaved successfully!");
                secDelay(1);

                main_menu();
                break;

            case 6:

                /*printf("for sorting by last name choose 1\nfor sorting by date of birth choose 2\n");
                scanf("%d",&sort);
                if(sort == 1)
                sort_by_lastname();
                else if(sort == 2)
                sort_by_date(); */
                print_all();
                break;

            case 7:
                exit_book();
                break;

            default:
                printf("You entered wrong number\n");
                secDelay(3);
                main_menu();


            }

}
}


void load_data()
{
    FILE *fp=fopen("phonebook.txt","r");
    if(!fp)     //fp == NULL
    {

        printf("file not found\n");
        exit(1);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%[^,],",book[count].last_name);
        fscanf(fp,"%[^,],",book[count].first_name);
        fscanf(fp,"%d-",&book[count].birth_date.day);
        fscanf(fp,"%d-",&book[count].birth_date.month);
        fscanf(fp,"%d,",&book[count].birth_date.year);
        fscanf(fp,"%[^,],",book[count].address);
        fscanf(fp,"%[^,],",book[count].email);
        fscanf(fp,"%[^\n]\n",book[count].telephone_num);
        count++;
    }

    fclose(fp);

}


void save()
{

    FILE *fp=fopen("phonebook.txt","w");
    if(!fp)     //fp == NULL
    {

        printf("file not found");
        exit(1);

}        int i;
        for(i=0; i<count; i++)
        {


            fprintf(fp,"%s,",book[i].last_name);
            fprintf(fp,"%s,",book[i].first_name);
            fprintf(fp,"%d-",book[i].birth_date.day);
            fprintf(fp,"%d-",book[i].birth_date.month);
            fprintf(fp,"%d,",book[i].birth_date.year);
            fprintf(fp,"%s,",book[i].address);
            fprintf(fp,"%s,",book[i].email);
            fprintf(fp,"%s\n",book[i].telephone_num);


        }
        fclose(fp);
    }
void display( int i)
    {

        printf("Last name: %s\n",book[i].last_name);
        printf("First name: %s\n",book[i].first_name);
        printf("Birthday: %d %d %d\n",book[i].birth_date.day, book[i].birth_date.month, book[i].birth_date.year);
        printf("Telephone number: %s\n",book[i].telephone_num);
        printf("email: %s\n",book[i].email);
        printf("address: %s\n",book[i].address);
    }

int to_number(char s[100]) {
    int num = 0;
    int sz = strlen(s);
    int i;
    for (i = 0; i < sz; i++)
        num = num * 10 + s[i] - '0';
    return num;
}

void multi_search( )
{
    system("cls");

    char first_name[100];
    char last_name[100];
    char day[100];
    char month[100];
    char year[100];
    char email[100];
    char telephone[100];
    char address[100];
    fflush(stdin);
    printf( "the contact first name: ");
    gets(first_name);
    fflush(stdin);
    printf( "the contact last name: ");
    gets(last_name);
    fflush(stdin);
    printf( "the day of birth of the contact: ");
    gets(day);
    fflush(stdin);
    printf( "the month of birth of the contact: ");
    gets(month);
    fflush(stdin);
    printf("the year of birth of the contact: " );
    gets(year);
    fflush(stdin);
    printf("the contact's address: " );
    gets(address);
    fflush(stdin);
    printf( "the contact email: ");
    gets(email);
    fflush(stdin);
    printf( "the contact telephone number: ");
    gets(telephone);

    int i;
    int flag1=1;


    for(i=0; i<count; i++)
    {

        if((last_name[0] == NULL || strcasecmp(book[i].last_name, last_name) == 0) &&
           (first_name[0] == NULL || strcasecmp(book[i].first_name, first_name) == 0) &&
           (day[0] == NULL || to_number(day) == book[i].birth_date.day)&&
           (month[0] == NULL || to_number(month) == book[i].birth_date.month)&&
           (year[0] == NULL || to_number(year) == book[i].birth_date.year)&&
           (email[0] == NULL || strcasecmp(book[i].email, email) == 0)&&
            (telephone[0] == NULL || strcasecmp(book[i].telephone_num, telephone) == 0)&&
           (address[0] == NULL || strcasecmp(book[i].address, address) == 0))





        {


            flag1=0;
            printf("\n\n");
            display(i);
            printf("\n\n");

        }

        }
        if (flag1==1)
        printf("not found\n");

        int choice;
        printf("\nTo search for another contact press 1\nTo go back to main menu press any other number\n");
        scanf("%d",&choice);
        if(choice==1)
            multi_search();
        else
            main_menu();
}

    void add ()
    {
        system("cls");

        //prompting user for first name and checking its validation

        printf( "The contact first name (letters and numbers only) : ");
        scanf( "%s",book[count].first_name);
        while(!strValidation(book[count].first_name))
        {
            printf("\n\aa name can only contain letters and numbers, please enter a valid name\n");
            printf( "The contact first name (letters and numbers only) : ");
            scanf( "%s",book[count].first_name);
        }

            //prompting user for last name and checking its validation

            printf( "The contact last name (letters and numbers only): ");
            scanf( "%s",book[count].last_name);
        while(!strValidation(book[count].last_name))
        {
            printf("\n\aa name can only contain letters and numbers, please enter a valid name\n");
            printf( "The contact last name (letters and numbers only): ");
            scanf( "%s",book[count].last_name);
        }

        //prompting user for birth date and checking its validation

        printf( "The contact's birth date (dd-mm-yyyy): ");
        scanf( "%d-%d-%d",&book[count].birth_date.day,&book[count].birth_date.month,&book[count].birth_date.year);
        while (!birthdateValidate(book[count].birth_date.day,book[count].birth_date.month,book[count].birth_date.year))
        {
            printf("\n\a Invalid birth date\n");
            printf( "The contact's birth date (dd-mm-yyyy): ");
            scanf( "%d-%d-%d",&book[count].birth_date.day,&book[count].birth_date.month,&book[count].birth_date.year);
        }

        //prompting user for email and checking its validation
        printf( "The contact email: ");
        fflush(stdin);
        scanf("%s",book[count].email);
        while(!emailValidation(book[count].email))
        {
            printf("\n\aInvalid email\n");
            printf( "The contact email: ");
            scanf("%s",book[count].email);
        }

        //prompting user for telephone number and checking its validation
        printf( "The contact telephone number: ");
        scanf("%s",book[count].telephone_num);
        while(numValidation(book[count].telephone_num))
        {
            if(numValidation(book[count].telephone_num)==1)
                printf("\aInvalid number.\n");
            if(numValidation(book[count].telephone_num)==2)
                printf("\aThis number is already saved.");
            printf( "The contact telephone number: \n");
            scanf("%s",book[count].telephone_num);
        }
        //prompting user for address and checking its validation
        printf("The user's address: ");
        fflush(stdin);
        gets(book[count].address);


        //book[count].index=count;
        count++;
        printf("\n\n To add another contact press '1'\n To go back the the main menu press any other number ");

        int choice;
        scanf("%d",&choice);
        if(choice == 1)
            add();
        else
            main_menu();
    }

    void modify()
    {
        system("cls");
        int i, choice;
        int flag=1; //0 if the contact is found 1 if not.
        int counter =0; //counter for how many contacts with similar last names
        char ln[100];

        printf("enter the last name of the contact you wish to modify its data: ");
        scanf("%s",ln);

        for(i=0; i<count; i++)//looping over the array to find all contacts with the same last name the user inputed.
        {

            if(strcasecmp(book[i].last_name,ln)==0)

            {
                flag=0;
                counter++;
                printf("Number %d: \n",counter);
                display(i);
                printf("\n----\n");


            }
        }

        if (flag==1)
        {
            printf("not found\n");
        }

        else
        {
            int x;

            printf("Select the number of the contact you want to modify: ");
            scanf("%d",&x);
            while(x>counter)
            {
                printf("please enter a number between 1 and %d\n",counter);
                printf("Select the number of the contact you want to modify: ");
                scanf("%d",&x);
            }
            counter=0;

            for(i=0; i<count; i++)
            {
                if(strcasecmp(book[i].last_name,ln) == 0)
                {

                    counter++;
                    if (counter==x)
                    {
                        system("cls");

                        printf("Please enter the field you'd like to modify:\n\n1.first name\t2.last name\t3.birth date\n4.email\t\t5.phone number  6.address\n");
                        scanf("%d",&choice);

                        switch (choice)
                        {
                            case 1: //modifying contact's first name.
                                printf( "The contact's current first name is %s, change it to: ",book[i].first_name);
                                scanf( "%s",book[i].first_name);
                                while(!strValidation(book[i].first_name))
                                {
                                    printf("\n\aA name can only contain letters and numbers, please enter a valid name\n");
                                    printf( "The contact's new first name (letters and numbers only) : ");
                                    scanf( "%s",book[i].first_name);
                                }
                                break;

                            case 2: //modifying contact's last name.
                                printf( "The contact's current last name is %s, change it to: ",book[i].last_name);
                                scanf( "%s",book[i].last_name);
                                while(!strValidation(book[i].last_name))
                                {
                                    printf("\na\A name can only contain letters and numbers, please enter a valid name\n");
                                    printf( "The contact's new last name (letters and numbers only): ");
                                    scanf( "%s",book[i].last_name);
                                }
                                break;

                            case 3: //modifying contact's birth date.
                                printf( "The contact's current birth date is %d-%d-%d, change it to: ",book[i].birth_date.day, book[i].birth_date.month, book[i].birth_date.year);
                                scanf("%d-%d-%d",&book[i].birth_date.day, &book[i].birth_date.month,&book[i].birth_date.year);
                                 while (!birthdateValidate(book[i].birth_date.day,book[i].birth_date.month,book[i].birth_date.year))
                                {
                                    printf("\n\a Invalid birth date\n");
                                    printf( "The contact's birth date (dd-mm-yyyy): ");
                                    scanf( "%d-%d-%d",&book[i].birth_date.day,&book[i].birth_date.month,&book[i].birth_date.year);
                                }
                                break;

                            case 4: //modifying contact's email.
                                printf( "The contact's current email is %s, change it to: ",book[i].email);
                                scanf("%s",book[i].email);
                                while(!emailValidation(book[i].email))
                                {
                                    printf("\n\aInvalid email\n");
                                    printf( "The contact email: ");
                                    scanf("%s",book[i].email);
                                }
                                break;

                            case 5: //modifying contact's phone number.
                                printf( "The contact's current telephone number is %s, change it to: ",book[i].telephone_num);
                                scanf("%s",book[i].telephone_num);
                                while(numValidation(book[i].telephone_num))
                                {
                                    if(numValidation(book[i].telephone_num)==1)
                                        printf("\aInvalid number.\n");
                                    if(numValidation(book[i].telephone_num)==2)
                                        printf("\aThis number is already saved.");
                                    printf( "The contact telephone number: \n");
                                    scanf("%s",book[i].telephone_num);
                                }
                                break;

                            case 6:
                                printf( "The contact's current address number is %s, change it to: ",book[i].address);
                                scanf("%s",book[i].address);
                                break;

                            default:
                                printf("invalid option");
                        }
                        break;

                    }


                }
            }
            printf("\nThe contact's data has been modified to:\n\n");
            printf("Last name: %s\n",book[i].last_name);
            printf("First name: %s\n",book[i].first_name);
            printf("Birthday: %d %d %d\n",book[i].birth_date.day, book[i].birth_date.month, book[i].birth_date.year);
            printf("Address: %s\n", book[i].address);
            printf("Telephone number: %s\n",book[i].telephone_num);
            printf("Email: %s\n",book[i].email);

        }
        printf("\n\n To modify another contact press '1'\n To go back the the main menu press any other key");
        scanf("%d",&choice);
        if(choice == 1)
            modify();
        else
            main_menu();


    }

    int compare_date(date d1,date d2)
    {
        if(d1.year != d2.year)
            return d1.year - d2.year;
        else if(d1.month != d2.month)
            return d1.month - d2.month;
        else
            return d1.day - d2.day;
    }

    void sort_by_date()
    {
        int i, j;
        for(i=0; i<count; i++)
        {
            for(j=i+1; j<count; j++)
            {
                if(compare_date(book[j].birth_date, book[i].birth_date) < 0)
                {
                    phonebook tmp = book[i];
                    book[i] = book[j];
                    book[j] = tmp;
                }
            }
        }
    }

    void sort_by_lastname()
    {
        int i,j;
        for(i=0; i<count; i++)
        {
            for(j=i+1; j<count; j++)
            {
                if(strcasecmp(book[i].last_name, book[j].last_name) > 0)
                {
                    phonebook tmp = book[i];
                    book[i] = book[j];
                    book[j] = tmp;
                }
            }
        }
    }


    void delete_phonebook()
    {
        char ln [100];
        char fn [100];

        system("cls");

        printf("enter the last name: ");
        scanf("%s",ln);
        printf("enter the first name: ");
        scanf("%s",fn);

        int i;
        int flag=1;

        for(i=0; i<count; i++)
        {


            if((strcasecmp(book[i].last_name,ln)==0)&& (strcasecmp(book[i].first_name,fn)==0))

            {
                flag=0;
                //display(i);


            for(;i < count - 1; i++) {
               book[i] = book[i+1];
            }

                //book[i]=book[count-1];
                count --;
                printf("Contact deleted successfully!\n");
                break;

            }


        }
        if (flag==1)
            printf("not found\n");

        int choice;
        printf("To delete another contact press 1, to go back to main menu press any other number");
        scanf("%d",&choice);
        if(choice == 1)
            delete_phonebook();
        else
            main_menu();
    }


    void print_all()
    {
        system("cls");

        int i;
        int choice;
        int sort;
        printf("for sorting by last name choose 1\nfor sorting by date of birth choose 2\nTo print all contacts without sorting press any other number\n");
                scanf("%d",&sort);
                if(sort == 1)
                sort_by_lastname();
                else if(sort == 2)
                sort_by_date();

        for (i=0; i<count; i++)
        {
            display(i);
            printf("\n");
        }
        printf("\n\nTo go back to main menu press 1");
        scanf("%d",&choice);
        if(choice == 1)
            main_menu();
    }
    void exit_book()
    {
        int choice;
        printf("Are you sure you want to exit? All your unsaved changes will be discarded.\nTo exit press 1 to go back to main menu press any other number\n");
        scanf("%d",&choice);
        if(choice==1)
            exit(0);
        else
            main_menu();

        //exit(0);


    }



