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
 *  .:: .:::      ...   .....::     .::.  Base UT: Optimizer_OutStream_Test
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
#include "dart/optimizer/GradientDescentSolver.hpp"
#include <Eigen/Dense>
#include <fstream>
#include <cstdio>
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
std::size_t autofuzz0;
char *autofuzz2;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  std::size_t fuzzvar0;
  fuzzvar0 = autofuzz_mutation.fuzzvar0();
  autofuzz0 = fuzzvar0;
  char *fuzzvar2;
  fuzzvar2 = const_cast<char *>(autofuzz_mutation.fuzzvar2().c_str());
  autofuzz2 = fuzzvar2;
  enterAutofuzz();
}