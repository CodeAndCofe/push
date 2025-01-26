CC= cc
FLAG= -Wall -Werror -Wextra
SRC= push_swap.c p_tools.c string.c manager.c \
	linked_list.c help.c sort.c sort_moves.c  my_algo.c\
	splite.c
all:
	$(CC) $(FLAG) $(SRC) && ./a.out -3485 -718 -4154 4159 1309 2898 -2630 2222 -4904 581 -3865 -5118 -1467 -4240 3342 -2550 -3302 -4578 3760 -197 -3007 -3799 -1455 2114 -2426 3765 2679 2412 -1533 1703 -5054 -4446 -3822 1794 327 -431 -5341 -1452 4162 -5580 3498 -2534 3152 -819 -4802 -5529 -4700 -3510 3835 -3299 -4284 2623 -4228 1455 3396 -1965 -118 3029 -4910 4026 4038 4343 170 -5454 -4276 232 -2891 2847 2510 3111 -2582 3603 -1908 -948 3645 -326 -3285 -5599 -564 -3932 -4312 1311 1959 4250 2557 3985 4256 1457 3401 -5023 -3890 3635 -4433 1893 -129 -1071 -5458 -516 -4615 -1235 1348 -4209 -2566 -2920 940 -1517 -5630 3926 -2980 -2056 -1981 4316 -2966 -4675 -782 486 1251 -4378 1778 2458 1970 2604 2963 -3378 -3428 3279 3824 3166 859 -84 2592 2626 -688 -1995 -2502 -3694 4279 2542 -2351 -3436 3240 -561 981 3497 4306 2101 2033 -4779 -2941 -848 -5608 -2671 -3293 -3266 46 587 620 3822 -3518 -3099 -3121 2041 -119 2645 -1374 -1607 -1793 -2768 3652 2890 373 -4529 3549 -1335 -122 2211 1047 4402 -3547 -2747 -2175 -935 -1949 2276 3307 -3006 -750 -3742 -5162 119 4350 -3 -1441 2383 3580 -5447 1701 -5020 666 -4075 -290 -2500 -4909 -4914 4535 3577 3495 1972 -613 -697 2788 -3354 -2246 1965 2341 495 1498 -1028 3667 -3238 880 -2040 1783 -4983 -1780 -4064 2357 2960 -1457 -2885 | pbcopy
