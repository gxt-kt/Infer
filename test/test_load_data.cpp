//
// Created by fss on 22-12-19.
//

#include "data/load_data.hpp"
#include "data/tensor.hpp"
#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(test_data_load, load_csv) {
  using namespace kuiper_infer;

  const std::string &file_path = "./tmp/data1.csv";
  auto data = CSVDataLoader::LoadData(file_path, ',');

  uint32_t index = 1;
  uint32_t rows = data.n_rows;
  uint32_t cols = data.n_cols;
  ASSERT_EQ(rows, 3);
  ASSERT_EQ(cols, 6);
  LOG(INFO) << "\n" << data;
  for (uint32_t r = 0; r < rows; ++r) {
    for (uint32_t c = 0; c < cols; ++c) {
      ASSERT_EQ(data.at(r, c), index);
      index += 1;
    }
  }
}
