

#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

QT += widgets
QT += network

INCLUDEPATH += $$SRC_DIR $$SRC_GROUP_DIR


include($$ROOT_DIR/../preferred/sysr.pri)
include($$ROOT_DIR/../preferred/gui.pri)



INCLUDEPATH += $$SRC_DIR/sm/c_api

# added "-ser" for the serialization files ...

HEADERS += \
    $$SRC_DIR/common/logger.h \
    $$SRC_DIR/common/status.h \
    $$SRC_DIR/common/thread_pool.h \
    $$SRC_DIR/sm/array/array.h \
    $$SRC_DIR/sm/array_schema/array_schema.h \
    $$SRC_DIR/sm/array_schema/attribute.h \
    $$SRC_DIR/sm/array_schema/dimension.h \
    $$SRC_DIR/sm/array_schema/domain.h \
    $$SRC_DIR/sm/array_schema/tile_domain.h \
    $$SRC_DIR/sm/buffer/buffer.h \
    $$SRC_DIR/sm/buffer/buffer_list.h \
    $$SRC_DIR/sm/buffer/const_buffer.h \
    $$SRC_DIR/sm/buffer/preallocated_buffer.h \
    $$SRC_DIR/sm/c_api/tiledb.h \
    $$SRC_DIR/sm/c_api/tiledb_enum.h \
    $$SRC_DIR/sm/c_api/tiledb_serialization.h \
    $$SRC_DIR/sm/c_api/tiledb_struct_def.h \
    $$SRC_DIR/sm/c_api/tiledb_version.h \
    $$SRC_DIR/sm/cache/buffer_lru_cache.h \
    $$SRC_DIR/sm/cache/lru_cache.h \
    $$SRC_DIR/sm/compressors/bzip_compressor.h \
    $$SRC_DIR/sm/compressors/dd_compressor.h \
    $$SRC_DIR/sm/compressors/gzip_compressor.h \
    $$SRC_DIR/sm/compressors/lz4_compressor.h \
    $$SRC_DIR/sm/compressors/rle_compressor.h \
    $$SRC_DIR/sm/compressors/zstd_compressor.h \
    $$SRC_DIR/sm/config/config.h \
    $$SRC_DIR/sm/config/config_iter.h \
    $$SRC_DIR/sm/cpp_api/array.h \
    $$SRC_DIR/sm/cpp_api/array_schema.h \
    $$SRC_DIR/sm/cpp_api/arrow_io_impl.h \
    $$SRC_DIR/sm/cpp_api/arrowio \
    $$SRC_DIR/sm/cpp_api/attribute.h \
    $$SRC_DIR/sm/cpp_api/config.h \
    $$SRC_DIR/sm/cpp_api/context.h \
    $$SRC_DIR/sm/cpp_api/core_interface.h \
    $$SRC_DIR/sm/cpp_api/deleter.h \
    $$SRC_DIR/sm/cpp_api/dimension.h \
    $$SRC_DIR/sm/cpp_api/domain.h \
    $$SRC_DIR/sm/cpp_api/exception.h \
    $$SRC_DIR/sm/cpp_api/filter.h \
    $$SRC_DIR/sm/cpp_api/filter_list.h \
    $$SRC_DIR/sm/cpp_api/group.h \
    $$SRC_DIR/sm/cpp_api/object.h \
    $$SRC_DIR/sm/cpp_api/object_iter.h \
    $$SRC_DIR/sm/cpp_api/query.h \
    $$SRC_DIR/sm/cpp_api/schema_base.h \
    $$SRC_DIR/sm/cpp_api/stats.h \
    $$SRC_DIR/sm/cpp_api/tiledb \
    $$SRC_DIR/sm/cpp_api/type.h \
    $$SRC_DIR/sm/cpp_api/utils.h \
    $$SRC_DIR/sm/cpp_api/version.h \
    $$SRC_DIR/sm/cpp_api/vfs.h \
    $$SRC_DIR/sm/crypto/crypto.h \
    $$SRC_DIR/sm/crypto/crypto_openssl.h \
    $$SRC_DIR/sm/crypto/crypto_win32.h \
    $$SRC_DIR/sm/crypto/encryption_key.h \
    $$SRC_DIR/sm/crypto/encryption_key_validation.h \
    $$SRC_DIR/sm/enums/array_type.h \
    $$SRC_DIR/sm/enums/compressor.h \
    $$SRC_DIR/sm/enums/datatype.h \
    $$SRC_DIR/sm/enums/encryption_type.h \
    $$SRC_DIR/sm/enums/filesystem.h \
    $$SRC_DIR/sm/enums/filter_option.h \
    $$SRC_DIR/sm/enums/filter_type.h \
    $$SRC_DIR/sm/enums/layout.h \
    $$SRC_DIR/sm/enums/object_type.h \
    $$SRC_DIR/sm/enums/query_status.h \
    $$SRC_DIR/sm/enums/query_type.h \
    $$SRC_DIR/sm/enums/serialization_type.h \
    $$SRC_DIR/sm/enums/vfs_mode.h \
    $$SRC_DIR/sm/enums/walk_order.h \
    $$SRC_DIR/sm/filesystem/azure.h \
    $$SRC_DIR/sm/filesystem/filelock.h \
    $$SRC_DIR/sm/filesystem/gcs.h \
    $$SRC_DIR/sm/filesystem/hdfs_filesystem.h \
    $$SRC_DIR/sm/filesystem/posix.h \
    $$SRC_DIR/sm/filesystem/s3.h \
    $$SRC_DIR/sm/filesystem/s3_thread_pool_executor.h \
    $$SRC_DIR/sm/filesystem/vfs.h \
    $$SRC_DIR/sm/filesystem/vfs_file_handle.h \
    $$SRC_DIR/sm/filesystem/win.h \
    $$SRC_DIR/sm/filter/bit_width_reduction_filter.h \
    $$SRC_DIR/sm/filter/bitshuffle_filter.h \
    $$SRC_DIR/sm/filter/byteshuffle_filter.h \
    $$SRC_DIR/sm/filter/checksum_md5_filter.h \
    $$SRC_DIR/sm/filter/checksum_sha256_filter.h \
    $$SRC_DIR/sm/filter/compression_filter.h \
    $$SRC_DIR/sm/filter/encryption_aes256gcm_filter.h \
    $$SRC_DIR/sm/filter/filter.h \
    $$SRC_DIR/sm/filter/filter_buffer.h \
    $$SRC_DIR/sm/filter/filter_pipeline.h \
    $$SRC_DIR/sm/filter/filter_storage.h \
    $$SRC_DIR/sm/filter/noop_filter.h \
    $$SRC_DIR/sm/filter/positive_delta_filter.h \
    $$SRC_DIR/sm/fragment/fragment_info.h \
    $$SRC_DIR/sm/fragment/fragment_metadata.h \
    $$SRC_DIR/sm/fragment/written_fragment_info.h \
    $$SRC_DIR/sm/global_state/global_state.h \
    $$SRC_DIR/sm/global_state/libcurl_state.h \
    $$SRC_DIR/sm/global_state/openssl_state.h \
    $$SRC_DIR/sm/global_state/signal_handlers.h \
    $$SRC_DIR/sm/global_state/tbb_state.h \
    $$SRC_DIR/sm/global_state/unit_test_config.h \
    $$SRC_DIR/sm/global_state/watchdog.h \
    $$SRC_DIR/sm/metadata/metadata.h \
    $$SRC_DIR/sm/misc/cancelable_tasks.h \
    $$SRC_DIR/sm/misc/comparators.h \
    $$SRC_DIR/sm/misc/constants.h \
    $$SRC_DIR/sm/misc/macros.h \
    $$SRC_DIR/sm/misc/parallel_functions.h \
    $$SRC_DIR/sm/misc/stats_counters.h \
    $$SRC_DIR/sm/misc/tile_overlap.h \
    $$SRC_DIR/sm/misc/types.h \
    $$SRC_DIR/sm/misc/uri.h \
    $$SRC_DIR/sm/misc/utils.h \
    $$SRC_DIR/sm/misc/uuid.h \
    $$SRC_DIR/sm/misc/win_constants.h \
    $$SRC_DIR/sm/query/query.h \
    $$SRC_DIR/sm/query/query_macros.h \
    $$SRC_DIR/sm/query/read_cell_slab_iter.h \
    $$SRC_DIR/sm/query/reader.h \
    $$SRC_DIR/sm/query/result_cell_slab.h \
    $$SRC_DIR/sm/query/result_coords.h \
    $$SRC_DIR/sm/query/result_space_tile.h \
    $$SRC_DIR/sm/query/result_tile.h \
    $$SRC_DIR/sm/query/write_cell_slab_iter.h \
    $$SRC_DIR/sm/query/writer.h \
    $$SRC_DIR/sm/rest/curl.h \
    $$SRC_DIR/sm/rest/rest_client.h \
    $$SRC_DIR/sm/rtree/rtree.h \
    $$SRC_DIR/sm/serialization/array_schema.h \
    $$SRC_DIR/sm/serialization/capnp_utils.h \
    $$SRC_DIR/sm/serialization/query.h \
    $$SRC_DIR/sm/serialization/tiledb-rest.capnp.h \
    $$SRC_DIR/sm/stats/stats.h \
    $$SRC_DIR/sm/storage_manager/consolidator.h \
    $$SRC_DIR/sm/storage_manager/context.h \
    $$SRC_DIR/sm/storage_manager/open_array.h \
    $$SRC_DIR/sm/storage_manager/storage_manager.h \
    $$SRC_DIR/sm/subarray/cell_slab.h \
    $$SRC_DIR/sm/subarray/cell_slab_iter.h \
    $$SRC_DIR/sm/subarray/subarray.h \
    $$SRC_DIR/sm/subarray/subarray_partitioner.h \
    $$SRC_DIR/sm/tile/chunked_buffer.h \
    $$SRC_DIR/sm/tile/generic_tile_io.h \
    $$SRC_DIR/sm/tile/tile.h

SOURCES += \
    $$SRC_DIR/common/logger.cc \
    $$SRC_DIR/common/status.cc \
    $$SRC_DIR/common/thread_pool.cc \
    $$SRC_DIR/sm/array/array.cc \
    $$SRC_DIR/sm/array_schema/array_schema.cc \
    $$SRC_DIR/sm/array_schema/attribute.cc \
    $$SRC_DIR/sm/array_schema/dimension.cc \
    $$SRC_DIR/sm/array_schema/domain.cc \
    $$SRC_DIR/sm/buffer/buffer.cc \
    $$SRC_DIR/sm/buffer/buffer_list.cc \
    $$SRC_DIR/sm/buffer/const_buffer.cc \
    $$SRC_DIR/sm/buffer/preallocated_buffer.cc \
    $$SRC_DIR/sm/c_api/tiledb.cc \
    $$SRC_DIR/sm/cache/buffer_lru_cache.cc \
    $$SRC_DIR/sm/config/config.cc \
    $$SRC_DIR/sm/config/config_iter.cc \
    $$SRC_DIR/sm/crypto/crypto.cc \
    $$SRC_DIR/sm/crypto/encryption_key.cc \
    $$SRC_DIR/sm/crypto/encryption_key_validation.cc \
    $$SRC_DIR/sm/filesystem/azure.cc \
    $$SRC_DIR/sm/filesystem/gcs.cc \
    $$SRC_DIR/sm/filesystem/hdfs_filesystem.cc \
    $$SRC_DIR/sm/filesystem/s3.cc \
    $$SRC_DIR/sm/filesystem/s3_thread_pool_executor.cc \
    $$SRC_DIR/sm/filesystem/vfs.cc \
    $$SRC_DIR/sm/filesystem/vfs_file_handle.cc \
    $$SRC_DIR/sm/filesystem/win.cc \
    $$SRC_DIR/sm/filter/bit_width_reduction_filter.cc \
    $$SRC_DIR/sm/filter/checksum_md5_filter.cc \
    $$SRC_DIR/sm/filter/checksum_sha256_filter.cc \
    $$SRC_DIR/sm/filter/compression_filter.cc \
    $$SRC_DIR/sm/filter/encryption_aes256gcm_filter.cc \
    $$SRC_DIR/sm/filter/filter.cc \
    $$SRC_DIR/sm/filter/filter_buffer.cc \
    $$SRC_DIR/sm/filter/filter_pipeline.cc \
    $$SRC_DIR/sm/filter/filter_storage.cc \
    $$SRC_DIR/sm/filter/noop_filter.cc \
    $$SRC_DIR/sm/filter/positive_delta_filter.cc \
    $$SRC_DIR/sm/fragment/fragment_metadata.cc \
    $$SRC_DIR/sm/global_state/global_state.cc \
    $$SRC_DIR/sm/global_state/libcurl_state.cc \
    $$SRC_DIR/sm/global_state/signal_handlers.cc \
    $$SRC_DIR/sm/global_state/tbb_state.cc \
    $$SRC_DIR/sm/global_state/watchdog.cc \
    $$SRC_DIR/sm/metadata/metadata.cc \
    $$SRC_DIR/sm/misc/cancelable_tasks.cc \
    $$SRC_DIR/sm/misc/constants.cc \
    $$SRC_DIR/sm/misc/uri.cc \
    $$SRC_DIR/sm/misc/utils.cc \
    $$SRC_DIR/sm/misc/uuid.cc \
    $$SRC_DIR/sm/misc/win_constants.cc \
    $$SRC_DIR/sm/misc/work_arounds.cc \
    $$SRC_DIR/sm/query/query.cc \
    $$SRC_DIR/sm/query/read_cell_slab_iter.cc \
    $$SRC_DIR/sm/query/reader.cc \
    $$SRC_DIR/sm/query/result_tile.cc \
    $$SRC_DIR/sm/query/write_cell_slab_iter.cc \
    $$SRC_DIR/sm/query/writer.cc \
    $$SRC_DIR/sm/rest/rest_client.cc \
    $$SRC_DIR/sm/rtree/rtree.cc \
    $$SRC_DIR/sm/serialization/array_schema-ser.cc \
    $$SRC_DIR/sm/serialization/query-ser.cc \
    $$SRC_DIR/sm/stats/stats.cc \
    $$SRC_DIR/sm/storage_manager/consolidator.cc \
    $$SRC_DIR/sm/storage_manager/context.cc \
    $$SRC_DIR/sm/storage_manager/open_array.cc \
    $$SRC_DIR/sm/storage_manager/storage_manager.cc \
    $$SRC_DIR/sm/subarray/cell_slab_iter.cc \
    $$SRC_DIR/sm/subarray/subarray.cc \
    $$SRC_DIR/sm/subarray/subarray_partitioner.cc \
    $$SRC_DIR/sm/tile/chunked_buffer.cc \
    $$SRC_DIR/sm/tile/generic_tile_io.cc \
    $$SRC_DIR/sm/tile/tile.cc

