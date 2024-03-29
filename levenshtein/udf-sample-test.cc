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

#include <iostream>

#include <impala_udf/udf-test-harness.h>
#include "udf-sample.h"

using namespace impala;
using namespace impala_udf;
using namespace std;

int main(int argc, char** argv) {
  bool passed = true;
  // Using the test harness helpers, validate the UDF returns correct results.
  // These tests validate:
  
  passed &= UdfTestHarness::ValidateUdf<IntVal, StringVal, StringVal>(
      LevenshteinDistance, StringVal("hello"), StringVal("world"), IntVal(4));

  passed &= UdfTestHarness::ValidateUdf<IntVal, StringVal, StringVal>(
      LevenshteinDistance, StringVal("cat"), StringVal("bat"), IntVal(1));

  passed &= UdfTestHarness::ValidateUdf<IntVal, StringVal, StringVal>(
      LevenshteinDistance, StringVal("null"), StringVal::null(), IntVal::null());

  cout << "Tests " << (passed ? "Passed." : "Failed.") << endl;
  return !passed;
}
