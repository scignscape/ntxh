
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


SUBDIRS = \
  ../xk/external/gdcm/gdcm-common \
  ../xk/external/gdcm/gdcm-dict \
  ../xk/external/gdcm/gdcm-dsed \
  ../xk/external/gdcm/gdcm-iod \
  ../xk/external/gdcm/gdcm-jpeg8 \
  ../xk/external/gdcm/gdcm-jpeg12 \
  ../xk/external/gdcm/gdcm-jpeg16 \
  ../xk/external/gdcm/gdcm-mexd \
  ../xk/external/gdcm/gdcm-msff \
  ../xk/external/gdcm/gdcm-openjp2 


CONFIG += ordered

