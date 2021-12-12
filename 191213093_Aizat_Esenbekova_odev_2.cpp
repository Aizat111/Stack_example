#include<stdio.h>
#include<stdlib.h>
#define boyut   30
 typedef struct yigin{
 	int indis;
 	int eleman[boyut];
 	int simge[boyut];
 }yiginlar;
 
yiginlar geri;
yiginlar islem;
 
 bool yigin_bosmu()
 {
 	if(islem.indis==-1) return true;//yigin bos oldugunda geriye true gonderir
 	else return false;
 }
 
 bool yigin_dolumu()
 {
 	if(islem.indis>=boyut-1)return true;//yigin dolu oldugunda geriye true gonderir
 	else return false;
 }
 
 void ekle(int sayi)
 {
 	if(yigin_dolumu()==true)//yiginda yer var mi kontrol ediliyor
	{
	  	printf("yigin dolu\n");
	}
 	else					//yiginda yer varsa parametre olarak gelen sayiyi ekliyoruz
 	{
 		islem.indis++;
 		islem.eleman[islem.indis]=sayi;
 		geri.indis++;		//en son hangi islem yapildigini geri yapisinda tutuyoruz
 		geri.eleman[geri.indis]=sayi;
 		geri.simge[geri.indis]=1;//ben en son son yapilan islemi int tipinden bir degiskende tutabilmek icin toplamaya 1 dedim
	}
 }
 
 int sil()
 {
 	int silinecek_eleman;
 	if(yigin_bosmu()==true)	//yiginda eleman olup olmadigi kontrol ediliyor
 	{	
		  return -1;
	}
	else
	{
		silinecek_eleman=islem.eleman[islem.indis];
		islem.indis--;
		geri.indis++;
		geri.eleman[geri.indis]=silinecek_eleman;	//geri alma islemi yapabilmek icin hangi deger silindi elimizde tutuyoruz
		geri.simge[geri.indis]=-1;	//silinme islemini -1 olarak aldim
		return silinecek_eleman;
	}
 }
 
 void geri_al()
 {
 	if(geri.simge[geri.indis]==-1)	//eger en son yapilan islem silmeyse
 	{
 		ekle(geri.eleman[geri.indis]);	//silinen degeri geri ekle
		printf("%d silinme islemi geri alindi\n",geri.eleman[geri.indis]);
		geri.indis-=2;	//geri alma islemi yapilirken onu tekrar geri yapisinda tutmamiza gerek yok
	}
	else
	if(geri.simge[geri.indis==1])	//eger en son yapilan islem toplamaysa
	{
		sil();	//eklenen degeri sil
		printf("%d ekleme islemi geri alindi\n",geri.eleman[geri.indis]);
		geri.indis-=2;
	}
 }
 void yazdir()
 {
 	printf("\nyigini listeleyelim:)\n");
 	for(int i=islem.indis;i>=0;i--)
 	{
 		printf("%d\n",islem.eleman[i]);
	}
 	
 }
 int main()
 {
 	
 	int sayi,secim;
 	islem.indis=-1;
 	geri.indis=-1;
 	do
	{		//kullanici istedigi surece devam etsin
 		printf("****************\n1.Ekle\n2.Sil\n3.Geri al\n4.Yazdir\n5.Kodu sonlandir\n****************\n");
		printf("Sizin seciminiz---->");
 		scanf("%d",&secim);
 		switch(secim)
 		{
 			case 1: printf("\nyigina eklemek istediginiz degeri giriniz->");
 					scanf("%d",&sayi);
 					ekle(sayi);
 					printf("Deger eklendi.\n");
 					break;
 			case 2: sayi=sil();
			 		if(sayi==-1) 	printf("yigin bos\n");
		 			else	  		printf("\n%d degeri silindi\n",sayi);
 					break;
 			case 3:	geri_al();
					break;
 			case 4: yazdir();
 					break;
 			default:if(secim!=5) 	printf("\nMenude olmayan bir deger girdiniz:(");
		 			else 			printf("\nIsleminiz sonlandi hoscakalin:)");
		}
	}while(secim!=5);
	return 0;
}

