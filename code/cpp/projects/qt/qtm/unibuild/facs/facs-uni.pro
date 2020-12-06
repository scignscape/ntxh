
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


SUBDIRS = \
  ../xk/facs/cytoLib/qcytolib \
  ../xk/facs/facs-gui/facs-bridge \
  ../xk/facs/facs-gui/facs-bridge-console \
  ../xk/facs/facs-gui/facs-bridge-hgdm \
  ../xk/facs/facs-gui/facs-bridge-hgdm-console \
  ../xk/facs/facs-gui/facs-gui \


# exclude these for now ...
#../xk/facs/cytoLib/cytolib \
#../xk/facs/cytoLib/cytolib-console \



CONFIG += ordered

