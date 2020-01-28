#ifndef _HILMYS_H
#define _HILMYS_H

#include<stdio.h>
#include<stdlib.h>

//Struct
typedef struct{
	int healthReq, hygienicReq, moneyReq, socialReq;
}ActAttribute;

typedef struct{
	ActAttribute Makan;
	ActAttribute Tidur;
	ActAttribute Mandi;
}activities;

typedef struct{
	int health, social, hygienic, money;
}Person;

// Selector
#define Health(P) (P).health
#define Hygienic(P) (P).hygienic
#define Money(P) (P).money
#define Social(P) (P).social
#define Makan(P) (P).Makan
#define Tidur(P) (P).Tidur
#define Mandi(P) (P).Mandi
#define HealthReq(P) (P).healthReq
#define HygienicReq(P) (P).hygienicReq
#define MoneyReq(P) (P).moneyReq
#define SocialReq(P) (P).socialReq

//Konstruktor
void init(Person *Hilmys, int val);
void doMakan(Person *Hilmys);
void doTidur(Person *Hilmys);
void doMandi(Person *Hilmys);

#endif
