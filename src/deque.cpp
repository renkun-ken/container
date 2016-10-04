// [[Rcpp::plugins(cpp11)]]
#include <Rcpp.h>
#include <deque>
using namespace Rcpp;

typedef std::deque<SEXP> deque;

// [[Rcpp::export]]
XPtr<deque> deque_create() {
  deque *x = new deque;
  return XPtr<deque>(x);
}

// [[Rcpp::export]]
void deque_release(XPtr<deque>& x)
{
  x.release();
}

// [[Rcpp::export]]
bool deque_empty(const XPtr<deque>& x)
{
  return x->empty();
}

// [[Rcpp::export]]
R_xlen_t deque_size(const XPtr<deque>& x)
{
  return x->size();
}

// [[Rcpp::export]]
void deque_clear(XPtr<deque>& x)
{
  x->clear();
}

// [[Rcpp::export]]
void deque_push_back(XPtr<deque>& x, const SEXP& value)
{
  x->push_back(value);
}

// [[Rcpp::export]]
void deque_push_front(XPtr<deque>& x, const SEXP& value)
{
  x->push_front(value);
}

// [[Rcpp::export]]
void deque_pop_back(XPtr<deque>& x)
{
  if (x->size()) {
    x->pop_back();
  }
}

// [[Rcpp::export]]
void deque_pop_front(XPtr<deque>& x)
{
  if (x->size()) {
    x->pop_front();
  }
}

// [[Rcpp::export]]
SEXP deque_back(const XPtr<deque>& x)
{
  if (x->size()) {
    return x->back();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP deque_front(const XPtr<deque>& x)
{
  if (x->size()) {
    return x->front();
  } else {
    return R_NilValue;
  }
}

// [[Rcpp::export]]
SEXP deque_at(const XPtr<deque>& x, R_xlen_t i)
{
  return x->at(i);
}

// [[Rcpp::export]]
void deque_insert(const XPtr<deque>& x, R_xlen_t i, const SEXP& obj)
{
  x->insert(x->begin() + i, obj);
}

// [[Rcpp::export]]
void deque_erase(XPtr<deque>& x, R_xlen_t i)
{
  x->erase(x->begin() + i);
}

// [[Rcpp::export]]
List deque_as_list(const XPtr<deque>& x)
{
  List list(x->size());
  R_xlen_t i = 0;
  for (const auto& value : *x) {
    list[i] = value;
    ++i;
  }
  return list;
}
