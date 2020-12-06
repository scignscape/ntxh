
#           Copyright Nathaniel Christen 2019.
#  Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file LICENSE_1_0.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)


TEMPLATE = subdirs



SUBDIRS = \
  ../xk/external/angelscript/angelscript \
  ../xk/external/angelscript/angelscript-console \
  ../xk/external/angelscript/as-runner \
  ../xk/external/angelscript/as-runner-console \
  ../xk/external/cwl/cwl \
  ../dbk/whitedb/whitedb/whitedb \
  ../dbk/whitedb/whitedb/whitedb-console \
  ../dbk/dgdb/dgdb-white/dgdb-white \
  ../dbk/dgdb/dgdb-white/dgdb-white-console \
  ../dbk/dgdb/dgdb-white/dw-facs-console \
  ../dbk/whitedb/whitedb/wgdb-utility \
  ../dbk/bitgr/BitGraph/bitgraph-console \


CONFIG += ordered

