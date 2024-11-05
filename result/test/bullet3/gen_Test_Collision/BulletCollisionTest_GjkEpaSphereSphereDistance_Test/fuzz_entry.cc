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
 *BulletCollisionTest_GjkEpaSphereSphereDistance_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include <vector>
#include <gtest/gtest.h>
#include "SphereSphereCollision.h"
#include "BulletCollision/CollisionShapes/btHeightfieldTerrainShape.h"
#include "BulletCollision/CollisionShapes/btSphereShape.h"
#include "BulletCollision/CollisionShapes/btMultiSphereShape.h"
#include "BulletCollision/NarrowPhaseCollision/btComputeGjkEpaPenetration.h"
#include "BulletCollision/NarrowPhaseCollision/btMprPenetration.h"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
int autofuzz58;
int autofuzz59;
int autofuzz60;
int autofuzz61;
btScalar autofuzz71;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar58;
  fuzzvar58 = autofuzz_mutation.fuzzvar58();
  autofuzz58 = fuzzvar58;
  int fuzzvar59;
  fuzzvar59 = autofuzz_mutation.fuzzvar59();
  autofuzz59 = fuzzvar59;
  int fuzzvar60;
  fuzzvar60 = autofuzz_mutation.fuzzvar60();
  autofuzz60 = fuzzvar60;
  int fuzzvar61;
  fuzzvar61 = autofuzz_mutation.fuzzvar61();
  autofuzz61 = fuzzvar61;
  btScalar fuzzvar71;
  fuzzvar71 = autofuzz_mutation.fuzzvar71();
  autofuzz71 = fuzzvar71;
  enterAutofuzz();
}