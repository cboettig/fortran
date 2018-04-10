
#' @export
#' @useDynLib fortran, .registration = TRUE
test_rng <- function() {
  res <- .Fortran(
    "testit",
    x = numeric(1L))
    res$x
}
