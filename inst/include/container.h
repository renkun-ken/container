#pragma once

#include <stack>
#include <deque>
#include <queue>
#include <Rcpp.h>

typedef std::stack<SEXP> stack;
typedef std::deque<SEXP> deque;
typedef std::queue<SEXP> queue;
typedef std::priority_queue<double> priority_queue;
