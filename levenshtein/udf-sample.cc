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


// Count all occurrences of the letters (a,e,i,o,u) in the input string.
// Case-insensitive, so also counts (A,E,I,O,U).
IMPALA_UDF_EXPORT
IntVal CountVowels(FunctionContext* context, const StringVal& arg1) {
  if (arg1.is_null) return IntVal::null();

  int count;
  int index;
  uint8_t *ptr;

  for (ptr = arg1.ptr, count = 0, index = 0; index < arg1.len; index++, ptr++) {
    uint8_t c = tolower(*ptr);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      count++;
    }
  }
  return IntVal(count);
}

