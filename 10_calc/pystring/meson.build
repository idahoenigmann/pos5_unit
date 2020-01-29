pystring_inc_dir = include_directories(['.'])
src = ['pystring.cpp']
pystring_lib = static_library('pystring',
                           sources: src,
                           include_directories: pystring_inc_dir)

doctest_dir = include_directories(get_option('doctest'))