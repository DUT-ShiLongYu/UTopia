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
 *SnappyCorruption_UnterminatedVarint_Test
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
#include "autofuzz.h"
extern "C" {
snappy::uint32 autofuzz110;
char autofuzz116;
char autofuzz117;
char autofuzz118;
char autofuzz119;
char autofuzz120;
char autofuzz121;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  snappy::uint32 fuzzvar110;
  fuzzvar110 = autofuzz_mutation.fuzzvar110();
  autofuzz110 = fuzzvar110;
  char fuzzvar116;
  fuzzvar116 = autofuzz_mutation.fuzzvar116();
  autofuzz116 = fuzzvar116;
  char fuzzvar117;
  fuzzvar117 = autofuzz_mutation.fuzzvar117();
  autofuzz117 = fuzzvar117;
  char fuzzvar118;
  fuzzvar118 = autofuzz_mutation.fuzzvar118();
  autofuzz118 = fuzzvar118;
  char fuzzvar119;
  fuzzvar119 = autofuzz_mutation.fuzzvar119();
  autofuzz119 = fuzzvar119;
  char fuzzvar120;
  fuzzvar120 = autofuzz_mutation.fuzzvar120();
  autofuzz120 = fuzzvar120;
  char fuzzvar121;
  fuzzvar121 = autofuzz_mutation.fuzzvar121();
  autofuzz121 = fuzzvar121;
  enterAutofuzz();
}