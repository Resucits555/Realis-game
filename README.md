## Idea

The main idea of this project is making a simulation with all the properties such as temperature, pressure, speed
and physical concepts like bending materials, crumbling objects, explosions and more.

The sim is a cellular-automata: a big map of cells with relations to each other.
Cells could be assigned to objects to create "moving solids", a fairly hard concept to make in such enviroment.
To give free way for the imagination of users,
there should be a built in "element creator" to create materials with all kinds of properties needed, but also standart ones.


## Concept

The simulation has different elements to generalise properties of cells.
There are standart ones given but you can also define your own (WIP). The properties are:
- name: how the element is called. Max. 7 characters
- color: rgba 0-255
- mass: how heavy the element is
- elasticity: how much force is given to the surrounding cells rather than the force direction
- hardness: how much force the cell gives directly to the object/max. threshold

The simulation is a grid of cells. Each cell consists of:
- origin: cell position if there is no pressure aplied
- linVelocity: speed of the cell in a certain direction
- type: element of cell
- myobject: assigned object

To make "moving solids" possible, the sim has objects, which could be described as a connection of cells. It contains:
- linVelocity: linear general velocity

(it's still unknown if "object" will be a struct because of the lack of uses it will give)

The variables of each struct are not locked in,
they're still actively changing for the project requirements as the project is very raw and in the starting phase.
In other words, the whole concept and this paragraph could change drastically any time.

How many features will be in the end product depends on the speed of it.
Therefore the code should be highly optimised and memory efficient to make playing on relatively weak computers possible too.


## Movement, force and cells

The simulation is based around force. Force should be everywhere, like in reality.

How a cell should behave is not fully known yet, but that's what I already came up with:
Imagine a 3x3px quadratic object out of cells with the same type.
The middle one has connections to the cells in a one pixel radius around it.
These should always stay in the radius and only can move around the cell to make the object rotate.
A cell can only disconnect if the force is more than the element can withstand.
Any force given to one of the cells should be distibuted to the other cells and cannot vanish (conservation of energy).
The amount of cells can only be changed by drawing and deleting with the mouse.

Bending objects are realised with the "origin" variable. It points to the position where the cell would be if there is no pressure.
There should always be generated a force in direction to origin based on the distance.

Any suggestions to give more clarity how the sim should work at the end would be highly appreciated.


## Compilation

To compile you need to:
1. Create a new folder build
2. Go to that folder in the console
3. Type "cmake .."

When finished, you can use Visual studio to compile the project through the solution


## Current state

The project is in it's very starting phase. Right now it's just like a very bad paint replica with one color and one shape.

The sim is very small but should be made bigger in future. Now the size is just enough to test the current features.