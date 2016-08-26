// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <queue>
using namespace Rcpp;

typedef std::priority_queue<double> priority_queue;

// [[Rcpp::export]]
XPtr<priority_queue> create_priority_queue() {
  priority_queue *x = new priority_queue;
  return XPtr<priority_queue>(x);
}

// [[Rcpp::export]]
void priority_queue_release(XPtr<priority_queue> x)
{
  x.release();
}

// [[Rcpp::export]]
bool priority_queue_empty(XPtr<priority_queue> x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t priority_queue_size(XPtr<priority_queue> x)
{
  return x->size();
}

// [[Rcpp::export]]
void priority_queue_push(XPtr<priority_queue> x, double value)
{
  x->push(value);
}

// [[Rcpp::export]]
void priority_queue_pop(XPtr<priority_queue> x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
double priority_queue_top(XPtr<priority_queue> x)
{
  if (x->size()) {
    return x->top();
  } else {
    return NA_REAL;
  }
}
