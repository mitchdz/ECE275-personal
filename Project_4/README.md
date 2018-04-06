Author: <br>
NetID: <br>
Date: <br>
Project Name: project_5 <br>
Course Name: ece275 <br>

# High-level Description
## Kinematic Model Simulation
In this project, you will create a program that controls an autonomous vehicle from an input control file. The only problem is that the input controls are jumbled, since a function that operated on the linked list that stored them was badly designed: they were stored in order in a queue, but the queue was designed by a Visual Basic programmer who doesn't understand memory. They printed the nodes out by order of memory address of the list nodes, instead of by the node order prescribed by the next pointers.

So you need to put them back in the right order before proceeding. This program will read in time value at which this command should be executed, then the commanded speed, and tire angle. The duration of the command is the difference between this command's time value, and the next time value (when the nodes are in order), at a maximum of 201 ms. If there are any durations longer than 201 ms, the input file should be declared invalid, and no simulation should take place.

With this sequence of commands, you should save the vehicle's state at each time step. During the execution of control commands, this program will record the vehicle's state as it moves (or stands still), and save the output states to a file.

## Vehicle Model
You are developing a vehicle simulator, which describes the kinematic motion of a front-steered, two-wheel drive vehicle. The vehicle you are simulating is visually depicted below.

![Kinematic Model](https://storage.googleapis.com/ece-gitlab/catcar.png)

Where x_1 is translation forward motion,  x_2 is translational left/right modtion,  x_3 is the tire angle, and x_4  is the heading of the vehicle. For control inputs,  u_1 represents commanded vehicle velocity, and u_2 represents angular rate of change for the tire angle. The wheelbase L is defined in the CarSimulator.h file. Using a simple discretization of these differential equations with a duration , we can use the following equations for motion:

1.  x_pos = x_prev + duration*velocity*cos(tire_angle)*cos(heading)
2. y_pos = y_prev + duration*velocity*cos(tire_angle)*sin(heading)
3. tire_angle = tire_angle_prev + duration*tire_angle_rate
4. heading = heading_prev + duration*velocity*(1.0/L)*sin(tire_angle)
5. time_stamp = time_stamp_prev + duration
