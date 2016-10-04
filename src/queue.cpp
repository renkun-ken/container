// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <queue>
using namespace Rcpp;

typedef std::queue<SEXP> queue;

// [[Rcpp::export]]
XPtr<queue> queue_create() {
  queue *x = new queue;
  return XPtr<queue>(x);
}

// [[Rcpp::export]]
void queue_release(XPtr<queue>& x)
{
  x.release();
}

// [[Rcpp::export]]
bool queue_empty(const XPtr<queue>& x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t queue_size(const XPtr<queue>& x)
{
  return x->size();
}

// [[Rcpp::export]]
void queue_push(XPtr<queue>& x, const SEXP& value)
{
  x->push(value);
}

// [[Rcpp::export]]
void queue_pop(XPtr<queue>& x)
{
  if (x->size()) {
    x->pop();
  }
}

// [[Rcpp::export]]
SEXP queue_back(const XPtr<queue>& x)
{
  if (x->size()) {
    return x->back();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP queue_front(const XPtr<queue>& x)
{
  if (x->size()) {
    return x->front();
  } else {
    return R_NilValue;
  }
}
