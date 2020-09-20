#include<stdio.h>
#include<conio.h>


/*---- FAKT�R�YEL HESAPLAYAN RECURSIVE FONKS�YON ----*/
int Recursive_Faktoriyel_Hesaplama(int sayi){
	
	if(sayi <= 1) // say� birden k���kse. ---- 4.ad�m
	return 1; // geriye 1 de�eri d�nd�
	else // say� birden b�y�kse. ---- 5.ad�m
	return(sayi*(Recursive_Faktoriyel_Hesaplama(sayi-1))); // say� �arp� fonksiyonun yeniden �a��r�lmas�.
	
}
	


/*---- ANA FONKS�YON ----*/
int main(){
	
	int sayi , sonuc; // de�i�kenleri tan�mlad�k. 
	
	printf("FAKTORIYEL HESAPLANACAK SAYIYI GIRINIZ = "); // ekrana bilgi yazd�rd�k.
	scanf("%d",&sayi); // fakt�riyel hesaplanacak say�y� ald�k. ---- 2.ad�m
	
	sonuc = Recursive_Faktoriyel_Hesaplama(sayi); // recursive fonksiyonu �a��rd�k. ---- 3. ve 6. ad�mlar
	
	printf("SONUC = %d ",sonuc); // sonucu ekrana yazd�rd�k. ---- 7.ad�m
	
	
	
	getch();
	return 0;
}


// THIS CODES BLONG TO RTcY SoftWare
