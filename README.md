#Table Gprof and Valgrind

 input1.txt( 4818331strings; in strings aproximately 500-600 symbols)
 
Time

  info | time
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
   
