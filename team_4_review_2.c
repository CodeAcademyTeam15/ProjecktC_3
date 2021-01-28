/*Трябва да направите софтуер за заявки на хотел. Хотелът има два типа стаи - Луксозна, с цена 180 лв на нощ,
Стандартна -120 лв на нощ. Туристическият данък е 6%. Направете програма, която калкулира очаквана себестойност
за клиентите в зависимост от брой нощувки и стаи, и я отпечатва на екрана. Валидността на офертата е 14 дни.
Продължение1:
▪Ако клиентът заяви повече от 5 нощувки, независимо в какви и колко стаи, получава 15% отстъпка от цената.
Продължение 2:
▪Ако клиентът направи оборот без данък повече от 700 лв за нощувки общо може да избира, дали да получи 15%
отстъпка или да получи спа процедура за 100 лв.
▪След като клиентът направи своя избор, трябва да отпечатате цялото предложение на екран.
Продължение 3:
▪Ако клиентът заяви нощувки за повече от 1000 лв. общо, може да избира между:
▪20% отстъпка
▪Спа процедура на стойност 200 лв
▪2 Безплатни вечери за семейството
След като клиентът заяви своя избор, трябва да отпечатате финалната оферта на екран.*/

#include <stdio.h>
#include <stdlib.h>
const float c_fPRICE_STANDART = 120.00F;
const float c_fPRICE_LUX = 180.00F;
const float c_fDISCOUNT_FIFTEEN = 0.85F;
const float c_fDISCOUNT_TWENTY = 0.80F;
const float c_fTOURIST_FEE = 1.06F;

int iNumOfStandart, iNumOfLux, iNumOfNights, iNumNightsStandart, iNumNightsLux;
float fTotalWithoutTF;
float fAssignedDiscount = 1.00F;
char *assignedBonusName;

int getChoice(int n);
float getTotal(void);
float calculateTotalWithoutTF();
void printOrder(void);
void hotelMenu(void);

int main(void){
    hotelMenu();
    return 0;
}

void hotelMenu(){
    printf("Welcome to \"The MAN`s Hotel\"(Martin Anton Nikolay)!\nYou can choose between Standart and Luxury rooms.\n");
    printf("How many standart rooms would you like?(120 lv. per room for one night)\n");
    scanf("%d", &iNumOfStandart);
    printf("How many nights do you want to book?(120 lv. per room for one night)\n");
    scanf("%d", &iNumNightsStandart);
    printf("How many lux rooms would you like?(180 lv. per room for one night)\n");
    scanf("%d", &iNumOfLux);
    printf("How many nights would you like to book?(180 lv. per room for one night)\n");
    scanf("%d", &iNumNightsLux);
    calculateTotalWithoutTF();
    iNumOfNights = iNumNightsStandart + iNumNightsLux;
    if (iNumOfNights >= 5 && fTotalWithoutTF < 700){
        fAssignedDiscount = c_fDISCOUNT_FIFTEEN;
        assignedBonusName = "15% discount";
        printOrder();
    }
    else if (fTotalWithoutTF >= 700 && fTotalWithoutTF < 1000){
        printf("Because your bill is over 700 lv. you get to choose between two discounts.\n");
        printf("1. 15 %% discount on the bill.(press 1)\n");
        printf("2. Spa procedures for 100lv.(press 2)\n");
        int iChoise = getChoice(2);
        switch (iChoise){
        case 1:
            fAssignedDiscount = c_fDISCOUNT_FIFTEEN;
            assignedBonusName = "15% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 100lv";
            printOrder();
            break;
        }
    }
    else if (fTotalWithoutTF >= 1000){
        printf("Because your bill is over 1000 lv. you get to choose between three discounts. \n");
        printf("1. 20 %% discounton the bill.(press 1) \n");
        printf("2. Spa procedures for 200lv.(press 2) \n");
        printf("3. Two family dinners for free.(press 3) \n");
        int iChoise = getChoice(3);
        switch (iChoise){
        case 1:
            fAssignedDiscount = c_fDISCOUNT_TWENTY;
            assignedBonusName = "20% discount";
            printOrder();
            break;

        case 2:
            assignedBonusName = "Spa procedures for 200 lv.";
            printOrder();
            break;
        case 3:
            assignedBonusName = "Two free dinners";
            printOrder();
            break;
        }
    } else {
        assignedBonusName = "no discounts";
        printOrder();
    }
}

int getChoice(int n){
    int iChoise;
    do{
        printf("Please enter a number from 1 to %d\n", n);
        scanf("%d", &iChoise);
    } while (iChoise < 1 || iChoise > n);
    return iChoise;
}

float getTotal(){
    return fTotalWithoutTF * fAssignedDiscount * c_fTOURIST_FEE;
}

float calculateTotalWithoutTF(){
    fTotalWithoutTF = (iNumNightsLux * iNumOfLux * c_fPRICE_LUX) + (iNumNightsStandart * iNumOfStandart * c_fPRICE_STANDART);
    return fTotalWithoutTF;
}

void printOrder(){
    printf("Your offer includes %d Standart rooms for %d nights and %d Luxury rooms for %d nights "
           "for the total price of %.2f lv.\n",
           iNumOfStandart, iNumNightsStandart, iNumOfLux, iNumNightsLux, getTotal());
    printf("Assigned discount: %s \n", assignedBonusName);
    printf("There is a 6 %% Tourist fee included!\n");
    printf("The offer is valid for 14 days!\n");
    printf("The number of your offer is %d!", rand());
}
