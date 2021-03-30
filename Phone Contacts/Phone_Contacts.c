#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

void add_contact();
void delete_contact();
void edit_contact();
void search_contact();
void display_contacts();
void sorting();
void counter_assignment();

struct info
{
  char FirstName[100]; 
  char LastName[30];
  char PhoneNumber[20];
  char Email[50];
}array[100];

FILE * fp;
int counter,print;

int main(void)
{
    int broke = 0,round=0;
    char operation;
    while(!broke)
    {

        //if file doesn't created yet
        if (round != 0)
        {
            counter_assignment();
            sorting();
        }
            
        printf("\n\n\t\t\t\t\t\t  MENU\t\t\t\t\n\n");
        printf("\t\t1.Add New   \t\t2.Delete   \t\t3.Modify  \n\t\t4.Search \t\t5.Exit (Press 'Q')\n");
        printf("\t\t\t\tEnter operation code: ");
        scanf(" %c",&operation);
        while ((operation > '4' || operation < '1') && (operation != 'q' && operation != 'Q'))
        {
            printf("Operation numbers only 1,2,3,4,5\n");
            printf("Enter operation code: ");
            scanf("%c ",&operation);
        }
        #ifdef _WIN32
    			system("cls");
    		#else
    			system("clear");
			#endif
        //if file doesn't created yet
        if (round != 0)
            display_contacts();
        
        switch(operation)
        {
            case '1':
                add_contact();
            break;
            case '2': 
                delete_contact();
            break;
            case '3': 
                edit_contact();
            break;
            case '4': 
                print = 1;
                search_contact();
            break;
            case 'Q':case 'q': 
                broke = 1;
            break;
        }
        round++;
    }
}

void add_contact()
{
    printf("First Name : ");
    scanf("%s",array[counter].FirstName);
    printf("Last Name : ");
    scanf("%s",array[counter].LastName);
    printf("Number : ");
    scanf("%s",array[counter].PhoneNumber);
    printf("Email : ");
    scanf("%s",array[counter].Email);
    print = 0;
    if (counter != 0)
        search_contact();
    if (print == 0)
    {
        fp = fopen ("contact_database.txt","a");
        #ifdef _WIN32
                fprintf(fp, "%s\t\t%s\t\t%s\t\t%s\n", strupr(array[counter].FirstName), strupr(array[counter].LastName), array[counter].PhoneNumber,array[counter].Email);    fclose (fp);
    		#else
                fprintf(fp, "%s\t\t%s\t\t%s\t\t%s\n", array[counter].FirstName, array[counter].LastName, array[counter].PhoneNumber,array[counter].Email);
			#endif
        fclose (fp);
        counter++;
    }
    else
        printf("\nAlready exits !\n");
}

void delete_contact()
{
    FILE *fileptr1, *fileptr2;
    char ch;
    int delete_line, temp = 1;

    fileptr1 = fopen("contact_database.txt", "r");
    ch = getc(fileptr1);
    rewind(fileptr1);
    printf(" \n Enter line number of the line to be deleted:");
    scanf("%d", &delete_line);

    //open new file in write mode
    fileptr2 = fopen("replica.txt", "w");
    ch = 'A';
    while (ch != EOF)
    {
        ch = getc(fileptr1);
        //except the line to be deleted
        if (temp != delete_line)
        {
            //copy all lines in file replica.c
            putc(ch, fileptr2);
        }
        if (ch == '\n')
        {
            temp++;
        }
    }
    fclose(fileptr1);
    fclose(fileptr2);
    remove("contact_database.txt");

    //rename the file replica.c to original name
    rename("replica.txt", "contact_database.txt");
    counter --;
}

void edit_contact()
{
    int id,choice,i = 0;
    char line[1024] ;

    printf("What's the ID of contact which will be edited : ");
    scanf("%d",&id);
    printf("Which one will be edited ?\n1) First Name\t\t2)Last Name\t\t3)Phone Number\t\t4)Mail\n");
    scanf("%d",&choice);
    fp = fopen("contact_database.txt", "r");

    while (fgets(line , sizeof(line) , fp )!= NULL)
    {
        i++;
        if (id == i)
        {   
            char* pch;
            char information[4][40];
            pch = strtok (line,"\t\t");
            int j=0;
            while (pch != NULL)
            {
                strcpy(information[j],pch);
                pch = strtok (NULL, "\t\t");
                j++;
            }
            switch (choice)
            {
            case 1:
                printf("New First Name : ");
                scanf("%s",information[0]);
                break;
            case 2:
                printf("New Last Name : ");
                scanf("%s",information[1]);
                break;
            case 3:
                printf("New Phone Number : ");
                scanf("%s",information[2]);
                break;
            case 4:
                printf("New Mail : ");
                scanf("%s",information[3]);
                break;
            
            default:
                printf("Wrong choice.");
                break;
            }
            fclose(fp);

            FILE *fileptr1, *fileptr2;
            char ch;
            int delete_line, temp = 1;

            fileptr1 = fopen("contact_database.txt", "r");
            ch = getc(fileptr1);
            rewind(fileptr1);
            delete_line = id;

            //open new file in write mode
            fileptr2 = fopen("replica.txt", "w");
            ch = 'A';
            int one_time = 0;
            while (ch != EOF)
            {
                ch = getc(fileptr1);
                //except the line to be deleted
                if (temp != delete_line)
                {
                    //copy all lines in file replica.c
                    putc(ch, fileptr2);
                }
                else if(one_time == 0)
                {
                    one_time ++;
                    fprintf(fileptr2, "%s\t\t%s\t\t%s\t\t%s\n", information[0], information[1], information[2], information[3]);
                }
                if (ch == '\n')
                {
                    temp++;
                }
            }
            fclose(fileptr1);
            fclose(fileptr2);
            remove("contact_database.txt");

            //rename the file replica.c to original name
            rename("replica.txt", "contact_database.txt");
            break;
        }
    }
}

void search_contact()
{
    int exits = 0;
    char key[50],str[50];
    char **string = malloc(4 * sizeof(char *)); // Allocate row pointers
    int i;

    if (print == 1)
    {
        printf("Enter anything to search : ");
        scanf(" %[^\n]%*c",str);
        char* pch;
        pch = strtok (str," ,.-");
        i = 0;
        while (pch != NULL)
        {
            string[i] = malloc(100 * sizeof(char));  // Allocate each row separately
            strcpy(string[i],pch);
            pch = strtok (NULL, " ,.-");
            i++;
        }
        i--;
    }
    //came from add_contact
    else
    {
        string[0] = malloc(100 * sizeof(char));  // Allocate each row separately
        strcpy(string[0], array[counter].FirstName);
        string[1] = malloc(100 * sizeof(char));  
        strcpy(string[1], array[counter].LastName);
        string[2] = malloc(100 * sizeof(char));  
        strcpy(string[2], array[counter].PhoneNumber);
        string[3] = malloc(100 * sizeof(char));  
        strcpy(string[3], array[counter].Email);
        i = 4;
    }
    
    char line[1024];
    fp = fopen("contact_database.txt", "r") ;
    printf("\n");
    while (fgets(line , sizeof(line) , fp )!= NULL)
    {
        if (strstr(line , string[0]) != NULL)
        {
            if (i >= 1)
            {
                if (strstr(line , string[1]) != NULL)
                {
                    if (i >= 2)
                    {
                        if (strstr(line , string[2] )!= NULL)
                        {
                            if (i >= 3)
                            {
                                if (strstr(line , string[3] )!= NULL)
                                {
                                    if (print == 1)
                                        printf("%s",line);
                                    else
                                    {
                                        exits = 1;
                                        break;
                                    }
                                }
                            }
                            else if(print == 1)
                                printf("%s",line);
                        }
                    }
                    else if(print == 1)
                        printf("%s",line);
                }
            }
            else if(print == 1)
                printf("%s",line);
        }
    }
    fclose(fp);
    free(string);
    if (exits == 1)
        print = 2;
}

void display_contacts()
{
    char ch;
    fp = fopen("contact_database.txt", "r");

    /* fopen() return NULL if last operation was unsuccessful */
    if(fp == NULL)
    {
        /* Unable to open file hence exit */
        printf("Unable to open file.\n");
        printf("Please check whether file exists and you have read privilege.\n");
        exit(EXIT_FAILURE);
    }

    int x = 0;

    do
    {
        x++;
        printf("ID : %d\t\t\t\t",x);
        do 
        {
            /* Read single character from file */
            ch = fgetc(fp);

            /* Print character read on console */
            putchar(ch);

        } while((ch <= 256 && ch >= 0) && ch != '\n'); 
    } while (ch <= 256 && ch >= 0 && ch != EOF);    /* Repeat this if last read character is not EOF and ... */

    fclose(fp);
    printf("\n");
}

void sorting()
{
    FILE * fpw;
    struct sorting
    {
        char FirstName[100]; 
        char LastName[30];
        char PhoneNumber[20];
        char Email[50];
    }arr_sort[100];
	struct sorting temp;
	int i=0,size,j;
	char ch = 'A'; 
 
	fp=fopen("contact_database.txt","r");
    rewind(fp);
	if(fp==NULL)
	{ 
	    printf("\n Cannot open the file \n");
	    exit(1);
	}
	while(ch!=EOF)
	{
	    fscanf(fp,"%s\t\t%s\t\t%s\t\t%s",arr_sort[i].FirstName,arr_sort[i].LastName,arr_sort[i].PhoneNumber,arr_sort[i].Email);  
	    ch=fgetc(fp); 
	    i++;  
	}
    fclose(fp);
    //buble sort
	size=i-1;
	for(i=1;i<size;++i)
    {
        for(j=0;j<size-i;j++)
        {
            if(strcmp(arr_sort[j+1].FirstName, arr_sort[j].FirstName) < 0)
            {
                temp=arr_sort[j];
                arr_sort[j]=arr_sort[j+1];
                arr_sort[j+1]=temp;
            }
        }
    }
	fpw=fopen("replica1.txt","w");
	for(i=0;i<size+1;i++)
    {
	    fprintf(fpw,"%s\t\t%s\t\t%s\t\t%s\n",arr_sort[i].FirstName,arr_sort[i].LastName,arr_sort[i].PhoneNumber,arr_sort[i].Email);
    }
    fclose(fpw);
    
    remove("contact_database.txt");
    //rename the file replica.c to original name
    rename("replica1.txt", "contact_database.txt");
    

}

void counter_assignment()
{
    char ch;
    fp = fopen("contact_database.txt", "r");

    /* fopen() return NULL if last operation was unsuccessful */
    if(fp == NULL)
    {
        counter = 0;
        exit(1);
    }
    int x = 0;
    do
    {
        x++;
        do 
        {
            /* Read single character from file */
            ch = fgetc(fp);

        } while((ch <= 256 && ch >= 0) && ch != '\n');
    } while (ch <= 256 && ch >= 0 && ch != EOF);
    counter = x;
    /* Done with this file, close file to release resource */
    fclose(fp);
    printf("\n");
}
