/*
 * bind_vertex_array.cpp
 *
 *  Created on: 20.10.2013
 *      Author: scn
 */


#include "base_fixture.h"

#include <GL/glew.h>

class bind_vertex_array_test : public base_fixture {};


TEST_F(bind_vertex_array_test, is_reachable) {
  glBindVertexArray(1);
  auto invocation_count = s_stub.function_calls().size();
  ASSERT_EQ(1, invocation_count);

  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.name(), "glBindVertexArray");
}


TEST_F(bind_vertex_array_test, has_correct_params) {
  glBindVertexArray(1);
  auto first_invocation = s_stub.function_calls().front();
  ASSERT_EQ(first_invocation.param("array"), t_arg(1));
}

