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
#include "autofuzz.h"
#ifdef __cplusplus
extern "C" {
#endif
extern double autofuzz0;
extern double autofuzz1;
extern double autofuzz2;
extern double autofuzz3;
extern double autofuzz4;
extern double autofuzz5;
extern double autofuzz6;
extern double autofuzz7;
extern double autofuzz8;
extern double autofuzz9;
extern double autofuzz10;
extern double autofuzz11;
extern double autofuzz12;
extern double autofuzz13;
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

#include "TestHelpers.hpp"

#include <dart/dynamics/Inertia.hpp>

#include <dart/math/Random.hpp>

#include <gtest/gtest.h>

using namespace dart;

//==============================================================================
TEST(Inertia, Verification)
{
  const int numIter = 10;

  for (int i = 0; i < numIter; ++i) {
    const auto mass = math::Random::uniform<double>(autofuzz0, autofuzz1);
    const auto com = math::Random::uniform<Eigen::Vector3d>(-5, 5);
    const auto i_xx = math::Random::uniform<double>(autofuzz2, autofuzz3);
    const auto i_yy = math::Random::uniform<double>(autofuzz4, autofuzz5);
    const auto i_zz = math::Random::uniform<double>(autofuzz6, autofuzz7);
    const auto i_xy = math::Random::uniform<double>(autofuzz8, autofuzz9);
    const auto i_xz = math::Random::uniform<double>(autofuzz10, autofuzz11);
    const auto i_yz = math::Random::uniform<double>(autofuzz12, autofuzz13);

    const dynamics::Inertia inertia(
        mass, com[0], com[1], com[2], i_xx, i_yy, i_zz, i_xy, i_xz, i_yz);

    EXPECT_TRUE(inertia.verify());
  }
}

#ifdef __cplusplus
extern "C" {
#endif
void enterAutofuzz() {
  class AutofuzzTest : public Inertia_Verification_Test {
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
