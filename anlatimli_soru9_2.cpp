#include<stdio.h>
#include<conio.h>
#include<stdlib.h>



int *a_dizisi_pointer , *b_dizisi_pointer;// a ve b dizilerinin i�aret�ilerini tan�mlad�k
int a_eleman_sayisi = 0 , b_eleman_sayisi = 0;// a ve b dizileri i�in kullan�c� say� girdik�e eleman say�s�n� tutan de�i�ken tan�mlad�k.



/*---- GELEN SAYIYI DE���KENE G�RE KONTROL ED�P D�Z�LERE YAZAN FONKS�YON ----*/
void Write_To_Array(int write , int control){// gelen say�y� ve kontrol de�erini al�r
	
	switch(control){// gelen say�n�n tek veya �ift olmas� duruman g�re i�lem yapan switch - case yap�s� tan�mlad�k.
		case 0 : // e�er kontrol 0 ise yani say� �ift ise
		if(b_eleman_sayisi == 0){// e�er dizide hi� eleman yoksa
			b_dizisi_pointer = (int*) malloc(1*sizeof(int));// b dizisine eklenecek olan ilk say� i�in malloc kullanarak haf�zadan yer ay�rd�k.
			*(b_dizisi_pointer + b_eleman_sayisi) = write;// ay�rd���m�z haf�za alan�na gelen say�y� koyduk.
			b_eleman_sayisi++;// dizinin eleman say�s�n� bir artt�rd�k.
			
		}
		else{// e�er gelen sayi diziye eklenecek ilk eleman de�ilse
			b_dizisi_pointer = (int*) realloc(b_dizisi_pointer,1*sizeof(int));// b dizisinin boyutunu realloc kullanarak 1 elemanl�k artt�rd�k.
			*(b_dizisi_pointer + b_eleman_sayisi) = write;// artt�rd���m�z yere yeni gelen say�y� yazd�k.
			b_eleman_sayisi++;// eleman say�s�n� artt�rd�k.

		}
		break;
		case 3 :// e�er kontrol 3 ise yani say� tek ise
		if(a_eleman_sayisi == 0){// e�er tek say� dizisinde hi� eleman yoksa 
			a_dizisi_pointer = (int*) malloc(1*sizeof(int));// a dizisine eklenecek olan ilk say� i�in malloc kullanarak haf�zadan yer ay�rd�k.
			*(a_dizisi_pointer+a_eleman_sayisi) = write;// ay�rd���m�z haf�za alan�na gelen say�y� koyduk.
			a_eleman_sayisi++;// dizinin eleman say�s�n� bir artt�rd�k.
		}
		else{// e�er gelen sayi diziye eklenecek ilk eleman de�ilse
			a_dizisi_pointer = (int*) realloc(a_dizisi_pointer,1*sizeof(int));// b dizisinin boyutunu realloc kullanarak 1 elemanl�k artt�rd�k.
			*(a_dizisi_pointer + a_eleman_sayisi) = write;// artt�rd���m�z yere yeni gelen say�y� yazd�k.
			a_eleman_sayisi++;// eleman say�s�n� artt�rd�k.
		}
		break;
		defaul :// e�er yanl�� kontrol de�i�keni geldiyse.
			printf("\n HATA !!! \n");// hata mesaj� d�nd�rd�k.
			break;
	}
	
}



/*---- GELEN SAYIYI TEK VEYA ��FT OLARAK AYIRAN FONKS�YON ----*/
void Tek_Mi_Cift_Mi(int value){
	
	if(value%2 == 0){// gelen say� 2 ye tam b�l�n�yorsa
		printf("Sayi Cifttir. B cift sayilar dizisine eklenmistir.\n");// bilgi verdik
		Write_To_Array(value,0);// say�lar� dizilere yazan fonksiyonumuzu �a��rd�k ve i�erisine kontrol,girilen sayi de�erlerini g�nderdik
	}
	else{// gelen say� tekse
		printf("Sayi Tektir A tek sayilar dizisine eklenmistir.\n");
		Write_To_Array(value,3);// say�lar� dizilere yazan fonksiyonumuzu �a��rd�k ve i�erisine kontrol,girilen sayi de�erlerini g�nderdik
	}
}



/*---- A VE B D�Z�LER�N� EKRANA YAZDIRAN FONKS�YON ----*/
void Print_The_Arrays(){
	
	if(b_eleman_sayisi == 0){// e�er kullan�c� say� girmeden 0 a basrsa veya hi� �ift eleman girmezse
		printf("B DIZISINDE HIC ELEMAN BULUNMAMAKTADIR !!!\n");
	}
	
	else{// b dizisinde eleman varsa
		printf("\n---B CIFT DIZISININ ELEMANLARI ---\n");
	for(int i = 0;i<b_eleman_sayisi;i++){// b dizisindeki say�lar� ekrana yazd�rd�k
		
		printf("%d\n",*(b_dizisi_pointer+i));
	}
	}
	
	if(a_eleman_sayisi == 0){// e�er kullan�c� say� girmeden 0 a basrsa veya hi� tek eleman girmezse
		printf("A DIZISINDE HIC ELEMAN BULUNMAMAKTADIR !!!\n");
	}
	
	else{// b dizisinde eleman varsa
		printf("\n---A TEK DIZISININ ELEMANLARI ---\n");
	for(int i = 0;i<a_eleman_sayisi;i++){// a dizisindeki say�lar� ekrana yazd�rd�k
		
		printf("%d\n",*(a_dizisi_pointer + i));
	}	
	}
}



/*---- KULLANICIDAN VER� G�R��� SA�LAYAN FONKS�YON ----*/
void User_Nubmers_Entry(){

	int prf_longdon;// kullan�c�n�n girece�i say�y� almak i�in int eleman tan�mlad�k
	
	while(1){// sonsuz d�ng�m�z
		printf("Sayi Giriniz = ");
		scanf("%d",&prf_longdon);// say�y� ald�k
		if(prf_longdon == 0){// e�er say� 0 ise kullan�c�ya ��k�� yapt�rd�k.
		printf("\n----CIKIS YAPILIYOR !!!----\n");
		break;
		}
		
		Tek_Mi_Cift_Mi(prf_longdon);// say� s�f�r de�ilse tek veya �ift kontrol� yapan fonksiyona g�nderdik.
	}
}



/*---- ANA FONKS�YON ----*/
int main(){
	
	User_Nubmers_Entry();// kullan�c�dan girdi alan fonksiyonu �a��rd�k.
	
	Print_The_Arrays();// dizileri ekrana yazd�ran fonksiyonu �a��rd�k.
	
	free(b_dizisi_pointer);// b�t�n i�lemler bittikten sonra haf�zada doluluk olmams� i�in b dizisini sildik
	free(a_dizisi_pointer);// b�t�n i�lemler bittikten sonra haf�zada doluluk olmams� i�in a dizisini sildik
	
	getch();
	return 0;
}



// BU KODLAR RIZA TURANCAN YILMAZ'A A�TT�R.
// KOPYALANMASI VEYA �O�ALTILMASI YASAKTIR.

