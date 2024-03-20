# ml-unicycle
Machine Learning Unicycle/Inverted Pendulum Simulator in C++

# Setting Up The Source Code
## Requirements
1. Install Git
2. Install CMake
3. Install C++ compiler

## Installation
```
git clone https://github.com/gavintranquilino/ml-unicycle.git
```

## Setting up the build with CMake
1. Create a build/ and bin/ folder at the project root
```
mkdir build 
mkdir bin
```

2. Change directory to build 
```
cd build
```

3. Build Makefile with CMake from source
- This step can be skipped if it was ran previously
```
cmake -S ../ -B .
```

4. Build with Makefile
```
cmake --build .
```

5. Run the .exe
```
../bin/unicycle.exe
```

# Resources

## Setting up CMake
- Setting up CMake: [Code, Tech, and Tutorials](https://www.youtube.com/watch?v=nlKcXPUJGwA&list=PLalVdRk2RC6o5GHu618ARWh0VO0bFlif4&index=2)

## Inverted Pendulum
- OpenAI gym: [cartpole](https://www.gymlibrary.dev/environments/classic_control/cart_pole/)
- jasleon: [Inverted-Pendulum](https://github.com/jasleon/Inverted-Pendulum)

### Relevant Math and Control Theory
- Karooza: [Modelling an inverted pendulum](https://karooza.net/modelling-an-inverted-pendulum)
