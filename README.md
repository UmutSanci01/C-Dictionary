# C-Dictionary

# Gereksinimler
- Visual Studio
- VS Code

## VS Code ile Derleme ve Çalıştırma
1. Developer Command Prompt for VS 20xx üzerinden VS Code'u açın.
2. **Run** veya **Debug** düğmesine basın ve **cl.exe**'yi seçin.

# Nasıl Kullanılır
En tepesinde "ItemData" değişkeni bulunduran herhangi bir "struct" yapısı bu sözlükte saklanabilir.

# Önemli özellikler
- Anahtar ve değerler tabloya eklenirken kopyalanır; tablo kendi içinde ayrı bellek ayırır ve sahiplenir. Buna karşın, kopyalanan struct içinde dinamik olarak ayrılmış iç veriler (`char*`, `int*` vb.) varsa, bu iç bellek otomatik olarak serbest bırakılmaz; bu tür tipler için ek temizleme işlemi gerekebilir.
- Çakışma çözümü: çiftli hash (double hashing) kullanılır.
- Hash fonksiyonu: polinomiyel rolling-hash yaklaşımı (ASCII karakterler üzerinden) uygulanır.
- Yeniden boyutlandırma: Yük oranı %70'i geçerse tablo büyütülür; %10'un altına düşerse küçültülür. Tablo boyutları asal sayılara yuvarlanır.
- Silme işlemi için `DELETED` işaretçisi kullanılır; silinmiş öğeler zinciri bozmadan işlenir.
- Çoklu iş parçacığı (thread) güvenliği yoktur — gerekli ise dışarıdan senkronizasyon uygulanmalıdır.

# API Özeti
- `Table* AllocTable()` — Yeni bir hash tablosu oluşturur (başlangıç boyutu için tablo içinden prime boyut hesaplanır).
- `void FreeTable(Table* table)` — Tabloyu ve içindeki öğeleri serbest bırakır. Dikkat: öğe içindeki dinamik alt yapı temizlenmez.
- `void Insert(Table* table, const void* key, const void* value)` — Anahtar-değer çifti ekler veya anahtar zaten varsa değeri günceller.
- `void Delete(Table* table, const void* key)` — Anahtara karşılık gelen öğeyi siler (DELETED ile işaretler).
- `Item* Search(Table* table, const void* key)` — Anahtarı arar; bulunursa `Item*`, yoksa `NULL` döner. Dönen `Item*` tablo tarafından yönetilen dahili belleğe işaret eder; üzerinde doğrudan serbest bırakma/modifikasyon yapmayın.

# Referans
Bu proje, https://github.com/0xdeadc0de/C_HashTable.git adresindeki C HashTable projesi temel alınarak geliştirilmiştir.






# Requirements
- Visual Studio
- VS Code

## Build and Run with VS Code
1. Open VS Code from Developer Command Prompt for VS 20xx.
2. Press the **Run** or **Debug** button and select **cl.exe**.

# Usage
Any `struct` containing an "ItemData" variable at the top can be stored in this dictionary.

# Key Features
- Keys and values are copied when inserted into the table. The table allocates and owns separate memory for them. However, if the copied struct contains dynamically allocated internal data (char*, int*, etc.), this internal memory is not automatically freed; additional cleanup may be required for such types.
- Collision resolution: Double hashing is used.
- Hash function: A polynomial rolling hash approach is used, operating on ASCII characters.
- Resizing: The table grows when the load factor exceeds 70% and shrinks when it falls below 10%. Table sizes are adjusted to the nearest suitable prime number.
- Deletion: A `DELETED` marker is used for deletion; deleted entries are handled without breaking the probing chain.
- Thread safety: The table is not thread-safe. External synchronization must be used if thread safety is required.

# API Overview
- `Table* AllocTable()` — Creates a new hash table. The initial table size is calculated internally as a prime number.
- `void FreeTable(Table* table)` — Frees the table and the items it contains. Note: Dynamically allocated data contained within the items is not freed.
- `void Insert(Table* table, const void* key, const void* value)` — Inserts a key-value pair into the table, or updates the value if the key already exists.
- `void Delete(Table* table, const void* key)` — Deletes the item associated with the given key by marking it as DELETED.
- `Item* Search(Table* table, const void* key)` — Searches for the given key. Returns an Item* if found, or NULL otherwise. The returned Item* points to memory managed internally by the table; do not free or modify it directly.


# Reference
This project is based on the C HashTable project found at https://github.com/0xdeadc0de/C_HashTable.git.