#include<conio.h>
#include<stdio.h>
#include<stdlib.h>



/*--- LEFT ROTATED SHIFT (SOLA KAYDIRMA) YAPAN FONKS�YONUMUZ ---*/
int LRS(int a,int b){
	
	unsigned short value , value2 , result, result2; // i�aretsiz veri tutan de�i�kenlerimizi tan�mlad�k.
	
	value = a; // a de�i�kenini bitlerine ay�rd�k.	---- 4. ad�m. 							// 1011 1010 0001 0001 as�l say�  47 633
	value2 = b; // b de�i�kenini bitlerine ay�rd�k. ---- 4. ad�m.
	
	result = value << value2 ; // gelen say�n�n sola kayd�r�lmas� ---- 5. ad�m.				// 1010 0001 0001 0000 sola 4 kaym�� hali 41 232  
	result2 = value >> (16-value2);	// gelen say�n�n sa�a kayd�r�lmas� ---- 5. ad�m. 		// 0000 0000 0000 1011 sa�a 12 kaym�� hali 11
	
	return (result|result2); // sa�a ve sola kayd�r�lan de�erlerin veya	---- 6. ad�m.		//1010 0001 0001 1011 veyalanm�� hali 41 243
							// i�lemi ile sonu� olarak d�nd�r�lmesi	

}

// gelen say�y� istenilen kadar sola kayd�r�yoruz.mesela(4 kez) 
// ard�ndan bitsel olarak tam tersi kadar sa�a kayd�r�yoruz.mesela(16-4 = 12 kez ) 
// ard�ndan bu iki say�y� veya i�lemine tutup lrs halini buluyoruz
// bir say�y� sola kayd�rmak demek o say� kayd�r�lan miktar kadar 2 ile �arpmak demektir.
// << i�lemi bitsel olarak "sola" kayd�rma 
// >> i�lemi bitsel olarak "sa�a" kayd�rma
// | i�lemi bitsel olarak "veya"




/*--- ANA FONKS�YONUMUZ ---*/
int main(){
	

	unsigned short result; // sonu� de�i�kenimiz.
	int a , b; // kullan�c�dan girdi almak i�in de�i�kenler.
	
	printf("Sayiyi giriniz = "); // ekrana bilgi yazd�k
	scanf("%d",&a); // ilk say�y� ald�k. (kayd�r�lacak say�)  ---- 2. ad�m.
	
	printf("Kaydirilacak miktari giriniz = "); // ekrana bilgi yazd�k.
	scanf("%d",&b); // ikinci say�y� al�dk. (kayd�r�lacak miktar)  ---- 2. ad�m.
	
	result = LRS(a , b); // sonu� de�i�kenimize kayd�rma yapan yonksiyonumzun sonucunu atad�k. ---- 3. ad�m.
	
	printf("LRS YAPILMIS HALI = %d ",result); // sonucu yazd�rd�k. ---- 7. ad�m.

	
	getch();
	return 0;
}




// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.
