project('YourProject', 'cpp', version : '0.1', meson_version : '>= 1.3.0', default_options : ['warning_level=3', 'cpp_std=c++17', 'default_library=static'])
# Change all of the above to your liking. 
# The cpp_std must be greater than c++14 (if you attempt to use c++14 or earlier, the project will fail to build). 
# I used c++17 because that is the earlier standard that works.
useSystemSFML = get_option('useSystemSFML')
programName = 'YourProject'

if useSystemSFML
  sfmldep = dependency('sfml-all')
  executable(programName, 'main.cpp', dependencies : sfmldep)
else
  cmake = import('cmake')
  sfml_proj = cmake.subproject('SFML')
  sfml_graphics = sfml_proj.dependency('sfml-graphics')
  sfml_window = sfml_proj.dependency('sfml-window')
  sfml_system = sfml_proj.dependency('sfml-system')
  sfml_audio = sfml_proj.dependency('sfml-audio')
  sfml_network = sfml_proj.dependency('sfml-network')

  if build_machine.system() == 'windows'
    compiler = meson.get_compiler('cpp')
    winmm = compiler.find_library('winmm', required: true)
    ogl = compiler.find_library('opengl32', required: true)
    sfml_main = sfml_proj.dependency('sfml-main')
    executable(programName, 'main.cpp', dependencies : [sfml_graphics, sfml_window, sfml_system, sfml_audio, sfml_network, sfml_main, winmm, ogl], win_subsystem: 'console')
  else
    executable(programName, 'main.cpp', dependencies : [sfml_graphics, sfml_window, sfml_system, sfml_audio, sfml_network])
  endif
endif
