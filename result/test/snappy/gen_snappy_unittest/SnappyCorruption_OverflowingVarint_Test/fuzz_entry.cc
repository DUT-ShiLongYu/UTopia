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
 *SnappyCorruption_OverflowingVarint_Test
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
char autofuzz124;
char autofuzz125;
char autofuzz126;
char autofuzz127;
char autofuzz128;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  snappy::uint32 fuzzvar110;
  fuzzvar110 = autofuzz_mutation.fuzzvar110();
  autofuzz110 = fuzzvar110;
  char fuzzvar124;
  fuzzvar124 = autofuzz_mutation.fuzzvar124();
  autofuzz124 = fuzzvar124;
  char fuzzvar125;
  fuzzvar125 = autofuzz_mutation.fuzzvar125();
  autofuzz125 = fuzzvar125;
  char fuzzvar126;
  fuzzvar126 = autofuzz_mutation.fuzzvar126();
  autofuzz126 = fuzzvar126;
  char fuzzvar127;
  fuzzvar127 = autofuzz_mutation.fuzzvar127();
  autofuzz127 = fuzzvar127;
  char fuzzvar128;
  fuzzvar128 = autofuzz_mutation.fuzzvar128();
  autofuzz128 = fuzzvar128;
  enterAutofuzz();
}