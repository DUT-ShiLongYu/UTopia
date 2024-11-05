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
 *CorruptedTest_VerifyCorrupted_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <vector>
#include "snappy.h"
#include "snappy-internal.h"
#include "snappy-test.h"
#include "snappy-sinksource.h"
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include "autofuzz.h"
extern "C" {
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz1;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz38;
size_t autofuzz39;
size_t autofuzz40;
snappy::uint32 autofuzz42;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar1;
  fuzzvar1 = autofuzz_mutation.fuzzvar1();
  autofuzz1 = fuzzvar1;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar38;
  fuzzvar38 = autofuzz_mutation.fuzzvar38();
  autofuzz38 = fuzzvar38;
  size_t fuzzvar39;
  fuzzvar39 = autofuzz_mutation.fuzzvar39();
  autofuzz39 = fuzzvar39;
  size_t fuzzvar40;
  fuzzvar40 = autofuzz_mutation.fuzzvar40();
  autofuzz40 = fuzzvar40;
  snappy::uint32 fuzzvar42;
  fuzzvar42 = autofuzz_mutation.fuzzvar42();
  autofuzz42 = fuzzvar42;
  enterAutofuzz();
}