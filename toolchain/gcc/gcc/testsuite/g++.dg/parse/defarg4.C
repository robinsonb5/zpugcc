// { dg-do compile }

// Copyright (C) 2003 Free Software Foundation, Inc.
// Contributed by Nathan Sidwell 3 Jul 2003 <nathan@codesourcery.com>

// PR c++ 9162. default args got left unprocessed

struct S {
  friend int foo (int = 100);
};
int i = foo ();

struct R
{
  template <typename T> R (T, int = 0);
};

int Foo ()
{
  R s (1);
}

template <typename T> struct Q
{
  int Foo (T, int = 0);
};

int Foo (Q<int> *s)
{
  s->Foo (1);
}
