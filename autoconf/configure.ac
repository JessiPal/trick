dnl To generate a new top level configure script from this autoconf directory
dnl 1.  aclocal
dnl 2.  autoconf -o ../configure

AC_INIT([Trick],[16.0])
AC_LANG(C++)

AC_CONFIG_AUX_DIR([autoconf])

AC_DEFUN([AX_LLVM_HOME],[
    AC_ARG_WITH([llvm],
                AS_HELP_STRING([--with-llvm@<:@=DIR@:>@], [LLVM root directory]),
                [LLVM_HOME="$withval"],
                [LLVM_HOME="/usr"]
               )
    AC_SUBST([LLVM_HOME])
])

AC_DEFUN([AX_HDF5_HOME],[
    AC_ARG_WITH([hdf5],
                AS_HELP_STRING([--with-hdf5@<:@=DIR@:>@], [HDF5 root directory]),
                [HDF5_HOME="$withval"
                 AS_IF([test "$HDF5_HOME" = "yes"],
                  AC_CHECK_HEADER(hdf5.h,[HDF5_HOME="/usr"],AC_MSG_ERROR([could not find hdf5.h])),
                  AC_CHECK_FILE([$HDF5_HOME/include/hdf5.h],
                               [],
                               AC_MSG_ERROR([could not find $HDF5_HOME/include/hdf5.h])
                              )
                )],
                [HDF5_HOME=""]
               )
    AC_SUBST([HDF5_HOME])
])

AC_DEFUN([AX_DMTCP_HOME],[
    AC_ARG_WITH([dmtcp],
                AS_HELP_STRING([--with-dmtcp@<:@=DIR@:>@], [DMTCP root directory]),
                [DMTCP_HOME="$withval"
                 AS_IF([test "$DMTCP_HOME" = "yes"],
                  AC_CHECK_HEADER(dmtcpaware.h,[DMTCP_HOME="/usr"],AC_MSG_ERROR([could not find dmtcpaware.h])),
                  AC_CHECK_FILE([$DMTCP_HOME/include/dmtcpaware.h],
                               [],
                               AC_MSG_ERROR([could not find $DMTCP_HOME/include/dmtcpaware.h])
                              )
                )],
                [DMTCP_HOME=""]
               )
    AC_SUBST([DMTCP_HOME])
])

AC_DEFUN([AX_TPRO_HOME],[
    AC_ARG_WITH([tpro],
                AS_HELP_STRING([--with-tpro@<:@=DIR@:>@], [TPRO root directory]),
                [TPROCTE_HOME="$withval"
                 AC_CHECK_FILE([$TPRO_HOME/h/tpro.h],
                               [],
                               AC_MSG_ERROR([could not find $TPRO_HOME/h/tpro.h])
                              )
                ],
                [TPROCTE_HOME=""]
               )
    AC_SUBST([TPROCTE_HOME])
])

AC_DEFUN([AX_BC635_HOME],[
    AC_ARG_WITH([bc635],
                AS_HELP_STRING([--with-bc635@<:@=DIR@:>@], [BC635 root directory]),
                [BC635_HOME="$withval"
                 AC_CHECK_FILE([$BC635_HOME/sample/bcuser.h],
                               [],
                               AC_MSG_ERROR([could not find $BC635_HOME/sample/bcuser.h])
                              )
                ],
                [BC635_HOME=""]
               )
    AC_SUBST([BC635_HOME])
])

AC_DEFUN([AX_GSL_HOME],[
    AC_ARG_WITH([gsl],
                AS_HELP_STRING([--with-gsl@<:@=DIR@:>@], [GSL root directory]),
                [GSL_HOME="$withval"
                 AS_IF([test "$GSL_HOME" = "yes"],
                  AC_CHECK_HEADER(gsl/gsl_rng.h,[GSL_HOME="/usr"],AC_MSG_ERROR([could not find gsl/gsl_rng.h])),
                  AC_CHECK_FILE([$GSL_HOME/include/gsl],
                               [],
                               AC_MSG_ERROR([could not find $GSL_HOME/include/gsl])
                              )
                )],
                [GSL_HOME=""]
               )
    AC_SUBST([GSL_HOME])
])

AC_DEFUN([AX_GTEST_HOME],[
    AC_ARG_WITH([gtest],
                AS_HELP_STRING([--with-gtest@<:@=DIR@:>@], [GTEST root directory]),
                [GTEST_HOME="$withval"
                 AC_CHECK_FILE([$GTEST_HOME/include/gtest],
                               [],
                               AC_MSG_ERROR([could not find $GTEST_HOME/sample/bcuser.h])
                              )
                ],
                [GTEST_HOME=""]
               )
    AC_SUBST([GTEST_HOME])
])

dnl test if we want to use er7_utils, default to yes
AC_DEFUN([AX_ER7_UTILS],[
    AC_ARG_ENABLE([er7utils],
                  AS_HELP_STRING([--enable-er7utils], [use er7_utils (default is yes)]),
                  AS_IF([test "x$enable_er7utils" = xyes], [USE_ER7_UTILS="1"], [USE_ER7_UTILS="0"]),
                  [USE_ER7_UTILS="1"]
                 )
    AC_SUBST([USE_ER7_UTILS])
])

dnl if fermi-ware directory exists, test for motif.
AC_DEFUN([AX_JSC_DIRS],[
    AC_CHECK_FILE([trick_source/data_products/fermi-ware],
      [
       AC_CHECK_HEADER(Xm/Xm.h, [MOTIF_HOME="/usr"],
        AC_CHECK_FILE(/usr/local/include/Xm/Xm.h, [MOTIF_HOME="/usr/local"],
         AC_CHECK_FILE(/sw/include/Xm/Xm.h, [MOTIF_HOME="/sw"],AC_MSG_ERROR([could not find Xm/Xm.h]))))
      ],
      [
       MOTIF_HOME=""
      ]
    )
    AC_SUBST([MOTIF_HOME])
])

dnl add extra paths to find xml headers and X headers on the mac.
XTRAINCPATHS="-I/usr/include/libxml2/ -I/usr/X11/include"
CFLAGS="$CFLAGS $XTRAINCPATHS"
CPPFLAGS="$CPPFLAGS $XTRAINCPATHS"

dnl look for programs we need to compile and run
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LEX
AS_IF([test "x$LEX" = "x:"],AC_MSG_ERROR([could not find flex]),[])
AC_PATH_PROG(BISON, bison, nobison)
AS_IF([test "$ac_cv_path_BISON" = "nobison"],AC_MSG_ERROR([could not find bison]),[])
AC_PATH_PROG(PERL, perl, noperl)
AS_IF([test "$ac_cv_path_PERL" = "noperl"],AC_MSG_ERROR([could not find perl]),[])
AC_PATH_PROG(PYTHON, python, nopython)
AS_IF([test "$ac_cv_path_PYTHON" = "nopython"],AC_MSG_ERROR([could not find python]),[])
AC_PATH_PROG(SWIG, swig, noswig, "/bin:/usr/bin:/usr/local/bin:/sw/bin")
AS_IF([test "$ac_cv_path_SWIG" = "noswig"],AC_MSG_ERROR([could not find swig]),[])
AC_PATH_PROG(GNUPLOT, gnuplot, nognuplot)
AS_IF([test "$ac_cv_path_GNUPLOT" = "nognuplot"],AC_MSG_NOTICE([could not find gnuplot]),[])
AX_PROG_JAVA_CC(javac)

dnl look for libraries and headers we need to compile
AC_PATH_X
AS_IF([test "$no_x" = "yes"],AC_MSG_ERROR([could not find Xwindows development libraries and/or headers]),[])
AC_CHECK_HEADER([X11/Intrinsic.h],[],AC_MSG_ERROR([could not find libxt development headers]))
AX_JSC_DIRS([])
AC_CHECK_LIB(xml2, main,
    [LIBXML=-lxml2
     AC_SUBST([LIBXML])]
)
AC_CHECK_HEADER([libxml/tree.h],[],AC_MSG_ERROR([could not find libxml development headers]))
AX_PTHREAD()
AX_PYTHON_DEVEL([>='2.5'])
AX_PROG_PERL_MODULES( Text::Balanced ,[],AC_MSG_ERROR([could not find perl modules Text::Balanced]))
AX_PROG_PERL_MODULES( Digest::MD5,[],AC_MSG_ERROR([could not find perl module Digest::MD5]))

dnl process the optional --with-llvm command line arguments
AX_LLVM_HOME([])
AC_PATH_PROG(LLVM_CONFIG, llvm-config, no-llvm-config, "$LLVM_HOME/bin:/bin:/usr/bin:/usr/local/bin:/sw/bin")
AS_IF([test "$ac_cv_path_LLVM_CONFIG" = "no-llvm-config"],AC_MSG_ERROR([could not find clang]),[])
LLVM_LIB_DIR=`$LLVM_CONFIG --libdir`
LLVM_BIN_DIR=`$LLVM_CONFIG --bindir`
AC_CHECK_FILE([$LLVM_LIB_DIR/libLLVMSupport.a],
  [],
  AC_MSG_ERROR([could not find clang library files in $LLVM_LIB_DIR])
)
AC_PATH_PROG(CLANG, clang, noclang, "$LLVM_BIN_DIR:$LLVM_HOME/bin:/bin:/usr/bin:/usr/local/bin:/sw/bin")
AS_IF([test "$ac_cv_path_CLANG" = "noclang"],AC_MSG_ERROR([could not find clang]),[])

dnl process the other optional command line arguments
AX_HDF5_HOME([])
AX_DMTCP_HOME([])
AX_TPRO_HOME([])
AX_BC635_HOME([])
AX_GSL_HOME([])
AX_GTEST_HOME([])
AX_ER7_UTILS([])

AC_OUTPUT([share/trick/makefiles/config_user.mk])

