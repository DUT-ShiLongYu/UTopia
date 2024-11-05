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
 *  .:: .:::      ...   .....::     .::.  Base UT: Snappy_IOVecCopyOverflow_Test
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
#include <algorithm>
#include "autofuzz.h"
extern "C" {
char *autofuzz43;
unsigned autofuzz43size;
int autofuzz44;
int autofuzz45;
int autofuzz46;
unsigned long autofuzz104;
snappy::uint32 autofuzz106;
int autofuzz107;
int autofuzz108;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  char fuzzvar43[4 + 1] = {};
  autofuzz43size = 4 <= autofuzz_mutation.fuzzvar43().size()
                       ? 4
                       : autofuzz_mutation.fuzzvar43().size();
  std::copy(autofuzz_mutation.fuzzvar43().begin(),
            autofuzz_mutation.fuzzvar43().begin() + autofuzz43size, fuzzvar43);
  autofuzz43 = fuzzvar43;
  int fuzzvar44;
  if (autofuzz_mutation.fuzzvar44() < 1)
    return;
  fuzzvar44 = autofuzz_mutation.fuzzvar44() & 0x3fff;
  autofuzz44 = fuzzvar44;
  int fuzzvar45;
  fuzzvar45 = autofuzz_mutation.fuzzvar45();
  autofuzz45 = fuzzvar45;
  int fuzzvar46;
  fuzzvar46 = autofuzz_mutation.fuzzvar46();
  autofuzz46 = fuzzvar46;
  unsigned long fuzzvar104;
  if (autofuzz_mutation.fuzzvar104() < 1)
    return;
  fuzzvar104 = autofuzz_mutation.fuzzvar104() & 0x3fff;
  autofuzz104 = fuzzvar104;
  snappy::uint32 fuzzvar106;
  fuzzvar106 = autofuzz_mutation.fuzzvar106();
  autofuzz106 = fuzzvar106;
  int fuzzvar107;
  fuzzvar107 = autofuzz_mutation.fuzzvar107();
  autofuzz107 = fuzzvar107;
  int fuzzvar108;
  fuzzvar108 = autofuzz_mutation.fuzzvar108();
  autofuzz108 = fuzzvar108;
  enterAutofuzz();
}