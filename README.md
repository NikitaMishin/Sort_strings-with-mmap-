#Table Gprof and Valgrind

|) input1.txt( 4818331strings; in strings aproximately 500-600 symbols)
 
 MERGESORT
 
Time

  title | time
    ---|---  
real	|9m25.458s
user	|1m44.436s
sys	|0m25.528s
  

Each sample counts as 0.01 seconds.

  %time   | cumulative seconds |  self seconds |    calls   | self s/call | total  s/call |name    
   ----   |   ------           |     ----      |     ----   | ---         |-----          |------ 
    59.64 |       25.91         |    25.91    |    1        |      25.91  |  25.91        | printstrings
 21.92    | 35.43   |  9.52   |     1    | 9.52  |   9.52 | setstrings
 15.83    | 42.31  |   6.88 |103063007   |  0.00    | 0.00 | comparer
  2.32     |43.31   |  1.01  |4818330     |0.00    | 0.00  |merge
  0.25     |43.42    | 0.11 |       1     |0.11    | 7.99  |mergesortRecursively
  0.09     |43.46     |0.04 |             |         |      |bubblesort
  0.02     |43.47     |0.01  |            |         |      |main
  0.00     |43.47    | 0.00  |1049279     |0.00     |0.00  |swap
  0.00     |43.47    | 0.00  | 624027     |0.00     |0.00  |copyarray
  0.00     |43.47    | 0.00 |       1     |0.00    | 7.99  |mergesort
  
  
  
   Call graph
   
granularity: each sample hit covers 2 byte(s) for 0.02% of 43.47 seconds
  
  
   index %| time     |     self        |  children       |       called    |       name
   ---   |-----     |-------          |-----------      |------------     |  -------- 
         |          |                 |                 |                 |    <spontaneous>
[1]      |    99.9   |     0.01       |  43.42          |                 |        main [1]
         |           |       25.91    |    0.00       |        1/1       |    printstrings [2]
         |           |     9.52       |   0.00         |   1/1           |   setstrings [3]
         |           |0.00            |   7.99          |    1/1        |   mergesort [4]
         |           |               |                 |                 |
         |           |       25.91    |0.00          | 1/1     |      main [1]
[2]   |  59.6 |  25.91   | 0.00 |      1       |  printstrings [2]
         |         |                  |                |                  |
        |           | 9.52           | 0.00            |    1/1          |    main [1]
[3]    | 21.9 |    9.52  |  0.00   |    1     |    setstrings [3]   
        |           |               |                 |                 |
       |           |   0.00          |  7.99           |    1/1           |         main [1]
[4]   |  18.4    |0.00   | 7.99    |   1      |   mergesort [4]
      |         | 0.11  |  7.88   |    1/1    |       mergesortRecursively [5]   
       |         |                  |                |                  | 
       |         |                 |                 |     9636660      |       mergesortRecursively [5]
       |         |   0.11          | 7.88            |    1/1           |     mergesort [4]
[5]    | 18.4|    0.11  |  7.88    |   1+9636660| mergesortRecursively [5]
       |        | 1.01   | 6.74| 4818330/4818330   |  merge [6]
        |        |0.14    |0.00 |2097152/103063007 |    comparer [7]
         |      | 0.00    |0.00 |1049279/1049279 |    swap [9]
          |     | 0.00    |0.00 | 624027/624027 |     copyarray [10]
           |     |        |     |9636660      |       mergesortRecursively [5]
       |         |                  |                |                  | 
       |          |   1.01         | 6.74            | 4818330/4818330|     mergesortRecursively [5]
[6]    | 17.8   | 1.01 |   6.74| 4818330      |   merge [6]
       |       |  6.74  |  0.00 |100965855/103063007|     comparer [7]  
      |         |                  |                |                  |  
        ||       0.14 |   0.00| 2097152/103063007|     mergesortRecursively [5]
       |        | 6.74  |  0.00 |100965855/103063007|     merge [6]
[7]   |  15.8 |   6.88  |  0.00 |103063007   |      comparer [7]    
       |         |                  |                |                  |        
        |      | 0.00 |   0.00| 1049279/1049279 |    mergesortRecursively [5]
[9]   |   0.0  |  0.00 |   0.00 |1049279     |  swap [9] 
  |         |                  |                |                  | 
      |      |   0.00   | 0.00|  624027/624027 |     mergesortRecursively [5]
[10]  |   0.0|    0.00  |  0.00  |624027    |     copyarray [10]

  [6] merge                   [3] setstrings
   [7] comparer                [4] mergesort               [9] swap
  [10] copyarray               [5] mergesortRecursively
   [1] main                    [2] printstrings
   
   
 QUICKSORT
   
   title| time
  -----  |-----
   real	|10m17.456s
user	|1m31.920s
sys	|0m27.400s
Index by function name

 %  time | cumulative seconds | self seconds | calls | self ns/call | total ns/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 47.97 |  11.47 |  11.47 |  163134654 |  70.30 |  70.30 |  comparer 
 27.09 |  17.95 |  6.48 |  |  |  |  printstrings 
 22.12 |  23.23 |  5.29 |  |  |  |  setstrings 
 2.94 |  23.94 |  0.70 |  |  |  |  quicksort 
 0.13 |  23.97 |  0.03 |  |  |  |  bubblesort 
 0.08 |  23.99 |  0.02 |  26101832 |  0.77 |  0.77 |  swap 

   [5] bubblesort              [3] printstrings            [4] setstrings
   [2] comparer       
         [1] quicksort               [6] swap
Call graph


granularity: each sample hit covers 2 byte(s) for 0.04% of 23.99 seconds


 index | % time | self | children | called | name 
------ | ------ | ------ | ------ | ------ | ------ 
 |  |  |  |1767794   |  quicksort  [1]
 [1] |  50.8 |  0.70 |  11.49 |  0+1767794 |  quicksort  [1]
 |  |  11.47 |  0.00 |  163134654/163134654 |  comparer  [2]
 |  |  0.02 |  0.00 |  26101832/26101832 |  swap  [6]
 |  |  |  |  1767794 |  quicksort  [1]
 |  |  11.47 |  0.00 |  163134654/163134654 |  quicksort  [1]
 [2] |  47.8 |  11.47 |  0.00 |  163134654 |  comparer  [2]
  |  |  |  |  |  |  <spontaneous>  
[3] |  27.0 |  6.48 |  0.00 | | printstrings  [3]
 |  |  |  |  |  <spontaneous>  
[4] |  22.0 |  5.29 |  0.00 ||  setstrings  [4]
 |  |  |  |  |  <spontaneous>  
 [5]  |  0.1 |  0.03 |  0.00 |  bubblesort  [5]
 |  |  0.02 |  0.00 |  26101832/26101832 |  quicksort  [1]
 [6] |  0.1 |  0.02 |  0.00 |  26101832 |  swap  [6]



==4755==  VALGRIND(merge 400000strings)
==4755== HEAP SUMMARY:
==4755==     in use at exit: 0 bytes in 0 blocks
==4755==   total heap usage: 3 allocs, 3 frees, 6,401,032 bytes allocated
==4755== 
==4755== All heap blocks were freed -- no leaks are possible
==4755== 
==4755== For counts of detected and suppressed errors, rerun with: -v
==4755== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)


Conclusion:mmap - is really good function. Win by time(1min) and memory(X40) is obviously.  Both (quick and merge work very fast but merge faster). There could be some improvements in functions printstring


   
