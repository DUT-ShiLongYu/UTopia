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
*  .:: .:::      ...   .....::     .::.  Base UT: ScrewJoint_ThreadPitch_Test
*  .:: .:::      .::.  ..::::.     .::.
*  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
*  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
*   .::::..  .:: .:::  .:::    ..:::..
*      ..:::...   :::  ::.. .::::..
*          ..:::.. ..  ...:::..
*             ..::::..::::.
*                 ..::..
*****************************************************************************/
#include "dart/dart.hpp"
#include <gtest/gtest.h>
#include "autofuzz.h"
#ifdef __cplusplus
extern "C" {
#endif
extern double autofuzz0;
extern double autofuzz1;
#ifdef __cplusplus
}
#endif
/*
 * Copyright (c) 2011-2024, The DART development contributors
 * All rights reserved.
 *
 * The list of contributors can be found at:
 *   https://github.com/dartsim/dart/blob/main/LICENSE
 *
 * This file is provided under the following "BSD-style" License:
 *   Redistribution and use in source and binary forms, with or
 *   without modification, are permitted provided that the following
 *   conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *   CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *   INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *   MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 *   CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
 *   USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 *   AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *   LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *   ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *   POSSIBILITY OF SUCH DAMAGE.
 */

#include "dart/dart.hpp"

#include <gtest/gtest.h>

#include <tuple>

using namespace dart;

//==============================================================================
TEST(ScrewJoint, ThreadPitch)
{
  using namespace dart::math::suffixes;

  // Create single-body skeleton with a screw joint
  auto skel = dynamics::Skeleton::create();
  auto pair = skel->createJointAndBodyNodePair<dart::dynamics::ScrewJoint>();
  auto screwJoint = pair.first;
  auto bodyNode = pair.second;

  // Initial settings
  screwJoint->setPosition(0, 0.0_pi);
  const Eigen::Vector3d axis = screwJoint->getAxis();
  const Eigen::Vector3d pos0 = bodyNode->getTransform().translation();

  auto pitch = autofuzz0;
  auto angle = 1.0_pi;
  screwJoint->setPitch(pitch);
  EXPECT_EQ(screwJoint->getPitch(), pitch);
  screwJoint->setPosition(0, angle);
  Eigen::Vector3d pos1 = bodyNode->getTransform().translation();
  Eigen::Vector3d diff = pos1 - pos0;
  Eigen::Vector3d expectedDiff = axis * pitch * angle / 2.0_pi;
  EXPECT_TRUE(diff.isApprox(expectedDiff));

  pitch = autofuzz1;
  angle = 4.5_pi;
  screwJoint->setPitch(pitch);
  EXPECT_EQ(screwJoint->getPitch(), pitch);
  screwJoint->setPosition(0, angle);
  pos1 = bodyNode->getTransform().translation();
  diff = pos1 - pos0;
  expectedDiff = axis * pitch * angle / 2.0_pi;
  EXPECT_TRUE(diff.isApprox(expectedDiff));
}

#ifdef __cplusplus
extern "C" {
#endif
void enterAutofuzz() {
  class AutofuzzTest : public ScrewJoint_ThreadPitch_Test {
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
