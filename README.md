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

  
  

   
