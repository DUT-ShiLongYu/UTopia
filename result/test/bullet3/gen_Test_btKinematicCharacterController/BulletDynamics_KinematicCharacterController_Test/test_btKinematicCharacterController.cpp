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
*  .:: .:::      ...   .....::     .::.  Base UT: BulletDynamics_KinematicCharacterController_Test
*  .:: .:::      .::.  ..::::.     .::.
*  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
*  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
*   .::::..  .:: .:::  .:::    ..:::..
*      ..:::...   :::  ::.. .::::..
*          ..:::.. ..  ...:::..
*             ..::::..::::.
*                 ..::..
*****************************************************************************/
#include <btBulletDynamicsCommon.h>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include <gtest/gtest.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>
#include "autofuzz.h"
#ifdef __cplusplus
extern "C" {
#endif
extern btScalar autofuzz2;
#ifdef __cplusplus
}
#endif


#include <btBulletDynamicsCommon.h>
#include <BulletDynamics/Character/btKinematicCharacterController.h>
#include <gtest/gtest.h>
#include <BulletCollision/CollisionDispatch/btGhostObject.h>

GTEST_TEST(BulletDynamics, KinematicCharacterController)
{
	btPairCachingGhostObject* ghostObject = new btPairCachingGhostObject();
	btBoxShape* convexShape = new btBoxShape(btVector3(1, 1, 1));

	//For now only a simple test that it initializes correctly.
	btKinematicCharacterController* tested = new btKinematicCharacterController(ghostObject, convexShape, autofuzz2);
	EXPECT_TRUE(tested);

	EXPECT_FLOAT_EQ(-9.8 * 3.0, tested->getGravity().x());
	EXPECT_FLOAT_EQ(0, tested->getGravity().y());
	EXPECT_FLOAT_EQ(0, tested->getGravity().z());
}


#ifdef __cplusplus
extern "C" {
#endif
void enterAutofuzz() {
  class AutofuzzTest : public BulletDynamics_KinematicCharacterController_Test {
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
