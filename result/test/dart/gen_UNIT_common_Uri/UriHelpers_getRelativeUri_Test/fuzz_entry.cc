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
 *UriHelpers_getRelativeUri_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include "TestHelpers.hpp"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
bool autofuzz87;
bool autofuzz88;
char *autofuzz89;
bool autofuzz90;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  bool fuzzvar87;
  fuzzvar87 = autofuzz_mutation.fuzzvar87();
  autofuzz87 = fuzzvar87;
  bool fuzzvar88;
  fuzzvar88 = autofuzz_mutation.fuzzvar88();
  autofuzz88 = fuzzvar88;
  char *fuzzvar89;
  fuzzvar89 = const_cast<char *>(autofuzz_mutation.fuzzvar89().c_str());
  autofuzz89 = fuzzvar89;
  bool fuzzvar90;
  fuzzvar90 = autofuzz_mutation.fuzzvar90();
  autofuzz90 = fuzzvar90;
  enterAutofuzz();
}