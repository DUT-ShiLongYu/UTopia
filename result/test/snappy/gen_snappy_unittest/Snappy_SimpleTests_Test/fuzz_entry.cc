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
 *  .:: .:::      ...   .....::     .::.  Base UT: Snappy_SimpleTests_Test
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
int autofuzz7;
int autofuzz9;
int autofuzz10;
int autofuzz11;
__off_t autofuzz12;
int autofuzz24;
size_t autofuzz25;
char autofuzz33;
char *autofuzz47;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz48;
char autofuzz49;
char *autofuzz50;
char *autofuzz51;
char *autofuzz52;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz53;
char autofuzz54;
char *autofuzz55;
char *autofuzz56;
char *autofuzz57;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz58;
char autofuzz59;
char *autofuzz60;
char *autofuzz61;
char *autofuzz62;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz63;
char autofuzz64;
char *autofuzz65;
char *autofuzz66;
char *autofuzz67;
std::__cxx11::basic_string<char, std::char_traits<char>,
                           std::allocator<char>>::size_type autofuzz68;
char autofuzz69;
char *autofuzz70;
char *autofuzz71;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar7;
  fuzzvar7 = autofuzz_mutation.fuzzvar7();
  autofuzz7 = fuzzvar7;
  int fuzzvar9;
  fuzzvar9 = autofuzz_mutation.fuzzvar9();
  autofuzz9 = fuzzvar9;
  int fuzzvar10;
  fuzzvar10 = autofuzz_mutation.fuzzvar10();
  autofuzz10 = fuzzvar10;
  int fuzzvar11;
  fuzzvar11 = autofuzz_mutation.fuzzvar11();
  autofuzz11 = fuzzvar11;
  __off_t fuzzvar12;
  fuzzvar12 = autofuzz_mutation.fuzzvar12();
  autofuzz12 = fuzzvar12;
  int fuzzvar24;
  fuzzvar24 = autofuzz_mutation.fuzzvar24();
  autofuzz24 = fuzzvar24;
  size_t fuzzvar25;
  fuzzvar25 = autofuzz_mutation.fuzzvar25();
  autofuzz25 = fuzzvar25;
  char fuzzvar33;
  fuzzvar33 = autofuzz_mutation.fuzzvar33();
  autofuzz33 = fuzzvar33;
  char *fuzzvar47;
  fuzzvar47 = const_cast<char *>(autofuzz_mutation.fuzzvar47().c_str());
  autofuzz47 = fuzzvar47;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar48;
  if (autofuzz_mutation.fuzzvar48() < 1)
    return;
  fuzzvar48 = autofuzz_mutation.fuzzvar48() & 0x3fff;
  autofuzz48 = fuzzvar48;
  char fuzzvar49;
  fuzzvar49 = autofuzz_mutation.fuzzvar49();
  autofuzz49 = fuzzvar49;
  char *fuzzvar50;
  fuzzvar50 = const_cast<char *>(autofuzz_mutation.fuzzvar50().c_str());
  autofuzz50 = fuzzvar50;
  char *fuzzvar51;
  fuzzvar51 = const_cast<char *>(autofuzz_mutation.fuzzvar51().c_str());
  autofuzz51 = fuzzvar51;
  char *fuzzvar52;
  fuzzvar52 = const_cast<char *>(autofuzz_mutation.fuzzvar52().c_str());
  autofuzz52 = fuzzvar52;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar53;
  if (autofuzz_mutation.fuzzvar53() < 1)
    return;
  fuzzvar53 = autofuzz_mutation.fuzzvar53() & 0x3fff;
  autofuzz53 = fuzzvar53;
  char fuzzvar54;
  fuzzvar54 = autofuzz_mutation.fuzzvar54();
  autofuzz54 = fuzzvar54;
  char *fuzzvar55;
  fuzzvar55 = const_cast<char *>(autofuzz_mutation.fuzzvar55().c_str());
  autofuzz55 = fuzzvar55;
  char *fuzzvar56;
  fuzzvar56 = const_cast<char *>(autofuzz_mutation.fuzzvar56().c_str());
  autofuzz56 = fuzzvar56;
  char *fuzzvar57;
  fuzzvar57 = const_cast<char *>(autofuzz_mutation.fuzzvar57().c_str());
  autofuzz57 = fuzzvar57;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar58;
  if (autofuzz_mutation.fuzzvar58() < 1)
    return;
  fuzzvar58 = autofuzz_mutation.fuzzvar58() & 0x3fff;
  autofuzz58 = fuzzvar58;
  char fuzzvar59;
  fuzzvar59 = autofuzz_mutation.fuzzvar59();
  autofuzz59 = fuzzvar59;
  char *fuzzvar60;
  fuzzvar60 = const_cast<char *>(autofuzz_mutation.fuzzvar60().c_str());
  autofuzz60 = fuzzvar60;
  char *fuzzvar61;
  fuzzvar61 = const_cast<char *>(autofuzz_mutation.fuzzvar61().c_str());
  autofuzz61 = fuzzvar61;
  char *fuzzvar62;
  fuzzvar62 = const_cast<char *>(autofuzz_mutation.fuzzvar62().c_str());
  autofuzz62 = fuzzvar62;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar63;
  if (autofuzz_mutation.fuzzvar63() < 1)
    return;
  fuzzvar63 = autofuzz_mutation.fuzzvar63() & 0x3fff;
  autofuzz63 = fuzzvar63;
  char fuzzvar64;
  fuzzvar64 = autofuzz_mutation.fuzzvar64();
  autofuzz64 = fuzzvar64;
  char *fuzzvar65;
  fuzzvar65 = const_cast<char *>(autofuzz_mutation.fuzzvar65().c_str());
  autofuzz65 = fuzzvar65;
  char *fuzzvar66;
  fuzzvar66 = const_cast<char *>(autofuzz_mutation.fuzzvar66().c_str());
  autofuzz66 = fuzzvar66;
  char *fuzzvar67;
  fuzzvar67 = const_cast<char *>(autofuzz_mutation.fuzzvar67().c_str());
  autofuzz67 = fuzzvar67;
  std::__cxx11::basic_string<char, std::char_traits<char>,
                             std::allocator<char>>::size_type fuzzvar68;
  if (autofuzz_mutation.fuzzvar68() < 1)
    return;
  fuzzvar68 = autofuzz_mutation.fuzzvar68() & 0x3fff;
  autofuzz68 = fuzzvar68;
  char fuzzvar69;
  fuzzvar69 = autofuzz_mutation.fuzzvar69();
  autofuzz69 = fuzzvar69;
  char *fuzzvar70;
  fuzzvar70 = const_cast<char *>(autofuzz_mutation.fuzzvar70().c_str());
  autofuzz70 = fuzzvar70;
  char *fuzzvar71;
  fuzzvar71 = const_cast<char *>(autofuzz_mutation.fuzzvar71().c_str());
  autofuzz71 = fuzzvar71;
  enterAutofuzz();
}