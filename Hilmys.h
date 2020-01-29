#ifndef _HILMYS_H
#define _HILMYS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//====================Struct======================

//Atribut dari aktivitas
typedef struct{
	int healthReq, hygienicReq, moneyReq, socialReq;
}ActAttribute; 

//Kumpulan Aktivitas
typedef struct{
	ActAttribute Makan;
	ActAttribute Tidur;
	ActAttribute Mandi;
}activities; 

//Stats Hilmys's
typedef struct{
	int health, social, hygienic, money;
}Person; 



//=====================Selector=========================


//Bagian penyingkat, mungkin nanti ditambah lagi, supaya lebih modular...
#define Health(P) (P).health
#define Hygienic(P) (P).hygienic
#define Money(P) (P).money
#define Social(P) (P).social




//===============Konstruktor========================

//Bagian fungsi/prosedur tambahan
int mini(int a, int b);

//Bagian Stat
bool cekLosing(Person *Hilmys);
bool cekWinning(Person *Hilmys);
void printStat(Person *Hilmys, activities *Act);
void kurangStat(Person *Hilmys, int health, int social, int hygienic, int money);
void tambahStat(Person *Hilmys, int health, int social, int hygienic, int money);
bool isEnoughStat(int param, int userVal);

//Bagian inisialisasi awal
void init(Person *Hilmys, activities *Act,  int val);

//Bagian Kegiatan
void doMakan(Person *Hilmys, activities *Act);
void doTidur(Person *Hilmys, activities *Act);
void doMandi(Person *Hilmys, activities *Act);


#endif
