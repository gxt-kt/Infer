//
// Created by fss on 22-11-17.
//

#ifndef KUIPER_INFER_SOURCE_LAYER_LAYER_FACTORY_HPP_
#define KUIPER_INFER_SOURCE_LAYER_LAYER_FACTORY_HPP_
#include <map>
#include <memory>
#include <string>

#include "layer.hpp"
#include "runtime/runtime_op.hpp"

namespace kuiper_infer {

// 注册类，用来注册所有的层
class LayerRegisterer {
 public:
  // 函数指针类型，创建层的函数
  using Creator =
      ParseParameterAttrStatus (*)(const std::shared_ptr<RuntimeOperator> &op,
                                   std::shared_ptr<Layer> &layer);

  // 存储的key是层的类型，value是这个层对应的创建函数
  // 注册的好处是在so中就注册好了层，后面实际创建层的时候很方便，直接根据key就可以拿到创建的函数
  typedef std::map<std::string, Creator> CreateRegistry;

  // 实际需要调用的注册函数，输入就是map对应的key和value
  static void RegisterCreator(const std::string &layer_type,
                              const Creator &creator);

  // 用来读取map，输入和输出就是map对应的key和value
  static std::shared_ptr<Layer> CreateLayer(
      const std::shared_ptr<RuntimeOperator> &op);

  // 返回单例的map
  static CreateRegistry &Registry();
};

// 给外部调用的接口，实际将函数RegisterCreator包装了一层
class LayerRegistererWrapper {
 public:
  LayerRegistererWrapper(const std::string &layer_type,
                         const LayerRegisterer::Creator &creator) {
    LayerRegisterer::RegisterCreator(layer_type, creator);
  }
};

}  // namespace kuiper_infer

#endif  // KUIPER_INFER_SOURCE_LAYER_LAYER_FACTORY_HPP_
