#' @export
priority_queue <- function() {
  pointer <- create_priority_queue()

  local({
    empty <- function() priority_queue_empty(pointer)
    size <- function(x) priority_queue_size(pointer)
    push <- function(x) priority_queue_push(pointer, x)
    pop <- function() priority_queue_pop(pointer)
    top <- function() priority_queue_top(pointer)
    container(environment(), "priority_queue")
  })
}
