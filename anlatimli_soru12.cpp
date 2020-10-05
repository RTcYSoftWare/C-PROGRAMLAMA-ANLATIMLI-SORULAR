#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



typedef struct Tek_Yonlu_Bagli_Liste{ // tek y�nl� ba�l� listeyi tan�mlad�k.
	int sayi; // d���m�n tutaca�� integer de�eri tan�mlad�k.
	struct Tek_Yonlu_Bagli_Liste *sonraki_bag; // d���m�n tutaca�� sonraki d���m�n adresini bar�nd�ran de�eri tan�mlad�k.
	
}Liste; // kullan�m a��s�ndan kolayl�k i�in tek y�nl� ba�l� listenin isim k�saltmas�.


Liste *ilk = NULL , *onceki = NULL , *gecici = NULL , *yeni_eklenecek = NULL , *silinecek = NULL; // yap�lacak i�lemler i�in gerekli olan pointer (i�aret�i) de�i�kenleri tan�mlad�k.
int bulunan_sira = 0; // silinecek ve bulunacak say�lar i�in gerekli olan global de�i�ken. 

/*
# ilk = ba�l� listenin ilk eleman�n� tutmak i�in kullan�l�r.
# yeni_eklenecek = eklenecek olan yeni gelen eleman� tutmak i�in kullan�l�r.
# gecici = her yerde kullan�lan joker eleman.:D
# onceki = s�ral� eklemede bir �nceki de�eri tuttmak i�in kullan�l�r.
*/



/*--- BA�LI L�STEYE SIRALI EKLEME YAPAN FONKS�YON ---*/
void Listeye_Ekleme(int eklenecek_sayi){	
	
	yeni_eklenecek = (Liste*)malloc(sizeof(Liste)); // gelen say�y� eklemek i�in yeni bir d���m olu�turduk.
	yeni_eklenecek->sayi = eklenecek_sayi; // d���me say�y� ekledik.
	yeni_eklenecek->sonraki_bag = NULL; // d���m�n sonraki de�erini null yapt�k
	
	if(ilk == NULL){ // e�er ba�l� liste bo�sa.
		ilk = yeni_eklenecek; // ba�l� listenin ilk d���m� yeni eklenecek.
	}
	else{ // e�er ba�l� listede elemanlar d���mler varsa
		
		if(ilk->sayi > yeni_eklenecek->sayi){ // yeni gelen eleman�n say�s� ilk eleman�n say�s�ndan k���kse
			yeni_eklenecek->sonraki_bag = ilk; // gerekli olan sonraki ba� e�itlemelerini yapt�k.
			ilk = yeni_eklenecek;
		}
		
		else{ // yeni gelen eleman�n say�s� ilk eleman�n say�s�ndan k���k de�ilse.
			onceki = ilk; // onceki eleman� ilk e e�itledik
			gecici = ilk->sonraki_bag; // gecici ilk elemandan 1 sonraki elemana e�itledik
			
			while(gecici != NULL){ // gecici null olmad��� s�rece cal��an bir d�ng� kurduk.
				if(gecici->sayi < yeni_eklenecek->sayi){ // e�er gecicinin de�eri yeni de�erden k���kse
					onceki = onceki->sonraki_bag; // �ncekinin g�sterdi�i d���m� ilerlettik.
					gecici = gecici->sonraki_bag; // ge�icinin g�sterdi�i d���m� ilerlettik.
				}
				else{
					break;
				}
			}
			if(gecici == NULL){ // e�er gecici null a e�it ise
				onceki->sonraki_bag = yeni_eklenecek; // e�itlemeleri yapt�k
			}
			else{ // gecici null de�ilse 
				onceki->sonraki_bag = yeni_eklenecek; // say�n�n gelmesi gereken yere uygun �ekilde e�itlemeleri yapt�k
				yeni_eklenecek->sonraki_bag = gecici;
			}	
		}		
	}
}



/*--- L�STEY� EKRANA YAZAN FONKS�YON ---*/
void Listeyi_Ekrana_Basma(){
	
	gecici = ilk;
	while(gecici != NULL){ // ge�ici null olmayana kadar devam eden d�ng� olu�turduk
		printf("%d->",gecici->sayi); // ge�icinin eleman�n� ekrana yazd�rd�k.
		gecici = gecici->sonraki_bag; // ge�iciyi ilerlettik
	}	
}



/*--- L�STEDE �STEN�LEN SAYIYI S�LEN FONKS�YON ---*/
void Listeden_Silme(){
	
	if(silinecek == ilk){ // e�er silinecek ilk de�erse.
		ilk = ilk->sonraki_bag; // gerekli olan ba� de�i�imlerini yapt�k.
		free(silinecek); // silinecek olan d���m� sildik.
	}
	else{ // ilk de�er de�ilse
		gecici = ilk;
		while(gecici->sonraki_bag != silinecek){ // gecici silinecek ba��n bir �ncesine gidene kadar d�nen d�ng�.
			gecici = gecici->sonraki_bag; // gecici yi ilerlettik.
		}
		gecici->sonraki_bag = gecici->sonraki_bag->sonraki_bag; // silinecek say� bulundu�unda gerekli ba� de�i�imlerini yapt�k.
		free(silinecek); // silinecek say�y� sildik.
	}
}



/*--- L�STEDE �STEN�LEN SAYIYI BULAN FONKS�YON ---*/
void Listede_Bulma(int bulunacak){

	gecici = ilk;
	while(gecici != NULL){ // gecici null olmayana kadar d�nen d�ng� kurduk.
		if(gecici->sayi == bulunacak){ // e�er gecicinin say�s� bulunacak say� ise
			bulunan_sira++; // bulundu�u s�ray� artt�rd�k.
			silinecek = gecici; // silme i�lemi i�in de gecici pointer'�n tuttu�u adresi silinecek pointer'�na atad�k.
			break;
		}
		
		bulunan_sira++; // bulunamad�ysa bulunana kadar tekrar s�ray� artt�rd�k.
		gecici = gecici->sonraki_bag; // geciciyi ilerlettik.
		
		if(gecici == NULL){ // e�er gecici nulsa yani say� listede yoksa
			bulunan_sira = 0; // s�ray� s�f�rlad�k.
		}	
	}
}



/*--- ANA FONKS�YON ---*/
int main(){
	
	int sayi , kontrol = 1 , bulunacak , silinecek_sayi; // yap�lacak i�lemler i�in gerekli olan de�i�kenler
	
	printf("\n ----------------------------------------------------\n");
	printf(" ISTEDIGINIZ KADAR VERI GIREBILIRSINIZ !!! \n");
	printf(" CIKMAK ISTEDIGINIZDE 0'A, BASINIZ !!! \n\n");
	
	while(kontrol){ // s�f�r girilmedi�i s�rece sonsuz �al��an fonksiyonumuz.
		
		printf("SAYI GIRINIZ = "); // ekrana bilgi yazd�rd�k.
		scanf("%d",&sayi); // kullan�c�dan say�y� ald�k.
		
		kontrol = sayi; // say�y� kontrol de�i�kenine atad�k. (e�er girilen say� s�f�r ise d�ng�y� durdurmak i�in)
		
		if(kontrol == 0){ // e�er kontrol (girilen say�) 0 ise 
		printf(" CIKIS YAPILDI !!! \n "); // ekrana bilgi yazd�rd�k.
		break;	// d�ng�y� k�rd�k.
		}
		
		else{ // 0 dan farkl� bir say� girildiyse 
			Listeye_Ekleme(sayi); // listeye ekleme yapt�k.
		}
	}
	
	printf("\n----------------------------------------------------\n");
	printf("SIRALI EKLENMIS LISTE EKRANA BASILIYOR !!! \n\n"); // ekrana bilgi yazd�rd�k.
	Listeyi_Ekrana_Basma(); // listeyi ekrana yazd�rd�k.
	
	printf("\n----------------------------------------------------\n");
	printf("\n BULUNACAK SAYIYI GIRINIZ = "); // ekrana bilgi yazd�rd�k.
	scanf("%d",&bulunacak); // bulunacak say�y� ald�k.
	
	Listede_Bulma(bulunacak); // listede say�y� bulan fonksiyonumuzu �a��rd�k.
	
	if(bulunan_sira !=0 ){ // e�er listede say� mevcutsa
		printf("\n SAYI BULUNDU %d. SIRADA\n",bulunan_sira); // ekrana bilgi yazd�rd�k.
	}
	else{ // listede say� mevcut de�ilse
		printf("SAYI BULUNAMADI !!! \n"); // ekrana bilgi yazd�rd�k.
	}
	
	printf("\n\n----------------------------------------------------\n");
	printf("\n SILINECEK SAYIYI GIRINIZ = "); // ekrana bilgi yazd�rd�k.
	scanf("%d",&silinecek_sayi); // silinecek say�y� ald�k.

	Listede_Bulma(silinecek_sayi); // listede say�y� bulan fonksiyonumuzu �a��rd�k.
	
	if(bulunan_sira != 0){ // e�er say� listede mevcutsa
		Listeden_Silme(); // silme yapan fonksiyonumuzu �a��rd�k.
		printf("\n SAYI LISTEDEN SILINDI !!! LISTENIN YENI HALI !!! \n\n"); // ekrana bilgi yazd�rd�k.
		Listeyi_Ekrana_Basma(); // de�i�mi� listeyi ekrana yazd�rd�k.
	}
	else{ // e�er silinecek say� listede yoksa
		printf(" SILINECEK SAYI LISTEDE BULUNMAMAKTADIR !!! \n"); // ekrana bilgi yazd�rd�k.
	}
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
