AC_PREREQ([2.69])
AC_INIT([demo_ra1nsn0w_plugin], m4_esyscmd([git rev-list --count HEAD | tr -d '\n']), [tihmstar@gmail.com])

AC_CANONICAL_SYSTEM
AC_CANONICAL_HOST
AM_PROG_LIBTOOL

AM_INIT_AUTOMAKE([subdir-objects])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

AC_DEFINE([VERSION_COMMIT_COUNT], "m4_esyscmd([git rev-list --count HEAD | tr -d '\n'])", [Git commit count])
AC_DEFINE([VERSION_COMMIT_SHA], "m4_esyscmd([git rev-parse HEAD | tr -d '\n'])", [Git commit sha])
AC_SUBST([VERSION_COMMIT_COUNT], ["m4_esyscmd([git rev-list --count HEAD | tr -d '\n'])"])
AC_SUBST([VERSION_COMMIT_SHA], ["m4_esyscmd([git rev-parse HEAD | tr -d '\n'])"])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Check for operating system
AC_MSG_CHECKING([whether we need platform-specific build settings])
case $host_os in
  darwin* )
        AC_MSG_RESULT([${host_os}])
        CXXFLAGS+=" -stdlib=libc++ "
        ;;
  *mingw32*|*cygwin*|*msys*)
        AC_MSG_RESULT([${host_os}])
        win32=true
        LDFLAGS+=" -no-undefined -lws2_32"
        ;;
esac


CXXFLAGS+=" -std=c++11 -O3"
CFLAGS+=" -std=c11"

# Checks for libraries.
LIBGENERAL_REQUIRES_STR="libgeneral >= 75"
LIBINSN_REQUIRES_STR="libinsn >= 49"
LIBPATCHFINDER_REQUIRES_STR="libpatchfinder >= 153"
LIBRA1NSN0W_REQUIRES_STR="libra1nsn0w >= 37"
PKG_CHECK_MODULES(libgeneral, $LIBGENERAL_REQUIRES_STR)
PKG_CHECK_MODULES(libinsn, $LIBINSN_REQUIRES_STR)
PKG_CHECK_MODULES(libpatchfinder, $LIBPATCHFINDER_REQUIRES_STR)
PKG_CHECK_MODULES(libra1nsn0w, $LIBRA1NSN0W_REQUIRES_STR)

AC_ARG_ENABLE([debug],
            [AS_HELP_STRING([--enable-debug],
            [enable debug build(default is no)])],
            [debug_build=true],
            [debug_build=false])

if test "$debug_build" = true; then
  echo "*** Note: debug build requested ***"
  CFLAGS+=" -g -O0 -DDEBUG=1"
  CXXFLAGS+=" -g -O0 -DDEBUG=1"
fi

LT_INIT

AC_CONFIG_FILES([Makefile
                demo_ra1nsn0w_plugin/Makefile])
AC_OUTPUT

echo "
Configuration for $PACKAGE-$VERSION:
-------------------------------------------

  install prefix ..........: $prefix
  debug build  ............: $debug_build"
echo "  compiler ................: ${CC}

  Now type 'make' to build $PACKAGE-$VERSION,
  and then 'make install' for installation.
"
