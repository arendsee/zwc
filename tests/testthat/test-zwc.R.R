context("zwc.R")

test_that("Count '>z\nA'", {
  exp <- data.frame(word=c("A"), count=c(1))
  expect_equal(fasta_wc(1, text='>z\nA'), exp)
})

test_that("Count '>z\nA'", {
  exp <- data.frame(word=c("A"), count=c(2))
  expect_equal(fasta_wc(1, text='>z\nA\n>z\nA'), exp)
})
