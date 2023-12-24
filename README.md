# -> AÇIK ARTTIRMA ALGORİTMASI <-
## AÇIK ARTTIRMA ALGORİTMASI NEDİR? NE İŞE YARAR? 
* Bir ürünün açık arttırmaya çıktığında kazananı ve ödeyeceği miktarı belirlemek için kolaylık sağlayan bir programdır. </br>
* Özellikle çok sayıda katılım olduğunda işleri oldukça kolaylaştıran bir tür yazılımdır.</br>
* Konsol üzerinden uygulanır. </br>
## AÇIK ARTTIRMA VE OYUN TEORİSİ İLİŞKİSİ 
Oyun teorisi karar verme süreçlerini ve stratejik etkileşimleri inceleyen bir matematik dalıdır. Açık arttırma da bu başlıkları içeren bir oyun olarak düşünülebilir.
Açık arttırmadaki ne zaman teklif verileceği, ne kadar verileceği gibi stratejik yönleri oyun teorisi başlığı altında düşünülebilir.
## KODLARKEN KULLANILAN BAZI YAPILAR
### `struct` YAPISI:
`struct` komutu bir yapı içinde birden fazla değer taşımamızı ve gerektiğinde o yapıdan istenilen değeri çağırarak kullanmamızı sağlar. </br>
ÖRNEK:
```
#include <stdio.h>
#include <stdlib.h>

//struct asagidaki gibi tanimlanir
struct Ogrenci {
    int numara;
    char isim[50];
    float not;
};

int main() {
    struct Ogrenci ogrenci1; //bu sekilde struct yapisini cagirmak icin ogrenci1 komutunu kullaniyoruz

    // struct içindeki değerlerin atanması
    ogrenci1.numara = 1230505004;
    ogrenci1.not = 85;

    // struct içindeki değerlerin kullanımı
    printf("Ogrenci Numarasi: %d\n", ogrenci1.numara);
    printf("Ogrenci Ismi: %s\n", ogrenci1.isim);
    printf("Ogrenci Notu: %f\n", ogrenci1.not);

    return 0;
}
```
### `typedef` YAPISI:
`typedef` komutu bir değer ataması yaparken kullanılan komutları belirleyeceğimiz şekilde değiştirmemizi sağlar.
ÖRNEK:
```
#include <stdio.h>
#include <stdlib.h>
typedef struct yapi; // typdef sayesinde artik struct kullanmam gereken yerde struct degil yapi kullanacagim

yapi Ogrenci {
    int numara;
    char isim[50];
    float not;
};

int main() {
    yapi Ogrenci ogrenci1; 

    ogrenci1.numara = 1230505004;
    ogrenci1.not = 85;

    printf("Ogrenci Numarasi: %d\n", ogrenci1.numara);
    printf("Ogrenci Ismi: %s\n", ogrenci1.isim);
    printf("Ogrenci Notu: %f\n", ogrenci1.not);

    return 0;
}
```
### İSARETÇİLER (POINTERLAR):
Pointerlar bellekteki bir verinin adresini tutmak için kullanılır. Bu verilerin saklandığı bellekteki konumları işaret ederek verilere erişimi ve işlemleri kolaylaştırır. </br>
ÖRNEK:
```
#include <stdio.h>
#include <stdlib.h>

int main() {
    int sayi = 10;
    int *isaretci;

    isaretci = &sayi; // sayinin adresini isaretci pointerına atadık

    printf("x in degeri: %d\n", x); // x in değerini yazdırır
    printf("isaretci pointer ının gösterdiği deger: %d\n", *isaretci); // isaretci pointerının gösterdiği değeri yazdırır

    return 0;
}
```
## PROGRAM NASIL ÇALIŞTIRILIR:
* Repository'de paylaşılan kod çalıştırılır.
* Önümüze gelen ekranda sırasıyla şu işlemler yapılır :
1. Önce katılımcı sayısı girilir ve `enter` tuşlanır.
2. Program sırasıyla katılımcılardan teklifleri isteyecektir. Teklifler girilir ve `enter` tuşlanır.
3. Program kazananı ve ödeyeceği miktarı konsola yazdırır. </br></br>
<i><b>PROGRAM SİZ KODU ÇALIŞTIRDIĞINIZDA SİZİ YÖNLENDİRECEKTİR ASLINDA YUKARDAKİLERİN HİÇBİR ANLAMI YOKTUR :)</b><i/>
