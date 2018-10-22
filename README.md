[![Travis-CI Build Status](https://travis-ci.org/arendsee/zwc.svg?branch=master)](https://travis-ci.org/arendsee/zwc)
[![Coverage Status](https://img.shields.io/codecov/c/github/arendsee/zwc/master.svg)](https://codecov.io/github/arendsee/zwc?branch=master)

zwc
===

I wrote this program because I needed a fast fasta word counter and the EMBOSS ```wordcount``` utility is extremely slow.

zwc is on the order of 10X to 100X faster than EMBOSS' program, depending on the parameters and input data.

Installation
============

Install from github with

```R
library(devtools)
install_github('arendsee/zwc')
```

Usage
=====

```R
# Get counts of all 2-mers in a fasta file
fasta_wc("my-fasta-file.fa", k=2)
```
