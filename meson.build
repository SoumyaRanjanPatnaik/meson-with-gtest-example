project('binary_search', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

source_dir = 'src'
lib_dir = 'lib'
test_dir = 'test'

gtest = dependency('gtest')

libbsearch = library('bsearch', lib_dir / 'binary_search.cpp')
exe = executable(
  'main', 
  source_dir / 'main.cpp', 
  include_directories: lib_dir, 
  link_with: libbsearch
)
Test = executable(
  'Test', 
  test_dir / 'main.cpp', 
  dependencies: [gtest], 
  include_directories: lib_dir, 
  link_with: libbsearch
)

test('gtest', Test)
