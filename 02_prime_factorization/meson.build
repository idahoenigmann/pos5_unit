project('01_gcd',
        'cpp',
        version: '0.0.1',
        meson_version: '>0.46',
        default_options : ['cpp_std=c++2a', 'warning_level=3', 'werror=true'])

doctest_dir = include_directories('lib/doctest')
inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/primes.cpp']

executable('primes',
           sources : src,
           include_directories : inc_dir)

test_src = ['test/primes_test.cpp', 'src/primes.cpp']

test_exe = executable('test_exe',
                       sources : test_src,
                       include_directories : [inc_dir, doctest_dir])

test('test1', test_exe)
