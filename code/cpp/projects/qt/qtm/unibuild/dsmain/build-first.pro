
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


UNI_BUILD_CODE = first


SUBDIRS = \
  ./build-first/ntxh  \
  ./build-first/ntxh-parser  \
  ./build-first/ngml-sdi  \
  ./build-first/dgh-sdi  \
  ./build-first/qring  \
  ./build-first/qh-package  \
  ./build-first/dsmain  \
  ./build-first/ScignStage-ling  \
  ./build-first/application-model  \
  ./build-first/_run__dsmain-console


CONFIG += ordered
