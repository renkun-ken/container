// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <queue>
using namespace Rcpp;

typedef std::priority_queue<double> priority_queue_double;

// [[Rcpp::export]]
XPtr<priority_queue_double> priority_queue_double_create() {
  priority_queue_double *x = new priority_queue_double;
  return XPtr<priority_queue_double>(x);
}

// [[Rcpp::export]]
void priority_queue_double_release(XPtr<priority_queue_double>& x)
{
  x.release();
}

// [[Rcpp::export]]
bool priority_queue_double_empty(const XPtr<priority_queue_double>& x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t priority_queue_double_size(const XPtr<priority_queue_double>& x)
{
  return x->size();
}

// [[Rcpp::export]]
void priority_queue_double_push(XPtr<priority_queue_double>& x, double value)
{
  x->push(value);
}

// [[Rcpp::export]]
void priority_queue_double_pop(XPtr<priority_queue_double>& x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
double priority_queue_double_top(const XPtr<priority_queue_double>& x)
{
  if (x->size()) {
    return x->top();
  } else {
    return NA_REAL;
  }
}
