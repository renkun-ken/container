Container <- function(class, ...) {
  e <- new.env(parent = parent.frame())
  e$class <- class
  list2env(list(...), e)
  lockEnvironment(e)
  class(e) <- c("Container", "environment")
  e
}

#' @importFrom utils ls.str
#' @export
print.Container <- function(x, ...) {
  cat(sprintf("<Container: %s>\n", x$class))
  print(ls.str(x, mode = "function"))
}

container <- function(x, class) {
  lockEnvironment(x, bindings = TRUE)
  reg.finalizer(x, function(x) x$finalize())
  class(x) <- c(class, "container", "environment")
  x
}

get_pointer <- function(x) {
  parent.env(x)$pointer
}

#' @importFrom utils ls.str
#' @export
print.container <- function(x, ...) {
  cat("<", class(x)[[1L]], ">\n", sep = "")
  print(ls.str(x, mode = "function"))
}
