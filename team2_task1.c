#include <stdio.h>


/*
Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна - цена 180 лв на нощ, Стандартна - 120 лв на нощ. 
Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност за клиентите в зависимост от брой нощувки и стаи, 
и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение1:
▪Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
▪Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15% отстъпка или да получи спа
процедура за 100 лв.
▪След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
▪Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
▪20% отстъпка
▪Спа процедура на стойност 200 лв
▪2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран. 
*/


const float c_fPriceStandart = 120.00F;
const float c_fPriceLux = 180.00F;
const float c_fDiscountFifteen = 0.85F;
const float c_fDiscountTwenty = 0.80F;
const float c_fTouristFee = 1.06F;

int iNumOfStandart;
int iNumOfLux;
int iNumOfNights;

float iTotalWithoutTF;
char *assignedBonusName;
float assignedDiscount = 1.00F;


int getChoice(int n);
float getTotal();
void calculateTotalWithoutTF();
void printOrder();
int menu();

int main(void){

    menu();

    return 0;
}

int getChoice(int n){
    int iChoise;
    do
    {
        printf("Please enter number from 1 to %d\n", n);
        scanf("%d", &iChoise);
    } while (iChoise < 1 || iChoise > 3);
    return iChoise;
}

float getTotal(){
    float priceDisc = iTotalWithoutTF * assignedDiscount;
    return priceDisc * c_fTouristFee;
}

void calculateTotalWithoutTF(){
    iTotalWithoutTF = ((iNumOfNights * iNumOfLux * c_fPriceLux) + (iNumOfNights * iNumOfStandart * c_fPriceStandart));
}

void printOrder(){
    printf("\nYour offer includes %d Standart rooms, %d Luxury Rooms, "
           "for %d nights for the total price of %.2f lv.\n",
           iNumOfStandart, iNumOfLux, iNumOfNights, getTotal());
    printf("Assigned discount: %s \n", assignedBonusName);
    printf("In the price there is 6 %% Tourist fee included!\n");
    printf("The offer is valid for 14 days!\n");
    /* printf("The number of your offer is %d!\n", rand()); */
}

int menu(){

    printf("Welcome to \"The MAN`s Hotel\"(Martin Anton Nikolay)!\n");
    printf("How many standart rooms would you like?(120 lv. per room for one night)");
    scanf("%d", &iNumOfStandart);
    printf("How many lux rooms would you like?(180 lv. per room for one night)");
    scanf("%d", &iNumOfLux);

    if((iNumOfStandart || iNumOfLux) != 0){
        printf("For how many nights?");
        scanf("%d", &iNumOfNights);
        calculateTotalWithoutTF();
    } else {
        printf("Bye. HAve a nice day.\n");
        return 0;
    }

    if (iNumOfNights >= 5 && iTotalWithoutTF < 700){
        assignedDiscount = c_fDiscountFifteen;
        assignedBonusName = "15% discount";
        printOrder();
    }
    else if (iTotalWithoutTF >= 700 && iTotalWithoutTF < 1000){
        printf("Because your bill is over 700 lv. you get to choose between two discounts. \n");
        printf("1. 15 %% discounton the bill.(press 1) \n");
        printf("2. Spa procedures for 100lv.(press 2) \n");
        int iChoise = getChoice(2);
        switch (iChoise){
        case 1:
            assignedDiscount = c_fDiscountFifteen;
            assignedBonusName = "15% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 100lv";
            printOrder();
            break;
        }
    }
    else if (iTotalWithoutTF >= 1000){
        printf("Because your bill is over 1000 lv. you get to choose between three discounts. \n");
        printf("1. 20 %% discounton the bill.(press 1) \n");
        printf("2. Spa procedures for 200lv.(press 2) \n");
        printf("3. Two free diners.(press 3) \n");
        int iChoise = getChoice(3);
        switch (iChoise){
        case 1:
            assignedDiscount = c_fDiscountTwenty;
            assignedBonusName = "20% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 200 lv.";
            printOrder();
            break;
        case 3:
            assignedBonusName = "Two free diners";
            printOrder();
            break;
        }
    } else {
        assignedBonusName = "no discounts";
        printOrder();
    }
}