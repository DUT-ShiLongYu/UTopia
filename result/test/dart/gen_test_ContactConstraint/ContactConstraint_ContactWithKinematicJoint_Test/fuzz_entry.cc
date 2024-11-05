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
 *ContactConstraint_ContactWithKinematicJoint_Test
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
#include "dart/common/common.hpp"
#include "dart/constraint/constraint.hpp"
#include "dart/dynamics/dynamics.hpp"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
dart::dynamics::Joint::ActuatorType autofuzz0;
std::size_t autofuzz1;
double autofuzz2;
dart::dynamics::Joint::ActuatorType autofuzz3;
std::size_t autofuzz4;
double autofuzz5;
std::size_t autofuzz6;
double autofuzz7;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  dart::dynamics::Joint::ActuatorType fuzzvar0;
  fuzzvar0 = static_cast<dart::dynamics::detail::ActuatorType>(
      autofuzz_mutation.fuzzvar0());
  autofuzz0 = fuzzvar0;
  std::size_t fuzzvar1;
  fuzzvar1 = autofuzz_mutation.fuzzvar1();
  autofuzz1 = fuzzvar1;
  double fuzzvar2;
  fuzzvar2 = autofuzz_mutation.fuzzvar2();
  autofuzz2 = fuzzvar2;
  dart::dynamics::Joint::ActuatorType fuzzvar3;
  fuzzvar3 = static_cast<dart::dynamics::detail::ActuatorType>(
      autofuzz_mutation.fuzzvar3());
  autofuzz3 = fuzzvar3;
  std::size_t fuzzvar4;
  fuzzvar4 = autofuzz_mutation.fuzzvar4();
  autofuzz4 = fuzzvar4;
  double fuzzvar5;
  fuzzvar5 = autofuzz_mutation.fuzzvar5();
  autofuzz5 = fuzzvar5;
  std::size_t fuzzvar6;
  fuzzvar6 = autofuzz_mutation.fuzzvar6();
  autofuzz6 = fuzzvar6;
  double fuzzvar7;
  fuzzvar7 = autofuzz_mutation.fuzzvar7();
  autofuzz7 = fuzzvar7;
  enterAutofuzz();
}