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
 *InvDynCompare_bulletUrdfR2D2_Test
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
#include <functional>
#include <btBulletDynamicsCommon.h>
#include <btMultiBodyTreeCreator.hpp>
#include <BulletDynamics/Featherstone/btMultiBodyConstraintSolver.h>
#include <BulletDynamics/Featherstone/btMultiBodyDynamicsWorld.h>
#include <BulletDynamics/Featherstone/btMultiBodyPoint2Point.h>
#include <BulletDynamics/Featherstone/btMultiBodyLinkCollider.h>
#include <gtest/gtest.h>
#include "../../examples/CommonInterfaces/CommonGUIHelperInterface.h"
#include "../../examples/Importers/ImportURDFDemo/BulletUrdfImporter.h"
#include "../../examples/Importers/ImportURDFDemo/URDF2Bullet.h"
#include "../../examples/Importers/ImportURDFDemo/MyMultiBodyCreator.h"
#include "../../examples/Utils/b3ResourcePath.h"
#include <invdyn_bullet_comparison.hpp>
#include <btMultiBodyFromURDF.hpp>
#include <MultiBodyTreeDebugGraph.hpp>
#include "Bullet3Common/b3CommandLineArgs.h"
#include "Bullet3Common/b3Random.h"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include <algorithm>
#include "autofuzz.h"
extern "C" {
bool autofuzz25;
bool autofuzz27;
char *autofuzz28;
unsigned autofuzz28size;
char *autofuzz29;
unsigned autofuzz29size;
int autofuzz30;
double autofuzz39;
double autofuzz40;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  bool fuzzvar25;
  fuzzvar25 = autofuzz_mutation.fuzzvar25();
  autofuzz25 = fuzzvar25;
  bool fuzzvar27;
  fuzzvar27 = autofuzz_mutation.fuzzvar27();
  autofuzz27 = fuzzvar27;
  char fuzzvar28[10 + 1] = {};
  autofuzz28size = 10 <= autofuzz_mutation.fuzzvar28().size()
                       ? 10
                       : autofuzz_mutation.fuzzvar28().size();
  std::copy(autofuzz_mutation.fuzzvar28().begin(),
            autofuzz_mutation.fuzzvar28().begin() + autofuzz28size, fuzzvar28);
  autofuzz28 = fuzzvar28;
  char fuzzvar29[1024 + 1] = {};
  autofuzz29size = 1024 <= autofuzz_mutation.fuzzvar29().size()
                       ? 1024
                       : autofuzz_mutation.fuzzvar29().size();
  std::copy(autofuzz_mutation.fuzzvar29().begin(),
            autofuzz_mutation.fuzzvar29().begin() + autofuzz29size, fuzzvar29);
  autofuzz29 = fuzzvar29;
  int fuzzvar30;
  if (autofuzz_mutation.fuzzvar30() < 1)
    return;
  fuzzvar30 = autofuzz_mutation.fuzzvar30() & 0x3fff;
  autofuzz30 = fuzzvar30;
  double fuzzvar39;
  fuzzvar39 = autofuzz_mutation.fuzzvar39();
  autofuzz39 = fuzzvar39;
  double fuzzvar40;
  fuzzvar40 = autofuzz_mutation.fuzzvar40();
  autofuzz40 = fuzzvar40;
  enterAutofuzz();
}