#include<stdio.h>
#include<conio.h>



/*---- RECURSIVE "�ZY�NELEMEL�" �ST ALAN FONKS�YONUMUZ ----*/
int Ozyinelemeli_Ust_Alma(int sayi,int ust){

	if(ust>0) // e�er girilen �st 0 dan b�y�kse ---- 4.ad�m
	return (sayi*(Ozyinelemeli_Ust_Alma(sayi,ust-1))); // girilen say� ile tekrar fonksiyonumuzun �a��r�lmas�n�n �arp�m�.
	
	else // e�er �st 0 dan k���k veya s�f�r ise  ---- 5.ad�m
	return 1; // 1 d�nd�rd�k.
}



int main(){
	
	int sayi , ust , sonuc; // de��i�kenleri tan�mlad�k.
	
	printf("SAYI GIRINIZ = "); //ekrana bilgi yazd�k
	scanf("%d",&sayi); // kullan�c�dan say�y� ald�k ---- 2.ad�m
	
	printf("UST GIRINIZ = "); //ekrana bilgi yazd�k
	scanf("%d",&ust); // kullan�c�dan ust ald�k ---- 2.ad�m
	
	sonuc = Ozyinelemeli_Ust_Alma(sayi,ust); // �zyinelemeli "recursive" fonksiyonumuzu �a��rd�k. ---- 3 ve 6. ad�mlar
	printf("SONUC = %d",sonuc); // ekrana ust alman�n sonucunu yazd�rd�k. ---- 7.ad�m
	
	
	getch();
	return 0;
} 



