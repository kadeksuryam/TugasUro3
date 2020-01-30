#ifndef _HILMYS_H
#define _HILMYS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//====================Konstruktor======================

//Atribut dari aktivitas
typedef struct{
	int healthReq, hygienicReq, moneyReq, socialReq;
}ActAttribute; 

//Kumpulan Aktivitas
typedef struct{
	ActAttribute Makan;
	ActAttribute Tidur;
	ActAttribute MCK;
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




//===============Fungsi/Prosedur Tambahan========================

int mini(int a, int b);

//Bagian Stat
bool cekLosing(Person *Hilmys);
bool cekWinning(Person *Hilmys);
void printStat(Person *Hilmys, activities *Act);
void kurangStat(Person *Hilmys, int health, int social, int hygienic, int money);
void tambahStat(Person *Hilmys, int health, int social, int hygienic, int money);
bool isEnoughStat(int param, int userVal);
void pilihKegiatan(Person *Hilmys, activities *Act);

//Bagian inisialisasi awal
void init(Person *Hilmys, activities *Act,  int val);

//Bagian Kegiatan
void doTidur(Person *Hilmys, activities *Act);
void doMakan(Person *Hilmys, activities *Act);
void doMCK(Person *Hilmys, activities *Act);



#endif
