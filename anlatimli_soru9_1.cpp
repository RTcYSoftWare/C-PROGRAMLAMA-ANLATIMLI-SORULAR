#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



FILE *arsene_lupen;// tan�mlad���m�z dosya pointer'�



/*---- BULUNAN ASAL SAYILARI DOSYAYA YAZAN FONKS�YON ----*/
void File_Write(int write){// kendisine gelen asal say�lar� dosyaya yazan fonksiyon	
	
	arsene_lupen = fopen("primes.txt","a+");// dosyay� a�t�k
	if(arsene_lupen == NULL)// dosyan�n a��l�p a��lmad���n� kontrol ettik.
	printf("HATA !!! DOSYA BULUNAMADI !!!");// hata mesaj� g�sterdik
	
	fprintf(arsene_lupen,"%d\n",write);// gelen asal say�y� dosyaya yazd�k
	fclose(arsene_lupen); // dosyay� kapatt�k
}



/*---- ASAL SAYIYI RECURSIVE BULAN FONKS�YON ----*/
int Is_Prime(int entered_number , int previous_numbers){// previous_numbers = �nceki say�lar� kapsar, number = gelen say�
	
	if(entered_number < 2)// sayi 2 den k���kse 0 d�nd�rd�k
	return 0;
	
	if(previous_numbers == entered_number){// e�er gelen sayi ile artt�rarak g�nderdi�imiz say� birbirine e�itse 1 d�nd�rd�k
		return 1;
	}
	
	if(entered_number % previous_numbers == 0)// e�er sayi kendisinden �nceki sayilara tam b�l�n�yorsa 0 d�nd�rd�k
		return 0;
	
	return Is_Prime(entered_number,previous_numbers+1);// fonksiyonu tekrar �a��rarak �nceki_sayilar de�i�kenini bir attt�rd�k.
	
}
/* Yukar�da yazm�� oldu�um recursive fonksiyonun mant��� gayet basittir.
	# E�er say� 2 den ku��kse 0 d�nd�r.
	# E�er onceki_sayilar ana say�ya e�itse 1 d�nd�r. Bu �art say�n�n asal olup olmad���n� belirler.
	Yani onceki say�n�n ana say�ya e�it olabilmesi i�in ana say�n�n onceki say�lara tam b�l�nmemesi gerekir.
	# E�er ana say� onceki say�ya tam b�l�n�yorsa 0 d�nd�r. ��nki asal say� de�ildir.
	
  */



/*GIRILEN ARALIKTAKI ASAL SAYILARI BULAN FONKSIYON*/
void Find_Prime_Between_Numbers(int btw_value , int btw_value2){
	
	
	if(btw_value > btw_value2){// e�er girilen ilk say� b�y�kse yani girdi 45-5 �eklinde ise
	printf("-----------BULUNAN ASAL SAYILAR----------\n");
		for(int i = btw_value2;i <= btw_value;i++){// ku�uk sayidan b�y�k say�ya giden d�ng� olu�turduk 
			
			int is_prime = Is_Prime(i,2);// sayiyi recursive asal say� bulan fonksiyonumuza yollad�k.
				
			/*if(is_prime == 0)// e�er sonuc 0 ise
			printf("asal degil = %d\n",i);// asal de�il*/
				
			if(is_prime == 1){// e�er sonuc 1 ise ---- 4.ad�m
			printf("--- %d\n",i);// say� asal ---- 6.ad�m
			File_Write(i);// dosyaya yazd�k ---- 5.ad�m
			}	
		}
		printf("ASAL SAYILAR DOSYAYA YAZILDI !!!\n");
	}
	
	
	if(btw_value2 > btw_value){// girilen ikinci sayi b�y�kse yani girdi 5-45 �eklinde ise
	printf("-----------BULUNAN ASAL SAYILAR----------\n");
		for(int i = btw_value;i <= btw_value2;i++){// ku�uk sayidan b�y�k say�ya giden d�ng� olu�turduk 
			
			int is_prime = Is_Prime(i,2);// sayiyi recursive asal say� bulan fonksiyonumuza yollad�k.
				
			/*if(is_prime == 0)// e�er sonuc 0 ise
			printf("asal degil = %d\n",i);// asal de�il*/
				
			if(is_prime == 1){// e�er sonuc 1 ise ---- 4.ad�m
			printf("--- %d\n",i);// say� asal ---- 6.ad�m
			File_Write(i);// dosyaya yazd�k ---- 5.ad�m
			}	
		}
		printf("ASAL SAYILAR DOSYAYA YAZILDI !!!\n");
	}
}



/*---- ANA FONKS�YONUMUZ ----*/
int main(){
	
	int value , value2;
	
	printf("----GIRILECEK ARALIK SAYILARI BUYUK KUCUK FARKETMEK SIZIN GIRINIZ----\n");
	printf("----ORN 5-45 YA DA 45-5 SEKLINDE TEK TEK GIRINIZ ----\n");
	
	printf("ASAL SAYILARIN ARANACAGI ARALIKTAKI 1. SAYIYI GIRINIZ = ");
	scanf("%d",&value); // ---- 2.ad�m
	
	printf("ASAL SAYILARIN ARANACAGI ARALIKTAKI 2. SAYIYI GIRINIZ = ");
	scanf("%d",&value2); // ---- 2.ad�m
	
	Find_Prime_Between_Numbers(value , value2);// aral�ktaki asal say�lar� bulan fonksiyonu �a��rd�k. ---- 3.ad�m
	
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
