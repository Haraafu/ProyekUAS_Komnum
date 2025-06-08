# Estimasi Ukuran Input Maksimum dengan Metode Secant

## Nama (NPM)
Falah Andhesryo (2306161990)  
Komnum-02

## Deskripsi Program

Program ini dibuat untuk memperkirakan **ukuran input maksimum (`n`)** yang dapat diproses oleh suatu algoritma dalam waktu eksekusi tertentu, misal **maksimal 10 detik**. Model ini diasumsikan berbentuk fungsi nonlinear:  

T(n) = a * n * log(n) + b * n + c  

Karena tidak ada solusi eksak untuk membalikkan fungsi ini secara aljabar, saya menggunakan pendekatan numerik yaitu **metode Secant** untuk mencari akar dari fungsi:  

f(n) = T(n) - T_max  

Program ini akan mencetak nilai `n` hasil estimasi yang membuat waktu eksekusi tepat atau mendekati nilai `T_max`. Metode ini cocok digunakan dalam kasus evaluasi performa algoritma, terutama dalam konteks sistem real-time atau terbatas waktu.

## Fitur Program
- Implementasi metode Secant tanpa turunan eksplisit
- Output hasil estimasi `n` dan waktu eksekusinya
- Kontrol toleransi dan jumlah iterasi maksimal

## Cara Menjalankan
Kompilasi dan jalankan dengan GCC:

```bash
gcc main.c -o main
./main
```