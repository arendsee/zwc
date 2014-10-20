zwc
===

I wrote this program because I needed a fast fasta word counter and the EMBOSS ```wordcount``` utility is extremely slow.

zwc is on the order of 10X to 100X faster than EMBOSS' program, depending on the parameters and input data.

Usage
=====

zwc [word length] < input.fasta

Example
=======

```bash
zwc 2 < Arabidopsis_thaliana.cds.fasta
TA	2057553
CG	1451808
AT	3107841
CC	1699984
AC	2224214
AG	3257240
GG	2384179
CA	2848048
CT	2828292
GC	1948092
TT	3501534
TG	3298581
AA	3895826
GT	2375837
TC	2955840
GA	3676482
```

Benchmarking
============

* atfaa is aliased to cat the Arabidopsis proteome
* atfna the whole genome
* atcds the coding sequences

```bash
$ time atcds | zwc 2 > /dev/null
real	0m5.766s
user	0m5.708s
sys	0m0.056s

$ time atcds | wordcount -wordsize 2 -filter > /dev/null
real	0m19.956s
user	0m19.253s
sys	0m0.664s

$ time atfaa | zwc 2 > /dev/null
real	0m1.917s
user	0m1.908s
sys	0m0.012s

$ time atfaa | wordcount -wordsize 2 -filter > /dev/null
real	0m49.976s
user	0m49.155s
sys	0m0.656s

$ time atfaa | zwc 3 > /dev/null
real	0m2.515s
user	0m2.496s
sys	0m0.016s

$ time atfaa | wordcount -wordsize 3 -filter > /dev/null
real	6m36.356s
user	6m33.365s
sys	0m1.544s

$ time atfaa | zwc 4 > /dev/null
real	0m4.802s
user	0m4.796s
sys	0m0.008s

$ time wordcount -sequence <(atfaa) -wordsize 4 -filter > /dev/null
real	2m33.722s
user	2m31.881s
sys	0m1.276s

$ time atfaa | zwc 5 > /dev/null
real	0m8.001s
user	0m7.888s
sys	0m0.108s

$ time wordcount -sequence <(atfaa) -wordsize 5 -filter > z
real	0m57.676s
user	0m55.707s
sys	0m1.616s
```

I should probably do some more sophisticated benchmarking, the above results for ```wordcount``` are kind of bizzare.
