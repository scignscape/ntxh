
#           Copyright Nathaniel Christen 2020.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


message(current UNI_BUILD_CODE: $$UNI_BUILD_CODE)


isEmpty(UNI_BUILD_CODE) {
  UNI_BUILD_CODE = nomark
}

BUILD_DIR_CODE = uni-$$UNI_BUILD_CODE

message(BUILD_DIR_CODE: $$BUILD_DIR_CODE)



CHOICE_CODE = $$BUILD_DIR_CODE-choices

WHICH_BUILD_DIR_CODE = $$BUILD_DIR_CODE

UNIBUILD_TARGET_DIR = uni

include(../_choices/$${WHICH_BUILD_DIR_CODE}_choices.pri)

include(../build-root-both.pri)

