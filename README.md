# anglePlatformer
angle platformer is a platormer 2D game that aims to showcase proper usage of the TLE5012 angle sensor 


The game project consists of two main compartments:
    + The TLE5012B (referred to as arduino)
    + The Python game that runs on the computer connected to the TLE5012B




# Arduino Code
The TLE5012B is the main input device for the game, where the user has to rotate the knob and dependant on the rotation the game character will take a specific arch of movement

Lets take a look at how this takes place


<div align="center">
    <img src="Repo Graphics/how the sensor works.PNG" alt="how the coordinate system works" width=400/>
</div>
The TLE5012B measures the magnetic field and creates a coordinate system out of its measurements, where it marks the angles from 0 to 90 to 180 and then from -180 to -90 to 0 

<div align="center">
    <img src="Repo Graphics/Arduino Code Flow Chart.PNG" alt="Alt text" width="700" />
</div>





