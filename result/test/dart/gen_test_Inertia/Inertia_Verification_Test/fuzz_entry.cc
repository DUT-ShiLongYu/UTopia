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
 *  .:: .:::      ...   .....::     .::.  Base UT: Inertia_Verification_Test
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
double autofuzz0;
double autofuzz1;
double autofuzz2;
double autofuzz3;
double autofuzz4;
double autofuzz5;
double autofuzz6;
double autofuzz7;
double autofuzz8;
double autofuzz9;
double autofuzz10;
double autofuzz11;
double autofuzz12;
double autofuzz13;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  double fuzzvar0;
  fuzzvar0 = autofuzz_mutation.fuzzvar0();
  autofuzz0 = fuzzvar0;
  double fuzzvar1;
  fuzzvar1 = autofuzz_mutation.fuzzvar1();
  autofuzz1 = fuzzvar1;
  double fuzzvar2;
  fuzzvar2 = autofuzz_mutation.fuzzvar2();
  autofuzz2 = fuzzvar2;
  double fuzzvar3;
  fuzzvar3 = autofuzz_mutation.fuzzvar3();
  autofuzz3 = fuzzvar3;
  double fuzzvar4;
  fuzzvar4 = autofuzz_mutation.fuzzvar4();
  autofuzz4 = fuzzvar4;
  double fuzzvar5;
  fuzzvar5 = autofuzz_mutation.fuzzvar5();
  autofuzz5 = fuzzvar5;
  double fuzzvar6;
  fuzzvar6 = autofuzz_mutation.fuzzvar6();
  autofuzz6 = fuzzvar6;
  double fuzzvar7;
  fuzzvar7 = autofuzz_mutation.fuzzvar7();
  autofuzz7 = fuzzvar7;
  double fuzzvar8;
  fuzzvar8 = autofuzz_mutation.fuzzvar8();
  autofuzz8 = fuzzvar8;
  double fuzzvar9;
  fuzzvar9 = autofuzz_mutation.fuzzvar9();
  autofuzz9 = fuzzvar9;
  double fuzzvar10;
  fuzzvar10 = autofuzz_mutation.fuzzvar10();
  autofuzz10 = fuzzvar10;
  double fuzzvar11;
  fuzzvar11 = autofuzz_mutation.fuzzvar11();
  autofuzz11 = fuzzvar11;
  double fuzzvar12;
  fuzzvar12 = autofuzz_mutation.fuzzvar12();
  autofuzz12 = fuzzvar12;
  double fuzzvar13;
  fuzzvar13 = autofuzz_mutation.fuzzvar13();
  autofuzz13 = fuzzvar13;
  enterAutofuzz();
}