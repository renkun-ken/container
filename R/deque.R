#' @export
deque <- function() {
  pointer <- create_deque()

  local({
    empty <- function() deque_empty(pointer)
    size <- function(x) deque_size(pointer)
    push_back <- function(x) deque_push_back(pointer, x)
    push_front <- function(x) deque_push_front(pointer, x)
    pop_back <- function(x) deque_pop_back(pointer)
    pop_front <- function(x) deque_pop_front(pointer)
    back <- function() deque_back(pointer)
    front <- function() deque_front(pointer)
    at <- function(i) deque_at(pointer, i)
    as_list <- function() deque_as_list(pointer)
    container(environment(), "deque")
  })
}

#' @export
as.list.deque <- function(x, ...) {
  x$as_list()
}

