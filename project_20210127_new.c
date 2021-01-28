#include <stdio.h>
#include <ctype.h>

const double dPriceStandart = 120.00F;
const double dPriceLux = 180.00F;
const double dDiscountFifteen = 0.85F;
const double dDiscountTwenty = 0.80F;
const double dTouristFee = 1.06F;
const char cNumForDiscount = 5;
/*
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв на нощ, Стандартна -120 лв на нощ. Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност за клиентите в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение1:
▪Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
▪Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15% отстъпка или да получи спа процедура за 100 лв.
▪След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
▪Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
▪20% отстъпка
▪Спа процедура на стойност 200 лв
▪2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран. 
*/

extern int iNumOfStandardNights;
extern int iNumOfLuxNights;
extern int iNumOfStandard;
extern int iNumOfLux;
extern char cChosenDiscount;

void menu(void);
void roomOptions(int choice);
void getNights(int *Rooms, int *Nights);
double calculateTotalWithTF(void);
double calculateTotalWithoutTF(void);
void printCur(void);
void printOrder(void);
void extraGift(char cSwitch);



int main(void){

    printf("Welcome to \"The MAN`s Hotel\"\n");

    menu();
    return 0;
}


void menu(void){
    char choice;

    printf("\nFor standart room press 1,\n"
        "for luxury room press 2,\n"
        "to proceed with order press 3,\n"
        "to quit order press 4!\n");

    scanf("%d",&choice);
    while((choice<1||choice>4) && isalpha(choice)){
        printf("Please choose one of the above options\n");
        fflush(stdin);
        scanf("%d",&choice);
    }

    roomOptions(choice);
}


void roomOptions(int choice){
    switch(choice){
        case 1:
            getNights(&iNumOfStandard, &iNumOfStandardNights);
            break;
        case 2:
            getNights(&iNumOfLux, &iNumOfLuxNights);
            break;
        case 3:
            printOrder();
            break;
        case 4:
            printf("Have a nice day!\n");
            return;
        default:
            printf("Ooops something went wrong please try again!\n");
            return;
    }

    printCur();

    char cMenu;
    printf("To go to booking press 1\n"
        "To go to offer press 2\n"
        "To exit press another button\n");
    scanf("%d",&cMenu);

    switch(cMenu){
        case 1:
            menu();
            break;
        case 2: 
            printOrder();
            break;
        default:
            printf("Have a nice day!\n");
            return;
    }

}


void getNights(int *Rooms,int *Nights){
    int addNights,addRooms;

    do{
        printf("How many rooms would you like?(Up to 200): ");
        fflush(stdin);
        scanf("%d",&addRooms);
    }while(addRooms<0);

    *Rooms+=addRooms;

    do{
        printf("How many nights would you like to stay?(Up to 1095): ");
        fflush(stdin);
        scanf("%d",&addNights);
    }while(addNights<0);

    *Nights+=addRooms*addNights;

}


void printCur(){
    printf("You have booked %d standard rooms for a total of %d nights\n"
        "and %d lux rooms for a total of %d nights\n"
        "Total price without tourist fee: %.2lf\n"
        "Total price with tourist fee: %.2lf\n\n",
        iNumOfStandard, iNumOfStandardNights, iNumOfLux, iNumOfLuxNights,
        calculateTotalWithoutTF(),calculateTotalWithTF());
}

double calculateTotalWithTF(void){
    double cost=0;

    cost=calculateTotalWithoutTF()*dTouristFee;

    return cost;
}


double calculateTotalWithoutTF(void){
    double cost=0;

    cost += dPriceStandart*iNumOfStandardNights;
    cost += dPriceLux*iNumOfLuxNights;

    return cost;
}

void printOrder(void){
    double totalPrice=calculateTotalWithoutTF();

    if(totalPrice>1000){
        extraGift(1);
    }else if(totalPrice>700){
        extraGift(2);
    }

    if(iNumOfStandardNights+iNumOfLuxNights>cNumForDiscount){
        totalPrice*=dDiscountFifteen;
    }



    printf("You have booked %d standard rooms for a total of %d nights\n"
        "and %d lux rooms for a total of %d nights\n",
        iNumOfStandard, iNumOfStandardNights, iNumOfLux, iNumOfLuxNights);

    switch(cChosenDiscount){
        case 5:
            totalPrice*=dDiscountFifteen;
            printf("You have chosen a bonus: 15%% extra discount\n");
            break;
        case 6:
            printf("You have chosen a bonus: Spa for 100\n");
            break;
        case 7:
            totalPrice*=dDiscountTwenty;
            printf("You have chosen a bonus: 20%% extra discount\n");
            break;
        case 8:
            printf("You have chosen a bonus: Spa for 200\n");
            break;
        case 9:
            printf("You have chosen a bonus: 2 free family dinners\n");
            break;
        default:
            break;
    }

    totalPrice*=dTouristFee;

    printf("Total price with tourist fee is: %.2lf\n", totalPrice);
    printf("The offer is valid for 14 days!\n");
}

void extraGift(char cSwitch){
    int n=0, choice=0;

    switch (cSwitch)
    {
    case 1:
        n=3;
        printf("You can choose one of the following:\n"
            "20%% discount (press 1)\n"
            "Spa for 200 (press 2)\n"
            "2 free family dinners (press 3)\n");
        break;
    case 2:
        n=2;
        printf("You can choose one of the following:\n"
            "15%% discount (press 1)\n"
            "Spa for 100 (press 2)\n");
            
        break;
    default:
        return;
    }

    scanf("%d",&choice);

    while(choice<1||choice>n){
        printf("Please choose a valid number\n");
        fflush(stdin);
        scanf("%d",&choice);
    }

    cChosenDiscount=(n*2)+choice;
}


int iNumOfStandardNights = 0;
int iNumOfLuxNights = 0;
int iNumOfStandard = 0;
int iNumOfLux = 0;
char cChosenDiscount=0;