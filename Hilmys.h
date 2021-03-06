#ifndef _HILMYS_H
#define _HILMYS_H

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//====================Konstruktor======================

//Atribut dari aktivitas
typedef struct{
	int healthReq, hygienicReq, moneyReq, socialReq, happinessReq;
}ActAttribute; 

//Kumpulan Aktivitas
typedef struct{
	ActAttribute Makan;
	ActAttribute Tidur;
	ActAttribute MCK;
	ActAttribute bkj; //Berkunjung ke rumah tetangga
	ActAttribute Gambling;
	ActAttribute Olahraga;
	ActAttribute NontonAnime;
	ActAttribute Quiz;
	ActAttribute pancing; // Memancing
	ActAttribute pmdA;	//ke Pemandian Air Panas
}activities; 

//Stats Hilmys's
typedef struct{
	int health, social, hygienic, money, happiness;
}Person; 



//=====================Selector=========================


//Bagian penyingkat, mungkin nanti ditambah lagi, supaya lebih modular...
#define Health(P) (P).health
#define Hygienic(P) (P).hygienic
#define Money(P) (P).money
#define Social(P) (P).social
#define Happiness(P) (P).happiness



//===============Fungsi/Prosedur Tambahan========================

int mini(int a, int b);

//Bagian Stat
bool cekLosing(Person *Hilmys);
bool cekWinning(Person *Hilmys);
void printStat(Person *Hilmys, activities *Act);
void kurangStat(Person *Hilmys, int health, int social, int hygienic, int money, int happiness);
void tambahStat(Person *Hilmys, int health, int social, int hygienic, int money, int happiness);
bool isEnoughStat(int param, int userVal);
void pilihKegiatan(Person *Hilmys, activities *Act);

//Bagian inisialisasi awal
void init(Person *Hilmys, activities *Act,  int val);

//Bagian Kegiatan
void doTidur(Person *Hilmys, activities *Act); //Health
void doMakan(Person *Hilmys, activities *Act); //Health
void doMCK(Person *Hilmys, activities *Act); //Health
void doBerkunjung(Person *Hilmys, activities *Act); //Social
void doGambling(Person *Hilmys, activities *Act); //Money
void doOlahraga(Person *Hilmys, activities *Act); //Happiness
void doNontonAnime(Person *Hilmys, activities *Act);
void doQuiz(Person *Hilmys, activities *Act);
void doPemandianAirPanas(Person *Hilmys, activities *Act); //Health, Happines, Hygienic
void doMemancing(Person *Hilmys, activities *Act); //Happines, money, social

//Bagian Side Game
void tebakAngka(Person *Hilmys);
void sticksGame(Person *Hilmys);
void soal(Person *Hilmys);


#endif
