cc = meson.get_compiler('cpp')
thorvg_dep = dependency('thorvg-1', required: true)
examples_dep = [thorvg_dep, dependency('sdl2', required: true)]
compiler_flags = ['-DSDL_MAIN_HANDLED']

# GL or GLES
gl_dep = dependency('gl', required: false)
gles_dep = dependency('glesv2', required: false)

if gl_dep.found()
    examples_dep += gl_dep
elif gles_dep.found()
    examples_dep += gles_dep
    compiler_flags += ['-DTVGEXAMPLE_GLES_SUPPORTED']
else
    message('Neither OpenGL nor OpenGL ES was found. Skipping GL examples.')
endif

# WebGPU
wgpu_dep = dependency('wgpu_native', required: false)

if wgpu_dep.found()
    examples_dep += wgpu_dep
    compiler_flags += ['-DTVGEXAMPLE_WGPU_SUPPORTED']
    if host_machine.system() == 'darwin'
        add_languages('objcpp', native: false)
        examples_dep += declare_dependency(link_args: ['-lobjc', '-framework', 'Cocoa', '-framework', 'CoreVideo', '-framework', 'IOKit', '-framework', 'QuartzCore'])
        compiler_flags += ['-x', 'objective-c++']
    endif
endif

source_files = [
    'thorvg_ui.h',
    'Demo.cpp',
]

thorvg_inc = include_directories(
    join_paths(
        thorvg_dep.get_variable(pkgconfig: 'includedir'),
        'thorvg-1'
    )
)

executable(
    'demo',
    source_files,
    dependencies: examples_dep,
    include_directories: thorvg_inc,
    cpp_args: compiler_flags
)