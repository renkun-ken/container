// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <queue>
using namespace Rcpp;

typedef std::queue<SEXP> queue;

// [[Rcpp::export]]
XPtr<queue> create_queue() {
  queue *x = new queue;
  return XPtr<queue>(x);
}

// [[Rcpp::export]]
void queue_release(XPtr<queue> x)
{
  x.release();
}

// [[Rcpp::export]]
bool queue_empty(XPtr<queue> x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t queue_size(XPtr<queue> x)
{
  return x->size();
}

// [[Rcpp::export]]
void queue_push(XPtr<queue> x, SEXP value)
{
  x->push(value);
}

// [[Rcpp::export]]
void queue_pop(XPtr<queue> x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
SEXP queue_back(XPtr<queue> x)
{
  if (x->size()) {
    return x->back();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP queue_front(XPtr<queue> x)
{
  if (x->size()) {
    return x->front();
  } else {
    return R_NilValue;
  }
}