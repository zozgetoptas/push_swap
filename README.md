# Push Swap - Sayı Sıralama Projesi

## Proje Hakkında

**Push Swap**, verilen sayıları iki adet yığın (stack) kullanarak minimum sayıda işlem ile sıralayan optimize edilmiş bir C programıdır. Bu proje, 42 Okulu algoritma zorluğu olarak tasarlanmıştır.

## Amaç

İki stack (A ve B) kullanan sıralama algoritmasıdır:
- **Stack A**: Giriş(input) ve çıkış(output) için kullanılır
- **Stack B**: Yardımcı stack olarak kullanılır

Amaç, Stack A'daki sayıları artan sırada sıralamaktır ve bunu minimum sayıda işlem ile yapmaktır.

## Desteklenen İşlemler

### Stack A Üzerinde İşlemler
- **sa**: Stack A'nın ilk iki elemanını yer değiştirir
- **pa**: Stack B'nin en üstündeki elemanı Stack A'ya taşır
- **ra**: Stack A'nın tüm elemanlarını bir pozisyon yukarıya kaydırır
- **rra**: Stack A'nın tüm elemanlarını bir pozisyon aşağıya kaydırır

### Stack B Üzerinde İşlemler
- **pb**: Stack A'nın en üstündeki elemanı Stack B'ye taşır
- **rb**: Stack B'nün tüm elemanlarını bir pozisyon yukarıya kaydırır
- **rrb**: Stack B'nün tüm elemanlarını bir pozisyon aşağıya kaydırır

## Sıralama Algoritmaları

Program, input boyutuna göre en uygun sıralama algoritmasını seçer:

| Eleman Sayısı | Algoritma | Açıklama |
|---|---|---|
| 2 | Easy Sort | 1 işlem |
| 3 | Easy Sort | En fazla 2-3 işlem |
| 4-5 | Easy Sort | Optimizasyonlu sıralama |
| 6+ | Chunk Sort / Hybrid | Input boyutuna göre optimize edilmiş |

### 1. Easy Sorting (2-5 Eleman)
- Küçük boyutlu inputlar için özel hareket kombinasyonları
- Minimum işlem sayısı garantisi

### 2. Chunk Sort (6+ Eleman)
- Stack A'yı chunk'lara böler
- Dinamik chunk boyutu hesaplayıp, Stack B'ye taşır
- Hybrid yöntem ile sıralama optimizasyonu

### 3. Normalizasyon (Normalize)
- Input sayıları 0'dan başlayan rank değerlerine dönüştürü
- Sayıların aralığını görmezden gelerek optimize eder

## Proje Yapısı

```
push_swap/
├── Makefile                 # Derleme komutları
├── includes/
│   └── push_swap.h         # Header dosyası, tanımlamalar
└── sources/
    ├── main.c              # Program giriş noktası
    ├── parsing.c           # Argümanları parse etme
    ├── arg_checks.c        # Argüman doğrulaması
    ├── error_handling.c    # Hata yönetimi
    ├── easy_sorting.c      # 2-5 eleman için sıralama
    ├── easy_sorting_utils.c # Yardımcı işlevler
    ├── hard_sorting.c      # 6+ eleman için sıralama
    ├── chunk_sort_stuff.c  # Chunk sıralama 1
    ├── chunk_sort_stuff_2.c # Chunk sıralama 2
    ├── radix_sort_stuff.c  # Radix sort uygulaması
    ├── normalize.c         # Normalizasyon işlemi
    ├── optimising.c        # Optimizasyon işlevleri
    ├── pushing.c           # Pa/Pb işlemleri
    ├── swapping.c          # Swap işlemleri
    ├── rotating.c          # Ra/Rb işlemleri
    └── reverse_rotating.c  # Rra/Rrb işlemleri
```

## Veri Yapıları

### t_node (Düğüm)
```c
typedef struct s_node
{
    int             value;      // Sayı değeri
    struct s_node   *next;      // Sonraki düğüme işaretçi
}   t_node;
```

### t_stack (Yığın)
```c
typedef struct s_stack
{
    t_node  *top;   // En üstteki düğüm
    int     size;   // Yığının boyutu
}   t_stack;
```

## Derleme ve Çalıştırma

### Derleme
```bash
make
```

### Çalıştırma
```bash
./push_swap <sayılar>
```

### Örnekler
```bash
./push_swap 3 2 1 0             # Çıktı: Sıralama işlemleri
./push_swap 50 3 100 -42 5      # Pozitif ve negatif sayılar
./push_swap 1 2 3 4 5           # Zaten sıralı (hiç çıktı yok)
```

### Checker ile Test Etme
```bash
./push_swap 3 2 1 0 | ./checker_linux 3 2 1 0
```

## Derleme Komutları

```bash
make        # Program derle
make clean  # Object dosyalarını sil
make fclean # Object ve executable'ı sil
make re     # Temizle ve yeniden derle
```

## Giriş Validasyonu

Program aşağıdaki kontrolleri yapır:

1. ✓ Yalnızca sayısal giriş kabul eder
2. ✓ Aktüel sayı aralığını kontrol eder (INT_MIN - INT_MAX)
3. ✓ Tekrarlayan sayıları reddeder
4. ✓ Boş argümanları reddeder

Hata durumunda:
```
Error
```

## Optimizasyon Stratejileri

1. **Chunk Boyutu Dinamik Hesaplama**: Input boyutuna uyarlanan chunk boyutu
2. **En Uygun Dönüş Yönü**: Yukarı/Aşağı rotate seçimi minimum adım için
3. **Akıllı Yer Değiştirme**: Tekrarlayan işlemlerin elimine edilmesi
4. **Hybrid Sıralama**: Chunk sort + radix sort kombinasyonu

## Test Ortamı

- **İşletim Sistemi**: Linux/Unix
- **Derleyici**: GCC (cc)
- **Standart**: C89/C90
- **Flags**: -Wall -Wextra -Werror (Strict compilation)

## Algoritma Karmaşıklığı

- **En İyi Durum**: O(n)  - Zaten sıralı
- **Orta Durum**: O(n log n) - Chunk sort
- **En Kötü Durum**: O(n²) - Worst case sıralama

## Yazarlar

- **ztoptas** - 42 Kocaeli Öğrencisi
- Email: ztoptas@student.42kocaeli.com

## Lisans

Bu proje 42 okulu eğitim projesidir.

---

## İlginç Bilgiler

- Program, saf **C** ile yazılmış (harici kütüphane yok)
- **Linked List** veri yapısı kullanılır
- **42 Standard** yazım kurallarına uyar
- **Deterministic** (belirleyici) - Aynı input her zaman aynı çıktı verir

## Kaynaklar

- 42 Okulu Öğretimi
- Stack ve Linked List Algoritmaları
- Sıralama Algoritmaları (Sorting)
- Optimizasyon Teknikleri
