/*
 * create_program.cpp
 *
 *  Created on: 05.10.2013
 *      Author: scn
 */

#include "base_fixture.h"

#include <GL/glew.h>

class create_program_test : public base_fixture {
  protected:

  int m_result;
  void SetUp() {
    base_fixture::SetUp();
    m_result = 7;
    s_stub.register_function_result("glCreateProgram", m_result);
  }
};


TEST_F(create_program_test, is_reachable) {
  glCreateProgram();
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glCreateProgram");
}


TEST_F(create_program_test, returns_correctly) {
  ASSERT_EQ(m_result, glCreateProgram());
}

