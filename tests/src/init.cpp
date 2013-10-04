/*
 * init.cpp
 *
 *  Created on: 24.08.2013
 *      Author: scn
 */


#include <GL/glew.h>

#include "base_fixture.h"

class init_test : public base_fixture {
  protected:

  int m_result;
  void SetUp() {
    base_fixture::SetUp();
    m_result = 5;
    s_stub.register_function_result("glewInit", m_result);
  }

  int call() {
    return glewInit();
  }
};


TEST_F(init_test, is_reachable) {
  call();
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glewInit");
}


TEST_F(init_test, returns_correctly) {
  ASSERT_EQ(m_result, call());
}

