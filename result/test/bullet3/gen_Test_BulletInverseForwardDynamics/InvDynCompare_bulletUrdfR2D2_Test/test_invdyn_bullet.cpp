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
*  .:: .:::      ...   .....::     .::.  Base UT: InvDynCompare_bulletUrdfR2D2_Test
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
#include "autofuzz.h"
#ifdef __cplusplus
extern "C" {
#endif
extern bool autofuzz25;
extern bool autofuzz27;
extern char * autofuzz28;
extern unsigned autofuzz28size;
extern char * autofuzz29;
extern unsigned autofuzz29size;
extern int autofuzz30;
extern double autofuzz39;
extern double autofuzz40;
void assign_fuzz_input_to_global_autofuzz25();
void assign_fuzz_input_to_global_autofuzz27();
void assign_fuzz_input_to_global_autofuzz28();
#ifdef __cplusplus
}
#endif
/// create a bullet btMultiBody model of a tree structured multibody system,
/// convert that model to a MultiBodyTree model.
/// Then - run inverse dynamics on random input data (q, u, dot_u) to get forces
///      - run forward dynamics on (q,u, forces) to get accelerations
///      - compare input accelerations to inverse dynamics to output from forward dynamics

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <string>

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
#include "../../examples/Importers/ImportURDFDemo/URDF2Bullet.h"
#include "../../examples/Utils/b3ResourcePath.h"
#include <invdyn_bullet_comparison.hpp>
#include <btMultiBodyFromURDF.hpp>
#include <MultiBodyTreeCreator.hpp>
#include <MultiBodyTreeDebugGraph.hpp>
#include "Bullet3Common/b3CommandLineArgs.h"
#include "Bullet3Common/b3Random.h"

using namespace btInverseDynamics;

bool FLAGS_verbose = false;

static btVector3 gravity(0, 0, -10);
static bool kBaseFixed = false;
static char kUrdfFile[] = "r2d2.urdf";

/// this test loads the a urdf model with fixed, floating, prismatic and rotational joints,
/// converts in to an inverse dynamics model and compares forward to inverse dynamics for
/// random input
TEST(InvDynCompare, bulletUrdfR2D2)
{
	MyBtMultiBodyFromURDF mb_load(gravity, kBaseFixed);

	char relativeFileName[1024]; { for (unsigned i=0; i<autofuzz29size; ++i) { relativeFileName[i] = autofuzz29[i]; } }

	ASSERT_TRUE(b3ResourcePath::findResourcePath(kUrdfFile, relativeFileName, autofuzz30,0));

	mb_load.setFileName(relativeFileName);
	mb_load.init();

	btMultiBodyTreeCreator id_creator;
	btMultiBody *btmb = mb_load.getBtMultiBody();
	ASSERT_EQ(id_creator.createFromBtMultiBody(btmb), 0);

	MultiBodyTree *id_tree = CreateMultiBodyTree(id_creator);
	ASSERT_EQ(0x0 != id_tree, true);

	vecx q(id_tree->numDoFs());
	vecx u(id_tree->numDoFs());
	vecx dot_u(id_tree->numDoFs());
	vecx joint_forces(id_tree->numDoFs());

	const int kNLoops = 10;
	double max_pos_error = 0;
	double max_acc_error = 0;

	b3Srand(0);

	for (int loop = 0; loop < kNLoops; loop++)
	{
		for (int i = 0; i < q.size(); i++)
		{
			q(i) = b3RandRange(-B3_PI, B3_PI);
			u(i) = b3RandRange(-B3_PI, B3_PI);
			dot_u(i) = b3RandRange(-B3_PI, B3_PI);
		}

		double pos_error = autofuzz39;
		double acc_error = autofuzz40;
		btmb->clearForcesAndTorques();
		id_tree->clearAllUserForcesAndMoments();
		// call inverse dynamics once, to get global position & velocity of root body
		// (fixed, so q, u, dot_u arbitrary)
		EXPECT_EQ(id_tree->calculateInverseDynamics(q, u, dot_u, &joint_forces), 0);

		EXPECT_EQ(compareInverseAndForwardDynamics(q, u, dot_u, gravity, FLAGS_verbose, btmb, id_tree,
												   &pos_error, &acc_error),
				  0);

		if (pos_error > max_pos_error)
		{
			max_pos_error = pos_error;
		}
		if (acc_error > max_acc_error)
		{
			max_acc_error = acc_error;
		}
	}

	if (FLAGS_verbose)
	{
		printf("max_pos_error= %e\n", max_pos_error);
		printf("max_acc_error= %e\n", max_acc_error);
	}

	EXPECT_LT(max_pos_error, std::numeric_limits<idScalar>::epsilon() * 1e4);
	EXPECT_LT(max_acc_error, std::numeric_limits<idScalar>::epsilon() * 1e5);
}



#ifdef __cplusplus
extern "C" {
#endif
void assign_fuzz_input_to_global_autofuzz25() {
    FLAGS_verbose = autofuzz25;
}
void assign_fuzz_input_to_global_autofuzz27() {
    kBaseFixed = autofuzz27;
}
void assign_fuzz_input_to_global_autofuzz28() {
    { for (unsigned i=0; i<autofuzz28size; ++i) { kUrdfFile[i] = autofuzz28[i]; } }
}
void enterAutofuzz() {
  assign_fuzz_input_to_global_autofuzz25();
  assign_fuzz_input_to_global_autofuzz27();
  assign_fuzz_input_to_global_autofuzz28();
  class AutofuzzTest : public InvDynCompare_bulletUrdfR2D2_Test {
  public:
    void runTest() {
      try {
        SetUpTestCase();
      } catch (std::exception &E) {}
      try {
        SetUp();
      } catch (std::exception &E) {}
      try {
        TestBody();
      } catch (std::exception &E) {}
      try {
        TearDown();
      } catch (std::exception &E) {}
      try {
        TearDownTestCase();
      } catch (std::exception &E) {}
    }
  };
  AutofuzzTest Fuzzer;
  Fuzzer.runTest();
}
#ifdef __cplusplus
}
#endif
