container <- function(x, class) {
  lockEnvironment(x, bindings = TRUE)
  structure(x, class = c(class, "container", "environment"))
}

#' @export
print.container <- function(x, ...) {
  cat("<", class(x)[[1L]], ">\n", sep = "")
}
