#' @export
queue <- function() {
  pointer <- queue_create()
  local({
    empty <- function() queue_empty(pointer)
    size <- function() queue_size(pointer)
    push <- function(x) queue_push(pointer, x)
    pop <- function() queue_pop(pointer)
    front <- function() queue_front(pointer)
    back <- function() queue_back(pointer)
    container(environment(), "queue")
  })
}
