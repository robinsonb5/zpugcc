// 2004-03-31  Paolo Carlini  <pcarlini@suse.de>

// Copyright (C) 2004 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// 27.4.3 fpos

#include <fstream>
#include <testsuite_hooks.h>

#define TWO_GB 2147483648UL

// Basic test for LFS support.
void test01()
{
#ifdef _GLIBCXX_USE_LFS
  using namespace std;
  bool test __attribute__((unused)) = true;

  typedef filebuf::pos_type 	pos_type;
  typedef filebuf::off_type 	off_type;

  __gnu_test::set_file_limit(TWO_GB + 200);

  basic_filebuf<char> fb;
  fb.open("14775_tmp", ios_base::out | ios_base::in | ios_base::trunc);

  pos_type ret = fb.pubseekoff(TWO_GB + 100, ios_base::beg);
  VERIFY( ret != pos_type(off_type(-1)) );

  fb.close();
#endif
}

int main()
{
  test01();
  return 0;
}

