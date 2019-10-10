// Copyright 2019 Cloudera Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "udf-sample.h"

#include <cctype>
#include <cmath>
#include <string>

#include "common.h"

size_t impLevenshteinDistance(const std::string &s1, const std::string &s2)
{
  const size_t m(s1.size());
  const size_t n(s2.size());
 
  if( m==0 ) return n;
  if( n==0 ) return m;
 
  size_t *costs = new size_t[n + 1];
 
  for( size_t k=0; k<=n; k++ ) costs[k] = k;
 
  size_t i = 0;
  for ( std::string::const_iterator it1 = s1.begin(); it1 != s1.end(); ++it1, ++i )
  {
    costs[0] = i+1;
    size_t corner = i;
 
    size_t j = 0;
    for ( std::string::const_iterator it2 = s2.begin(); it2 != s2.end(); ++it2, ++j )
    {
      size_t upper = costs[j+1];
      if( *it1 == *it2 )
      {
        costs[j+1] = corner;
      } else {
        size_t t(upper<corner?upper:corner);
        costs[j+1] = (costs[j]<t?costs[j]:t)+1;
      }
      corner = upper;
    }
  }
 
  size_t result = costs[n];
  delete [] costs;
 
  return result;
}

IMPALA_UDF_EXPORT
IntVal LevenshteinDistance(FunctionContext* context, const StringVal& arg1, const StringVal& arg2) {
  if (arg1.is_null || arg2.is_null) return IntVal::null();

  std::string str1 (arg1.ptr, arg1.ptr+arg1.len);
  std::string str2 (arg2.ptr, arg2.ptr+arg2.len);

  return impLevenshteinDistance(str1, str2);
}

