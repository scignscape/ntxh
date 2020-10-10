
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>


/**
 * @file   quickstart_sparse.cc
 *
 * @section LICENSE
 *
 * The MIT License
 *
 * @copyright Copyright (c) 2018-2020 TileDB, Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * @section DESCRIPTION
 *
 * When run, this program will create a simple 2D sparse array, write some data
 * to it, and read a slice of the data back.
 */

#include <iostream>

#define TILEDB_EXPORT
#define TILEDB_DEPRECATED

#include "tiledb/sm/cpp_api/context.h"
#include "tiledb/sm/cpp_api/deleter.h"
#include "tiledb/sm/cpp_api/filter_list.h"
#include "tiledb/sm/cpp_api/domain.h"
#include "tiledb/sm/cpp_api/dimension.h"
#include "tiledb/sm/cpp_api/array_schema.h"
#include "tiledb/sm/cpp_api/array.h"
#include "tiledb/sm/cpp_api/query.h"



//?#include "tiledb/tiledb.h"

//?using namespace tiledb;

// Name of array.
std::string array_name("quickstart_sparse_array");

void create_array() {
  // Create a TileDB context.
  tiledb::Context ctx;

  // The array will be 4x4 with dimensions "rows" and "cols", with domain [1,4].
  tiledb::Domain domain(ctx);
  domain.add_dimension(tiledb::Dimension::create<int>(ctx, "rows", {{1, 4}}, 4))
      .add_dimension(tiledb::Dimension::create<int>(ctx, "cols", {{1, 4}}, 4));

  // The array will be sparse.
  tiledb::ArraySchema schema(ctx, TILEDB_SPARSE);
  schema.set_domain(domain).set_order({{TILEDB_ROW_MAJOR, TILEDB_ROW_MAJOR}});

  // Add a single attribute "a" so each (i,j) cell can store an integer.
  schema.add_attribute(tiledb::Attribute::create<int>(ctx, "a"));

  // Create the (empty) array on disk.
  tiledb::Array::create(array_name, schema);
}

void write_array() {
  tiledb::Context ctx;

  // Write some simple data to cells (1, 1), (2, 4) and (2, 3).
  std::vector<int> coords_rows = {1, 2, 2};
  std::vector<int> coords_cols = {1, 4, 3};
  std::vector<int> data = {1, 2, 3};

  // Open the array for writing and create the query.
  tiledb::Array array(ctx, array_name, TILEDB_WRITE);
  tiledb::Query query(ctx, array, TILEDB_WRITE);
  query.set_layout(TILEDB_UNORDERED)
      .set_buffer("a", data)
      .set_buffer("rows", coords_rows)
      .set_buffer("cols", coords_cols);

  // Perform the write and close the array.
  query.submit();
  array.close();
}

void read_array() {
  tiledb::Context ctx;

  // Prepare the array for reading
  tiledb::Array array(ctx, array_name, TILEDB_READ);

  // Slice only rows 1, 2 and cols 2, 3, 4
  const std::vector<int> subarray = {1, 2, 2, 4};

  // Prepare the vector that will hold the result.
  // We take an upper bound on the result size, as we do not
  // know a priori how big it is (since the array is sparse)
  std::vector<int> data(3);
  std::vector<int> coords_rows(3);
  std::vector<int> coords_cols(3);

  // Prepare the query
  tiledb::Query query(ctx, array, TILEDB_READ);
  query.set_subarray(subarray)
      .set_layout(TILEDB_ROW_MAJOR)
      .set_buffer("a", data)
      .set_buffer("rows", coords_rows)
      .set_buffer("cols", coords_cols);

  // Submit the query and close the array.
  query.submit();
  array.close();

  // Print out the results.
  auto result_num = (int)query.result_buffer_elements()["a"].second;
  for (int r = 0; r < result_num; r++) {
    int i = coords_rows[r];
    int j = coords_cols[r];
    int a = data[r];
    std::cout << "Cell (" << i << ", " << j << ") has data " << a << "\n";
  }
}

int main() {
  tiledb::Context ctx;

  std::cout << "array ...";

  if (tiledb::Object::object(ctx, array_name).type() != tiledb::Object::Type::Array) {
    std::cout << "create array ...";
    create_array();
    std::cout << "write array ...";
    write_array();
  }

  std::cout << "read array ...";
  read_array();
  return 0;
}


//int main(int argc, char* argv[])
//{
// qDebug() << "OK";
// return 0;
//}

