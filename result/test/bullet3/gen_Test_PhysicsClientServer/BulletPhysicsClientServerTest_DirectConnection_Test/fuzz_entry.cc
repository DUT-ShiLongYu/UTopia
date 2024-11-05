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
 *BulletPhysicsClientServerTest_DirectConnection_Test
 *  .:: .:::      .::.  ..::::.     .::.
 *  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
 *  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
 *   .::::..  .:: .:::  .:::    ..:::..
 *      ..:::...   :::  ::.. .::::..
 *          ..:::.. ..  ...:::..
 *             ..::::..::::.
 *                 ..::..
 *****************************************************************************/
#include "FuzzArgsProfile.pb.h"
#include "libprotobuf-mutator/src/libfuzzer/libfuzzer_macro.h"
#include <algorithm>
#include "autofuzz.h"
extern "C" {
int autofuzz51;
int autofuzz52;
int autofuzz53;
int autofuzz54;
char *autofuzz55;
char *autofuzz56;
double autofuzz57;
double autofuzz58;
double autofuzz59;
double autofuzz60;
int autofuzz61;
int *autofuzz63;
unsigned autofuzz63size;
int autofuzz65;
double autofuzz69;
int autofuzz70;
double autofuzz72;
double autofuzz73;
double autofuzz74;
int autofuzz76;
int autofuzz78;
int autofuzz79;
int autofuzz80;
double autofuzz82;
double autofuzz83;
double autofuzz84;
double autofuzz85;
double autofuzz86;
double autofuzz87;
double autofuzz88;
double autofuzz89;
double autofuzz90;
double autofuzz91;
int autofuzz102;
int autofuzz103;
int autofuzz104;
char *autofuzz106;
char *autofuzz108;
}
DEFINE_PROTO_FUZZER(const AutoFuzz::FuzzArgsProfile &autofuzz_mutation) {
  int fuzzvar51;
  fuzzvar51 = autofuzz_mutation.fuzzvar51();
  autofuzz51 = fuzzvar51;
  int fuzzvar52;
  fuzzvar52 = autofuzz_mutation.fuzzvar52();
  autofuzz52 = fuzzvar52;
  int fuzzvar53;
  fuzzvar53 = autofuzz_mutation.fuzzvar53();
  autofuzz53 = fuzzvar53;
  int fuzzvar54;
  fuzzvar54 = autofuzz_mutation.fuzzvar54();
  autofuzz54 = fuzzvar54;
  char *fuzzvar55;
  fuzzvar55 = const_cast<char *>(autofuzz_mutation.fuzzvar55().c_str());
  autofuzz55 = fuzzvar55;
  char *fuzzvar56;
  fuzzvar56 = const_cast<char *>(autofuzz_mutation.fuzzvar56().c_str());
  autofuzz56 = fuzzvar56;
  double fuzzvar57;
  fuzzvar57 = autofuzz_mutation.fuzzvar57();
  autofuzz57 = fuzzvar57;
  double fuzzvar58;
  fuzzvar58 = autofuzz_mutation.fuzzvar58();
  autofuzz58 = fuzzvar58;
  double fuzzvar59;
  fuzzvar59 = autofuzz_mutation.fuzzvar59();
  autofuzz59 = fuzzvar59;
  double fuzzvar60;
  fuzzvar60 = autofuzz_mutation.fuzzvar60();
  autofuzz60 = fuzzvar60;
  int fuzzvar61;
  fuzzvar61 = autofuzz_mutation.fuzzvar61();
  autofuzz61 = fuzzvar61;
  int fuzzvar63[10 + 1] = {};
  autofuzz63size = 10 <= autofuzz_mutation.fuzzvar63().size()
                       ? 10
                       : autofuzz_mutation.fuzzvar63().size();
  std::copy(autofuzz_mutation.fuzzvar63().begin(),
            autofuzz_mutation.fuzzvar63().begin() + autofuzz63size, fuzzvar63);
  autofuzz63 = fuzzvar63;
  int fuzzvar65;
  fuzzvar65 = autofuzz_mutation.fuzzvar65();
  autofuzz65 = fuzzvar65;
  double fuzzvar69;
  fuzzvar69 = autofuzz_mutation.fuzzvar69();
  autofuzz69 = fuzzvar69;
  int fuzzvar70;
  fuzzvar70 = autofuzz_mutation.fuzzvar70();
  autofuzz70 = fuzzvar70;
  double fuzzvar72;
  fuzzvar72 = autofuzz_mutation.fuzzvar72();
  autofuzz72 = fuzzvar72;
  double fuzzvar73;
  fuzzvar73 = autofuzz_mutation.fuzzvar73();
  autofuzz73 = fuzzvar73;
  double fuzzvar74;
  fuzzvar74 = autofuzz_mutation.fuzzvar74();
  autofuzz74 = fuzzvar74;
  int fuzzvar76;
  fuzzvar76 = autofuzz_mutation.fuzzvar76();
  autofuzz76 = fuzzvar76;
  int fuzzvar78;
  fuzzvar78 = autofuzz_mutation.fuzzvar78();
  autofuzz78 = fuzzvar78;
  int fuzzvar79;
  fuzzvar79 = autofuzz_mutation.fuzzvar79();
  autofuzz79 = fuzzvar79;
  int fuzzvar80;
  fuzzvar80 = autofuzz_mutation.fuzzvar80();
  autofuzz80 = fuzzvar80;
  double fuzzvar82;
  fuzzvar82 = autofuzz_mutation.fuzzvar82();
  autofuzz82 = fuzzvar82;
  double fuzzvar83;
  fuzzvar83 = autofuzz_mutation.fuzzvar83();
  autofuzz83 = fuzzvar83;
  double fuzzvar84;
  fuzzvar84 = autofuzz_mutation.fuzzvar84();
  autofuzz84 = fuzzvar84;
  double fuzzvar85;
  fuzzvar85 = autofuzz_mutation.fuzzvar85();
  autofuzz85 = fuzzvar85;
  double fuzzvar86;
  fuzzvar86 = autofuzz_mutation.fuzzvar86();
  autofuzz86 = fuzzvar86;
  double fuzzvar87;
  fuzzvar87 = autofuzz_mutation.fuzzvar87();
  autofuzz87 = fuzzvar87;
  double fuzzvar88;
  fuzzvar88 = autofuzz_mutation.fuzzvar88();
  autofuzz88 = fuzzvar88;
  double fuzzvar89;
  fuzzvar89 = autofuzz_mutation.fuzzvar89();
  autofuzz89 = fuzzvar89;
  double fuzzvar90;
  fuzzvar90 = autofuzz_mutation.fuzzvar90();
  autofuzz90 = fuzzvar90;
  double fuzzvar91;
  fuzzvar91 = autofuzz_mutation.fuzzvar91();
  autofuzz91 = fuzzvar91;
  int fuzzvar102;
  fuzzvar102 = autofuzz_mutation.fuzzvar102();
  autofuzz102 = fuzzvar102;
  int fuzzvar103;
  fuzzvar103 = autofuzz_mutation.fuzzvar103();
  autofuzz103 = fuzzvar103;
  int fuzzvar104;
  fuzzvar104 = autofuzz_mutation.fuzzvar104();
  autofuzz104 = fuzzvar104;
  char *fuzzvar106;
  fuzzvar106 = const_cast<char *>(autofuzz_mutation.fuzzvar106().c_str());
  autofuzz106 = fuzzvar106;
  char *fuzzvar108;
  fuzzvar108 = const_cast<char *>(autofuzz_mutation.fuzzvar108().c_str());
  autofuzz108 = fuzzvar108;
  enterAutofuzz();
}