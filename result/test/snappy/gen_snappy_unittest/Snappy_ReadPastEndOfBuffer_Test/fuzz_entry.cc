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
 *  .:: .:::      ...   .....::     .::.  Base UT:
 *Snappy_ReadPastEndOfBuffer_Test
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
int autofuzz7;
int autofuzz9;
int autofuzz10;
int autofuzz11;
__off_t autofuzz12;
char *autofuzz43;
unsigned autofuzz43size;
int autofuzz44;
snappy::uint32 autofuzz130;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar7;
  fuzzvar7 = autofuzz_mutation.fuzzvar7();
  autofuzz7 = fuzzvar7;
  int fuzzvar9;
  fuzzvar9 = autofuzz_mutation.fuzzvar9();
  autofuzz9 = fuzzvar9;
  int fuzzvar10;
  fuzzvar10 = autofuzz_mutation.fuzzvar10();
  autofuzz10 = fuzzvar10;
  int fuzzvar11;
  fuzzvar11 = autofuzz_mutation.fuzzvar11();
  autofuzz11 = fuzzvar11;
  __off_t fuzzvar12;
  fuzzvar12 = autofuzz_mutation.fuzzvar12();
  autofuzz12 = fuzzvar12;
  char fuzzvar43[4 + 1] = {};
  autofuzz43size = 4 <= autofuzz_mutation.fuzzvar43().size()
                       ? 4
                       : autofuzz_mutation.fuzzvar43().size();
  std::copy(autofuzz_mutation.fuzzvar43().begin(),
            autofuzz_mutation.fuzzvar43().begin() + autofuzz43size, fuzzvar43);
  autofuzz43 = fuzzvar43;
  int fuzzvar44;
  if (autofuzz_mutation.fuzzvar44() < 1)
    return;
  fuzzvar44 = autofuzz_mutation.fuzzvar44() & 0x3fff;
  autofuzz44 = fuzzvar44;
  snappy::uint32 fuzzvar130;
  fuzzvar130 = autofuzz_mutation.fuzzvar130();
  autofuzz130 = fuzzvar130;
  enterAutofuzz();
}