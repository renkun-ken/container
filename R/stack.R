#' @export
stack <- function() {
  pointer <- create_stack()

  local({
    empty <- function() stack_empty(pointer)
    size <- function(x) stack_size(pointer)
    push <- function(x) stack_push(pointer, x)
    pop <- function() stack_pop(pointer)
    top <- function() stack_top(pointer)
    container(environment(), "stack")
  })
}
