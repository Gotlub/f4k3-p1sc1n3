# piscine-remake-42 {
#\* Hello world */"  \n  
RUSH 01 /      

probablement pas aux normes  - Norm not ok .  
Marche jusqu'au 8 * 8. Work util 8 * 8.  

Input on argv[2] , format "4 6 2 4 3 2 1 1 2 2 3 3 5 6 4 6 4 3 3 2 1 1 2 2 4 2 3 4" -> ( view in oder -> north south west est )    
online puzzle for test      

https://fr.puzzle-skyscrapers.com/   
https://codepen.io/rs_zdjn/pen/dyoYJjo  
 
"25815 gotlub      20   0  2612   932   844 R  99.9  0.0 10h49:28 ./a.out 3 2 1 3 2 2 4 6 3 2 1 5 3 4 3 2 4 5 3 4 3 4 2 3 1 4 2 3 3 3 1 3 2 3 3 5"  
-> 9*9 :'(  
 
"""  
[gotlub@fedora]$ gcc -Wall -Werror -Wextra -O3 main.c  
[gotlub@fedora]$ time valgrind ./a.out "4 6 2 4 3 2 1 1 2 2 3 3 5 6 4 6 4 3 3 2 1 1 2 2 4 2 3 4"  
==80075== Memcheck, a memory error detector  
==80075== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.  
==80075== Using Valgrind-3.19.0 and LibVEX; rerun with -h for copyright info  
==80075== Command: ./a.out 4\ 6\ 2\ 4\ 3\ 2\ 1\ 1\ 2\ 2\ 3\ 3\ 5\ 6\ 4\ 6\ 4\ 3\ 3\ 2\ 1\ 1\ 2\ 2\ 4\ 2\ 3\ 4  
==80075==   
4 1 5 2 3 6 7  
1 2 3 4 5 7 6  
2 3 1 6 7 4 5  
3 4 2 7 6 5 1  
5 6 7 1 2 3 4  
6 7 4 5 1 2 3  
7 5 6 3 4 1 2  
Joupi==80075==   
==80075== HEAP SUMMARY:  
==80075==     in use at exit: 0 bytes in 0 blocks  
==80075==   total heap usage: 18 allocs, 18 frees, 1,640 bytes allocated  
==80075==   
==80075== All heap blocks were freed -- no leaks are possible  
==80075==   
==80075== For lists of detected and suppressed errors, rerun with: -s  
==80075== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)  
  
real	0m1.260s  
user	0m0.682s  
sys	0m0.069s   

[gotlub@fedora]$ time ./a.out "4 6 2 4 3 2 1 1 2 2 3 3 5 6 4 6 4 3 3 2 1 1 2 2 4 2 3 4"  
4 1 5 2 3 6 7  
1 2 3 4 5 7 6  
2 3 1 6 7 4 5  
3 4 2 7 6 5 1  
5 6 7 1 2 3 4  
6 7 4 5 1 2 3  
7 5 6 3 4 1 2  
Joupi  
real	0m0.039s  
user	0m0.035s  
sys	0m0.003s  

[gotlub@fedora]$ time ./a.out "2 1 3 3 5 2 5 3 3 2 4 4 2 2 2 1 2 1 3 3 4 2 2 3 3 5 2 5 2 3 2 1"  
1 8 2 5 3 7 4 6  
8 1 3 7 4 6 5 2  
2 3 1 8 5 4 6 7  
3 4 8 6 7 5 2 1  
4 6 7 1 2 8 3 5  
6 2 5 3 8 1 7 4  
7 5 6 4 1 2 8 3  
5 7 4 2 6 3 1 8  
Joupi  
real	0m9.880s  
user	0m9.841s  
sys	0m0.006s  
  
   
[gotlub@fedora]$ time ./a.out "3 4 2 3 1 3 2 1 2 2 3 4 4 4 3 6 4 3 3 2 1 3 1 2 4 3 2 4" | cat -e  
5 3 6 1 7 4 2$  
1 2 4 5 3 6 7$  
3 1 2 4 5 7 6$  
2 4 3 7 6 5 1$  
4 5 7 6 1 2 3$  
6 7 1 2 4 3 5$  
7 6 5 3 2 1 4$  
Joupi  
real	0m0.449s  
user	0m0.446s  
sys	0m0.003s  
  
[gotlub@fedora]$ time ./a.out "4 6 2 1 2 3 2 1 2 2 3 3 3 4 3 7 4 4 3 2 1 4 1 2 2 3 3 3" | cat -e  
4 1 5 7 6 3 2$  
1 2 3 4 5 6 7$  
2 3 1 5 4 7 6$  
3 4 2 6 7 1 5$  
5 6 7 1 2 4 3$  
6 7 4 2 3 5 1$  
7 5 6 3 1 2 4$  
Joupi  
real	0m0.004s  
user	0m0.004s  
sys	0m0.000s  
  
  
"""    
  
 ---EDIT---  
6 sep 23H -> code update best perf 
[gotlub@fedora]$ time ./a.out "2 1 3 3 5 2 5 3 3 2 4 4 2 2 2 1 2 1 3 3 4 2 2 3 3 5 2 5 2 3 2 1"  
1 8 2 5 3 7 4 6  
8 1 3 7 4 6 5 2  
2 3 1 8 5 4 6 7  
3 4 8 6 7 5 2 1  
4 6 7 1 2 8 3 5  
6 2 5 3 8 1 7 4  
7 5 6 4 1 2 8 3  
5 7 4 2 6 3 1 8  
Joupi  
real    0m3.672s  
user    0m3.646s  
sys     0m0.007s  
[gotlub@fedora]$   

[gotlub@fedora]$ time ./a.out "3 4 2 3 1 3 2 1 2 2 3 4 4 4 3 6 4 3 3 2 1 3 1 2 4 3 2 4" | cat -e  
5 3 6 1 7 4 2$  
1 2 4 5 3 6 7$  
3 1 2 4 5 7 6$  
2 4 3 7 6 5 1$  
4 5 7 6 1 2 3$  
6 7 1 2 4 3 5$  
7 6 5 3 2 1 4$  
Joupi  
real    0m0.315s  
user    0m0.313s  
sys     0m0.005s  
[gotlub@fedora]  
   
  ---EDIT---
  V2 "twine"  
 
}  
C08 -> Norm ?   
 Work 
  
 
Gotlub#8595  
