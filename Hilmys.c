#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "Hilmys.h"

int mini(int a, int b){
	if(a <= b) return a;
	else return b;
}

void kurangStat(Person *Hilmys, int health, int social, int hygienic, int money){
	Health(*Hilmys) -= health;
	Social(*Hilmys) -= social;
	Hygienic(*Hilmys) -= hygienic;
	Money(*Hilmys) -= money;
}

void tambahStat(Person *Hilmys, int health, int social, int hygienic, int money){
	Health(*Hilmys) = mini(health+Health(*Hilmys), 100);
	Social(*Hilmys) = mini(social+Social(*Hilmys), 100);
	Hygienic(*Hilmys) = mini(hygienic+Hygienic(*Hilmys), 100);
	Money(*Hilmys) = mini(money+Money(*Hilmys), 100);
}

bool isEnough(int userVal, int param){
	if(userVal < param) return false;
	return true;
}

void init(Person *Hilmys, activities *Act, int val){
	//Inisialisasi Stat Awal Hilmys
		//Mulai
		Health(*Hilmys) = val;
		Social(*Hilmys) = val;
		Hygienic(*Hilmys) = val;
		Money(*Hilmys) = val;
		//Selesai
	//Inisialisasi Activities
		//inisialisasi aktivitas Tidur
		(*Act).Tidur.healthReq = 0; 
		(*Act).Tidur.socialReq = 0;
		(*Act).Tidur.hygienicReq = 0;
		(*Act).Tidur.moneyReq = 0;
		
		//inisialisasi aktivitas Makan 
		(*Act).Makan.healthReq = 5; //untuk makan perlu sehat dan ada uang
		(*Act).Makan.socialReq = 0;
		(*Act).Makan.hygienicReq = 0; 
		(*Act).Makan.moneyReq = 5;
		
		//inisialisasi aktivitas Mandi
		(*Act).Mandi.healthReq = 5; //untuk mandi perlu sehat dan ada uang buat beli sabun :v
		(*Act).Mandi.socialReq = 5;
		(*Act).Mandi.hygienicReq = 5;
		(*Act).Mandi.moneyReq = 5;
}

void doTidur(Person *Hilmys, activities *Act){
	bool canIt = (isEnough(Health(*Hilmys), (*Act).Tidur.healthReq) && isEnough(Social(*Hilmys), (*Act).Tidur.socialReq) && isEnough(Hygienic(*Hilmys), (*Act).Tidur.hygienicReq) && isEnough(Money(*Hilmys), (*Act).Tidur.moneyReq));
	if(canIt){
		kurangStat(Hilmys, (*Act).Tidur.healthReq , (*Act).Tidur.socialReq, (*Act).Tidur.hygienicReq, (*Act).Tidur.moneyReq);
		tambahStat(Hilmys, 5, 0, 0, 0);
	}
	else puts("Stat anda kurang mencukupi untuk melakukan kegiatan ini");
	return;	 	 
}

/*
void doMakan(Person *Hilmys, activities *Act){
	bool canIt = (isEnough(Health(*Hilmys)) && isEnough(Social(*Hilmys)) && isEnough(Hygienic(*Hilmys)) && isEnough(Money(*Hilmys)));
	if(canIt) kurangStat(*Hilmys, HealthReq(Makan(*Act)), SocialReq(Makan(*Act)), Hygienic(Makan(*Act)), MoneyReq(Makan(*Act)));
	else puts("Stat anda kurang mencukupi untuk melakukan kegiatan ini");
	return;
}

void doMandi(Person *Hilmys, activities *Act){
	bool canIt = (isEnough(Health(*Hilmys)) && isEnough(Social(*Hilmys)) && isEnough(Hygienic(*Hilmys)) && isEnough(Money(*Hilmys)));
	if(canIt) kurangStat(*Hilmys, HealthReq(Mandi(*Act)), SocialReq(Mandi(*Act)), Hygienic(Mandi(*Act)), MoneyReq(Mandi(*Act)));
	else puts("Stat anda kurang mencukupi untuk melakukan kegiatan ini");
	return;
} */
