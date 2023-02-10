#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void menu_makanan();
void menu_minuman();
int main();

int stat_menu[11][3] = {{0, 0, 0}, {1, 10, 7000}, {2, 10, 3000}, {3, 10, 6000}, {4, 10, 5000}, {5, 10, 3000}, {6, 10, 2000}, {7, 10, 3000}, {8, 10, 1500}, {9, 10, 5000}, {10, 10, 1000} };
char nama_menu[11][20] = {
  "null"
  "Ayam geprek",
  "Indomie goreng",
  "Ayam bakar",
  "Ayam goreng ",
  "Indomie rebus",
  "Teh manis",
  "Kopi susu",
  "Air putih",
  "Es jeruk",
  "Teh sisri",
};

int keranjang[10][11][3] = {
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}},
  {{0, 0, 0}, {1, 0, 0}, {2, 0, 0}, {3, 0, 0}, {4, 0, 0}, {5, 0, 0}, {6, 0, 0}, {7, 0, 0}, {8, 0, 0}, {9, 0, 0}, {10, 0, 0}}
};
char daftar_nama[10][100];


int main() {
  int start = 1;
  int id_pelanggan = 0;
  while (start == 1) {
    printf("Halo, apakah kamu akan membuka tokonya ?\n");
    printf("1. Tutup Toko\n");
    printf("2. Buka Toko\n\n");
    
    int toko;
    printf("Silahkan pilih opsimu (1/2)\n");
    scanf("%d", &toko);

    if (toko == 1){
      printf("Baik toko tutup\n");
      if (id_pelanggan == 0){
        printf("Tidak ada penjualan");
        start = 0;
      } else {
        int j;
        int k;
        int total_sold = 0;
        start = 0;
        for (j = 0; j < id_pelanggan; j++) {
          printf("Nama pelanggan : %s\n", daftar_nama[j]);
          printf("Nama Menu\tJumlah beli\tHarga\n");
          for (k = 0; k < 11; k++){
            total_sold += keranjang[j][k][1];
            if (keranjang[j][k][1] != 0){
              printf("%s\t%d\t\t%d\n", nama_menu[k], keranjang[j][k][1], keranjang[j][k][2]);
            }
          }  
        }
        FILE *fptr;
        fptr = fopen("transaksipenjualan.txt", "w");
        for (j = 0; j < id_pelanggan; j++) {
          fprintf(fptr,"Nama pelanggan : %s\n", daftar_nama[j]);
          fprintf(fptr,"Nama Menu\tJumlah beli\tHarga\n");
          for (k = 0; k < 11; k++){
            total_sold += keranjang[j][k][1];
            if (keranjang[j][k][1] != 0){
              fprintf(fptr,"%s\t%d\t\t%d\n", nama_menu[k], keranjang[j][k][1], keranjang[j][k][2]);
            }
          }  
        }       
        fclose(fptr);

        if(total_sold==0) {
          printf("Tidak ada penjualan");
        }
      }


    } else {
      printf("\nSelamat datang di Waroeng\n");
      printf("Silahkan masukkan nama anda\n");
      char nama[5000];
      scanf("%s", &nama);
      strcpy(daftar_nama[id_pelanggan], nama);
      printf("Selamat datang di Waroeng, %s\n", nama);
      int balik = 1;
      while (balik == 1){
        printf("Apa yang ingin kamu lakukan ?\n 1. Lihat menu\n 2. Beli barang \n 3. Keluar warung\n");
        int milih;
        scanf("%d", &milih);
        int lagi_milih;
        lagi_milih = 1;
        switch (milih)
        {
        case 1:
          menu_makanan();
          menu_minuman();
          break;
        case 2 :
          while (lagi_milih == 1){ 
            printf("Silahkan masukkan ID menu\n");
            int pilih_menu;
            scanf("%d", &pilih_menu);
            int stok;
            stok = 1;
            while (stok == 1){
              if (stat_menu[pilih_menu][1] != 0){
                printf("Berapa banyak ingin membeli menu tersebut ?\n");
                int jumlah_beli;
                scanf("%d", &jumlah_beli);
                if (jumlah_beli > stat_menu[pilih_menu][1]){
                  printf("Mohon maaf stok tidak memenuhi, apakah ingin mengganti menu (1) atau mengganti jumlah (2) ? atau ingin keluar warung (3)\n");
                  int pilih;
                  scanf("%d", &pilih);
                  if (pilih == 1){
                    stok = 0;
                    lagi_milih = 1;
                  } else if (pilih == 2){
                    stok = 1;
                  } else {
                    stok = 0;
                    lagi_milih = 0;
                    balik = 0;
                  }
                } else {
                    keranjang[id_pelanggan][pilih_menu][1] += jumlah_beli;
                    keranjang[id_pelanggan][pilih_menu][2] = stat_menu[pilih_menu][2]*jumlah_beli;
                    stok = 0;
                    lagi_milih = 0;
                }
              } else {
                printf("Mohon maaf stok menu tersebut habis, ingin ganti menu (1) atau keluar warung (2) ?\n");
                int lanjut;
                scanf("%d", &lanjut);
                if (lanjut == 1){
                  stok = 0;
                } else {
                  stok = 0;
                  lagi_milih = 0;
                  balik = 0;
                }
                
              }
            }
          }   
          break;  
        case 3 : 
          balik = 0;
          break;
        }
      }  
      id_pelanggan++;
    }
  }
  return 0;    
}

void menu_makanan(){
  printf("\nMenu ");
  printf("Makanan\n");
  int i;
  printf("ID Menu\t\tNama Menu\t\tHarga Menu\t\tStok\n");
  for (i = 1; i < 5; i++) {
    printf("%d\t\t%s\t\t%d\t\t%d\n", stat_menu[i][0], nama_menu[i], stat_menu[i][2], stat_menu[i][1]);
  }
}

void menu_minuman(){
  printf("\nMenu ");
  printf("Minuman\n");
  int i;
  printf("ID Menu\t\tNama Menu\t\tHarga Menu\tStok\n");
  for (i = 6; i < 10; i++) {
    printf("%d\t\t%s\t\t%d\t\t%d\n", stat_menu[i][0], nama_menu[i], stat_menu[i][2], stat_menu[i][1]);
  }
}


