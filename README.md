<p align="center">
  <img src="https://github.com/ehabesdev/ehabesdev/blob/main/banner/push_swape.png?raw=true" alt="Push_swap 42 project badge"/>
</p>

# 🥞 Push_Swap

[![Dil](https://img.shields.io/badge/Dil-C-blue.svg)](https://en.wikipedia.org/wiki/C_programming_language)
[![Okul](https://img.shields.io/badge/Okul-42%20Network-black.svg)](https://www.42network.org/)
[![Norm](https://img.shields.io/badge/Norm-v4-brightgreen.svg)](https://github.com/42school/norminette/blob/master/pdf/en.norm.pdf)

Bu proje, [42 Okulları](https://www.42kocaeli.com.tr) müfredatının bir parçasıdır. Temel amaç, verilen bir tamsayı yığınını (stack A) yalnızca sınırlı sayıda ve önceden tanımlanmış işlemler kullanarak en az hamle ile sıralamaktır. İkinci bir yığın (stack B) yardımcı olarak kullanılabilir.

## 📜 Proje Hakkında

`push_swap` programı, bir dizi tamsayıyı argüman olarak alır ve bu sayıları A yığınında artan sırada sıralamak için gereken en optimize komut dizisini standart çıktıya yazar. Hedef, sıralamayı mümkün olan en az komutla tamamlamaktır.

Proje, algoritma karmaşıklığı, veri yapısı yönetimi (yığınlar) ve optimizasyon konularında derinlemesine bir anlayış gerektirir.

## ✨ Temel Özellikler

* **Girdi Doğrulama:** Geçersiz girdileri (sayı olmayanlar, tekrar edenler, taşma sınırları dışındakiler) kontrol eder ve hata mesajı verir.
* **Verimli Sıralama Algoritması:** Farklı girdi boyutları için optimize edilmiş sıralama stratejileri kullanır.
* **Sınırlı İşlemler:** Yalnızca izin verilen yığın işlemlerini kullanır.
* **Norm V4 Uyumluluğu:** Kod, 42 Okulları'nın katı kodlama standartlarına (Norminette v4) uygundur.
* **Modüler Tasarım:** Kod, okunabilirlik ve bakım kolaylığı için mantıksal modüllere ayrılmıştır.
* **Bonus: `checker` Program:** `push_swap` tarafından üretilen komutların doğruluğunu kontrol eden bir yardımcı program içerir.

## ⚙️ Nasıl Çalışır?

1.  **Argüman Ayrıştırma (Parsing):** Program, komut satırı argümanlarını okur, doğrular ve tamsayılara dönüştürerek A yığınına ekler.
2.  **İndeksleme/Normalleştirme:** Sayıların sıralı haldeki pozisyonlarına göre indekslenmesi (veya normalize edilmesi), sıralama algoritmasının daha verimli çalışmasını sağlar. Bu, gerçek değerler yerine 0'dan N-1'e kadar olan sıralı indekslerle çalışmayı kolaylaştırır.
3.  **Sıralama Algoritması:**
    * **Küçük Yığınlar (Örn: 2, 3 veya 5 eleman):** Bu durumlar için önceden hesaplanmış, en az hamle gerektiren sabit komut dizileri kullanılır.
    * **Büyük Yığınlar:** Bu projede **Gruplama (Chunking)** yöntemi tercih edilmiştir. Aşağıda bu yaklaşım ve Radix Sort ile farkları açıklanmaktadır.

### 🧩 Kullanılan Sıralama Yaklaşımı: Gruplama (Chunking)

Bu projede, büyük yığınları sıralamak için "Gruplama" (Chunking) adı verilen bir strateji kullanılmıştır. Bu yöntemin temel mantığı şöyledir:

1.  **Gruplara Ayırma:** Sıralanmış hedef indeksler (0'dan N-1'e kadar) belirli sayıda eşit veya yaklaşık eşit boyutlu gruplara (chunk) ayrılır. Grup sayısı, genellikle yığındaki eleman sayısına bağlı olarak dinamik olarak belirlenir (örneğin, 100 eleman için 5 grup, 500 eleman için 11 grup gibi).
2.  **Grup İşleme:** Algoritma, bu grupları sırayla (veya bazen stratejik olarak farklı sıralarda) işler. Her adımda, mevcut hedef gruba ait olan sayılar A yığınından B yığınına taşınır.
3.  **Optimize Taşıma:** A yığınından B yığınına bir sayı taşınırken, hedef gruptaki sayılardan hangisinin en az `ra`/`rra` hamlesiyle A yığınının tepesine getirilebileceği hesaplanır ve o sayı B'ye itilir (`pb`). Bu, gereksiz rotasyonları azaltmaya yardımcı olur. Genellikle, gruptaki hem en küçük hem de en büyük indekse sahip elemanların A yığınının tepesine olan uzaklıkları kontrol edilir ve daha az hamle gerektiren tercih edilir.
4.  **B'den A'ya Geri Taşıma:** B yığınına yeterli sayıda eleman (genellikle bir veya daha fazla grup tamamlandığında veya B yığını dolmaya yaklaştığında) itildikten sonra, B yığınındaki en büyük (veya hedeflenen sıradaki) eleman A yığınının tepesine getirilir (`pa`). B'den A'ya taşıma sırasında, B yığınındaki en büyük elemanı tepeye getirmek için en uygun `rb`/`rrb` hamlesi seçilir.
5.  **Tekrarlama:** Tüm sayılar sıralı bir şekilde A yığınına geri dönene kadar grup işleme ve taşıma adımları tekrarlanır.

**🤔 Neden Gruplama Yöntemi Tercih Edildi?**

* **📖 Anlaşılabilirlik:** Radix Sort'a kıyasla bazı geliştiriciler için mantığı daha sezgisel olabilir. Gruplar halinde düşünmek, problemi daha küçük alt problemlere ayırmayı kolaylaştırabilir.
* **🎨 Esneklik:** Hangi elemanın B'ye itileceği konusunda (grup içindeki en yakın elemanı seçme gibi) optimizasyonlar yapmaya olanak tanır.
* **🚀 Performans:** Doğru grup boyutu seçimi ve taşıma optimizasyonları ile özellikle belirli veri dağılımlarında oldukça verimli sonuçlar üretebilir ve Radix Sort ile rekabet edebilir veya daha iyi performans gösterebilir.

### 🆚 Gruplama (Chunking) vs. Radix Sort

`push_swap` probleminde sıkça kullanılan bir diğer popüler yöntem Radix Sort (Taban Sıralaması)'dur. İki yöntemin temel farkları şunlardır:

* **🔢 Radix Sort:**
    * Sayıların indekslerinin **ikili (binary) gösterimi** üzerinden çalışır.
    * Her adımda, sayıların belirli bir biti (en anlamsız bitten başlayarak) kontrol edilir.
    * Bite göre (0 veya 1) sayılar A'dan B'ye itilir (`pb`) veya A'da bırakılır (`ra`).
    * Bir bit pozisyonu için tüm sayılar işlendikten sonra, B'deki sayılar tekrar A'ya alınır (`pa`).
    * Bu işlem, en anlamlı bite kadar tüm bitler için tekrarlanır.
    * Genellikle büyük ve rastgele dağılmış veri setlerinde çok verimlidir. Mantığı tamamen bit manipülasyonuna dayanır.
* **🧩 Gruplama (Chunking):**
    * Sayıların indekslerinin **değer aralıkları (gruplar)** üzerinden çalışır.
    * Sayıları bitlerine göre değil, ait oldukları **indeks grubuna** göre B'ye iter.
    * Hangi sayının B'ye itileceği konusunda daha **stratejik kararlar** (en az hamle gerektireni seçme gibi) alınabilir.
    * Radix'e göre implementasyonu ve ince ayarı (grup boyutu gibi) farklı bir yaklaşım gerektirir.

Her iki yöntemin de amacı en az hamle ile sıralama yapmaktır ve farklı durumlarda birbirlerine göre avantajları veya dezavantajları olabilir. Bu projede Gruplama yöntemi, sağladığı esneklik ve optimize taşıma potansiyeli nedeniyle tercih edilmiştir.

4.  **Komut Üretimi:** Algoritmanın adımları, izin verilen `push_swap` komutlarına (`sa`, `pb`, `ra` vb.) çevrilir.
5.  **Çıktı:** Optimize edilmiş komut listesi standart çıktıya yazdırılır.

## 🛠️ Kullanım ve Derleme

1.  **Projeyi Klonlama:**
    Öncelikle projeyi GitHub deposundan yerel makinenize klonlayın:
    ```bash
    git clone git@github.com:ehabesdev/push_swap.git push_swap
    cd push_swap
    ```

2.  **Derleme:**
    Projeyi derlemek için kök dizinde aşağıdaki komutları kullanabilirsiniz:
    * **Zorunlu Kısım (`push_swap`):**
        ```bash
        make
        ```
        Bu komut, `push_swap` yürütülebilir dosyasını oluşturur.
      
    * **Bonus Kısım (`checker`):**
        ```bash
        make bonus
        ```
        Bu komut, `checker` yürütülebilir dosyasını oluşturur.
      
**`push_swap` Kullanımı:**

Programı çalıştırmak için sıralanacak tamsayıları argüman olarak verin:

```bash
./push_swap 4 67 3 8 2 90
```

**`checker` (Bonus) Kullanımı:**

`checker`, standart girdiden komutları okur ve verilen başlangıç yığınını bu komutlarla sıralayıp sıralamadığını kontrol eder.

* **Manuel Komut Girişi:**

    ```bash
    ./checker 4 67 3 8 2 90
    # Komutları buraya girin (örn: sa, pb, ra), her biri yeni satırda
    # Girişi bitirmek için CTRL+D
    ```
* **`push_swap` Çıktısı ile Kullanım:**

  * **Basit Örnek:**

    ```bash
    ARG="4 67 3 8 2 90"; ./push_swap $ARG | ./checker $ARG
    ```
  
  * **`perl` ile Rastgele Sayılar:**

    ```bash
    ARG=$(perl -MList::Util=shuffle -e 'my @arr = (-1000..1000); @arr = shuffle(@arr); print join(" ", @arr[0..5]);')
    ```
  
  * **`perl` ile Daha Büyük Rastgele Sayılar:**

    ```bash
    # Not: Perl komutunun çalışması için sisteminizde Perl ve List::Util modülünün kurulu olması gerekir.
    # Daha büyük rastgele sayılarla (örn: 701 adet, -1000 ile 1000 arasında):

    ARG=$(perl -MList::Util=shuffle -e 'my @arr = (-1000..1000); @arr = shuffle(@arr); print join(" ", @arr[0..700]);')
    ./push_swap $ARG | ./checker $ARG

    ```checker`, yığın doğru sıralandıysa `OK`, sıralanmadıysa `KO` çıktısı verir. Hatalı bir komut girilirse `Error` verir.
    ```

  * **Performans Kontrolü (Adım Sayısı):**
    * **100 Sayı İçin:**
      
       ```bash
       # Hedef: 100 sayı için < 700 adım (Minimum geçer not: 80)

       ARG=$(perl -MList::Util=shuffle -e 'my @arr = (-1000..1000); @arr = shuffle(@arr); print join(" ", @arr[0..99]);')
       ./push_swap $ARG | wc -l
       ```
    * **500 Sayı İçin:**
      
       ```bash
       # Hedef: 500 sayı için < 5500 adım (Tam puan / Bonus için)

       ARG=$(perl -MList::Util=shuffle -e 'my @arr = (-1000..1000); @arr = shuffle(@arr); print join(" ", @arr[0..499]);')
       ./push_swap $ARG | wc -l
       ```

---

## 📚 Kullanılabilir İşlemler

| Komut | Açıklama                                           |
| :---- | :------------------------------------------------- |
| `sa`  | `swap a`: A yığınındaki ilk iki elemanı yer değiştirir. |
| `sb`  | `swap b`: B yığınındaki ilk iki elemanı yer değiştirir. |
| `ss`  | `sa` ve `sb` işlemlerini aynı anda yapar.          |
| `pa`  | `push a`: B yığınındaki ilk elemanı A yığınının başına alır. |
| `pb`  | `push b`: A yığınındaki ilk elemanı B yığınının başına alır. |
| `ra`  | `rotate a`: A yığınındaki tüm elemanları bir pozisyon yukarı kaydırır (ilk eleman sona geçer). |
| `rb`  | `rotate b`: B yığınındaki tüm elemanları bir pozisyon yukarı kaydırır (ilk eleman sona geçer). |
| `rr`  | `ra` ve `rb` işlemlerini aynı anda yapar.          |
| `rra` | `reverse rotate a`: A yığınındaki tüm elemanları bir pozisyon aşağı kaydırır (son eleman başa geçer). |
| `rrb` | `reverse rotate b`: B yığınındaki tüm elemanları bir pozisyon aşağı kaydırır (son eleman başa geçer). |
| `rrr` | `rra` ve `rrb` işlemlerini aynı anda yapar.         |


## 🚀 Geliştirme Süreci

Bu projenin her aşaması (gereksinim analizi, yol haritası oluşturma, dosya yapısı tasarımı, kodlama, test etme) detaylı bir şekilde ele alındı. Geliştirme sürecinde karşılaşılan zorluklar, özellikle algoritma optimizasyonu ve Norm V4 kurallarına sıkı uyum gibi konular, dikkatli çalışma ve araştırma ile aşıldı.

## 🙏 Teşekkürler

Bu projenin geliştirilmesi sürecinde sağlanan eğitim ve kaynaklar için **42 Kocaeli** ekibine teşekkür ederim. Ayrıca, proje süresince fikir alışverişinde bulunduğum veya karşılaştığım zorluklarda yardımcı olan tüm **42 Network öğrencilerine (cadet)** ve yol gösterici olan çeşitli **çevrimiçi kaynaklara** minnettarım.
