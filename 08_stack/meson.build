project('08_stack',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

subdir('stack')

cc = meson.get_compiler('cpp')

lib_fmt = cc.find_library('fmt', dirs:[get_option('fmt_lib')])
lib_spdlog = cc.find_library('libspdlog', dirs:[get_option('spdlog_lib')])
inc_dir = include_directories(['include', get_option('resources'), get_option('spdlog_include')])
src = ['src/main.cpp']

executable('go',
           sources : src,
           include_directories : [inc_dir, stack_inc_dir],
           dependencies: [lib_fmt, lib_spdlog],
           link_with: stack_lib)
