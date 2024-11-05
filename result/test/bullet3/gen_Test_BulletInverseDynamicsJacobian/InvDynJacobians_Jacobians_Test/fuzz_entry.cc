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
 *InvDynJacobians_Jacobians_Test
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
int autofuzz36;
int autofuzz71;
btScalar autofuzz72;
int autofuzz77;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar22;
  fuzzvar22 = autofuzz_mutation.fuzzvar22();
  autofuzz22 = fuzzvar22;
  int fuzzvar36;
  fuzzvar36 = autofuzz_mutation.fuzzvar36();
  autofuzz36 = fuzzvar36;
  int fuzzvar71;
  fuzzvar71 = autofuzz_mutation.fuzzvar71();
  autofuzz71 = fuzzvar71;
  btScalar fuzzvar72;
  fuzzvar72 = autofuzz_mutation.fuzzvar72();
  autofuzz72 = fuzzvar72;
  int fuzzvar77;
  fuzzvar77 = autofuzz_mutation.fuzzvar77();
  autofuzz77 = fuzzvar77;
  enterAutofuzz();
}