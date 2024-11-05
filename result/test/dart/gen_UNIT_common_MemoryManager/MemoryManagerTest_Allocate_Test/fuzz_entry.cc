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
 *MemoryManagerTest_Allocate_Test
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
#include <dart/common/MemoryManager.hpp>
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
size_t autofuzz0;
size_t autofuzz1;
size_t autofuzz2;
size_t autofuzz3;
size_t autofuzz4;
size_t autofuzz5;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  size_t fuzzvar0;
  fuzzvar0 = autofuzz_mutation.fuzzvar0();
  autofuzz0 = fuzzvar0;
  size_t fuzzvar1;
  fuzzvar1 = autofuzz_mutation.fuzzvar1();
  autofuzz1 = fuzzvar1;
  size_t fuzzvar2;
  fuzzvar2 = autofuzz_mutation.fuzzvar2();
  autofuzz2 = fuzzvar2;
  size_t fuzzvar3;
  fuzzvar3 = autofuzz_mutation.fuzzvar3();
  autofuzz3 = fuzzvar3;
  size_t fuzzvar4;
  fuzzvar4 = autofuzz_mutation.fuzzvar4();
  autofuzz4 = fuzzvar4;
  size_t fuzzvar5;
  fuzzvar5 = autofuzz_mutation.fuzzvar5();
  autofuzz5 = fuzzvar5;
  enterAutofuzz();
}