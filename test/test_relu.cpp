//
// Created by fss on 22-12-20.
//
#include <glog/logging.h>
#include <gtest/gtest.h>

#include "layer/abstract/layer_factory.hpp"
#include "layer/details/relu.hpp"

// 有了注册机制后的框架是如何init layer
TEST(test_layer, forward_relu2) {
  using namespace kuiper_infer;
  float thresh = 0.f;
  std::shared_ptr<RuntimeOperator> tmp = std::make_shared<RuntimeOperator>();
  tmp->type = "nn.ReLU";
  std::shared_ptr<Layer> relu_layer = LayerRegisterer::CreateLayer(tmp);

  std::shared_ptr<Tensor<float>> input =
      std::make_shared<Tensor<float>>(1, 1, 3);
  input->index(0) = -1.f;
  input->index(1) = -2.f;
  input->index(2) = 3.f;
  std::vector<std::shared_ptr<Tensor<float>>> inputs;
  std::vector<std::shared_ptr<Tensor<float>>> outputs;
  inputs.push_back(input);
  outputs.resize(inputs.size());
  relu_layer->Forward(inputs, outputs);
  for (int i = 0; i < outputs.size(); ++i) {
    outputs.at(i)->Show();
    ASSERT_EQ(outputs.at(i)->index(0), 0.f);
    ASSERT_EQ(outputs.at(i)->index(1), 0.f);
    ASSERT_EQ(outputs.at(i)->index(2), 3.f);
  }
}