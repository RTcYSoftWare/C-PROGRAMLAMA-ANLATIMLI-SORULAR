#include<stdio.h>
#include<conio.h>



int gecici = 1; // global de�i�kenleri tan�mlad�k.


/*---- RECURSIVE EKOK BULAN FONKS�YON ----*/
int EKOK(int sayi1 , int sayi2){
	
	if(gecici % sayi1 == 0 && gecici % sayi2 == 0) // ---- 4.ad�m
	return gecici;
	
	else{ // ---- 5.ad�m
		gecici++;
		return EKOK(sayi1,sayi2);
	}
	
}



/*---- ANA FONKS�YON ----*/
int main(){
	
	int sayi1 , sayi2 , sonuc; // de�i�kenleri tan�mlad�k.
	
	printf(" ---- Birinci Sayiyi Giriniz = "); // ekrana bilgi yazd�rd�k.
	scanf("%d",&sayi1); // birinci say�y� ald�k. ---- 2.ad�m
	
	printf(" ---- Ikinci Sayiyi Giriniz = "); // ekrana bilgi yazd�rd�k.
	scanf("%d",&sayi2); // birinci say�y� ald�k. ---- 2.ad�m
	
	sonuc = EKOK(sayi1,sayi2); // recursive fonksiyonu �a��rd�k. ---- 3. ad�m
	
	printf(" ---- EKOK(%d,%d) = %d",sayi1,sayi2,sonuc); // ekrana bilgi yazd�rd�k. ---- 6.ad�m
	
	
	getch();
	return 0;
}



// THIS CODES BLONG TO RTcY SoftWare
