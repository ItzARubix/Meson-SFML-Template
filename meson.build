project('NylCaster', 'cpp')
useSystemSFML = get_option('useSystemSFML')

if useSystemSFML
  sfmldep = dependency('sfml-all')
  executable('NylCaster', 'main.cpp', dependencies : sfmldep)
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
    executable('NylCaster', 'main.cpp', dependencies : [sfml_graphics, sfml_window, sfml_system, sfml_audio, sfml_network, sfml_main, winmm, ogl], win_subsystem: 'console')
  else
    executable('NylCaster', 'main.cpp', dependencies : [sfml_graphics, sfml_window, sfml_system, sfml_audio, sfml_network])
  endif
endif
