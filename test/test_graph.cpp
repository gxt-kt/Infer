//
// Created by fss on 22-12-14.
//
#include <glog/logging.h>
#include <gtest/gtest.h>

// #include "data/load_data.hpp"
#include <armadillo>

#include "runtime/runtime_ir.hpp"

// 测试tensor库是否正常使用

TEST(test_model, read_graph_file) {
  using namespace kuiper_infer;

  const std::string& param_path = "tmp/test.pnnx.param";
  const std::string& weight_path = "tmp/test.pnnx.bin";
  RuntimeGraph graph(param_path, weight_path);
  graph.Build("pnnx_input_0", "pnnx_output_0");
}
