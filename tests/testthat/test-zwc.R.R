context("zwc.R")

test_that("Count '>z\nA'", {
  exp <- data.frame(word=c("A"), count=c(1))
  # Requires `expect_equivalent`, not `expect_equal`, because `exp` does not
  # have the class attribute (`wordcount`) that fasta_wc() returned value
  # contains. `expext_equivalent ignores attributes.
  testthat::expect_equivalent(fasta_wc(1, text='>z\nA'), exp)
})

test_that("Count '>z\nA'", {
  exp <- data.frame(word=c("A"), count=c(2))
  testthat::expect_equivalent(fasta_wc(1, text='>z\nA\n>z\nA'), exp)
})
