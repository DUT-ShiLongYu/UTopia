/*****************************************************************************
 *                 .::::.
 *             ..:::...::::..
 *         ..::::..      ..::::.
 *      ..:::..              ..:::..
 *   .::::.                      .::::.
 *  .::.                            .::.
 *  .::                         ..:. ::.  UTopia
 *  .:: .::.                ..::::: .::.  Unit Tests to Fuzzing
 *  .:: .:::             .::::::..  .::.  https://github.com/Samsung/UTopia
 *  .:: .:::            ::::...     .::.
 *  .:: .:::      ...   .....::     .::.  Base UT: Snappy_ZeroOffsetCopy_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "snappy.h"
#include "snappy-internal.h"
#include "snappy-test.h"
#include "snappy-sinksource.h"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include <algorithm>
#include "autofuzz.h"
extern "C" {
char *autofuzz133;
char *autofuzz134;
unsigned autofuzz134size;
size_t autofuzz135;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  char *fuzzvar133;
  fuzzvar133 = const_cast<char *>(autofuzz_mutation.fuzzvar133().c_str());
  autofuzz133 = fuzzvar133;
  char fuzzvar134[100 + 1] = {};
  autofuzz134size = 100 <= autofuzz_mutation.fuzzvar134().size()
                        ? 100
                        : autofuzz_mutation.fuzzvar134().size();
  std::copy(autofuzz_mutation.fuzzvar134().begin(),
            autofuzz_mutation.fuzzvar134().begin() + autofuzz134size,
            fuzzvar134);
  autofuzz134 = fuzzvar134;
  size_t fuzzvar135;
  fuzzvar135 = autofuzz_mutation.fuzzvar135();
  autofuzz135 = fuzzvar135;
  enterAutofuzz();
}