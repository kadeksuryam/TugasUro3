#ifndef _MAKE_PERSON_H
#define _MAKE_PERSON_H

#include<stdio.h>
#include<stdlib.h>

//Struct
typedef struct{
	int healthReq, socialReq, hygienicReq, moneyReq, staminaReq;
}ActAttribute;

typedef struct{
	ActAttribute Makan;
	ActAttribute Tidur;
	ActAttribute Quiz;
	ActAttribute Dating;
	ActAttribute Mandi;
	ActAttribute Visiting;
	ActAttribute Excercise;
}activities;

typedef struct{
	int health, social, romance, hygienic, money, stamina;
	char name[100];
}Person;

// Selector
#define GetName(P) (P).name
#define Health(P) (P).health
#define Social(P) (P).social
#define Romance(P) (P).romance
#define Hygienic(P) (P).hygienic
#define Money(P) (P).money
#define Stamina(P) (P).stamina
#define Makan(P) (P).Makan
#define Tidur(P) (P).Tidur
#define Quiz(P) (P).Quiz
#define Dating(P) (P).Dating
#define Mandi(P) (P).Mandi
#define Visiting(P) (P).Visiting
#define Excercise(P) (P).Excercise
#define HealthReq(P) (P).healthReq
#define SocialReq(P) (P).socialReq
#define HygienicReq(P) (P).hygienicReq
#define MoneyReq(P) (P).moneyReq
#define StaminaReq(P) (P).staminaReq

//Konstruktor
void makePerson(Person *Unnamed);

#endif
