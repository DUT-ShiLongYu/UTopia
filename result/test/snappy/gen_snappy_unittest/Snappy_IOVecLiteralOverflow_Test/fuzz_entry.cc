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
 *Snappy_IOVecLiteralOverflow_Test
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
unsigned long autofuzz99;
snappy::uint32 autofuzz101;
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
  unsigned long fuzzvar99;
  if (autofuzz_mutation.fuzzvar99() < 1)
    return;
  fuzzvar99 = autofuzz_mutation.fuzzvar99() & 0x3fff;
  autofuzz99 = fuzzvar99;
  snappy::uint32 fuzzvar101;
  fuzzvar101 = autofuzz_mutation.fuzzvar101();
  autofuzz101 = fuzzvar101;
  enterAutofuzz();
}