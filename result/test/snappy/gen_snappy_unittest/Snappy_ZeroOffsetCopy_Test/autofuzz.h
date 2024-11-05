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
*  .:: .:::      ...   .....::     .::.  Base UT: Snappy_ZeroOffsetCopy_Test
*  .:: .:::      .::.  ..::::.     .::.
*  .:: .::: .:.  .:::  :::..       .::.  This file was generated automatically
*  .::. ... .::: .:::  ....        .::.  by UTopia v.0.2.0
*   .::::..  .:: .:::  .:::    ..:::..
*      ..:::...   :::  ::.. .::::..
*          ..:::.. ..  ...:::..
*             ..::::..::::.
*                 ..::..
*****************************************************************************/
#ifndef AUTOFUZZ_H
#define AUTOFUZZ_H

#ifndef AUTOFUZZ
#error AUTOFUZZ is not defined. Do not include this header without AUTOFUZZ Definition.
#endif // AUTOFUZZ

#ifndef FUZZ_FILEPATH_PREFIX
#define FUZZ_FILEPATH_PREFIX ""
#endif // FUZZ_FILEPATH_PREFIX

#ifdef __cplusplus
#include <exception>
#include <ostream>
#include <string>

struct AutofuzzException : public std::exception {
  AutofuzzException(const std::string Src) {}
  template <typename T>
  AutofuzzException &operator<<(const T Rhs) { return *this; }
  AutofuzzException &operator<<(std::ostream& (&Src)(std::ostream&)) { return *this; }
};

#undef GTEST_PRED_FORMAT2_
#define THROW_AUTOFUZZ_EXCEPTION(Msg) throw AutofuzzException(Msg)
#define GTEST_PRED_FORMAT2_(pred_format, v1, v2, on_failure) \
  GTEST_ASSERT_(\
    pred_format(#v1, #v2, v1, v2), THROW_AUTOFUZZ_EXCEPTION)

extern "C" {
#endif // __cplusplus
void enterAutofuzz();
#ifdef __cplusplus
}
#endif // __cplusplus
// Redefine access modifier to public
// to access private/protected Testbody or Setup/Teardown
#define private public
#define protected public
#endif // AUTOFUZZ_H
