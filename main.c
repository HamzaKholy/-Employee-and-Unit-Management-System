/**  
* @file main.c  
* @assignment First
* @description for testing functions
* @date 11/12/2024
* @author hamza khouli
*/
#include <stdio.h>
#include <stdlib.h>
#include "proje1.h"


int main(int argc , char *argv[]){
    if (argc < 3)
    {
        printf("error");
        return 1;
    }
// argv[0] = result
// argv[1] = b.txt
// argv[2] = c.txt
 char *birimfile = argv[1];
 char *calisanfile = argv[2];   
     
 birim *birimArr = NULL;
 int birimsayisi = 0;


birim a = yenibirimolustur("meta",101);
birim b = yenibirimolustur("turknet",102);
birim c = yenibirimolustur("BMW",103);

diziyebirimekle(&birimArr,&birimsayisi,a);
diziyebirimekle(&birimArr,&birimsayisi,b);
diziyebirimekle(&birimArr,&birimsayisi,c);

birimleridosyadangetir(birimfile,&birimArr,&birimsayisi); 

 

calisan a2 = yenicalisanolustur("ahmet","kan",101,1400,2023);
calisan a3 = yenicalisanolustur("mehmet","can",103,200,1999);
calisan a4 = yenicalisanolustur("zehra","nur",106,1200,2023);

diziyecalisanekle(birimArr , birimsayisi,a2);
diziyecalisanekle(birimArr , birimsayisi,a3);
diziyecalisanekle(birimArr , birimsayisi,a4);
 
calisanlaridosyadangetir(calisanfile,birimArr,birimsayisi);


//calisanyazdir(&a2);
//birimyazdir(&a);
//tumbirimlerdenenyuksekmaas(birimArr , birimsayisi);
tumcalisanleriyazdir(birimArr , birimsayisi);
//maasduzelt(1000 , birimArr , birimsayisi);
//printf("%.2f",birimdeortalamamaas(a));
//ortalmamaasalanlar(&a);
//tumcalisanleriyazdir(birimArr , birimsayisi);



birimleridosyayaekle(birimfile,birimArr,birimsayisi);
calisanlaridosyayaekle(calisanfile,birimArr,birimsayisi);





for (int i = 0; i < birimsayisi; i++) {
    free(birimArr[i].birimAdi);
    for (int j = 0; j < 20; j++) {
        if (birimArr[i].birimCalisanlar[j].calisanAdi != NULL) {
            free(birimArr[i].birimCalisanlar[j].calisanAdi);
            free(birimArr[i].birimCalisanlar[j].calisanSoyadi);
        }
    }
    free(birimArr[i].birimCalisanlar);
}
free(birimArr);


 

 




} 
