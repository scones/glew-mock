/*
 * base_fixture.h
 *
 *  Created on: 14.07.2013
 *      Author: scn
 */

#ifndef BASE_FIXTURE_H_
#define BASE_FIXTURE_H_

#include <gtest/gtest.h>

#include "stubber/stubber.h"

struct base_fixture : public ::testing::Test {
  protected:

  base_fixture() : ::testing::Test() {
  }
  virtual ~base_fixture() {
  }

  void SetUp() {
    s_stub.reset();
  }

  void TearDown() {
  }
};

#endif /* BASE_FIXTURE_H_ */

