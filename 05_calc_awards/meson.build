project('05_calc_awards',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

cc = meson.get_compiler('cpp')

inc_dir = include_directories(['include', get_option('resources')])
lib_fmt = cc.find_library('fmt', dirs:[get_option('fmt_lib')])
src = ['src/main.cpp', 'src/file_utilities.cpp', 'src/string_utilities.cpp', 'src/csv_utilities.cpp', 'src/calc_awards.cpp']

executable('awards',
           sources : src,
           include_directories : inc_dir,
           dependencies: lib_fmt)
