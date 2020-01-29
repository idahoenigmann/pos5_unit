project('09_protocalc',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

subdir('pystring')
subdir('repl')

inc_dir = include_directories(['include', get_option('resources'), get_option('magic_enum')])
src = ['src/main.cpp']

executable('calc',
           sources : src,
           include_directories : [inc_dir, pystring_inc_dir, repl_inc_dir],
           link_with: [pystring_lib, repl_lib])