/**  
* @file proje1.h 
* @assignment First
* @description defied the 2 struct in here and made connection with main.c and proje1.c
* @date 11/12/2024
* @author hamza khouli
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char *calisanAdi;
    char *calisanSoyadi;
    unsigned short int birimKodu;
    float maas;
    int girisYili;
}calisan;

typedef struct {
    char *birimAdi;
    unsigned short int birimKodu;
    calisan *birimCalisanlar;
}birim;



calisan yenicalisanolustur(char* ad ,char* soyad , unsigned short int birimKodu ,float maas ,int girisYili);
birim yenibirimolustur(const char *birimAdi, unsigned short int birimKodu);
void calisanyazdir( const calisan *b);
void birimyazdir(const birim *b);
void diziyebirimekle(birim **birimArr, int *size, birim eklenecekBirim);
void diziyecalisanekle(birim *birimarry , int birimsayisi, calisan eklenecek);
void tumbirimleriyazdir(birim *birimarr,int size);
void tumcalisanleriyazdir(birim *birimarry, int size);
float birimdeortalamamaas(birim birim);
void ortalmamaasalanlar(birim *birim);
void tumbirimlerdenenyuksekmaas(birim *birim, int birimsayisi);
void maasduzelt(float maas , birim *birimarry , int birimsayisi);
void birimleridosyayaekle(const char *fileName, birim *birimArr, int birimSayisi);
void calisanlaridosyayaekle(const char *fileName, birim *birimArr, int birimSayisi);
void birimleridosyadangetir(const char *fileName, birim **birimArr, int *birimSayisi);
void calisanlaridosyadangetir(const char *fileName, birim *birimArr, int birimSayisi);