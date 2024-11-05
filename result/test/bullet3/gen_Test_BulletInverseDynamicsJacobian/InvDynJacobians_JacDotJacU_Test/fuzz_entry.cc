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
 *InvDynJacobians_JacDotJacU_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <gtest/gtest.h>
#include "Bullet3Common/b3Random.h"
#include "CloneTreeCreator.hpp"
#include "CoilCreator.hpp"
#include "DillCreator.hpp"
#include "RandomTreeCreator.hpp"
#include "MultiBodyTreeDebugGraph.hpp"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
int autofuzz22;
int autofuzz62;
btScalar autofuzz63;
int autofuzz68;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar22;
  fuzzvar22 = autofuzz_mutation.fuzzvar22();
  autofuzz22 = fuzzvar22;
  int fuzzvar62;
  fuzzvar62 = autofuzz_mutation.fuzzvar62();
  autofuzz62 = fuzzvar62;
  btScalar fuzzvar63;
  fuzzvar63 = autofuzz_mutation.fuzzvar63();
  autofuzz63 = fuzzvar63;
  int fuzzvar68;
  fuzzvar68 = autofuzz_mutation.fuzzvar68();
  autofuzz68 = fuzzvar68;
  enterAutofuzz();
}