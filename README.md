# Meson-SFML-Template
Template repository for using SFML with the Meson build tool

# What is this?
[Simple and Fast Multimedia Library](https://www.sfml-dev.org/) (SFML) is a library that is used to create multimedia applications. It provides tools to handle OpenGL contexts/windows, audio, network, and other system components. SFML also has their own [CMake project template](https://github.com/SFML/cmake-sfml-project) which can be used if you want to start using SFML to create one of your own projects. This repository aims to serve a similar purpose for individuals who wish to use Meson instead of CMake as their build tool of choice.

# Why not use `meson wrap install sfml`?
It uses a highly outdated version of SFML by default. This template will pull from the SFML Github page, and you can choose which branch or commit you'd like to use (as a sidenote, it is recommended, though not necessary, that you run `git submodule update --remote` followed by `meson setup --wite builddir` frequently after running `meson setup builddir`, in order to pick an up-to-date commit of SFML, as if you follow the below instructions without doing so, the version of SFML that is used will also be old, which is the whole reason we don't use `meson wrap install sfml` in the first place). Similarly, if you choose to use your systemside install of SFML, you get to control which version of SFML you use, and can use the most up-to-date version if you desire.

# Dependencies
When using this template, you are given the choice between using a systemwide installation of SFML, or using SFML as a Git submodule in case you are unable (or do not want to) install SFML systemwide. Instructions on how to use a systemwide SFML install and how to use the Git subproject are provided below (using a systemwide SFML install will drastically decrease compile times).

(LINUX ONLY) If you intend to use the Git submodule for SFML, you need to install all of SFML's dependencies, which allow SFML to be compiled. Here's what you need:
- `libxrandr-dev`
- `libxcursor-dev`
- `libudev-dev`
- `libflac-dev`
- `libvorbis-dev`
- `libgl1-mesa-dev`
- `libegl1-mesa-dev`
- `libdrm-dev`
- `libgbm-dev`

(I imagine that the non-dev versions of all of these packages work as well). Use your distro's package manager to install all of these. (On Windows, I'm pretty sure SFML uses packages that are shipped with the OS, so you don't need to install anything additional).

Finally, make sure you have both Meson and CMake installed and available in your PATH. This can be done through `pip`, but it's recommended to use your package manager if you can. See [Meson's installation page](https://mesonbuild.com/Getting-meson.html) for more information. Meson and CMake both have a number of dependencies which must be installed for them to work correctly, and Ninja (one of Meson's dependencies) should be included in your PATH as well. As always, since package managers tend to handle dependencies for you, it's recommended to install through them if you are able to.

# Compilation/Installation guide

## If you have a systemwide SFML install
- Make sure Meson and SFML are both installed
- Clone and `cd` into this repository
- Run `meson setup builddir -DuseSystemSFML=true`
- Run `cd builddir`
- Run `meson compile`
- The executable should now be in the build directory. 

## If you want to use the SFML submodule
- Make sure Meson and CMake are both installed
- Clone and `cd` into this repository
- Run `meson setup builddir`
- Run `cd builddir`
- Run `meson compile`
- The executable should now be in the build directory.
### Whenever you want to update the SFML submodule, follow these instructions:
- `cd` out of your `builddir` into your project root
- Run `git submodule update --remote`
- Run `meson setup --wipe builddir`
