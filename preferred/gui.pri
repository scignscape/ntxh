
# this was a setup I needed on a machine to run Qt GUIs without installing 
# anything non-manually; this should pair with developing via a sysroot.
# Of course the details for another system will be different, but maybe 
# this helps as an outline.  Of course, it is much simpler to install 
# everything via apt-get or another package manager -- but maybe 
# you want to control what actually gets installed more precisely ... 


LIBS += -L/home/.../gl/xcb/lib/x86_64-linux-gnu -lGL

LIBS += /home/.../xcb/libxcb-dri3.so.0.0
LIBS += /home/.../xcb/lib/libexpat.so.1


LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libX11-xcb.so.1
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXdamage.so.1
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXfixes.so.3
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libX11.so.6

LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxcb-glx.so.0
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxcb-dri2.so.0
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxcb-present.so.0
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxcb-sync.so.1
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxshmfence.so.1.0.0

LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXext.so.6
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libglapi.so.0
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libxcb.so.1

LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libdrm.so.2
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXxf86vm.so.1
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXau.so.6
LIBS += /home/.../gl/xcb/lib/x86_64-linux-gnu/libXdmcp.so.6

