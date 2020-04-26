# Kecerdasan-Buatan-F

##### Fandi Wahyu R - 05111840000108

### Outline
+ [Tugas 1 - Uninformed Search](#Tugas-1)
    * [BFS](#BFS)
    * [DFS](#DFS)
    * [IDS](#IDS)
    * [8-Queen](#8-Queen)
+ [Tugas 2 - Informed Search](#Tugas-2)
    * [Heuristic 1](#Heuristic-1)
    * [Heuristic 2](#Heuristic-2)
    * [Hill Climbing](#Hill-Climbing)
+ [Tugas 3 - Adversarial Search](#Tugas-3)
    * [Minimax](#Minimax)
+ [Tugas 4 - 4-Queen](#Tugas-4) 

### Tugas 1
### Uninformed Search
#### BFS
BFS atau Breadth First Search adalah algoritma untuk melintasi atau mencari struktur data pohon atau grafik. BFS dimulai pada root pohon (atau beberapa titik sembarang dari grafik, kadang-kadang disebut sebagai 'kunci pencarian' [1]), dan menjelajahi semua node tetangga pada kedalaman saat ini sebelum pindah ke node di tingkat kedalaman selanjutnya.

Algoritma Breadth First Search (BFS) menelusuri grafik dalam gerakan breadthward dan menggunakan ``` queue ``` untuk mengingat untuk mendapatkan simpul berikutnya untuk memulai pencarian, ketika jalan buntu terjadi dalam setiap iterasi.

![Image-1](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/breadth_first_traversal.jpg)

Seperti dalam contoh yang diberikan di atas, algoritma BFS melintasi dari A ke B ke E ke F pertama kemudian ke C dan G terakhir ke D. Ia menggunakan aturan berikut.

Aturan 1 - Kunjungi verteks yang belum dikunjungi yang berdekatan. Tandai sebagai sudah dikunjungi. Tampilkan itu. Masukkan dalam antrian.

Aturan 2 - Jika tidak ada simpul yang berdekatan ditemukan, hapus simpul pertama dari antrian.

Aturan 3 - Ulangi Aturan 1 dan Aturan 2 sampai antrian kosong.


#### DFS
DFS (Depth-first search) adalah teknik yang digunakan untuk melintasi tree atau graph. Di sini, backtracking digunakan untuk traversal. Dalam traversal ini pertama-tama simpul terdalam dikunjungi dan kemudian melakukan backtracks ke simpul induknya jika tidak ada sibling dari simpul itu.

Algoritma DFS adalah algoritma rekursif yang menggunakan gagasan backtracking. Ini melibatkan pencarian lengkap dari semua node dengan melanjutkan, jika mungkin, dengan mundur.

Di sini, kata mundur berarti bahwa ketika Anda bergerak maju dan tidak ada lagi node di sepanjang jalur saat ini, Anda bergerak mundur di jalur yang sama untuk menemukan node untuk dilintasi. Semua node akan dikunjungi di jalur saat ini sampai semua node yang belum dikunjungi telah dilalui setelah jalur berikutnya akan dipilih.

Sifat rekursif DFS ini dapat diimplementasikan menggunakan tumpukan. Ide dasarnya adalah sebagai berikut:
Pilih simpul awal dan dorong semua simpul yang berdekatan ke tumpukan.
Pop sebuah node dari stack untuk memilih node berikutnya untuk mengunjungi dan mendorong semua node yang berdekatan ke dalam stack.
Ulangi proses ini sampai tumpukan kosong. Namun, pastikan bahwa node yang dikunjungi ditandai. Ini akan mencegah Anda mengunjungi simpul yang sama lebih dari sekali. Jika Anda tidak menandai node yang dikunjungi dan Anda mengunjungi node yang sama lebih dari sekali, Anda mungkin berakhir dalam loop tak terbatas.

Contoh DFS :
![Image-2](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/9fa1119.jpg)

#### IDS
#### 8-Queen


### Tugas 2
### Informed Search
#### Heuristic-1
#### Heuristic-2
#### Hill-Climbing


### Tugas 3
### Adversarial Search
#### Minimax


### Tugas 4
### 4-Queen
    
    
