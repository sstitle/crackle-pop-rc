# Maskfile

This is a [mask](https://github.com/jacobdeichert/mask) task runner file.

## build

Build the project using CMake in the /build directory.

```bash
cmake -S . -B build -G Ninja
cmake --build build
```

## run

Build and run the main executable.

```bash
$MASK build
./build/main
```
