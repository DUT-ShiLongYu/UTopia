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
 *  .:: .:::      ...   .....::     .::.  Base UT: Snappy_IOVecEdgeCases_Test
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
unsigned long autofuzz89;
snappy::uint32 autofuzz91;
int autofuzz92;
int autofuzz93;
int autofuzz94;
int autofuzz95;
int autofuzz96;
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
  unsigned long fuzzvar89;
  if (autofuzz_mutation.fuzzvar89() < 1)
    return;
  fuzzvar89 = autofuzz_mutation.fuzzvar89() & 0x3fff;
  autofuzz89 = fuzzvar89;
  snappy::uint32 fuzzvar91;
  fuzzvar91 = autofuzz_mutation.fuzzvar91();
  autofuzz91 = fuzzvar91;
  int fuzzvar92;
  fuzzvar92 = autofuzz_mutation.fuzzvar92();
  autofuzz92 = fuzzvar92;
  int fuzzvar93;
  fuzzvar93 = autofuzz_mutation.fuzzvar93();
  autofuzz93 = fuzzvar93;
  int fuzzvar94;
  fuzzvar94 = autofuzz_mutation.fuzzvar94();
  autofuzz94 = fuzzvar94;
  int fuzzvar95;
  fuzzvar95 = autofuzz_mutation.fuzzvar95();
  autofuzz95 = fuzzvar95;
  int fuzzvar96;
  fuzzvar96 = autofuzz_mutation.fuzzvar96();
  autofuzz96 = fuzzvar96;
  enterAutofuzz();
}