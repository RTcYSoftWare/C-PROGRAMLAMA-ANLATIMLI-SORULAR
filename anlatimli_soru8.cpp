#include<stdio.h>
#include<conio.h>



/*---- RECURSIVE EBOB (OBEB) BULAN FONKS�YON ----*/
int OBEB(int sayi1 , int sayi2){

	if(sayi2==0 ){ // e�er ikinci say� s�f�rsa ---- 4.ad�m
		return sayi1; // say� biri d�nd�r  ---- 4.ad�m
	}

	else{ // de�ilse ---- 5.ad�m
		return OBEB(sayi2,sayi1%sayi2); // fonksiyonu �a��r ve sayi2 ile sayi1 mod sayi2 de�erlerini (sayi2,sayi1%sayi2) yolla. ---- 5.ad�m
	}
}



/*---- ANA FONKS�YON ----*/
int main (){
	
	int sayi1 , sayi2 , sonuc; // de�i�kenleri tan�mlad�k.
	
    printf(" ---- Birinci Sayiyi Giriniz: "); // ekrana bilgi yazd�rd�k.
    scanf("%d", &sayi1); // birinci say�y� ald�k. ---- 2.ad�m
   
    printf(" ---- Ikinci Sayiyi Giriniz: "); // ekrana bilgi yazd�rd�k.
    scanf("%d", &sayi2); // ikinci say�y� ald�k. ---- 2.ad�m
 
    sonuc = OBEB(sayi1,sayi2); // recursive fonksiyonu �a��rd�k. ---- 3. ve 6. ad�mlar
   
    printf(" ---- OBEB(%d,%d) = %d", sayi1, sayi2, sonuc); // ekrana bilgi yazd�rd�k. ---- 7.ad�m
    
	
	
	
	
	getch();
	return 0;
}



// THIS CODES BLONG TO RTcY SoftWare
