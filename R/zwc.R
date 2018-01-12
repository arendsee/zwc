#' @useDynLib zwc
#' @importFrom Rcpp sourceCpp
#' @importFrom graphics hist
NULL

#' Cound words in fasta file
#' 
#' @param k Word size
#' @param file FASTA filename
#' @param text FASTA data as character vector
#' @export
fasta_wc <- function(k=1, file="", text=NULL){
  d <- NULL
  if(file.exists(file)){
    d <- wc_from_file(k, file)
  }
  else if(! is.null(text)){
    d <- wc_from_string(k, text)
  } else {
    warning("Please provide 'file' or 'text' arguments")
  }
  class(d) <- append('wordcount', class(d))
  return(d)
}

#' Histograph of counts
#' 
#' @param x a class wordcount entity
#' @param ... other arguments for hist()
#' @return a histogram plot
#' @export
hist.wordcount <- function(x, ...) {
  # I know, this is a dumb way to plot it, but for now I am just testing
  hist(x$count, ...)
}

#' Bar plot of counts
#' 
#' @param x a class wordcount entity
#' @param ... other arguments for ggplot2::geom_bar()
#' @return a bar plot
#' @export
plot.wordcount <- function(x, ...) {
  ggplot2::ggplot(x) +
    ggplot2::geom_bar(ggplot2::aes_string('word', 'count'), stat='identity', ...)
}
