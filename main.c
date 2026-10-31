#include<stdio.h>
int main(){
    printf("Welcome to RBI Bank\n");
    int balance=10000,amount,password,attempts=0,choice,login=0;
    char rec;
    while(attempts<3){
        printf("Enter your 4 digit password: ");
        if(scanf("%d",&password)!=1)return 1;
        attempts++;
        if(password>=1000&&password<=9999){
            printf("Login Successful!!!\n");
            login=1;
            break;
        }else{
            printf("Invalid Password. It should be 4 digits.\n");
        }
    }
    if(login==0){
        printf("Access denied due to many login attempts.\n");
        return 0;
    }
    do{
        printf("RBI ATM Display\n");
        printf("1. Withdraw the amount\n");
        printf("2. Check the bank balance\n");
        printf("3. Deposit the amount\n");
        printf("4. Exit from the system\n");
        printf("Enter the choice: ");
        if(scanf("%d",&choice)!=1)return 1;
        switch(choice){
            case 1:
                printf("Enter the amount to withdraw: ");
                if(scanf("%d",&amount)!=1)return 1;
                if(amount<500||amount>5000){
                    printf("Withdrawal amount must be between 500 and 5000.\n");
                }else if(amount>balance){
                    printf("Insufficient balance.\n");
                }else{
                    balance-=amount;
                    printf("Withdrawal successful.\n");
                    printf("Remaining balance: %d\n",balance);
                    printf("Do you want a receipt (y/n)? ");
                    scanf(" %c",&rec);
                    if(rec=='y'||rec=='Y')printf("Receipt: Withdrawn amount = %d, Balance = %d\n",amount,balance);
                    else if(rec=='n'||rec=='N')printf("Receipt not required.\n");
                    else printf("Invalid receipt choice.\n");
                }
                break;
            case 2:
                printf("Current bank balance: %d\n",balance);
                break;
            case 3:
                printf("Enter the amount to deposit: ");
                if(scanf("%d",&amount)!=1)return 1;
                if(amount<=0){
                    printf("Invalid deposit amount.\n");
                }else{
                    balance+=amount;
                    printf("Deposit successful.\n");
                    printf("Current balance: %d\n",balance);
                    printf("Do you want a receipt (y/n)? ");
                    scanf(" %c",&rec);
                    if(rec=='y'||rec=='Y')printf("Receipt: Deposited amount = %d, Balance = %d\n",amount,balance);
                    else if(rec=='n'||rec=='N')printf("Receipt not required.\n");
                    else printf("Invalid receipt choice.\n");
                }
                break;
            case 4:
                printf("Thank you for using RBI Bank ATM.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=4);
    return 0;
}