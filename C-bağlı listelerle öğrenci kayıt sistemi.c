#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list {
    int ogrenci_numarasi;
    char ogrenci_ismi[100];
    char ogrenci_soy_ismi[100];
    struct list *sonraki;
} liste;
liste *ilk = NULL, *son = NULL, *yeni, *silGecici, *gecici;
 
void menu();
void ekle();
void sil(int );
void listele();
void arama(int );
void ekranTemizle();
void bekle();

int main() {
    printf("Merhaba. Öğrenci sistemine hoş geldiniz.\n");
    
    int ogrenci_numarasi1 = 123456;
    char ogrenci_ismi1[100]="Kaan";
    char ogrenci_soy_ismi1[100]="Duman";
    
    int ogrenci_numarasi2 = 123457;
    char ogrenci_ismi2[100]="Atlas";
    char ogrenci_soy_ismi2[100]="Duman";
    
    ekle(ogrenci_numarasi1,ogrenci_ismi1,ogrenci_soy_ismi1);
    ekle(ogrenci_numarasi2,ogrenci_ismi2,ogrenci_soy_ismi2);
    
    while (1) {
        menu();
    }
    return 0;
}
 
void ekle(int veri,char veri1[100],char veri2[100]) {
    yeni = (liste *) malloc(sizeof (liste));
    yeni->ogrenci_numarasi = veri;
    strcpy(yeni->ogrenci_ismi,veri1);
    strcpy(yeni->ogrenci_soy_ismi,veri2);
    yeni->sonraki = NULL;
    if (ilk == NULL) { 
        ilk = yeni;
        son = ilk;
    } else {
        son->sonraki = yeni;
        son = son->sonraki;
    }
}
 
void sil(int veri) {
    int kontrol = 0;
    if (ilk->ogrenci_numarasi == veri) {
        silGecici = ilk;
        ilk = ilk->sonraki;
        free(silGecici);
        kontrol = 1;
    } else {
        gecici = ilk;
        while (gecici->sonraki != NULL) {
            if (gecici->sonraki->ogrenci_numarasi == veri) {
                kontrol = 1;
                silGecici = gecici->sonraki; 
                if (silGecici == son) 
                    son = gecici;
                gecici->sonraki = silGecici->sonraki; 
                free(silGecici); 
                break;
            }
            gecici = gecici->sonraki;
        }
    }
    if (kontrol == 0)
        printf("Silmek istediğiniz öğrenci sistemde yoktur...\n");
    else
        printf("%d öğrenci numarasıyla kayıtlı öğrenci sistemden silinmiştir...\n", veri);
}
 
void listele() {
    gecici = ilk;
    while (gecici != NULL) {
        printf("öğrenci ismi:%s\n",gecici->ogrenci_ismi);
        printf("öğrenci soy ismi:%s\n",gecici->ogrenci_soy_ismi);
        printf("öğrenci numarası:%d\n",gecici->ogrenci_numarasi);
        gecici = gecici->sonraki;
    }
}
 
void arama(int aranan) {
    int kontrol = 0;
    gecici = ilk;
    while (gecici != NULL) {
        if (aranan == gecici->ogrenci_numarasi) {
            kontrol = 1;
            break;
        }
        gecici = gecici->sonraki;
    }
    if (kontrol == 1)
        printf("\nAranan öğrencinin ismi:%s\nAranan öğrencinin soy ismi:%s\nAranan öğrencinin numarası:%d\n",gecici->ogrenci_ismi,gecici->ogrenci_soy_ismi, aranan);
    else
        printf("\nAranan öğrenci bulunamamıştır...\n");
}
 
void menu() {
    int secim, ogrenci_numarasi;
    char ogrenci_ismi[100];
    char ogrenci_soy_ismi[100];
    printf("\n1-Ekleme\n");
    printf("2-Arama\n");
    printf("3-Listeleme\n");
    printf("4-Silme\n");
    printf("5-Çıkış\n");
    printf("Seçiminiz:");
    scanf("%d", &secim);
    switch (secim) {
        case 1:
            printf("Öğrencinin numarasını giriniz:");
            scanf("%d", &ogrenci_numarasi);
            printf("Öğrencinin ismini giriniz:");
            scanf("%s",ogrenci_ismi);
            printf("Öğrencinin soy ismini giriniz:");
            scanf("%s",ogrenci_soy_ismi);
            ekle(ogrenci_numarasi,ogrenci_ismi,ogrenci_soy_ismi);
            printf("%s %s isimli %d numaralı öğrenci sisteme eklendi.\n",ogrenci_ismi,ogrenci_soy_ismi,ogrenci_numarasi);
            break;
        case 2:
            if (ilk == NULL) {
                printf("Liste boş. Lütfen eleman ekledikten sonra arama işlemini yapınız..\n");
                break;
            }
            printf("Öğrencinin numarasını giriniz:");
            scanf("%d", &ogrenci_numarasi);
            arama(ogrenci_numarasi);
            break;
        case 3:
            if (ilk == NULL) {
                printf("Liste boş. Lütfen eleman ekledikten sonra listeleme işlemini yapınız..\n");
                break;
            }
            listele();
            break;
        case 4:
            if (ilk == NULL) {
                printf("Liste boş. Lütfen eleman ekledikten sonra silme işlemini yapınız..\n");
                break;
            }
            printf("Öğrencinin numarasını giriniz:");
            scanf("%d", &ogrenci_numarasi);
            sil(ogrenci_numarasi);
            break;
        case 5:
            printf("Çıkış yapılıyor...İyi günler dilerim.\n");
            exit(0);
            break;
        default:
            printf("Hatalı seçim yaptınız.\n");
    }
}
