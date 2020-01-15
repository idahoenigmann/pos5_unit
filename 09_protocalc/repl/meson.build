repl_inc_dir = include_directories(['include', get_option('magic_enum'), '../stack/include'])
src = ['src/repl.cpp']

repl_lib = shared_library('repl',
                           sources: src,
                           include_directories: repl_inc_dir,
                           link_with: [stack_lib])
