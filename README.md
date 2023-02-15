<h1 align="center">Welcome to swarm-simulator 👋</h1>
<p>
  <img alt="Version" src="https://img.shields.io/badge/version-0.0.1-blue.svg?cacheSeconds=2592000" />
  <a href=" " target="_blank">
    <img alt="Documentation" src="https://img.shields.io/badge/documentation-yes-brightgreen.svg" />
  </a>
  <a href="https://github.com/kefranabg/readme-md-generator/graphs/commit-activity" target="_blank">
    <img alt="Maintenance" src="https://img.shields.io/badge/Maintained%3F-yes-green.svg" />
  </a>
  <a href="https://github.com/kasperg3/swarm-simulator/blob/79fbc5c29036169ec56d4c07bd64e2df01b3bf38/LICENCE" target="_blank">
    <img alt="License: MIT" src="https://img.shields.io/github/license/kasperg3/swarm-simulator" />
  </a>
  <a href=" " target="_blank">
    <img alt="Build" src="https://github.com/kasperg3/swarm-simulator/actions/workflows/build.yml/badge.svg" />
  </a>
  
</p>

![Simple Boids example](https://github.com/kasperg3/swarm-simulator/blob/main/assets/BoidsExample.gif)

A simple and effecient agent centered swarm simulator.

## Install

### Dependencies

```sh
sudo apt update && sudo apt install build-essential libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev libglm-dev libglfw3-dev libgsl-dev

```


### Build

```sh
mkdir build
cd build
cmake ..
make
```

### Install system wide
```sh
make install
```

<!-- ## Web Build

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
``` -->


## Run
To run the example, execute the following command:
```sh
./build/example/Experiment
```

# Usage
For a detailed explanation on usage, please take a look at the [GETTING_STARTED.md](https://github.com/kasperg3/swarm-simulator/blob/main/getting_started.md) file or check out the writeup on my site: https://blog.grontved.dk/blog/swarm-simulator/ 

# Author

👤 **Kasper Rømer Grøntved**

* Website: https://blog.grontved.dk
* GitHub: [@kasperg3](https://github.com/kasperg3)

# 🤝 Contributing

Contributions, issues and feature requests are welcome!<br />Feel free to check [issues page](https://github.com/kasperg3/swarm-simulator/issues). You can also take a look at the [contributing guide](https://github.com/kasperg3/swarm-simulator/blob/main/CONTRIBUTING.md).

# Show your support

Give a ⭐️ if this project helped you!

# 📝 License

Copyright © 2022 [Kasper Rømer Grøntved](https://github.com/kasperg3).<br />
This project is [MIT](https://github.com/kasperg3/swarm-simulator/blob/main/LICENCE) licensed.
