#include <stdio.h>
#include <stdlib.h>

typedef double function;

// Teklif bilgilerini iceren struct
struct Teklif {
    int teklifveren_no;
    double teklif;
};

struct Teklif bid;

// Arttirma bilgilerini iceren struct
struct Arttirma {
    struct Teklif *teklifler; // Tekliflerin dinamik olarak saklanmasý için pointer ekledik
	int kazanan_no;
	int katilimci_sayisi;
};

struct Arttirma a;

// Odemeyi hesaplayan fonksiyon
function odemeyi_hesapla(struct Arttirma a, int kazanan_no) {
    double odeme = 0.0;
    int i;
    for (i = 0; i < a.katilimci_sayisi; i++) {
        if (i == kazanan_no-1) {
            odeme = a.teklifler[i].teklif;
        }
        else {
        	continue;
		}
    }
    
    return odeme;
}

// Acik arttirmayý yapan fonksiyon
function acik_arttirma(struct Arttirma a) {
	
	printf("\n TEKLIF GIRERKEN KUSURATLI SAYI GIRILMEK ISTENIYORSA '.' KULLANINIZ! (ornek:10.34) \n");
	int k; // Tüm katilimcilarin teklifini aldik
    for (k = 0; k < a.katilimci_sayisi; k++) {
    	bid.teklifveren_no = k+1;
    	printf(" %d. TEKLIF VERENIN TEKLIFINI GIRIN : ", bid.teklifveren_no);
    	bas2:
    	while (scanf("%lf", &a.teklifler[k].teklif) != 1) // Sayi disinda bir karakter girildiginde tekrar girilmesini istedik
	    {
        	printf(" HATA : GECERSIZ DEGER. TEKRAR GIRINIZ : ");
        	while (getchar() != '\n'); 
        }
        
        if(a.teklifler[k].teklif<=0) // Teklif 0 veya daha kucuk olamaz. Tekrar girilmesini istedik
		{
		printf(" HATA : TEKLIFINIZ 0 DAN BUYUK OLMALIDIR. TEKRAR GIRINIZ : ");
		goto bas2;
		}
        
		int j;
    	for(j=0;j<k;j++)
		{
			if(a.teklifler[j].teklif == a.teklifler[k].teklif) // Iki teklifin esit olmasini engelledik ve tekrar girilmesini istedik
			{
				printf("\n BU DEGER BASKA BIR KATILIMCI TARAFINDAN GIRILDI. BASKA BIR DEGER GIRILMELI! \n");
				k--;
				break;
			}
		}
    }
	
    double enyuksek_teklif = -1.0;
    int kazanan_no = -1;
    int i;
    for (i = 0; i < a.katilimci_sayisi; i++) {
    	bid.teklifveren_no = i+1;
        if (a.teklifler[i].teklif > enyuksek_teklif) { // Girilen teklifler icindeki en yuksek teklifi bulduk
            enyuksek_teklif = a.teklifler[i].teklif;
            kazanan_no = bid.teklifveren_no;
        }
    }
    
    if (kazanan_no != -1) {
        printf("\n KAZANAN %d NUMARADIR.\n", kazanan_no);

        double odeme = odemeyi_hesapla(a, kazanan_no);
        printf(" ODEME : %.2f TL\n", odeme);
    }
	else { 
        printf(" HATA : KAZANAN BULUNAMADI.\n");
    }
    
    return 0;
}

int main() {
	system("COLOR B");
	printf("=======================================");
	printf("\n ACIK ARTTIRMA PROGRAMINA HOS GELDINIZ \n \n");
	
	printf(" LUTFEN KATILIMCI SAYISINI GIRINIZ : ");
	bas:
	while (scanf("%d", &a.katilimci_sayisi) != 1) // Sayi disinda bir karakter girildiginde tekrar girilmesini istedik
	{
        printf(" HATA : GECERSIZ DEGER. TEKRAR GIRINIZ : ");
        while (getchar() != '\n'); 
    }
    if(a.katilimci_sayisi<=1) // Katilimci sayisi 2 den kucuk olamaz. Tekrar girilmesini istedik
	{
		printf(" HATA : KATILIMCI SAYISI EN AZ 2 OLMALIDIR. TEKRAR GIRINIZ : ");
		goto bas;
	}

    // Bellekte teklifler icin katilimci sayisiyla orantili olarak yer ayirdik
    a.teklifler = (struct Teklif *)malloc(a.katilimci_sayisi * sizeof(struct Teklif));

	if (a.teklifler == NULL) { // Yer ayrilmadiysa hata mesaji verip cikis yaptik.
        printf(" HATA: BELLEK AYRILAMADI.\n");
        return 1;
    }

    // Acik arttirmayi yapmasi icin bu fonksiyona girdik
    acik_arttirma(a);

    // Bellekteki alani serbest biraktik
    free(a.teklifler);

	printf("=======================================");
	
	return 0;
}

