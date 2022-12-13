#include <stdio.h>

float atlanacak_nokta_adeti = 10;
float atlanacak_noktanin_sirasi = 1;
float noktalarin_uzunlugu = 10;
float her_atlanacak_nokta_arasi_delik_sayisi = 5;
float sifir_noktasina_uzaklik = 0;
float servo_bir_tur_adim_uzunlugu = 1000;

float iki_atlanacak_nokta_arasi_uzaklik;
float delik_delinebilecek_alan_uzunlugu;
float delikler_arasi_uzaklik;

float servo_pozisyon = 0;
int anlik_delik = 0;

int main(){
    iki_atlanacak_nokta_arasi_uzaklik = servo_bir_tur_adim_uzunlugu / atlanacak_nokta_adeti;
    delik_delinebilecek_alan_uzunlugu = iki_atlanacak_nokta_arasi_uzaklik - noktalarin_uzunlugu;
    delikler_arasi_uzaklik = delik_delinebilecek_alan_uzunlugu / her_atlanacak_nokta_arasi_delik_sayisi;

    printf("atlanacak_nokta_adeti: %d\n",(long)atlanacak_nokta_adeti);
    printf("atlanacak_noktanin_sirasi: %d\n",(long)atlanacak_noktanin_sirasi);
    printf("noktalarin_uzunlugu: %d\n",(long)noktalarin_uzunlugu);
    printf("her_atlanacak_nokta_arasi_delik_sayisi: %d\n",(long)her_atlanacak_nokta_arasi_delik_sayisi);
    printf("sifir_noktasina_uzaklik: %d\n",(long)sifir_noktasina_uzaklik);
    printf("servo_bir_tur_adim_uzunlugu: %d\n",(long)servo_bir_tur_adim_uzunlugu);

    printf("iki_atlanacak_nokta_arasi_uzaklik: %d\n",(long)iki_atlanacak_nokta_arasi_uzaklik);
    printf("delik_delinebilecek_alan_uzunlugu: %d\n",(long)delik_delinebilecek_alan_uzunlugu);
    printf("delikler_arasi_uzaklik: %d\n",(long)delikler_arasi_uzaklik);

    printf("| %.1f * ", (noktalarin_uzunlugu / 2) + (delikler_arasi_uzaklik / 2));
    for (int i = 1; i < her_atlanacak_nokta_arasi_delik_sayisi; i++)
    {
        printf("%.1f * ", delikler_arasi_uzaklik);
    }
    printf("%.1f |\n\n", (noktalarin_uzunlugu / 2) + (delikler_arasi_uzaklik / 2));
    

    anlik_delik++;
    float t = (noktalarin_uzunlugu / 2) + (delikler_arasi_uzaklik / 2);
    servo_pozisyon = t;
    printf("%d: %f, %f\n", anlik_delik, servo_pozisyon, t);

    for (int i = 0; i < atlanacak_nokta_adeti - 1; i++)
    {
        for (int k = 1; k <= her_atlanacak_nokta_arasi_delik_sayisi; k++)
        {
            anlik_delik++;
            if (k == her_atlanacak_nokta_arasi_delik_sayisi)
            {
                float t = delikler_arasi_uzaklik + noktalarin_uzunlugu;
                servo_pozisyon += t;
                printf("%d: %f, %f\n", anlik_delik, servo_pozisyon, t);
            }
            else
            {
                float t = delikler_arasi_uzaklik;
                servo_pozisyon += t;
                printf("%d: %f, %f\n", anlik_delik, servo_pozisyon, t);
            }
        } 
    }

    for (int l = 1; l <= her_atlanacak_nokta_arasi_delik_sayisi; l++)
    {
        anlik_delik++;
        if (l == her_atlanacak_nokta_arasi_delik_sayisi)
        {
            float t = (noktalarin_uzunlugu / 2) + (delikler_arasi_uzaklik / 2);
            servo_pozisyon += t;
            printf("Final: %f, %f\n", servo_pozisyon, t);
        }
        else
        {
            float t = delikler_arasi_uzaklik;
            servo_pozisyon += t;
            printf("%d: %f, %f\n", anlik_delik, servo_pozisyon, t);
        }
    }  
    return 0;
}