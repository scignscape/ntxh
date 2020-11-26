
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

include(../build-group.pri)

include($$ROOT_DIR/../preferred/sysr.pri)

CONFIG += staticlib


INCLUDEPATH += $$SRC_GROUP_DIR  \
  $$SRC_GROUP_DIR/configs \
  $$SRC_GROUP_DIR/configs/vcl \
  $$SRC_GROUP_DIR/configs/core \


INCLUDEPATH += \
  $$SRC_GROUP_DIR/vxl-vcl/vcl \
  $$SRC_GROUP_DIR/vxl-v3p/v3p/netlib \
  $$SRC_GROUP_DIR/vxl-v3p/v3p/netlib/linalg \
  $$SRC_GROUP_DIR/vxl-core/ \


HEADERS += \


SOURCES += \
  $$SRC_DIR/Templates/vnl_c_na_vector+double-.cxx \
  $$SRC_DIR/Templates/vnl_c_na_vector+float-.cxx \
  $$SRC_DIR/Templates/vnl_complex_ops+double-.cxx \
  $$SRC_DIR/Templates/vnl_complex_ops+float-.cxx \
  $$SRC_DIR/Templates/vnl_complex_ops+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+char-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+double-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+double_complex-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+float-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+float_complex-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+int-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+long-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+long_double_complex-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+longlong-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+schar-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+sshort-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+uchar-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+uint-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+ulong-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+ulonglong-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+ushort-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_c_vector+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_det+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_det+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_det+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_det+double-.cxx \
  $$SRC_DIR/Templates/vnl_det+float-.cxx \
  $$SRC_DIR/Templates/vnl_det+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_det+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_det+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+double-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix_fixed+complex_double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix_fixed+complex_float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix_fixed+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix_fixed+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+float-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+int-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_diag_matrix+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_file_matrix+double-.cxx \
  $$SRC_DIR/Templates/vnl_file_matrix+float-.cxx \
  $$SRC_DIR/Templates/vnl_file_matrix+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_file_matrix+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_file_vector+double-.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+double-.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy_fixed+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy_fixed+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+float-.cxx \
  $$SRC_DIR/Templates/vnl_fortran_copy+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_hungarian_algorithm+double-.cxx \
  $$SRC_DIR/Templates/vnl_hungarian_algorithm+int-.cxx \
  $$SRC_DIR/Templates/vnl_identity+int-.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_matrix+complex+double---.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_matrix+double--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_matrix+float--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_vector+complex+double---.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_vector+double--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print2+vnl_vector+float--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+double-.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+float-.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+int-.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_matlab_print+uint-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+char-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_matrix+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_matrix+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_matrix+double-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_exp+vnl_matrix+double--.cxx \
  $$SRC_DIR/Templates/vnl_matrix_exp+vnl_matrix_fixed+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+complex_double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+complex_float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+int.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed_ref+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed_ref+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+vnl_bignum.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_fixed+vnl_rational.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+float-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+int-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+long-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+longlong-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_ref+double-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_ref+float-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_ref+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_matrix_ref+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+schar-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+sshort-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+uchar-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+uint-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+ulong-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+ulonglong-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+ushort-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_matrix+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_polynomial+double-.cxx \
  $$SRC_DIR/Templates/vnl_polynomial+long-.cxx \
  $$SRC_DIR/Templates/vnl_polynomial+vnl_decnum-.cxx \
  $$SRC_DIR/Templates/vnl_polynomial+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_quaternion+double-.cxx \
  $$SRC_DIR/Templates/vnl_quaternion+float-.cxx \
  $$SRC_DIR/Templates/vnl_quaternion+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_rank+double-.cxx \
  $$SRC_DIR/Templates/vnl_rank+int-.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+double-.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+float-.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+int-.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_sparse_matrix+vnl_rational-.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+double-.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+float-.cxx \
  $$SRC_DIR/Templates/vnl_sym_matrix+int-.cxx \
  $$SRC_DIR/Templates/vnl_unary_function+double.vnl_vector+double--.cxx \
  $$SRC_DIR/Templates/vnl_unary_function+int.int-.cxx \
  $$SRC_DIR/Templates/vnl_vector+char-.cxx \
  $$SRC_DIR/Templates/vnl_vector+complex+double--.cxx \
  $$SRC_DIR/Templates/vnl_vector+complex+float--.cxx \
  $$SRC_DIR/Templates/vnl_vector+complex+long_double--.cxx \
  $$SRC_DIR/Templates/vnl_vector+double-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+complex_double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+complex_float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+int.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed_ref+double.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed_ref+float.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+slonglong.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+sshort.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+uchar.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+uint.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+ulonglong.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+ushort.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+vnl_bignum.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector_fixed+vnl_rational.allsizes-.cxx \
  $$SRC_DIR/Templates/vnl_vector+float-.cxx \
  $$SRC_DIR/Templates/vnl_vector+int-.cxx \
  $$SRC_DIR/Templates/vnl_vector+long-.cxx \
  $$SRC_DIR/Templates/vnl_vector+long_double-.cxx \
  $$SRC_DIR/Templates/vnl_vector+longlong-.cxx \
  $$SRC_DIR/Templates/vnl_vector_ref+alltypes.cxx \
  $$SRC_DIR/Templates/vnl_vector+schar-.cxx \
  $$SRC_DIR/Templates/vnl_vector+sshort-.cxx \
  $$SRC_DIR/Templates/vnl_vector+uchar-.cxx \
  $$SRC_DIR/Templates/vnl_vector+uint-.cxx \
  $$SRC_DIR/Templates/vnl_vector+ulong-.cxx \
  $$SRC_DIR/Templates/vnl_vector+ulonglong-.cxx \
  $$SRC_DIR/Templates/vnl_vector+ushort-.cxx \
  $$SRC_DIR/Templates/vnl_vector+vnl_bignum-.cxx \
  $$SRC_DIR/Templates/vnl_vector+vnl_rational-.cxx \
  $$SRC_DIR/algo/Templates/vnl_adjugate+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_adjugate+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_adjugate+int-.cxx \
  $$SRC_DIR/algo/Templates/vnl_chi_squared+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_chi_squared+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_chi_squared+int-.cxx \
  $$SRC_DIR/algo/Templates/vnl_convolve+double.double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_convolve+float.float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_convolve+int.double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_convolve+int.float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_convolve+int.int-.cxx \
  $$SRC_DIR/algo/Templates/vnl_determinant+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_determinant+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_determinant+int-.cxx \
  $$SRC_DIR/algo/Templates/vnl_determinant+vcl_complex+double--.cxx \
  $$SRC_DIR/algo/Templates/vnl_determinant+vcl_complex+float--.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_1d+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_1d+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_2d+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_2d+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_base+double.allsizes-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_base+float.allsizes-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_prime_factors+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_fft_prime_factors+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_matrix_inverse+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_matrix_inverse+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_orthogonal_complement+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_orthogonal_complement+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_orthogonal_complement+vcl_complex+double--.cxx \
  $$SRC_DIR/algo/Templates/vnl_orthogonal_complement+vcl_complex+float--.cxx \
  $$SRC_DIR/algo/Templates/vnl_qr+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_qr+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_qr+vcl_complex+double--.cxx \
  $$SRC_DIR/algo/Templates/vnl_qr+vcl_complex+float--.cxx \
  $$SRC_DIR/algo/Templates/vnl_scatter_3x3+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_scatter_3x3+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_economy+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_economy+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_economy+vcl_complex+double--.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_economy+vcl_complex+float--.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_fixed+double.allsizes-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd_fixed+float.allsizes-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd+float-.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd+vcl_complex+double--.cxx \
  $$SRC_DIR/algo/Templates/vnl_svd+vcl_complex+float--.cxx \
  $$SRC_DIR/algo/Templates/vnl_symmetric_eigensystem+double-.cxx \
  $$SRC_DIR/algo/Templates/vnl_symmetric_eigensystem+float-.cxx \


