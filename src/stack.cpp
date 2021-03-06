// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <stack>
using namespace Rcpp;

typedef std::stack<SEXP> stack;

// [[Rcpp::export]]
XPtr<stack> stack_create() {
  stack *x = new stack;
  return XPtr<stack>(x);
}

// [[Rcpp::export]]
void stack_release(XPtr<stack>& x)
{
  x.release();
}

// [[Rcpp::export]]
bool stack_empty(const XPtr<stack>& x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t stack_size(const XPtr<stack>& x)
{
  return x->size();
}

// [[Rcpp::export]]
void stack_push(XPtr<stack>& x, const SEXP& value)
{
  x->push(value);
}

// [[Rcpp::export]]
void stack_pop(XPtr<stack>& x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
SEXP stack_top(XPtr<stack>& x)
{
  if (x->size()) {
    return x->top();
  } else {
    return R_NilValue;
  }
}

