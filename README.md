# HERD - Human-AI Collaboration: Swarm Sim

TODO: add images

## Install dependencies

Install the dependencies:

```bash
sudo apt update && sudo apt install build-essential libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev libglm-dev libglfw3-dev
```

## Build

```bash
mkdir build
cd build
cmake ..
make
```

## Web Build

Alternatively to the normal CMake, a web assembly version can be compiled.

### Install dependencies for web build

Follow the guide to install emscripten:
<https://emscripten.org/docs/getting_started/downloads.html>

make sure to source the emcsdk before use:

```bash
source ~/emsdk/emsdk_env.sh
```

### Build web

```bash
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release
emmake make
```
