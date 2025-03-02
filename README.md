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
(it's still unknown if an "object" will be a struct because of lack of uses it will give)

The variables of each struct are not locked in,
they're still actively changing for the project requirements as the project is very raw and in the starting phase.
In other words, the whole concept and this paragraph could change drastically any time.


## Compilation

To compile you need to:
1. Create a new folder build
2. Go to that folder in the console
3. Type "cmake .."

When finished, you can use Visual studio to compile the project through the solution


## Current state

The project is in it's very starting phase. Right now it's just like a very bad paint replica with one color and one shape.