// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <deque>
using namespace Rcpp;

typedef std::deque<SEXP> deque;

// [[Rcpp::export]]
XPtr<deque> create_deque() {
  deque *x = new deque;
  return XPtr<deque>(x);
}

// [[Rcpp::export]]
void deque_release(XPtr<deque> x)
{
  x.release();
}

// [[Rcpp::export]]
bool deque_empty(XPtr<deque> x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t deque_size(XPtr<deque> x)
{
  return x->size();
}

// [[Rcpp::export]]
void deque_push_back(XPtr<deque> x, SEXP value)
{
  x->push_back(value);
}

// [[Rcpp::export]]
void deque_push_front(XPtr<deque> x, SEXP value)
{
  x->push_front(value);
}

// [[Rcpp::export]]
void deque_pop_back(XPtr<deque> x)
{
  if (x->size()) {
    x->pop_back();
  }
}

// [[Rcpp::export]]
void deque_pop_front(XPtr<deque> x)
{
  if (x->size()) {
    x->pop_front();
  }
}

// [[Rcpp::export]]
SEXP deque_back(XPtr<deque> x)
{
  if (x->size()) {
    return x->back();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP deque_front(XPtr<deque> x)
{
  if (x->size()) {
    return x->front();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP deque_at(XPtr<deque> x, int i)
{
  return x->at(i);
}

// [[Rcpp::export]]
List deque_as_list(XPtr<deque> x)
{
  List list(x->size());
  R_xlen_t i = 0;
  for (const auto value : *x) {
    list[i] = value;
    ++i;
  }
  return list;
}
