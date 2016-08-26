#' @export
stack <- function() {
  pointer <- stack_create()
  local({
    finalize <- function() stack_release(pointer)
    empty <- function() stack_empty(pointer)
    size <- function() stack_size(pointer)
    push <- function(x) stack_push(pointer, x)
    pop <- function() stack_pop(pointer)
    top <- function() stack_top(pointer)
    container(environment(), "stack")
  })
}
