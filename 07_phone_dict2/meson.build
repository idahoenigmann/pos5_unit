project('06_phone_dict',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

add_global_arguments('-DBACKWARD_HAS_BFD=1', language: 'cpp')

inc_dir = include_directories(['include', get_option('resources')])
src = ['src/main.cpp', 'src/sll.cpp', 'src/backward.cpp', 'src/Dictionary.cpp']

cc = meson.get_compiler('cpp')
lib_bfd = cc.find_library('bfd', dirs: ['/usr/lib/libbfd'])

executable('phone',
           sources : src,
           include_directories : inc_dir,
           dependencies: lib_bfd)

test_src = ['test/test.cpp', 'src/sll.cpp']

test_exe = executable('test_exe',
                       sources : test_src,
                       include_directories : [inc_dir, get_option('doctest')])

test('test1', test_exe)
