#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void new_account()
{
    int choice;
    struct node
    {
        struct node *next;
        int acc_number;
        char first_name[100];
        char second_name[100];
        char gender[20];
        // char date_birth[20];
        char address[2000];
        long long int deposit_money;
        // char today_date[20];
        long long int phone_number;
    };
    struct node *newnode, *head = 0, *temp = 0;
    int test, a = 0, b=0;
    printf("\n");
    printf("\t\t\t\t<------Customer Account Banking Management System------>\n\n");
    printf("\t\t\t\t\t <----------WELCOMING YOU!!---------->\n\n");
mainmenu:
    printf("\t\t****** Welcome to the Main Menu ******\n\n");
    printf("1.Create new account\n");
    printf("2.Remove Account\n");
    printf("3.Update information of existing account\n");
    printf("4.For Transactions\n");
    printf("5.Check the details of existing account\n");
    printf("6.View customers list\n");
    printf("7.Exit\n\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");
    if (choice == 1)
    {
       b++;
        // int testcase;
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;

        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }

        else
        {

            temp->next = newnode;
            temp = newnode;
        }
        printf("Enter Your  5 digit Account Number: ");
        scanf("%d", &newnode->acc_number);
        printf("Enter your First name, Second name: ");
        scanf("%s %s", newnode->first_name, newnode->second_name);
        printf("Enter your Gender: ");
        scanf("%s", newnode->gender);
        printf("Enter your phone number: ");
        scanf("%lld", &newnode->phone_number);
        // printf("Enter your date of birth(dd/mm/yyyy): ");
        // scanf("%s", newnode->date_birth);
        printf("Enter the money you want to deposit: ");
        scanf("%lld", &newnode->deposit_money);
        // printf("Enter today's date(dd/mm/yyyy): ");
        // scanf("%s", newnode->today_date);
        printf("Enter your city: ");
        scanf("%s", newnode->address);
        printf("\n");
        // gets(newnode->name);
        printf("<--------------------Account created successfully-------------------->\n\n");
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }


    else if (choice == 2)
    {
        a++;
        temp = head;
        int choice7;
        int accnumber;
        printf("Enter your account number: ");
        scanf("%d", &accnumber);
        while (temp != 0)
        {
            // {    char new_address[200];
            if (temp->acc_number == accnumber)
            {
                struct node *temp1;
                temp1 = temp->next;
                printf("1.Are you sure to remove account\n");
                printf("Press 1 to remove\n");
                scanf("%d", &choice7);
                if (choice7 == 1)
                {
                    temp = head;
                    struct node *temp2;
                    while (temp->acc_number != accnumber)
                    {
                        temp2 = temp;
                        temp = temp->next;
                    }

                    temp2->next = temp1;

                    printf("\n");
                    printf("<--------------------System Updated Successfully-------------------->\n\n");
                }
            }
            else
                printf("You have entered wrong choice.\n");

            temp = temp->next;
        }
        printf("\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }


    else if (choice == 3)
    {
        temp = head;
        int choice2;
        int accnumber;
        printf("Enter your account number: ");
        scanf("%d", &accnumber);
        while (temp != 0)
        {
            // {    char new_address[200];
            if (temp->acc_number == accnumber)
            {
                printf("1.Want to update your address\n");
                printf("2.Want to update your phone number\n");
                scanf("%d", &choice2);
                if (choice2 == 1)
                {
                    printf("Enter your new address\n");
                    scanf("%s", temp->address);
                    printf("\n");
                    printf("<--------------------Account Updated Successfully-------------------->\n\n");
                }
                else if (choice2 == 2)
                {
                    printf("Enter your new number:\n");
                    scanf("%lld", &temp->phone_number);
                    printf("\n");
                    printf("<--------------------Account Updated Successfully-------------------->\n\n");
                }

                else
                    printf("You have entered wrong choice.\n");
                temp = temp->next;
            }
        }
        printf("\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }
    else if (choice == 4)
    {
        temp = head;
        int choice3;
        int accnumber = 0;
        long long int transac_money = 0;
        // printf("\n");
        printf("Enter your account number: ");
        scanf("%d", &accnumber);
        printf("\n\n");
        while (temp != 0)
        {
            // {    char new_address[200];
            if (temp->acc_number == accnumber)
            {
                printf("Press buttons according to your requirements\n");
                printf("1.To Deposit\n");
                printf("2.To Withdraw\n");
                scanf("%d", &choice3);
                printf("\n");
                if (choice3 == 1)
                {
                    printf("Enter the amount you want to depost: ");
                    scanf("%lld", &transac_money);
                    temp->deposit_money += transac_money;
                    printf("\n");
                    printf("<--------------------Account Updated Successfully-------------------->\n\n");
                }
                else if (choice3 == 2)
                {
                    printf("Enter the amount you want to withdraw: ");
                    scanf("%lld", &transac_money);
                    // printf("\n");
                    if (transac_money > temp->deposit_money)
                    {
                        printf("You don't have enough cash.\n");
                    }
                    else
                    {
                        temp->deposit_money -= transac_money;
                        printf("\n");
                        printf("<--------------------Account Updated Successfully-------------------->\n\n");
                    }
                }
                else
                    printf("You have entered wrong choice.\n");
            }
            temp = temp->next;
        }
        printf("\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }


else if (choice == 5)
    {
        if (a > 0 && b<2)
        {
            printf("S.no.\tName\t\tAccount number\t\tAccount Balance\t\tPhone Number");
            
        }
        else
            {
                temp = head;
            int sno = 1;
            //  printf("S.no.\t\tName\t\tAccount number\t\tAccount Balance\t\tPhone Number");
            //     printf("\n");
            int accnumber = 0;
            printf("Enter your account number: ");
            scanf("%d", &accnumber);
            printf("\n");
            while (temp != 0)
            {
                if (accnumber == temp->acc_number)
                {
                    temp->acc_number = accnumber;
                   printf("S.no.\t\t Name\t\t Account number\t\tAccount Balance\t\t Phone Number");
                    printf("\n");
                    printf("%d\t\t%s %s\t\t%d\t\t\t%lld\t\t %lld", sno, temp->first_name, temp->second_name, temp->acc_number, temp->deposit_money, temp->phone_number);
                break;
                }
                else
                {
                    printf("Entered account number doest not exist\n");
                }
                temp = temp->next;
                // sno++;
            }
            }

        printf("\n\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }



    else if (choice == 6)
    {
        if (a > 0 && b<2)
        {
            printf("S.no.\tName\t\tAccount number\t\tAccount Balance\t\tPhone Number");
            
        }
        else {
            temp = head;
            int sno = 1;
            printf("S.no.\t\t Name\t\t Account number\t\tAccount Balance\t\t Phone Number");
            printf("\n");
            while (temp != 0)
            {

                printf("%d\t\t%s %s\t\t%d\t\t\t%lld\t\t %lld", sno, temp->first_name, temp->second_name, temp->acc_number, temp->deposit_money, temp->phone_number);
                printf("\n");
                temp = temp->next;
                sno++;
            }
        }
        printf("\n\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }

else if(choice==7){
    goto exit;
}


    else
    {
        printf("You have entered wrong choice.\n\n");
        test = 0;
        printf("Enter 1 to go main menu or 0 to exit\n");
        scanf("%d", &test);

        if (test == 1)
        {
            printf("\n\n");
            goto mainmenu;
        }
        else
        {
            goto exit;
        }
    }

exit:
    temp = newnode;
}

int main()
{
    new_account();

    return 0;
}