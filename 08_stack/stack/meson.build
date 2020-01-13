stack_inc_dir = include_directories(['include', get_option('spdlog_include')])
src = ['src/stack.cpp']
stack_lib = static_library('stack',
                           sources: src,
                           include_directories: stack_inc_dir)

doctest_dir = include_directories(get_option('doctest'))

test_src = ['tests/test.cpp']

test_exe = executable('test_exe',
                       sources : [src, test_src],
                       include_directories : [stack_inc_dir, doctest_dir])

test('test1', test_exe)