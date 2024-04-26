# Steps
## add CMakeLists.txt
```shell
touch CMakeLists.txt
# ...
```
## add vcpkg config
```shell
vcpkg new --application  # create file: vcpkg.json, vcpkg-configuration.json
```

## create CMakePresets.json
```shell
{
  "version": 2,
  "configurePresets": [
    {
      "name": "default",
      "generator": "Ninja",
      "binaryDir": "${sourceDir}/vcpkg-build",
      "cacheVariables": {
        "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
      }
    }
  ]
}
```

## add dependencies
```shell
vcpkg add port fmt
```

## add source code (include, src)
add files `include/common.h`, `src/common.cpp`

## build
```shell
cmake --preset=default
cmake --build vcpkg-build
```

## install from overlay
```shell
vcpkg install port-example --overlay-ports=/path/to/vcpkg-port-example/vcpkg-overlay
vcpkg install port-example --overlay-ports=/home/wii/code/vcpkg-port-example/vcpkg-overlay
```