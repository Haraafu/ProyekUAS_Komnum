#include <stdio.h>
#include <math.h>

// Konstanta model waktu T(n) = a * n * log(n) + b * n + c
#define A 1.2e-6
#define B 2.5e-5
#define C 0.1

// Batas maksimum waktu eksekusi yang diizinkan (dalam detik)
#define T_MAX 10.0

// Toleransi konvergensi untuk metode Secant
#define TOL 0.001

// Fungsi T(n) - T_max yang akan dicari akarnya
double fn(double n) {
    return A * n * log(n) + B * n + C - T_MAX;
}

int main() {
    // Dua tebakan awal nilai n 
    double n0 = 10000;
    double n1 = 20000;
    double n2;

    int max_iter = 100;
    int iter = 0;

    printf("Estimasi akar fungsi f(n) = T(n) - T_max dengan metode Secant\n\n");

    while (iter < max_iter) {
        double f0 = fn(n0);
        double f1 = fn(n1);

        // Hindari pembagian dengan nol
        if (fabs(f1 - f0) < 1e-12) {
            printf("Perbedaan terlalu kecil, iterasi dihentikan.\n");
            break;
        }

        // Rumus utama metode Secant
        n2 = n1 - f1 * (n1 - n0) / (f1 - f0);

        // Cetak hasil setiap iterasi (opsional tapi bermanfaat untuk melihat progres)
        printf("Iterasi %2d: n = %.4f, f(n) = %.6f\n", iter + 1, n2, fn(n2));

        // Cek apakah hasilnya sudah cukup dekat dengan akar
        if (fabs(fn(n2)) < TOL) {
            break;
        }

        // Perbarui nilai tebakan untuk iterasi selanjutnya
        n0 = n1;
        n1 = n2;
        iter++;
    }

    printf("\nEstimasi ukuran input maksimum (n) = %.4f\n", n2);
    printf("Waktu eksekusi pada n = %.4f detik\n", A * n2 * log(n2) + B * n2 + C);

    return 0;
}
