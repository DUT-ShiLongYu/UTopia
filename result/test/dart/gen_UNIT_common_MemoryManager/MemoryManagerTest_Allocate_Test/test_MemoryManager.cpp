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
*  .:: .:::      ...   .....::     .::.  Base UT: MemoryManagerTest_Allocate_Test
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
#include <dart/common/MemoryManager.hpp>
#include "autofuzz.h"
#ifdef __cplusplus
extern "C" {
#endif
extern size_t autofuzz0;
extern size_t autofuzz1;
extern size_t autofuzz2;
extern size_t autofuzz3;
extern size_t autofuzz4;
extern size_t autofuzz5;
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

#include <dart/common/MemoryManager.hpp>

#include <gtest/gtest.h>

using namespace dart;
using namespace common;

//==============================================================================
TEST(MemoryManagerTest, BaseAllocator)
{
  auto mm = MemoryManager();
  auto& baseAllocator = mm.getBaseAllocator();
  auto& freeListAllocator = mm.getFreeListAllocator();
  auto& poolAllocator = mm.getPoolAllocator();

  EXPECT_EQ(&freeListAllocator.getBaseAllocator(), &baseAllocator);
  EXPECT_EQ(&poolAllocator.getBaseAllocator(), &freeListAllocator);
}

//==============================================================================
TEST(MemoryManagerTest, Allocate)
{
  auto mm = MemoryManager();

  // Cannot allocate 0 bytes
  EXPECT_EQ(mm.allocateUsingFree(autofuzz0), nullptr);
  EXPECT_EQ(mm.allocateUsingPool(autofuzz1), nullptr);

  // Allocate 1 byte using FreeListAllocator
  auto ptr1 = mm.allocateUsingFree(autofuzz2);
  EXPECT_NE(ptr1, nullptr);
#if DART_BUILD_MODE_DEBUG
  EXPECT_TRUE(mm.hasAllocated(ptr1, 1));
  EXPECT_FALSE(mm.hasAllocated(nullptr, 1));
  EXPECT_FALSE(mm.hasAllocated(ptr1, 1 * 2));
#endif

  // Allocate 1 byte using PoolAllocator
  auto ptr2 = mm.allocateUsingPool(autofuzz3);
  EXPECT_NE(ptr2, nullptr);
#if DART_BUILD_MODE_DEBUG
  EXPECT_TRUE(mm.hasAllocated(ptr2, 1));
  EXPECT_FALSE(mm.hasAllocated(nullptr, 1));
  EXPECT_FALSE(mm.hasAllocated(ptr2, 1 * 2));
#endif

  // Deallocate all
  mm.deallocateUsingFree(ptr1, autofuzz4);
  mm.deallocateUsingPool(ptr2, autofuzz5);
}

//==============================================================================
TEST(MemoryManagerTest, MemoryLeak)
{
  auto a = MemoryManager();

  // Allocate small memory
  auto ptr1 = a.allocateUsingPool(1);
  EXPECT_NE(ptr1, nullptr);

  // Allocate small memory
  auto ptr2 = a.allocateUsingFree(1);
  EXPECT_NE(ptr2, nullptr);

  // Expect that MemoryManager complains that not all the memory is deallocated
}

#ifdef __cplusplus
extern "C" {
#endif
void enterAutofuzz() {
  class AutofuzzTest : public MemoryManagerTest_Allocate_Test {
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
