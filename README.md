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
Dalam Tugas 2, kita harus menyelesaikan 8-puzzle dengan metode heuristic1 dan heuristic2

Dalam 8-Puzzle kita harus mencapai goal puzzle dari initial puzzle yang diberikan. Untuk mencapai goal puzzle, 8-puzzle ini menyediakan satu grid kosong agar grid-grid lain disekitarnya dapat digerakkan. Sebagai contoh Inisial State dan Goal State dari sebuah puzzle adalah :

![Image-3](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/1.PNG)

Dalam bahasan ini, fungsi heuristik yang akan kita tampilkan yaitu adalah sebagai berikut.
- h₁(n) : sebagai banyak grid yang menempati tempat yang salah.
- h₂(n) : sebagai total keseluruhan jarak tiap grid yang menempati tempat yang salah terhadap posisi grid yang benar, atau sering disebut dengan manhattan distance.

#### Heuristic-1
Solusi Heuristic1 adalah banyaknya grid yang menempati posisi yang salah

langkah-langkahnya adalah :

![Image-4](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/2.PNG)
![Image-5](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/2,5.PNG)
![Image-6](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/3.PNG)

Solusi :
Initial State -> Right -> Up -> Right -> Down -> Down -> Left -> Up -> Right -> Down(Goal)

#### Heuristic-2
Solusi Heuristic 2 adalah total keseluruhan jarak tiap grid yang menempati tempat yang salah terhadap posisi grid yang benar, atau sering disebut dengan manhattan distance.

langkah-langkahnya adalah :

![Image-7](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/4.PNG)
![Image-8](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/5.PNG)
![Image-9](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/6.PNG)

Solusi :
Initial State -> Right -> Up -> Right -> Down -> Down -> Left -> Up -> Right -> Up(Goal)

Penggunaan Heuristic2 lebih optimal karena pada penggunaan fungsi heuristik pertama jumlah State puzzle yang memiliki fungsi heuristik yang sama lebih banyak dari pada penggunaan fungsi heuristik kedua.

#### Hill-Climbing

Hill Climbing adalah pencarian heuristik yang digunakan untuk masalah optimasi matematis di bidang Inteligensi Buatan.

Dengan sejumlah besar input dan fungsi heuristik yang baik, ia mencoba untuk menemukan solusi yang cukup baik untuk masalah tersebut. Solusi ini mungkin bukan global optimal maksimum.
- Dalam definisi di atas, `Mathematical Optimization Problems` menyiratkan bahwa mendaki bukit memecahkan masalah di mana kita perlu memaksimalkan atau meminimalkan fungsi nyata yang diberikan dengan memilih nilai dari input yang diberikan. Contoh-Traveling salesman masalah di mana kita perlu meminimalkan jarak yang ditempuh oleh salesman.
- `Heuristic Search` berarti bahwa algoritma pencarian ini mungkin tidak menemukan solusi optimal untuk masalah tersebut. Namun, itu akan memberikan solusi yang baik dalam waktu yang wajar.
- `Heuristic Function` adalah fungsi yang akan memberi peringkat semua alternatif yang mungkin pada setiap langkah percabangan dalam algoritma pencarian berdasarkan informasi yang tersedia. Ini membantu algoritma untuk memilih rute terbaik dari rute yang mungkin.

![image-10](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/hill%20climb.png)

#### Fitur Hill Climbing
#### a. Varian dari menghasilkan dan menguji algoritma

Ini adalah varian dari algoritma generate and test. Algoritma generate and test adalah sebagai berikut:
- Hasilkan solusi yang mungkin.
- Tes untuk melihat apakah ini solusi yang diharapkan.
- Jika solusinya telah ditemukan, keluar lagi, lanjutkan ke langkah 1.

Oleh karena itu kami menyebut Hill climbing sebagai varian dari algoritma hasil dan uji karena mengambil umpan balik dari prosedur pengujian. Kemudian umpan balik ini digunakan oleh generator dalam memutuskan langkah selanjutnya dalam ruang pencarian.

#### b. Menggunakan Greedy Aproach

Pada titik mana pun di ruang keadaan, pencarian bergerak ke arah itu saja yang mengoptimalkan biaya fungsi dengan harapan menemukan solusi optimal di akhir.

#### Jenis Hill Climbing
#### a. Simple Hill Climbing

Ini memeriksa node tetangga satu per satu dan memilih node tetangga pertama yang mengoptimalkan biaya saat ini sebagai node berikutnya. Ini memeriksa node tetangga satu per satu dan memilih node tetangga pertama yang mengoptimalkan biaya saat ini sebagai node berikutnya.

Algoritma Simple Hill climbing :
- Evaluasi keadaan awal. Jika itu adalah keadaan tujuan maka berhentilah dan kembalikan kesuksesan. Kalau tidak, jadikan kondisi awal sebagai kondisi saat ini.
- Loop sampai keadaan solusi ditemukan atau tidak ada operator baru yang dapat diterapkan ke keadaan saat ini.
- Exit

#### b. Steepest-Ascent Hill Climbing

Pertama-tama memeriksa semua node tetangga dan kemudian memilih simpul yang paling dekat dengan keadaan solusi pada simpul berikutnya.

- Evaluasi keadaan awal. Jika status tujuan maka keluar dari yang lain jadikan status saat ini sebagai keadaan awal
- Ulangi langkah ini sampai solusi ditemukan atau keadaan saat ini tidak berubah
- Exit

#### c. Stochastic Hill Climbing

Itu tidak memeriksa semua node tetangga sebelum memutuskan node mana yang akan dipilih. Itu hanya memilih node tetangga secara acak dan memutuskan (berdasarkan jumlah peningkatan tetangga itu) apakah akan pindah ke tetangga itu atau untuk memeriksa yang lain.

#### State Space Diagram untuk Hill Climbing

adalah representasi grafis dari himpunan status yang dapat dicapai oleh algoritma pencarian kami vs nilai fungsi objektif kami (fungsi yang ingin kami maksimalkan).

`X - axis` menunjukkan ruang keadaan yaitu keadaan atau konfigurasi yang dapat dicapai algoritma kami.

`Y - axis` menunjukkan nilai-nilai fungsi obyektif yang sesuai dengan keadaan tertentu.

Solusi terbaik adalah ruang negara di mana fungsi objektif memiliki nilai maksimum (global maksimum).

![image-11](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/77142942-355a7680-6ab4-11ea-8c1d-66b86aaef6c9.png)

#### Daerah berbeda di State Space Diagram

- `Local Maximum` Ini adalah state yang lebih baik daripada state tetangganya namun ada state yang lebih baik daripada itu (global maksimum). Keadaan ini lebih baik karena di sini nilai fungsi objektif lebih tinggi daripada tetangganya.
- `Global Maximum` Ini adalah keadaan terbaik yang mungkin dalam diagram ruang keadaan. Ini karena pada keadaan ini, fungsi objektif memiliki nilai tertinggi.
- `Plateua/Flat Local Maximum` Ini adalah wilayah datar ruang negara di mana negara-negara tetangga memiliki nilai yang sama.
- `Ridge` Ini adalah wilayah yang lebih tinggi dari tetangganya tetapi memiliki kemiringan. Ini adalah jenis khusus maksimum lokal.
- `Current State` Wilayah diagram ruang keadaan tempat kami saat ini hadir selama pencarian.
- `Shoulder` Ini adalah dataran tinggi yang memiliki tepi menanjak.

#### Permasalahan di Berbagai Daerah di Hill Climbing

- `Local Maximum` semua state tetangga memiliki nilai yang lebih buruk daripada keadaan saat ini. Karena Hill Climbing menggunakan pendekatan serakah, itu tidak akan bergerak ke keadaan yang lebih buruk dan mengakhiri dirinya sendiri. Proses ini akan berakhir meskipun mungkin ada solusi yang lebih baik.  

`To Overcome Local Maximum Problem` Gunakan teknik backtracking. Menyimpan daftar negara yang dikunjungi. Jika pencarian mencapai kondisi yang tidak diinginkan, pencarian dapat mundur ke konfigurasi sebelumnya dan menjelajahi jalur baru.

- `Plateau` Di plateau semua tetangga memiliki nilai yang sama. Oleh karena itu, tidak mungkin untuk memilih arah terbaik.

`To Overcome Plateaus` Lakukan lompatan besar. Pilih negara yang secara acak jauh dari keadaan saat ini. Kemungkinannya adalah bahwa kita akan mendarat di wilayah non-dataran tinggi

- `Ridges` Setiap titik di punggung bukit dapat terlihat seperti puncak karena gerakan ke semua arah yang mungkin terjadi adalah ke bawah. Karenanya algoritma berhenti ketika mencapai kondisi ini.

`To Overcome Ridge` Dalam hambatan semacam ini, gunakan dua aturan atau lebih sebelum pengujian. Itu berarti bergerak ke beberapa arah sekaligus.


### Tugas 3
### Adversarial Search
#### Minimax
Minimax adalah semacam algoritma backtracking yang digunakan dalam pengambilan keputusan dan teori permainan untuk menemukan langkah optimal bagi pemain, dengan asumsi bahwa lawan Anda juga bermain secara optimal. Ini banyak digunakan dalam dua permainan berbasis giliran pemain seperti Tic-Tac-Toe, Backgammon, Mancala, Catur, dll.

Di Minimax kedua pemain disebut maximizer dan minimizer. Maximizer mencoba untuk mendapatkan skor setinggi mungkin sementara minimizer mencoba melakukan yang sebaliknya dan mendapatkan skor serendah mungkin.

Setiap board state memiliki nilai yang terkait dengannya. Dalam keadaan tertentu jika maximizer lebih unggul, skor pada board akan cenderung bernilai positif. Jika minimizer berada di lebih unggul di papan itu maka akan cenderung menjadi nilai negatif. Nilai-nilai papan dihitung oleh beberapa heuristik yang unik untuk setiap jenis permainan.

Contoh Implementasi :

![image-12](https://raw.githubusercontent.com/Asmophel/Kecerdasan-Buatan-F/master/Gambar/TIC_TAC.jpg)

Gambar ini menggambarkan semua jalur yang mungkin bisa diambil oleh game dari state board root. Ini sering disebut Game Tree.
3 skenario yang mungkin dalam contoh di atas adalah:

- Pindah ke Kiri: Jika X memainkan [2,0]. Maka O akan bermain [2,1] dan memenangkan permainan. Nilai langkah ini adalah -10
- Gerakan Tengah: Jika X memainkan [2,1]. Kemudian O akan memainkan [2,2] yang menarik permainan. Nilai langkah ini adalah 0
- Pindah Kanan: Jika X memainkan [2,2]. Maka dia akan memenangkan pertandingan. Nilai langkah ini adalah +10;

Ingat, meskipun X memiliki kemungkinan menang jika dia memainkan langkah tengah, O tidak akan pernah membiarkan itu terjadi dan akan memilih untuk menggambar.
Oleh karena itu pilihan terbaik untuk X, adalah bermain [2,2], yang akan menjamin kemenangan baginya.


### Tugas 4
### 4-Queen
4-Queen memiliki penyelesaian yang sama persis dengan 8-Queen, Source Code dari 8-Queen hanya perlu diganti pada N nya menjadi N = 4

Pada problem 4 queen ini digunakan algoritma backtracking, yaitu mencoba menaruh queen dimulai dari kolom atas kiri atau kolom pertama baris pertama, lalu kita mencoba menaruh queen lain dan di cek apakah ada yang saling melawan atau tidak. Jika saat kita menaruh queen dan tidak ada yang saling melawan dengan queen lain maka baris dan kolomnya akan dijadikan sebagai bagian dari solusi, bila pada hasil akhir tidak ditemukan hasil yang tepat karena masih ada queen yang saling melawan, maka akan di backtrack dan return false.
    
