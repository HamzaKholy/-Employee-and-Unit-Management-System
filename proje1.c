/**  
* @file proje1.c
* @assignment First
* @description all functions were writen here
* @date 11/12/2024
* @author hamza khouli
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proje1.h"

calisan yenicalisanolustur(char *ad, char *soyad, unsigned short int birimKodu, float maas, int girisYili)
{
    //This function takes all the necessary parameters then returns a struct from claisan type
    calisan a;
    a.calisanAdi = (char *)calloc(30, sizeof(char));
    a.calisanSoyadi = (char *)calloc(30, sizeof(char));
    strcpy(a.calisanAdi, ad);
    strcpy(a.calisanSoyadi, soyad);
    a.birimKodu = birimKodu;
    a.maas = maas;
    a.girisYili = girisYili;
    return a;
};
birim yenibirimolustur(const char *birimAdi, unsigned short int birimKodu)
{
    //This function also takes all the necessary information to return  them into a struct form birim type
    birim a;
    a.birimAdi = (char *)malloc(30 * sizeof(char));
    a.birimCalisanlar = (calisan *)malloc(20 * sizeof(calisan));
    strcpy(a.birimAdi, birimAdi);
    a.birimKodu = birimKodu;

    for (int i = 0; i < 20; i++)
    {
        a.birimCalisanlar[i].calisanAdi = NULL;    
        a.birimCalisanlar[i].calisanSoyadi = NULL; 
    }
    return a;
}

void calisanyazdir(const calisan *b)
{
    //Prints the calisan's informations
    if (b->calisanAdi != NULL)
    {
        printf("==============\n");
        printf("Adi: %s \n", b->calisanAdi);
        printf("Soyadi: %s \n", b->calisanSoyadi);
        printf("birim kodu: %d \n", b->birimKodu);
        printf("maas: %.2f \n", b->maas);
        printf("giris yili: %d \n", b->girisYili);
        printf("==============\n");

    }
}
void birimyazdir(const birim *b)
{
    //Prints the birim's informations

    printf("Adi: %s \n", b->birimAdi);
    printf("birim Kodu: %d \n", b->birimKodu);
}

void diziyebirimekle(birim **birimArr, int *size, birim eklenecekBirim) {
    //I have created a birim type array to store all the birims inside of it and this function will 
    //add the new birim was created in the main or in the file  to the array
    //Also checks if there is any duplicates either in the file or the main
    for (int i = 0; i < *size; i++) {
        if ((*birimArr)[i].birimKodu == eklenecekBirim.birimKodu) {
            return;
        }
    }

    *birimArr = (birim *)realloc(*birimArr, (*size + 1) * sizeof(birim));
    (*birimArr)[*size] = eklenecekBirim;
    (*size)++;
}

void diziyecalisanekle(birim *birimArr, int birimSayisi, calisan eklenecek) {
    //This function will take the created birim array and the claisan wich needs to be added to the array
    // and first checks if the calisan is already existing if not adds it to the array
    for (int i = 0; i < birimSayisi; i++) {
        for (int j = 0; j < 20; j++)
        {
           if (birimArr[i].birimCalisanlar[j].calisanAdi != NULL &&
                    strcmp(birimArr[i].birimCalisanlar[j].calisanAdi, eklenecek.calisanAdi) == 0 &&
                    strcmp(birimArr[i].birimCalisanlar[j].calisanSoyadi, eklenecek.calisanSoyadi) == 0 &&
                    birimArr[i].birimCalisanlar[j].maas == eklenecek.maas &&
                    birimArr[i].birimCalisanlar[j].girisYili == eklenecek.girisYili){
                        return;
                    }


        if (birimArr[i].birimKodu == eklenecek.birimKodu) {
            for (int j = 0; j < 20; j++) {
                if (birimArr[i].birimCalisanlar[j].calisanAdi == NULL) {
                    birimArr[i].birimCalisanlar[j] = eklenecek;
                    return;
                }
            }}
        }
    }
}


void tumbirimleriyazdir(birim *birimarr, int size)
{
    //Simple function that prints all the birim using for loop then using birimyazdir function
    for (int i = 0; i < size; i++)
    {

        birimyazdir(&birimarr[i]);
    }
}
void tumcalisanleriyazdir(birim *birimarry, int size){
    //This function also prints all the calisans but first check if its null or not
for (int i = 0; i < size; i++)
{
    for (int j = 0; j < 20; j++)
    {
        if (birimarry[i].birimCalisanlar[j].calisanAdi != NULL)
        {
            calisanyazdir(&birimarry[i].birimCalisanlar[j]);
        }
        
    }
    
}

}


float birimdeortalamamaas(birim birim)
{
    //The function will take a specific birim to calculate the average salary in it then returns it as a float type
    float toplam = 0;
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        if (birim.birimCalisanlar[i].calisanAdi != NULL)
        {
            toplam += birim.birimCalisanlar[i].maas;
            count++;
        }
    }
    return toplam / count;
}
void ortalmamaasalanlar(birim *birim)
{
    //This function takes all the birims by taking the birim array
    // then check the highest payed calisan and prints there informations

    printf("ortalama maas: %.2f \n", birimdeortalamamaas(*birim));
    printf("ortalama maas uzerinde maas alan calisanlar:\n ");
    float ortalama_maas = birimdeortalamamaas(*birim);
    for (int i = 0; i < 20; i++)
    {
        if (birim->birimCalisanlar[i].calisanAdi != NULL)
        {
            if (birim->birimCalisanlar[i].maas > ortalama_maas)
            {
                calisanyazdir(&birim->birimCalisanlar[i]);
            }
        }
    }
}
void tumbirimlerdenenyuksekmaas(birim *birim, int birimsayisi)
{
 //This function also takes all the birims by taking the birim array 
 //then check the most payed calisan in every birim and prints there informations
    for (int i = 0; i < birimsayisi; i++)
    {
        calisan *yuksekalanmaas = NULL;
        for (int j = 0; j < 20; j++)
        {
            if (birim[i].birimCalisanlar[j].calisanAdi != NULL && (yuksekalanmaas == NULL || birim[i].birimCalisanlar[j].maas > yuksekalanmaas->maas))
            {
                yuksekalanmaas = &birim[i].birimCalisanlar[j];
            }
        }
        if (yuksekalanmaas != NULL)
        {
            printf("%s biriminde en yuksek alan maas: \n", birim[i].birimAdi);
            calisanyazdir(yuksekalanmaas);
        }
    }
}
void maasduzelt(float maas , birim *birimarry , int birimsayisi){
    //The function checks in all the calisans inside the birim array and checks
    // if the calisan have ben working for more then 10 years and if have been taking 
    //less then the price wich was sent but the function if its true then changes his salary to the new sent price

    for (int i = 0; i < birimsayisi; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (birimarry[i].birimCalisanlar[j].calisanAdi != NULL)
            {
                if (birimarry[i].birimCalisanlar[j].maas < maas && (2024 - birimarry[i].birimCalisanlar[j].girisYili) > 10)
                {
                    birimarry[i].birimCalisanlar[j].maas = maas;
                    
                }
                
            }
            
        }
        
    }
    
}
void birimleridosyayaekle(const char *fileName, birim *birimArr, int birimSayisi) {
    //This function will open the birim file and prints to it all the birims inside the birim array
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        return;
    }

    for (int i = 0; i < birimSayisi; i++) {
       
        fprintf(file, "%s,%d\n", birimArr[i].birimAdi, birimArr[i].birimKodu);
      }

    fclose(file);
}
void calisanlaridosyayaekle(const char *fileName, birim *birimArr, int birimSayisi) {
    //This function also opens the calisan file and prints all the calisan informations using the birim array to the file

    FILE *file = fopen(fileName, "w"); 
    if (file == NULL) {
        return;
    }


    for (int i = 0; i < birimSayisi; i++) {
        for (int j = 0; j < 20; j++) {
            if (birimArr[i].birimCalisanlar[j].calisanAdi != NULL) {
                fprintf(file, "%s,%s,%d,%.2f,%d\n",
                        birimArr[i].birimCalisanlar[j].calisanAdi,
                     birimArr[i].birimCalisanlar[j].calisanSoyadi,
                        birimArr[i].birimCalisanlar[j].birimKodu,
                   birimArr[i].birimCalisanlar[j].maas,
                 birimArr[i].birimCalisanlar[j].girisYili);
            }
        }
    }

    fclose(file);
}

void birimleridosyadangetir(const char *fileName, birim **birimArr, int *birimSayisi) {
    //The function will open the birim file and reads all the birim informations 
    //then send them to the other function wich adds the birim to the birim array with checking if it was duped before
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return;
    }

    char birimAdi[30];
    unsigned short birimKodu;
    birimKodu = 0;
    

    while (fscanf(file, "%29[^,],%hu\n", birimAdi, &birimKodu) == 2) {
        birim newBirim = yenibirimolustur(birimAdi, birimKodu);
        diziyebirimekle(birimArr, birimSayisi, newBirim);
    }

    fclose(file);
}


void calisanlaridosyadangetir(const char *fileName, birim *birimArr, int birimSayisi) {
    //This function will open the calisan file and also reads all the calisans informations
    // to be sent to the function wich adds the calisan to the birim array checking for duped calisan also
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        return;
    }

    char calisanAdi[30], calisanSoyadi[30];
    unsigned short birimKodu;
    float maas;
    int girisYili;

    while (fscanf(file, "%29[^,],%29[^,],%hu,%f,%d\n",
         calisanAdi, calisanSoyadi, &birimKodu, &maas, &girisYili) == 5) {
           
           calisan newCalisan = yenicalisanolustur(calisanAdi, calisanSoyadi, birimKodu, maas, girisYili);
        diziyecalisanekle(birimArr, birimSayisi, newCalisan);
    }

    fclose(file);
}



