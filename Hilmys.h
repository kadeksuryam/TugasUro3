#ifndef _HILMYS_H
#define _HILMYS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
/*
#define Makan(P) (P).Makan
#define Tidur(P) (P).Tidur
#define Mandi(P) (P).Mandi */

#define HealthReq(P, i) (P).healthReq = i
#define HygienicReq(P) (P).hygienicReq = i
#define MoneyReq(P, i) (P).moneyReq = i
#define SocialReq(P, i) (P).socialReq = i

//Konstruktor
void kurangStat(Person *Hilmys, int health, int social, int hygienic, int money);
void tambahStat(Person *Hilmys, int health, int social, int hygienic, int money);
bool isEnough(int param, int userVal);
void init(Person *Hilmys, activities *Act,  int val);
void doMakan(Person *Hilmys, activities *Act);
void doTidur(Person *Hilmys, activities *Act);
void doMandi(Person *Hilmys, activities *Act);


#endif
