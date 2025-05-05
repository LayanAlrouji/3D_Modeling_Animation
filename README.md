![CCIS LOGO](images/CCISlogo.png)
# ProjectGroupXX     

This README serves as the full report for the Computer Graphics course project. All group members should contribute to updating this file as the project progresses.

---

## 📘 Project Overview

In this project, I designed a bird-inspired robot using basic 3D shapes. It includes:
 - A spherical body and head.
 - Moving legs to simulate walking and jumping.
 - Wings to simulate bird wings.


The goal of this project is to create smooth and repeatable movements, providing simple interaction through keyboard controls for walking and jumping.
It focuses on 3D modeling, animation, and interactive controls.

---

## 👥 Team Members & Roles

- Member 1: Layan Alrouji Alrouji / 444008839 (leader)

---
### Week 11
## 💡 Phase 1: Lighting, depth setup and first sketch (robot design)
- Description of the lighting setup and depth applied to the scene:


This phase focused on creating a more realistic 3D environment. The primary elements involved in setting up the lighting and depth adjustments include:


Lighting Setup:
 - Directional Light: Provides consistent lighting from a single direction. This light affects the whole scene equally from a particular 
   angle, much like how the sun illuminates everything in its path.
 - Positional Light: Radiates from a specific point, affecting only nearby objects. It is commonly used to mimic point lights such as light 
   bulbs. This type of light helps create dynamic lighting effects and adds realism to the scene.


Depth Setup:
To ensure objects are rendered correctly in relation to one another, depth testing was enabled. This allows the program to handle overlapping objects and render them in the correct order, ensuring that closer objects are drawn in front of farther ones. 

- pictures of your design sketch
![IMG_2754](https://github.com/user-attachments/assets/38184551-6475-4201-8b1b-9e7199905dc1)
 
- Screenshots and code snippets if relevant

![image](https://github.com/user-attachments/assets/ae146abc-2873-41fd-9e69-924ee2600cf9)




- describe Challenges and how you addressed them in the challenge table below.( for example GitHub issues that you've faced at this stage and how you solve them with screenshots)


  Challenge 1 : The lighting caused incorrect shading on parts of the robot.
  Solution : Adjusted lighting intensity, added a second light source.



  Challenge 2 : Objects were overlapping incorrectly due to disabled depth testing.

  Solution : Enabled depth testing with glEnable(GL_DEPTH_TEST)
  
---
### Week 12
## ✅ Phase 2: Robot Construction

- Description of how the robot was modeled using 3D primitives.


In this Phase , the robot was designed using basic 3D primitives. Here's how the robot was modeled:



Body: The body of the robot is represented by a large sphere. It forms the central part of the robot, making it round and simple.



Head: The head is also modeled using a smaller sphere placed on top of the body.



Legs: The legs of the robot were initially represented by spheres. These were positioned appropriately and it's simulate walking and jumping.



Wings: The wings are represented by spheres that simulating the bird's wings.



glPushMatrix() and glPopMatrix() were used to ensure proper hierarchical modeling. Each part of the robot was treated as a separate unit that can move independently while keeping the entire structure intact.


- Include screenshots of work progress including all the versions you've made.


![image](https://github.com/user-attachments/assets/79dac0c2-3480-45cb-8b3b-38bf27a8d04d)





- describe Challenges and how you addressed them in the challenge table below.

  Challenge 1 : The legs didn’t move or simulate walking.

  Solution : Used sphere to simulate the movement of the legs back and forth.



---
### Week 13
## 🦿 Phase 3: Basic Animation

- Explanation of which parts were animated and how.
  

The robot’s parts that simulate movement:


The legs were animated using Translate function to simulate walking and jumping of the robot. 

The Translate of the legs is controlled by the legMovement variable and jumpMovement variable , which increases over time to create the walking motion.



- Any specific animation logic or hierarchical modeling techniques.


Animation logic :
  

Legs Animation for walking : glTranslatef(legMovement, 0.0F, 0.0f) used to animate the legs walking. 

The value of legMovement increases with each frame, and when it exceeds a limit it resets to 0.0f (-30).


Legs Animation for jumping : glTranslatef(0.0f, jumpMovement, 0.0f) used to animate the jumping fot the legs. 

The value of jumpMovement increases with each frame, and when it exceeds a limit it resets to 0.0f.




hierarchical modeling techniques :


glPushMatrix() & glPopMatrix() functions : used to isolate transformations for each body part without affecting the others. 

This ensures that the robot can move independently.


 
<img width="581" alt="Screenshot 1446-11-07 at 8 22 49 AM" src="https://github.com/user-attachments/assets/7996e582-51ee-49b9-b58f-54e472876294" />


---
### Week 15
## 🧩 Phase 4: Interaction

- Summary of added controls (keyboard/mouse).


I added keyboard controls to interact with the robot's movement:


w: When pressing w, the robot starts or stops walking by updating the isWalking variable.


j: When pressing j, the robot starts or stops jumping by updating the isJumping variable.


- Any final improvements (design tweaks, environment polish).


Improved Lighting: Enhanced the lighting using directional and positional lights to provide consistent illumination across the scene.


Depth Testing: Enabled depth testing using glEnable(GL_DEPTH_TEST) to ensure the proper rendering order of overlapping objects, improving visual accuracy.


Background: Changed the background to a consistent color (light blue) to represent the sky.


  
- Screenshots


![image](https://github.com/user-attachments/assets/20bd3cd3-c560-4ba1-8614-6c7c652d7f28)





![image](https://github.com/user-attachments/assets/3e130728-4d28-4338-b1aa-8253a70a27d0)






---

## 🛠️ Challenges & Solutions

| Challenge | Solution |
|----------|----------|
|  Lighting was inconsistent | Adjusted the light intensity and added both directional and positional lights to ensure consistent lighting across the robot and the scene. |
|  Depth testing was not enabled | Enabled depth testing using glEnable(GL_DEPTH_TEST) to ensure proper rendering of overlapping objects. |
|  Jumping was not visible | Implemented glTranslatef() to simulate vertical motion when isJumping is activated. |


---


## 💬 Final Reflection 

- What did your team learn during this project?


I learned a lot about 3D modeling and animation using OpenGL and GLUT. Some of things I learned include:


 1- Basic 3D modeling techniques: I learned how to create and manipulate basic 3D shapes to construct a robot.


 2- Animation fundamentals: I understood how to animate objects by manipulating transformation matrices to create smooth, repeatable 
    movements.


 3- Lighting and depth: I learned how to set up directional and positional lights to simulate realistic lighting, and how to use depth 
    testing to ensure proper object rendering order.


 4- Hierarchical modeling ( glPushMatrix() and glPopMatrix() functions ) : I understood how to model and animate different parts of the 
    robot independently, while keeping the overall structure intact.



- What was the most challenging and rewarding part?


Most Challenging Part:


The most challenging aspect of the project was animating the robot smoothly. Getting the legs to walk and jump while balancing the speed of the movements and ensuring everything loops properly, was difficult.
Additionally, depth testing and lighting adjustments were also challenging, especially when ensuring the robot’s parts were properly lit and rendered correctly without visual glitches.




Most Rewarding Part:


The most rewarding part was seeing the robot come to life after all the animations were working together. Adding interactivity through the keyboard controls for walking and jumping made the robot feel even more alive and engaging.






- If you had more time, what would you improve or add?

                  -------- 
