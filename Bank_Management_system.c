#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_NUMBER 100

int admin_option();
int client_option();

void view_customer_list();
void create_acc();
void print_welcome(char *field_name);
int make_deposit(float client_balance);
int make_withdraw(float client_balance);
int id_check(int id);
int valid_id(int id);

int main()
{

    // Admin Numeric Variables
    int admin_pass_in;
    int admin_pass = 12345;

    // Admin Char Variables
    char is_admin;
    // Admin String Variables

    // Client Numeric Variables
    int client_pass_in, cl_choice, user_id;

    // Client  array
    char client_name[10][32] = {"ABDULLAH AL SAKIB", "TONG JIAN HAO", "CHONG JIEN SHENG", "Adam Omar bin Keni", "Harish", "WONG JING XIANG", "Lena Ramsey", "Elon Musk", "Jeff Bezos", "Bill Gates"};
    char client_ph_num[10][20] = {"+214141", "+148104", "+2437294", "+145141", "+1414143", "+234141", "+9036963", "+1548329", "+2847245", "+4125342"};
    long long int client_ID[10] = {1001, 1002, 1003, 1004, 1005, 1006, 1007, 1008, 1009, 1010};
    float client_balance[10] = {10000, 6969, 3000, 6000, 5000, 0, 0, 5000, 4000, 2000};
    int client_pass[10] = {1111, 2222, 3333, 4444, 5555, 6666, 7777, 8888, 9999, 1010};

    printf("\n                                             +-+-+-+-+-+  +-+-+-+-+                            ");
    printf("\n                                             |H|G|P|T|A| 	|B|A|N|K|                            ");
    printf("\n                                             +-+-+-+-+-+  +-+-+-+-+                            ");
    printf("\n                                               Management System                               ");
    printf("\n\n\n\n");

    // ADMIN QUESTION
    printf("Are You an Admin?[Y/N] : ");
    scanf("%c", &is_admin);

    // ADMIN
    if (is_admin == 'Y' || is_admin == 'y')
    {

        int count = 3;
        int i;
        for (i = 0; i < count; i++)

        {
            print_welcome("ADMIN PORTAL");
            printf("\nInput password: ");
            scanf("%d", &admin_pass_in);

            if (admin_pass_in == admin_pass)
            {
                int ad_choice = admin_option();
                switch (ad_choice)
                {
                case 1:
                    create_acc();
                    exit(1);
                    break;
                case 2:
                    view_customer_list();
                    exit(1);
                    break;
                case 3:
                    exit(1);
                    break;

                default:
                    exit(1);
                    break;
                }
            }
            else
            {
                printf("Wrong password");
            }
            printf("\n");
        }
    }

    // client
    if (is_admin == 'N' || is_admin == 'n')
    {

        int count = 3;
        int i;
        for (i = 0; i < count; i++)

        {
            print_welcome("CLIENT PORTAL");
            printf("\nInput User ID: ");
            scanf("%d", &user_id);

            int num = id_check(user_id);
            num = valid_id(num);
            print_welcome(client_name[num]);
            printf("\nPlease enter your password: ");
            scanf("%d", &client_pass_in);

            if (client_pass_in == client_pass[num])

            {
                cl_choice = client_option();
                switch (cl_choice)
                {
                case 1:
                    print_welcome("USER INFORMAITON");
                    printf("\nUser Name   :   %s", client_name[num]);
                    printf("\nUser ID     :   %d", client_ID[num]);
                    printf("\nUser Cash   :   %.2f", client_balance[num]);
                    printf("\nUser Phone number: %s", client_ph_num[num]);
                    break;
                case 2:
                    print_welcome("USER NAME");
                    printf("\nUser Name   :   %s", client_name[num]);
                    printf("\nUser Cash   :   %.2f", client_balance[num]);
                    break;
                case 3:
                    make_deposit(client_balance[num]);
                    break;
                case 4:
                    make_withdraw(client_balance[num]);
                    break;
                case 5:
                    break;

                default:
                    break;
                }
            }
            else
            {

                printf("Wrong password");
            }
            printf("\n");
        }
    }

    return 0;
}

int admin_option()
{
    int ad_choice;
    printf("\n");
    printf("\n -------------------------------------------------------------------------------");
    printf("\n                        WELCOME TO THE HGPTA BANK MAIN MENU                      ");
    printf("\n -------------------------------------------------------------------------------");
    printf("\n");
    printf("\n                      1.  Create new account");
    printf("\n                      2.  View customer's list ");
    printf("\n                      3.  Exit ");
    printf("\n\n");

    printf("Please select your choice : ");
    scanf("%d", &ad_choice);
    if (ad_choice < 4 && ad_choice > 0)
        return ad_choice;
    else
        return 3;
}

void create_acc()
{
    char name[50], birth[15], mail[50], gendertype[10], depo, deposit, ic_no[20], phone[15];
    int gender;
    FILE *f1 = fopen("name.txt", "wb");
    FILE *f2 = fopen("Passport.txt", "wb");
    FILE *f3 = fopen("birth.txt", "wb");
    FILE *f4 = fopen("mail.txt", "wb");
    FILE *f5 = fopen("phone.txt", "wb");

    printf("\nEnter Your Name     : ");
    fflush(stdin);
    scanf("%[^\n]", &name);
    fscanf(f1, "%c", name);
    fputs(name, f1);
    fclose(f1);
    fflush(stdin);
    printf("Enter IC/Passport no. : ");
    scanf("%c", &ic_no);
    fscanf(f2, "%c", ic_no);
    fputs(ic_no, f2);
    fclose(f2);
    printf("Enter Your Birthdate  : ");
    fflush(stdin);
    scanf("%[^\n]", &birth);
    fscanf(f3, "%c", birth);
    fputs(birth, f3);
    fclose(f3);
    fflush(stdin);
    printf("Enter Your Email      : ");
    fflush(stdin);
    scanf("%[^\n]", &mail);
    fscanf(f4, "%c", mail);
    fputs(mail, f4);
    fclose(f4);
    fflush(stdin);
    printf("Enter Your Phone no.  : ");
    scanf("%c", &phone);
    fscanf(f5, "%c", phone);
    fputs(phone, f5);
    fclose(f5);
    printf("\nChoose Your Gender [TYPE 1 For Male || TYPE 2 For Female] : ");
    scanf("%d", &gender);
    fflush(stdin);

    switch (gender)
    {
    case 1:
        strcpy(gendertype, "Male");
        break;

    case 2:
        strcpy(gendertype, "Female");
        break;

    default:
        strcpy(gendertype, "Invalid");
    }

    printf("\nDo You Have Deposit Of Minimum RM200?      [Y/N]          : ");
    scanf("%c", &depo);
    fflush(stdin);
    if (depo == 'Y' || depo == 'y')
    {
        printf("\n ------------------------------------------");
        printf("\n     Succesfully Created New Account       ");
        printf("\n ------------------------------------------");
        printf("\n Name            : %s", name);
        printf("\n IC/Passport no. : %d", ic_no);
        printf("\n Birthdate       : %s", birth);
        printf("\n Gender          : %s", gendertype);
        printf("\n Email           : %s", mail);
        printf("\n Phone no.       : %d", phone);
        printf("\n ------------------------------------------");
        printf("\n     Thank You For Choosing HGST Bank      ");
        printf("\n ------------------------------------------");
    }

    else if (depo == 'N' || depo == 'n')
    {
        printf("\n ------------------------------------------");
        printf("\n            Transection cancelled.         ");
        printf("\n ------------------------------------------");
        printf("\n ------------------------------------------");
        printf("\n     Thank You For Choosing HGST Bank      ");
        printf("\n ------------------------------------------");
    }

    else
    {
        printf(" Error");
    }
}

void view_customer_list()
{
    FILE *fp;
    FILE *fp2;
    char line[LINE_NUMBER], *name;
    int i;

    fp2 = fopen("ClientName.txt", "r");

    printf("\n");
    for (i = 0; i < 68; i++)
    {
        name = fgets(line, LINE_NUMBER, fp2);
        printf("%s", name);
    }

    fclose(fp2);
}

int client_option()
{
    int cl_choice;
    float deposit, withdraw;
    printf("\n");
    printf("\n -------------------------------------------------------------------------------");
    printf("\n                        WELCOME TO THE HGSTA BANK MAIN MENU                      ");
    printf("\n -------------------------------------------------------------------------------");
    printf("\n");
    printf("\n                      1.  Check User Information");
    printf("\n                      2.  Check Balance");
    printf("\n                      3.  Make a deposit");
    printf("\n                      4.  Withdraw amount");
    printf("\n                      5.  Exit ");
    printf("\n\n");

    printf("Please select your choice : ");
    scanf("%d", &cl_choice);
    if (cl_choice < 6 && cl_choice > 0)
        return cl_choice;
    else
        return 5;
}

int make_deposit(float client_balance)
{
    float deposit;

    printf("\nEnter the amount you wish to deposite :");
    scanf("%f", &deposit);

    printf("\nThe amount before : %.2f", client_balance);

    client_balance = client_balance + deposit;

    printf("\nThe amount of deposit : %.2f", deposit);
    printf("\nTotal Balance         : %.2f", client_balance);

    printf("\n\n---Deposited successfully---\n");
}

int make_withdraw(float client_balance)
{
    float withdraw;

    printf("\nEnter the amount you wish to withdraw :");
    scanf("%f", &withdraw);

    printf("\nThe amount before : %.2f", client_balance);

    client_balance = client_balance - withdraw;

    printf("\nThe amount withdrawed : RM %.2f", withdraw);
    printf("\nTotal Balance         : RM %.2f", client_balance);

    printf("\n\n---Withdrawed successfully---\n");
}

int id_check(int id)
{
    int num = id;
    int array_item_no = 0;
    switch (num)
    {
    case 1001:
        array_item_no = 0;
        break;
    case 1002:
        array_item_no = 1;
        break;
    case 1003:
        array_item_no = 2;
        break;
    case 1004:
        array_item_no = 3;
        break;
    case 1005:
        array_item_no = 4;
        break;
    case 1006:
        array_item_no = 5;
        break;
    case 1007:
        array_item_no = 6;
        break;
    case 1008:
        array_item_no = 7;
        break;
    case 1009:
        array_item_no = 8;
        break;
    case 1010:
        array_item_no = 9;
        break;

    default:
        array_item_no = 12;
        break;
    }
    return array_item_no;
}

int valid_id(int id)
{
    int input;
    if (id <= 10)
    {
        return id;
    }
    else
    {
        printf("invalid ID please!! enter the correct");
        scanf("%d", &input);
        id = id_check(input);
        return id;
    }
}

void print_welcome(char *field_name)
{
    printf("\n ------------------------------------------");
    printf("\n             %s              ", field_name);
    printf("\n ------------------------------------------\n\n");
}
