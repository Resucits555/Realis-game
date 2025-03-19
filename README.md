## Idea

The main idea of this project is making a simulation with all the properties such as temperature, pressure, speed
and physical concepts like bending materials, crumbling objects, explosions and more.

The sim is a cellular-automata: a big map of cells with relations to each other.
Cells could be assigned to objects to create "moving solids", a fairly hard concept to make in such enviroment.
To give free way for the imagination of users,
there should be a built in "element creator" to create materials with all kinds of properties needed, but also standart ones.


## Concept

The simulation has different elements to generalise properties of cells. The properties are:
- name: how the element is called. Max. 5 characters
- color: rgba 0-255
- spawnState: the state an element spawns with
- mass: how heavy the element is
- elasticity: how much force is given to the surrounding cells rather than the force direction
- hardness: how much force the cell gives directly to the object/max. threshold

The simulation is a grid of cells. Each cell consists of:
- origin: cell position if there is no pressure aplied
- move: the exact position inside the cell
- type: element of the cell
- state: state of the cell
- myobject: assigned object
- linVelocity: linear speed of the cell

To make "moving solids" possible, the sim has objects, which could be described as a connection of cells. It contains:
- linVelocity: linear general velocity

(it's still unknown if "object" will be a struct because of the lack of uses it will give)

The variables of each struct are not locked in,
they're still actively changing for the project's requirements as the project is very raw and in it's starting phase.
In other words, the whole concept and this paragraph will change a lot through the time.

How many features will be in the end product depends on the speed of it.
Therefore the code should be highly optimised and memory efficient to make playing on relatively weak computers possible too.

The simulation should also have liquids, gases and powders but these are far easier to simulate.


## Movement, force and cells

The simulation is based around force. Force should be everywhere, like in reality.

How a cell should behave is not fully known yet, but that's what I already came up with:\
Imagine a 3x3px quadratic object out of cells with the same type.
Each one has connections to the cells in a one pixel radius around it, so the middle one is connected to all the other cells.
These should always stay in the radius and only can move around the middle cell to make the object rotate.
A cell can only disconnect if the force is more than the element can withstand.
Any force given to one of the cells should be distributed to the other cells and cannot vanish (conservation of energy).
The amount of cells can only be changed by drawing and deleting with the mouse.

Both force and velocity of a cell are represented by the same variable "linVelocity" as they're mutually exclusive:
Only one of them is useful at a time.

Bending objects are realised with the "origin" variable. It points to the position where the cell would be if there was no pressure.
There should always be generated a force in direction to origin based on the distance.


## Compilation

For compilation you need cmake and git.

In Visual Studio, do the following:
1. Create a new folder build
2. Go to that folder in the console
3. Type "cmake .."

When finished, set "main" as the startup project in view/solution explorer and run the project\
If you use something else, I can't help.


## Current state

The project is in it's very starting phase.\
The sim is very small but should be made bigger in future. Now the size is just enough to test the current features.\
The name is not fixed, it could change anytime.