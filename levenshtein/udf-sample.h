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


#ifndef SAMPLES_UDF_H
#define SAMPLES_UDF_H

#include <impala_udf/udf.h>

using namespace impala_udf;



// Usage: > create function countvowels(string) returns int
//          location '/user/cloudera/libudfsample.so' SYMBOL='CountVowels';
//        > select countvowels('abracadabra hocus pocus');
//        > select countvowels(c1) from t1;
IntVal LevenshteinDistance(FunctionContext* context, const StringVal& arg1, const StringVal& arg1);


#endif
