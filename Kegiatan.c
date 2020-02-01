#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "Hilmys.h"

//inisialisasi karena kedua variabel ini bersyarat stats
bool sudahMakan = false;
bool sudahMCK = false;

int mini(int a, int b){
	if(a <= b) return a;
	else return b;
}

void pilihKegiatan(Person *Hilmys, activities *Act){
	time_t start = time(NULL);
	 time_t snt_tidur=start, snt_makan=start, snt_mck=start;
	 bool cekTidur = true, cekMakan = true, cekMCK = true;
		while(!cekWinning(Hilmys)){
		//==========input kegiatan oleh user===========
			int pil; 
			printf("\nSilahkan pilih kegiatan yang ingin dilakukan: \n");
			printf("1. Tidur         2. Makan\n");
			printf("3. MCK           4. Berkunjung\n");
			printf("5. Gambling      6. Olahraga\n");
			printf("7. Nonton Anime  8. Quiz\n");
			printf("0. Stats\n");
			printf("11. Poin Setiap Kegiatan\n");
			printf("Pilihan Anda [dalam angka diatas]: ");
			scanf("%d", &pil);
		//=============If else berbagai kegiatan=========
			if(cekLosing(Hilmys)){
				printf("Maaf, Anda Kalah :( \n");
				printf("Stats anda\n");
				printStat(Hilmys, Act);
				break;
			}
			if(pil == 1){
				//karena syarat tidur semuanya 0 kita tidak perlu membuat kondisi ketika doTidur tidak dieksekusi
				doTidur(Hilmys, Act);
				if(!cekTidur) cekTidur = true;
				snt_tidur = time(NULL);
				printf("=====Tidur sudah Selesai=====\n");
			}
			else if(pil == 2){
				doMakan(Hilmys, Act);
				if(sudahMakan){
					sudahMakan = false;
					if(!cekMakan) cekMakan = true;
					snt_makan = time(NULL);
					printf("=====Makan sudah Selesai=====\n");
				}	
			}
			else if(pil == 3){
				doMCK(Hilmys, Act);
				if(sudahMCK){
					sudahMCK = false;
					if(!cekMCK) cekMCK = true;
					snt_mck = time(NULL);
					printf("=====MCK sudah selesai=====\n");
				}
			}
			else if(pil == 4){
				doBerkunjung(Hilmys, Act);
				printf("=====Berkunjung ke rumah tetangga sudah selesai!=====");
			}
			else if(pil == 5) doGambling(Hilmys, Act);	
			else if(pil == 6) doOlahraga(Hilmys, Act);
			else if(pil == 7) doNontonAnime(Hilmys, Act);
			else if(pil == 8) doQuiz(Hilmys, Act);
			else if(pil == 0) printStat(Hilmys, Act);
			else if(pil == 11){
				//Dokumentasi aturan poin
				printf("====================================================================\n");
				printf("| Kegiatan         | HR | SR | HGR | MR     | HPR | Gain Poin      | \n");
				printf("| Tidur            | 0  | 0  |  0  | 0      |  0  | 5H             | \n");
				printf("| Makan Mie Instan | 5  | 0  |  0  | 5      |  0  | 10H            | \n");
				printf("| Makan Nasi Uduk  | 5  | 0  |  0  | 10     |  0  | 15H            | \n");
				printf("| Makan Ramen      | 5  | 0  |  0  | 15     |  0  | 20H            | \n");
				printf("| MCK              | 5  | 0  |  0  | 5      |  0  | 5H, 20HG       | \n");
				printf("| Berkunjung       | 0  | 0  |  5  | 5      |  0  | 30S            | \n");
				printf("| Gambling         | 10 | 5  |  0  | 0      |  0  | (userbet)M     | \n");
				printf("| Jalan Santai     | 5  | 0  |  0  | 0      |  0  | 5H, 5HP        | \n");
				printf("| Lari Keliling    | 10 | 0  |  0  | 0      |  0  | 10H, 10HP      | \n");
				printf("| Bermain Catur    | 5  | 0  |  0  | 0      |  0  | 10HP           | \n");
				printf("| CP (Win)         | 10 | 0  |  0  | 0      |  0  | 10H, 20HP      | \n");
				printf("| CP (Lost)        | 10 | 0  |  0  | 0      |  0  | 5H, 5HP        | \n");
				printf("| Nonton Anime     | 10 | 0  |  0  | 10/15  |  0  | (-10 to 15)HP  | \n");
				printf("| Quiz             | 5  | 0  |  0  | 0      |  0  | (10 to 20)M    | \n");
				printf("==================================================================== \n");
				printf("\n");
				printf("Keterangan: \n");
				printf("H = Hygienic, S = Social, HG = Hygienic, M = Money, HP = Happiness\n");
				printf("HR = Health Required\n");
				printf("SR = Social Required\n");
				printf("HGR = Hygienic Required\n");
				printf("MR = Money Required\n");
				printf("HPR = Happiness Required\n");
				getchar();
			}
			else printf("Pilihan yang anda masukkan salah silahkan pilih kegiatan kembali\n");
			
		//===========KEGIATAN BASED HEALTH==================
			time_t end = time(NULL);
			//================PRASYARAT UNTUK TIDUR===================
			//Jika sudah durasi sebelum tidur sudah 5 menit Hilmys harus tidur
			if((int)difftime(end, snt_tidur) >= 300){
				char pil;
				printf(" %d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys mengantuk dan perlu tidur untuk kesehatannya!\n");
				printf("Jika tidak tidur tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk tidur dan N untuk tidak \n");
				scanf(" %c", &pil);
				if(pil == 'Y'){
					doTidur(Hilmys, Act);
					printf("Tidur sudah selesai\n");
				}
				else{
					 snt_tidur = time(NULL);
					 cekTidur = false;
				}
			}
			//Jika tidak tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya	
			if(!cekTidur) (*Hilmys).health -= 1;
			
			//=================PRASYARAT UNTUK MAKAN=======================
			//Jika durasi sebelum makan sudah 3 menit maka Hilmys harus makan
			if((int)difftime(end, snt_makan) >= 180){
				char pil;
				printf("%d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys perlu makan untuk kesehatannya!\n");
				printf("Jika tidak makan tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk makan dan N untuk tidak \n");
				scanf(" %c", &pil);
				if(pil == 'Y') doMakan(Hilmys, Act);
				else{
					 snt_makan = time(NULL);
					cekMakan = false;

				}
			}
			//Jika makan tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya
			if(!cekMakan) (*Hilmys).health -= 1;
			//=================PRASYARAT UNTUK MCK=======================
			//Jika durasi sebelum makan sudah 4 menit maka Hilmys harus makan
			if((int)difftime(end, snt_mck) >= 240){
				char pil;
				printf("%d%s", (int)difftime(end, start)/60, " menit sudah lewat, Hilmys sakit perut dan perlu MCK untuk kesehatannya!\n");
				printf("Jika tidak MCK tingkat kesehatan hilmy akan berkurang 1 setiap detiknya!\n");
				printf("Pilih Y jika setuju untuk MCK dan N untuk tidak \n");
				scanf(" %c", &pil);
				if(pil == 'Y') doMCK(Hilmys, Act);
				else{
					 snt_mck = time(NULL);
					 cekMCK = false;
				}
			}
			//Jika makan tidur setiap <= menit, Health hilmy akan berkurang 1 setiap detiknya
			if(!cekMakan) (*Hilmys).health -= 1;
		//=================PRASYARAT WAKTU BERMAIN=================
			//Jika waktu bermain user sudah 15 menit otomatis kalah
			if((int)difftime(end, start) >= 900){
				printf("=====Hilmys sudah meninggal, Anda Kalah!=====\n");
				break;
			} 
		} 
		
}

void doPemandianAirPanas(Person *Hilmys, activities *Act)
{
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).pmdA.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).pmdA.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).pmdA.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).pmdA.moneyReq) && isEnoughStat(Happiness(*Hilmys), (*Act).pmdA.happinessReq));
	if (canIt)
	{
		tambahStat(Hilmys, 30, 5, 20, 0,5);
		kurangStat(Hilmys, (*Act).pmdA.healthReq , (*Act).pmdA.socialReq, (*Act).pmdA.hygienicReq, (*Act).pmdA.moneyReq, (*Act).pmdA.happinessReq);
	}
	return;
}

void doMemancing(Person *Hilmys, activities *Act)
{
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).pancing.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).pancing.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).pancing.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).pancimg.moneyReq) && isEnoughStat(Happiness(*Hilmys), (*Act).pancing.happinessReq));
	if (canIt)
	{
		tambahStat(Hilmys, 0, 5, 0, 10,5);
		kurangStat(Hilmys, (*Act).pancing.healthReq , (*Act).pancing.socialReq, (*Act).pancing.hygienicReq, (*Act).pancing.moneyReq, (*Act).pancing.happinessReq);
	}
	return;
}

void doBerkunjung(Person *Hilmys, activities *Act)
{
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).bkj.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).bkj.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).bkj.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).bkj.moneyReq) && isEnoughStat(Happiness(*Hilmys), (*Act).bkj.happinessReq));
	if (canIt)
	{
		tambahStat(Hilmys, 0, 30, 0, 0,0);
		kurangStat(Hilmys, (*Act).bkj.healthReq , (*Act).bkj.socialReq, (*Act).bkj.hygienicReq, (*Act).bkj.moneyReq, (*Act).bkj.happinessReq);
	}
	return;
}

void doTidur(Person *Hilmys, activities *Act){
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Tidur.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Tidur.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Tidur.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).Tidur.moneyReq) && isEnoughStat(Happiness(*Hilmys), (*Act).Tidur.happinessReq));
	if(canIt) tambahStat(Hilmys, 5, 0, 0, 0,0);
	return;	 	 
}

void doMakan(Person *Hilmys, activities *Act){
	int pil;
	printf("Pilih makanan yang akan dimakan Hilmys. Silahkan pilih sesuai nomor yang tertera.\n");
	printf("[Catatan : Harga berbanding lurus dengan pertambahan Health Hilmys]\n");
	printf("======Daftar Harga Makanan=======\n");
	printf("|   Makanan     |      Harga    |\n");
	printf("| 1. Mie Instan	|      5 Koin   |\n");
	printf("| 2. Nasi Uduk  |     15 Koin   |\n");
	printf("| 3. Ramen      |     20 Koin   |\n");
	scanf("%d", &pil);
	if(pil == 1){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 5) && isEnoughStat(Happiness(*Hilmys), (*Act).Makan.happinessReq));
		if(!canIt) printf("=====Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan=====\n");
		else{
			kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 5, (*Act).Makan.happinessReq);
			tambahStat(Hilmys, 10, 0, 0, 0, 0);
			sudahMakan = true;
		}
		
	}
	else if(pil == 2){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 15) && isEnoughStat(Happiness(*Hilmys), (*Act).Makan.happinessReq));
		if(!canIt) printf("=====Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan=====\n");
		else{
			 kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 15, (*Act).Makan.happinessReq);
			 tambahStat(Hilmys, 15, 0, 0, 0, 0);
			 sudahMakan = true;
		}
	}
	else if(pil == 3){
		bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Makan.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Makan.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Makan.hygienicReq) && isEnoughStat(Money(*Hilmys), 20) && isEnoughStat(Happiness(*Hilmys), (*Act).Makan.happinessReq));
		if(!canIt) printf("=====Stat anda tidak mencukupi, silahkan sesuaikan dengan syarat yang diberikan=====\n");
		else{
			 kurangStat(Hilmys, (*Act).Makan.healthReq , (*Act).Makan.socialReq, (*Act).Makan.hygienicReq, 20, (*Act).Makan.happinessReq);
			 tambahStat(Hilmys, 20, 0, 0, 0, 0);
			 sudahMakan = true;
		}
	}

}

void doMCK(Person *Hilmys, activities *Act){
	bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).MCK.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).MCK.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).MCK.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).MCK.moneyReq) && isEnoughStat(Happiness(*Hilmys), (*Act).MCK.happinessReq));
	if(canIt){
		sudahMCK = true;
		kurangStat(Hilmys, (*Act).MCK.healthReq , (*Act).MCK.socialReq, (*Act).MCK.hygienicReq, (*Act).MCK.moneyReq, (*Act).MCK.happinessReq);
		tambahStat(Hilmys, 5, 0, 20, 0, 0);
	}
	else printf("=====Stat anda tidak mencukupi untuk MCK=====\n");
	return;
} 

void doGambling(Person *Hilmys, activities *Act){
	//bool canIt = (isEnoughStat(Health(*Hilmys), (*Act).Gambling.healthReq) && isEnoughStat(Social(*Hilmys), (*Act).Gambling.socialReq) && isEnoughStat(Hygienic(*Hilmys), (*Act).Gambling.hygienicReq) && isEnoughStat(Money(*Hilmys), (*Act).Gambling.moneyReq));
	int pil;
	printf("======Selamat datang di Arena Gambling======\n");
	printf("Silahkan pilih game yang anda ingin mainkan!\n");
	printf("1. Tebak Angka                 2. Sticks134 Game \n");
	printf("Pilihan Anda: ");
	scanf("%d", &pil);
	if(pil == 1){
		tebakAngka(Hilmys);
		printf("\n");
		printf("=====Terimakasih telah bermain Game Tebak Angka :)=====\n");
	}
	else if(pil == 2){
		sticksGame(Hilmys);
		printf("=====Terimakasih telah bermain Sticks Game :)=====\n");
	}
}

void doOlahraga(Person *Hilmys, activities *Act){
	int pil;
	//Lari keliling lapangan perlu uang untuk gojek
	//Competitive Programming perlu uang untuk beli snack :v
	printf("Pilih Olahraga yang ingin dilakukan\n");
	printf("1. Jalan Santai                    2. Lari Keliling Lapangan\n");
	printf("3. Bermain Catur                   4. Competitive Programming\n");
    scanf(" %d", &pil);
    if(pil == 1){
		if(((*Hilmys).health < 5)){
			printf("=====Health Hilmys tidak mencukupi untuk Jalan Santai :( =====\n");
		}
		else{
			kurangStat(Hilmys, 5, 0, 0, 0, 0);
			tambahStat(Hilmys, 5, 0, 0, 0, 5);
			printf("=====Jalan Santai sudah selesai! Sekarang Hilmy lebih bahagia dan Sehat :)=====\n");
		}
	}
	else if(pil == 2){
		if(((*Hilmys).health < 10) || (*Hilmys).money < 10){
			printf("=====Health Hilmys tidak mencukupi untuk Lari Keliling Lapangan :( =====\n");
		}
		else{
			kurangStat(Hilmys, 10, 0, 0, 5, 0);
			tambahStat(Hilmys, 10, 0, 0, 0, 10);
			printf("=====Lari Keliling Lapangan sudah selesai!=====\n");
		}
	}
	else if(pil == 4){
		if((*Hilmys).health < 10 || (*Hilmys).money< 10){
			printf("=====Health Hilmys tidak mencukupi untuk CP :( =====\n");
			return;
		}
		else{
			int pilUser;
			srand(time(0));
			int n = rand()%100 + 10;
			int tmp = 1;
			while(true){
				tmp = (tmp << 1);
				if(tmp > n){
					tmp = (tmp >> 1);
					break;
				}
				else if(tmp == n) break;
			}
			int hasil = 2*(n-tmp) + 1;
			printf("Hilmys sedang mengerjakan soal CP, tapi kebingungan untuk menjawab soal seperti ini:\n");
			printf("Pada suatu masa, n tawanan akan dieksekusi. Tawanan tersebut disuruh untuk duduk melingkar\n");
			printf("Dimulai dari tawanan 1, akan membunuh tawanan 2, tawanan 3 akan membunuh tawanan 4, dan seterusnya sampai tersisa 1 orang\n");
			printf("Orang yang terakhir kali hidup tidak akan dieksekusi :( \n\n");
			printf("Disaat kasus kecil (1 <= n <= 9) Hilmys masih bisa untuk brute force\n");
			printf("Namun ketika n bernilai >= 10, Hilmys perlu mengetahui tawanan yang hidup terakhir untuk membuat formula umumnya.\n");
			printf("Tawanan yang terakhir hidup [dalam angka] ");
			printf("%s%d%s", "ketika n bernilai ", n, " adalah: ");
			scanf(" %d", &pilUser);
			if(pilUser == hasil){
				printf("=====Anda benar!, Sekarang Hilmys sudah bisa menemukan rumus umum dari permasalahan tersebut sehingga nilai happinessnya bertambah 20 :)=====\n");
				kurangStat(Hilmys, 10, 0, 0, 5, 0);
				tambahStat(Hilmys, 10, 0, 0, 0, 20);
			}
			else{
				printf("=====Anda salah!, Hilmys pun hanya bisa mengerjakan sebagian subtask, sehingga nilai happiness yang ia dapatkan hanyalah 5=====\n");
				kurangStat(Hilmys, 10, 0, 0, 5, 0);
				tambahStat(Hilmys, 5, 0, 0, 0, 5);
			}
		}
	}
	else if(pil == 3){
		if((*Hilmys).health < 10){
			printf("=====Health Hilmys tidak mencukupi untuk bermain Catur :( =====\n");
		}
		else{
			kurangStat(Hilmys, 5, 0, 0, 0, 0);
			tambahStat(Hilmys, 0, 0, 0, 0, 10);
			printf("=====Bermain Catur Sudah Selesai :)=====\n");
		}
	}
	
}

void doNontonAnime(Person *Hilmys, activities *Act){
	int pil;
	if((*Hilmys).health < (*Act).NontonAnime.healthReq){
		printf("=====Hilmys tidak cukup sehat untuk menonton anime :( =====\n");
		return;
	}
	printf("Pilih anime yang ingin ditonton\n");
	printf("1. 君の名は         [10 koin]    2. 秒速5センチメートル [10 koin]\n");
	printf("3. 男子高校生の日常 [15 koin]   4. デスノート         [15 koin]\n");
	scanf(" %d", &pil);
	while(pil < 1 || pil > 4){
		printf("==Silahkan pilih dengan nomor yang benar!==\n");
		printf("Pilih anime yang ingin ditonton: ");
		scanf(" %d", &pil);
	}
	if(pil == 1){
		if((*Hilmys).money < 10) printf("=====Uang Hilmys tidak mencukupi untuk membeli tiket anime tersebut :( =====\n");
		else{
			printf("=====Hilmys selesai menonton kimi no nawa=====\n");
			printf("=====Karena anime ini sangat menyentuh hati, happiness dari Hilmys pun bertambah 10=====");
			kurangStat(Hilmys, 0, 0, 0, 10, 0);
			tambahStat(Hilmys, 0, 0, 0, 0, 10);
		}
	}
	else if(pil == 2){
		if((*Hilmys).money < 10) printf("=====Uang Hilmys tidak mencukupi untuk membeli tiket anime tersebut :( =====\n");
		else{
			printf("=====Hilmys selesai menonton 5 cm per second=====\n");
			printf("=====Karena anime ini sangat menyedihkan, happiness dari Hilmys pun berkurang 5=====");
			kurangStat(Hilmys, 0, 0, 0, 10, 0);
			tambahStat(Hilmys, 0, 0, 0, 0, -5);
		}
	}
	else if(pil == 3){
		if((*Hilmys).money < 15) printf("=====Uang Hilmys tidak mencukupi untuk membeli tiket anime tersebut :( =====\n");
		else{
			printf("=====Hilmys selesai menonton Danshi Koukousei no Nichijou=====\n");
			printf("=====Karena anime ini sangat lucu, happiness dari Hilmys pun bertambah 15=====");
			kurangStat(Hilmys, 0, 0, 0, 15, 0);
			tambahStat(Hilmys, 0, 0, 0, 0, 15);
		}
	}
	else if(pil == 4){
		if((*Hilmys).money < 15) printf("=====Uang Hilmys tidak mencukupi untuk membeli tiket anime tersebut :( =====\n");
		else{
			printf("=====Hilmys selesai menonton Death Note=====\n");
			printf("=====Karena anime ini sangat suram, happiness dari Hilmys pun berkurang 10=====");
			kurangStat(Hilmys, 0, 0, 0, 15, 0);
			tambahStat(Hilmys, 0, 0, 0, 0, -10);
		}
	}
	printf("\n");
}

void doQuiz(Person *Hilmys, activities *Act){
	if((*Hilmys).health< (*Act).Quiz.healthReq) printf("Hilmys tidak cukup sehat untuk Quiz :(\n");
	else{
		soal(Hilmys);
		printf("=====Quiz Sudah Selesai=====\n");	
	}
}
