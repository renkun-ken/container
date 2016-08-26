container <- function(x, class) {
  lockEnvironment(x, bindings = TRUE)
  reg.finalizer(x, function(x) x$finalize())
  class(x) <- c(class, "container", "environment")
  x
}

get_pointer <- function(x) {
  parent.env(x)$pointer
}

#' @export
print.container <- function(x, ...) {
  cat("<", class(x)[[1L]], ">\n", sep = "")
}
