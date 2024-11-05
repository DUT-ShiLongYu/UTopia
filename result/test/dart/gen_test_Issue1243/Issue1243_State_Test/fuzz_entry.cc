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
 *  .:: .:::      ...   .....::     .::.  Base UT: Issue1243_State_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include <dart/dart.hpp>
#include <TestHelpers.hpp>
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
double autofuzz1;
std::size_t autofuzz2;
double autofuzz3;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  double fuzzvar1;
  fuzzvar1 = autofuzz_mutation.fuzzvar1();
  autofuzz1 = fuzzvar1;
  std::size_t fuzzvar2;
  fuzzvar2 = autofuzz_mutation.fuzzvar2();
  autofuzz2 = fuzzvar2;
  double fuzzvar3;
  fuzzvar3 = autofuzz_mutation.fuzzvar3();
  autofuzz3 = fuzzvar3;
  enterAutofuzz();
}