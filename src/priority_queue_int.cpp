// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <queue>
using namespace Rcpp;

typedef std::priority_queue<int> priority_queue_int;

// [[Rcpp::export]]
XPtr<priority_queue_int> priority_queue_int_create() {
  priority_queue_int *x = new priority_queue_int;
  return XPtr<priority_queue_int>(x);
}

// [[Rcpp::export]]
void priority_queue_int_release(XPtr<priority_queue_int>& x)
{
  x.release();
}

// [[Rcpp::export]]
bool priority_queue_int_empty(const XPtr<priority_queue_int>& x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t priority_queue_int_size(const XPtr<priority_queue_int>& x)
{
  return x->size();
}

// [[Rcpp::export]]
void priority_queue_int_push(XPtr<priority_queue_int>& x, int value)
{
  x->push(value);
}

// [[Rcpp::export]]
void priority_queue_int_pop(XPtr<priority_queue_int>& x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
int priority_queue_int_top(const XPtr<priority_queue_int>& x)
{
  if (x->size()) {
    return x->top();
  } else {
    return NA_INTEGER;
  }
}
