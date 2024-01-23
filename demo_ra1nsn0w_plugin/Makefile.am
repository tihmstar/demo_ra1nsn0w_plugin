AM_CFLAGS = $(libgeneral_CFLAGS) $(libinsn_CFLAGS) $(libpatchfinder_CFLAGS) $(libra1nsn0w_CFLAGS)
AM_CXXFLAGS = $(AM_CFLAGS)
AM_LDFLAGS = $(libgeneral_LIBS) $(libinsn_LIBS) $(libpatchfinder_LIBS) $(libra1nsn0w_LIBS)

lib_LTLIBRARIES = libdemo_ra1nsn0w_plugin.la

libdemo_ra1nsn0w_plugin_la_CPPFLAGS = $(AM_CFLAGS)
libdemo_ra1nsn0w_plugin_la_LIBADD = $(AM_LDFLAGS)
libdemo_ra1nsn0w_plugin_la_SOURCES =    DemoKPF.cpp \
                                        DemoObj.cpp \
                                        plugin.cpp