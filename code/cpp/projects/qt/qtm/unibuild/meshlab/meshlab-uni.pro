
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs


SUBDIRS = \
  ../xk/external/meshlab/meshlab-common \
  ../xk/external/meshlab/meshlab-core \
  ../xk/external/meshlab/meshlab-console \
  ../xk/external/meshlab/meshlab-mini \
  ../xk/external/meshlab/meshlabplugins-decoratebase \
  ../xk/external/meshlab/meshlabplugins-filter_measure \
  ../xk/external/meshlab/meshlabplugins-filter_meshing \
  ../xk/external/meshlab/meshlabplugins-iobase \
  ../xk/external/meshlab/meshlab-server \



CONFIG += ordered


