#' Priority queue
#' @name priority_queue
#' @export
#' @include container.R
NULL

priority_queue_new <- function(x)
  UseMethod("priority_queue_new")

priority_queue <- Container("priority_queue",
  new = priority_queue_new)

#' @export
priority_queue_new.integer <- function(x) {
  pointer <- priority_queue_int_create()
  local({
    type <- "integer"
    finalize <- function() priority_queue_int_release(pointer)
    empty <- function() priority_queue_int_empty(pointer)
    size <- function() priority_queue_int_size(pointer)
    push <- function(x) priority_queue_int_push(pointer, x)
    pop <- function() priority_queue_int_pop(pointer)
    top <- function() priority_queue_int_top(pointer)
    container(environment(), "priority_queue")
  })
}

#' @export
priority_queue_new.numeric <- function(x) {
  pointer <- priority_queue_double_create()
  local({
    type <- "numeric"
    finalize <- function() priority_queue_double_release(pointer)
    empty <- function() priority_queue_double_empty(pointer)
    size <- function() priority_queue_double_size(pointer)
    push <- function(x) priority_queue_double_push(pointer, x)
    pop <- function() priority_queue_double_pop(pointer)
    top <- function() priority_queue_double_top(pointer)
    container(environment(), "priority_queue")
  })
}

#' @export
priority_queue_new.NULL <- priority_queue_new.numeric
