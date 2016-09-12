#' Deque
#' @name deque
#' @export
#' @include container.R
NULL

deque <- Container("deque",
  new = function() {
  pointer <- deque_create()
  local({
    finalize <- function() deque_release(pointer)
    empty <- function() deque_empty(pointer)
    size <- function() deque_size(pointer)
    push_back <- function(x) deque_push_back(pointer, x)
    push_front <- function(x) deque_push_front(pointer, x)
    pop_back <- function() deque_pop_back(pointer)
    pop_front <- function() deque_pop_front(pointer)
    back <- function() deque_back(pointer)
    front <- function() deque_front(pointer)
    at <- function(i) deque_at(pointer, i)
    container(environment(), "deque")
  })
})

#' @export
as.list.deque <- function(x, ...) {
  deque_as_list(get_pointer(x))
}

#' @export
as.double.deque <- function(x, ...) {
  as.double(deque_as_list(get_pointer(x)))
}

#' @export
as.vector.deque <- function(x, mode = "any") {
  as.vector(deque_as_list(get_pointer(x)), mode)
}

#' @export
as.character.deque <- function(x, ...) {
  as.character.default(deque_as_list(get_pointer(x)), ...)
}

#' @export
as.logical.deque <- function(x, ...) {
  as.logical(deque_as_list(get_pointer(x)), ...)
}
