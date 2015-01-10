*test pattern

condition
PCI gen1/2 x1,x2,x4,x8

1. read (incremental)
   4byte  - 1M loop
   64byte - 1M loop

2. write (incremental)
2.1 ioremap
2.2 ioremap_wc
   4byte  - 1M loop
   64byte - 1M loop
