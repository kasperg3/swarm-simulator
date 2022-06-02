# HERD - Human-AI Collaboration: Swarm Sim

TODO: add images
## Install dependencies

Opengl:
```
sudo apt install libglm-dev
```
TODO: list the remaining dependencies

## Build

```
mkdir build
cd build
cmake ..
make
```

### Web

```
mkdir build
cd build
emcmake cmake .. -DPLATFORM=Web -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXE_LINKER_FLAGS="-s USE_GLFW=3"
emmake make
```

