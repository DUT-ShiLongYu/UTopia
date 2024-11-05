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
 *InvDynJacobians_VelocitiesFromJacobians_Test
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
int autofuzz55;
int autofuzz80;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar55;
  fuzzvar55 = autofuzz_mutation.fuzzvar55();
  autofuzz55 = fuzzvar55;
  int fuzzvar80;
  fuzzvar80 = autofuzz_mutation.fuzzvar80();
  autofuzz80 = fuzzvar80;
  enterAutofuzz();
}