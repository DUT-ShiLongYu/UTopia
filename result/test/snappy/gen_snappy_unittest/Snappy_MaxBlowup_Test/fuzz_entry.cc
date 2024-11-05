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
 *  .:: .:::      ...   .....::     .::.  Base UT: Snappy_MaxBlowup_Test
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
int autofuzz7;
int autofuzz9;
int autofuzz10;
int autofuzz11;
__off_t autofuzz12;
int autofuzz24;
size_t autofuzz25;
char autofuzz33;
int autofuzz73;
unsigned long autofuzz75;
int autofuzz76;
unsigned long autofuzz78;
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
  int fuzzvar24;
  fuzzvar24 = autofuzz_mutation.fuzzvar24();
  autofuzz24 = fuzzvar24;
  size_t fuzzvar25;
  fuzzvar25 = autofuzz_mutation.fuzzvar25();
  autofuzz25 = fuzzvar25;
  char fuzzvar33;
  fuzzvar33 = autofuzz_mutation.fuzzvar33();
  autofuzz33 = fuzzvar33;
  int fuzzvar73;
  fuzzvar73 = autofuzz_mutation.fuzzvar73();
  autofuzz73 = fuzzvar73;
  unsigned long fuzzvar75;
  fuzzvar75 = autofuzz_mutation.fuzzvar75();
  autofuzz75 = fuzzvar75;
  int fuzzvar76;
  fuzzvar76 = autofuzz_mutation.fuzzvar76();
  autofuzz76 = fuzzvar76;
  unsigned long fuzzvar78;
  fuzzvar78 = autofuzz_mutation.fuzzvar78();
  autofuzz78 = fuzzvar78;
  enterAutofuzz();
}