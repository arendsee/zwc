#' @useDynLib zwc
#' @importFrom Rcpp sourceCpp
NULL

#' Cound words in fasta file
#' 
#' @param k Word size
#' @param file FASTA filename
#' @param text FASTA data as character vector
#' @export
zwc <- function(k=1, file="", text=NULL){
  if(file.exists(file)){
    wc_from_file(k, file)
  }
  else if(! is.null(text)){
    wc_from_string(k, text)
  } else {
    warning("Please provide 'file' or 'text' arguments")
  }
}
