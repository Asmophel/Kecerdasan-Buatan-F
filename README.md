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
iterative deepening search atau iterative deepening depth-first search (IDS atau IDDFS) adalah strategi pencarian space / graph keadaan di mana versi pencarian depth-first depth-limited dijalankan berulang kali dengan meningkatkan batas kedalaman hingga tujuannya ditemukan. IDDFS optimal seperti BFS, tetapi menggunakan lebih sedikit memori; pada setiap iterasi, ia mengunjungi node di search tree dalam urutan yang sama seperti pencarian BFS, tetapi urutan kumulatif di mana node pertama kali dikunjungi secara efektif BFS.

IDS digunakan ketika Anda memiliki agen yang diarahkan pada tujuan dalam ruang pencarian yang tak terbatas (atau pohon pencarian).

Mengapa Breadth First Search (BFS) dan Depth First Search (DFS) gagal dalam kasus ruang pencarian yang tak terbatas?

Di DFS, Anda akan melihat secara verteks simpul yang berdekatan. DFS mungkin tidak berakhir di ruang pencarian yang tak terbatas. Juga, DFS mungkin tidak menemukan jalur terpendek ke tujuan. DFS membutuhkan O (d) ruang, di mana d adalah kedalaman pencarian.

BFS mengkonsumsi terlalu banyak memori. BFS perlu menyimpan semua elemen di level yang sama. Dalam kasus tree, level terakhir memiliki simpul daun N / 2, level terakhir kedua memiliki N / 4. Jadi, BFS membutuhkan ruang O (N).
Pencarian mendalam mendalam berulang Iterative (IDDFS) adalah hibrida dari BFS dan DFS. Dalam IDDFS, kami melakukan DFS hingga "limited depth" tertentu, dan terus meningkatkan "limited depth" ini setelah setiap iterasi.

Cara Kerja IDS :
![Image-2](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/498px-Graph.traversal.example.svg.png)

Dfs dimulai pada A, dengan asumsi bahwa tepi kiri dalam grafik yang ditunjukkan dipilih sebelum tepi kanan, dan dengan asumsi pencarian mengingat node yang dikunjungi sebelumnya dan tidak akan mengulanginya (karena ini adalah grafik kecil), akan mengunjungi node dalam urutan berikut: A, B, D, F, E, C, G. Tepi yang dilalui dalam bentuk pencarian ini adalah pohon Trémaux, struktur dengan aplikasi penting dalam teori grafik.

Melakukan pencarian yang sama tanpa mengingat node yang dikunjungi sebelumnya menghasilkan node mengunjungi dalam urutan A, B, D, F, E, A, B, D, F, E, dll selamanya, terperangkap dalam A, B, D, F , E cycle dan tidak pernah mencapai C atau G.

IDS mencegah loop ini dan akan mencapai node berikut pada kedalaman berikut, dengan asumsi itu melanjutkan dari kiri ke kanan seperti di atas:

0: A
1: A, B, C, E
(IDS sekarang telah melihat C, ketika pencarian depth-first konvensional tidak.)

2: A, B, D, F, C, G, E, F
(Masih melihat C, tetapi itu datang kemudian. Juga ia melihat E melalui jalur yang berbeda, dan kembali ke F dua kali.)

3: A, B, D, F, E, C, G, E, F, B
Untuk grafik ini, karena lebih banyak kedalaman ditambahkan, dua siklus "ABFE" dan "AEFB" hanya akan menjadi lebih lama sebelum algoritma menyerah dan mencoba cabang lain.

#### 8-Queen
The Eight Queen Problem, juga dikenal sebagai Eight Queen Puzzle, adalah masalah menempatkan delapan ratu di papan catur 8 x 8 sehingga tidak satupun dari mereka saling menyerang. Dengan menyerang, maksud kami tidak ada dua yang berada di baris, kolom, atau diagonal yang sama. Eight Queen Problem adalah bentuk masalah yang lebih umum yang dikenal sebagai N Queen Problem atau N Queen Puzzle di mana Anda harus menempatkan ratu N pada papan catur N x N sedemikian rupa sehingga tidak ada yang saling menyerang.

Solusinya adalah dengan algoritma backtracking. Idenya adalah untuk menempatkan ratu satu per satu di kolom yang berbeda, mulai dari kolom paling kiri. Ketika kami menempatkan seorang ratu dalam sebuah kolom, kami memeriksa bentrokan dengan ratu yang sudah ditempatkan. Di kolom saat ini, jika kami menemukan baris yang tidak ada bentrokan, kami menandai baris dan kolom ini sebagai bagian dari solusi. Jika kami tidak menemukan baris seperti itu karena bentrokan, maka kami mundur dan mengembalikan false.

Langkah-langkahnya adalah :

675/5000
1) Mulai di kolom paling kiri
2) Jika semua ratu ditempatkan
     kembali benar
3) Coba semua baris di kolom saat ini.
    Lakukan mengikuti untuk setiap baris yang dicoba.
     a) Jika ratu dapat ditempatkan dengan aman di baris ini
        kemudian tandai [baris, kolom] ini sebagai bagian dari
        solusi dan periksa secara rekursif jika menempatkan
        ratu di sini mengarah ke solusi.
     b) Jika menempatkan ratu di [baris, kolom] mengarah ke
        solusi kemudian mengembalikan true.
     c) Jika menempatkan ratu tidak mengarah ke solusi, maka
        hapus tanda [baris, kolom] ini (Mundur) dan pergi ke
        langkah (a) untuk mencoba baris lain.
3) Jika semua baris telah dicoba dan tidak ada yang berhasil,
    return false untuk memicu backtracking.

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
    
    
