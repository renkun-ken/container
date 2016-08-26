#' @export
priority_queue <- function(x)
  UseMethod("priority_queue")

#' @export
priority_queue.integer <- function(x) {
  pointer <- priority_queue_int_create()
  local({
    empty <- function() priority_queue_int_empty(pointer)
    size <- function() priority_queue_int_size(pointer)
    push <- function(x) priority_queue_int_push(pointer, x)
    pop <- function() priority_queue_int_pop(pointer)
    top <- function() priority_queue_int_top(pointer)
    container(environment(), "priority_queue")
  })
}

#' @export
priority_queue.numeric <- function(x) {
  pointer <- priority_queue_double_create()
  local({
    empty <- function() priority_queue_double_empty(pointer)
    size <- function() priority_queue_double_size(pointer)
    push <- function(x) priority_queue_double_push(pointer, x)
    pop <- function() priority_queue_double_pop(pointer)
    top <- function() priority_queue_double_top(pointer)
    container(environment(), "priority_queue")
  })
}

#' @export
priority_queue.NULL <- priority_queue.numeric
