

PHP_ARG_ENABLE([gtk4],
  [whether to enable gtk4 support],
  [AS_HELP_STRING([--enable-gtk4],
    [Enable gtk4 support])],
  [no])

if test "$PHP_GTK4" != "no"; then
 
  
  
  LIBOTHERLIB_LIBS=`pkg-config --libs gtk+-3.0`
  LIBOTHERLIB_INC=`pkg-config --cflags gtk+-3.0`

  PHP_EVAL_INCLINE($LIBOTHERLIB_INC, EXTRA_LDFLAGS)
  PHP_EVAL_LIBLINE($LIBOTHERLIB_LIBS, CFLAGS)
  AC_DEFINE(HAVE_LIBGTK, 1, [Whether you have gtk4])


  AC_DEFINE(HAVE_GTK4, 1, [ Have gtk4 support ])

  PHP_NEW_EXTENSION(gtk4, gtk4.c \
      src/G/GObject.c \
      src/Atk/AtkPlug.c \
      src/Gtk/Gtk.c \
      src/Gtk/GtkWidget.c \
      src/Gtk/GtkWindow.c, $ext_shared)
fi
