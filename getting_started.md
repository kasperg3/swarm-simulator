# Introduction
To show the most basic use of the library an example project has been created. The example contains the implementations of the Robot- (Where all agent logic is placed) and Widged-class (UI component) where user defined control can be created as a ui component, this is optional.

The usage of the library is currently under progress and is subject for change in the future. At the moment the user implementation have to be inside the cloned project, where in the future the library will be used as a static library.

There are four classes avaiable for the user to extend, which each adds a layer of abstraction to the simulation:
* Robot
  * Agent behaviour 
  * Agent rendering
* Environment
  * Environment variables, obstacles, etc.
  * Environment rendering
* Widget
  * Environment control
  * Widget Rendering
* SwarmSimulator
  * The application class, that uses the other core classes to orchestrate the simulation.


# Using the library
Clone the repository and implement your agents, environment and custom ui in the project it self. 
Do not hesitate to create a pull request and submit your implementations for the library.
