#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
void menu();
void addincome();
void addexpense();
void showincome();
void showexpense();
void incomebydate();
void expensebydate();
void close();
void invalid();
typedef struct Date {
int day, month, year;
} Date; /*Using struct to implement the data type of dates*/
struct{
int incomee;
int expensee;
Date income;
Date expense;
char cat[80];
}addi, adde, check;
int main(){
    menu();
    return 0;
}
void addincome(){ /*function to add income into database*/
system("cls");
FILE *ptr; /*Declaring a file pointer*/
ptr = fopen("incomeinfo.txt", "a+"); /*Creating a new file or writing in existing one*/
printf("Enter date(dd/mm/yyyy): \n");
scanf("%d/%d/%d",&addi.income.day, &addi.income.month, &addi.income.year); /*Date input*/
printf("Enter amount: \n");
scanf("%d", &addi.incomee); /*Taking input of the amount with the help of earlier implemented struct*/
printf("Enter category: \n");
scanf("%s", addi.cat);
fprintf(ptr,"%d/%d/%d %d %s\n", addi.income.day, addi.income.month, addi.income.year, addi.incomee, addi.cat); /*Writing in the file*/
fclose(ptr); /*Closing the file*/
printf("Income successfully added\n");
printf("\n\n\nPlease enter 5 to navigate to the main menu: ");
int i;
scanf("%d", &i);
if (i == 5){
    menu(); /*Navigating to main menu*/
}
}
void addexpense(){ /*Function that adds expense into the database*/
system("cls"); /*New screen*/
FILE *ptr1; /*Declaring file pointer*/
ptr1 = fopen("expenseinfo.txt", "a+"); /*Opening file/database for expenditure*/
printf("Enter date(dd/mm/yyyy): \n"); /*Date input with the help of earlier implemented struct*/
scanf("%d/%d/%d",&adde.expense.day, &adde.expense.month, &adde.expense.year);
printf("Enter amount: \n");
scanf("%d", &adde.expensee);
printf("Enter category: \n");
scanf("%s", adde.cat);
fprintf(ptr1,"%d/%d/%d %d %s\n", adde.expense.day, adde.expense.month, adde.expense.year, adde.expensee, adde.cat); /*Writing into the file/database*/
fclose(ptr1);/*closing the file*/
printf("Expense successfully added\n");
printf("\n\n\nPlease enter 5 to navigate to the main menu: ");
int i;
scanf("%d", &i);
if (i == 5){
    menu(); /*returning to main menu*/
}
}
void showincome(){ /*New function to read the database/file in other words, show all the earlier added incomes*/
system("cls");
FILE *ptr2; /*Declaring file pointer*/
ptr2 = fopen("incomeinfo.txt", "r"); /*Reading file*/
char *c ; /*Declaring string*/
c = (char*)calloc(60, sizeof(char)); /*Dynamic memory allocation for the string using calloc function*/
c = fgetc(ptr2);
while (c != EOF){
    printf("%c", c);
    c = fgetc(ptr2); /*printing from the file/database*/
}
fclose(ptr2);/*closing the file*/
printf("\n\n\nPlease enter 5 to navigate to the main menu: ");
int i;
scanf("%d", &i);
if (i == 5){
    menu();
}
free(c); /*Freeing c to avoid memory leakage*/
}
void showexpense(){ /*function to view expense file*/
system("cls"); /*Clearing screen*/
FILE *ptr3; /*File pointer*/
ptr3 = fopen("expenseinfo.txt", "r"); /*Reading the file*/
char *d; /*Declaring string*/
d = (char*)calloc(60, sizeof(char)); /*Dynamic memory allocation again*/
d = fgetc(ptr3);
while (d != EOF){
    printf("%c", d); /*Writing from the file/printing*/
    d = fgetc(ptr3);
}
fclose(ptr3);/*closing the file*/
printf("\n\n\nPlease enter 5 to navigate to the main menu: ");
int i;
scanf("%d", &i);
if (i == 5){
    menu();
}
free(d); /*Freeing allocated memory*/
}
void incomebydate(){ /*Function to filter the database*/
system("cls");
FILE *ptr4; /*File pointer*/
ptr4 = fopen("incomeinfo.txt", "r"); /*Reading the file*/
printf("Enter date(dd/mm/yyy): ");
scanf("%d/%d/%d", &check.income.day, &check.income.month, &check.income.year); /*Taking input*/
while(fscanf(ptr4, "%d/%d/%d %d %s", &addi.income.day, &addi.income.month, &addi.income.year, &addi.incomee, &addi.cat) != EOF){ /*filtering using fscanf*/
    if(addi.income.day == check.income.day && addi.income.month == check.income.month && addi.income.year == check.income.year){
        system("cls");
        printf("The added income on the searched date is: %d\n\n\n", addi.incomee); /*Printing the filtered data*/
    }
}
fclose(ptr4); /*Closing the file*/
printf("\nPlease enter 5 to navigate to the main menu: ");
int i;
scanf("%d", &i);
if (i == 5){
    menu(); /*Returning to main menu*/
}
}
void expensebydate(){ /*Filtering expenseinfo file*/
system("cls");
FILE *ptr5; /*File pointer*/
ptr5 = fopen("expenseinfo.txt", "r"); /*Reading the file*/
printf("Enter date(dd/mm/yyyy): "); /*Take input to filter data*/
scanf("%d/%d/%d", &check.expense.day, &check.expense.month, &check.expense.year);
while(fscanf(ptr5, "%d/%d/%d %d %s", &adde.expense.day, &adde.expense.month, &adde.expense.year, &adde.expensee, &adde.cat) != EOF){
    if(adde.expense.day == check.expense.day && adde.expense.month == check.expense.month && adde.expense.year == check.expense.year){
        system("cls");
        printf("The added expense on the searched date is: %d\n\n\n", adde.expensee); /*printing filtered result*/
    }
}
fclose(ptr5); /*Closing file*/
printf("\nPlease enter 5 to navigate to the main menu: ");
int k;
scanf("%d", &k);
if(k == 5){
    menu(); /*Returning to main menu*/
}
}
void close(){ /*function to close the program*/
system("cls");
}
void invalid(){ /*Invalid selection*/
system("cls");
printf("Inalid Choice!");
int i;
printf("\n\nEnter 5 to go back to the main menu: ");
scanf("%d", &i);
if(i == 5){
    menu();
}
}
void menu(){ /*Opening screen of the application!*/
system("cls");
printf("                                          Wallet (Incomes and Expenses)\n");
printf("                                                  Currency: HUF\n\n\n\n");
printf("Options:\n\n\n1. Add Incomes\n2. Add Expenses\n3. View Income History\n4. View Expense History\n5. Search Income of a Particular Day\n6. Search Expense of a Particular Day\n7. Close Wallet\n\n\n"); /*All the options which will be visible on the load screen of the application*/
int selection; /*Declaring a variable to navigate through the options*/
scanf("%d", &selection); /*Taking input from the user, which option they may want*/
    switch (selection){ /*Using switch case to navigate through the option with the help of different functions*/
        case 1: addincome(); break;
        case 2: addexpense(); break;
        case 3: showincome(); break;
        case 4: showexpense(); break;
        case 5: incomebydate(); break;
        case 6: expensebydate(); break;
        case 7: close(); break;
        default: invalid();
    }
}
