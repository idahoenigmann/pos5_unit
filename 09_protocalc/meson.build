project('09_protocalc',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

subdir('stack')

inc_dir = include_directories(['include', get_option('resources')])
src = ['src/main.cpp']

executable('calc',
           sources : src,
           include_directories : [inc_dir, stack_inc_dir],
           link_with: stack_lib)