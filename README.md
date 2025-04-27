![CCIS LOGO](images/CCISlogo.png)
# ProjectGroupXX     

This README serves as the full report for the Computer Graphics course project. All group members should contribute to updating this file as the project progresses.

---

## 📘 Project Overview

In this project, I designed a bird-inspired robot using basic 3D shapes. It includes:
 - A spherical body and head.
 - Moving legs to simulate walking.
 - Rotating wings to simulate bird-like motion.
The goal of this project is to create smooth and repeatable movements, providing simple interaction through keyboard controls for walking and jumping.
It focuses on 3D modeling, animation, and interactive controls to mimic bird-like movements.

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
 <img width="437" alt="Screenshot 1446-10-29 at 3 15 30 AM" src="https://github.com/user-attachments/assets/faedd160-c866-4c2f-b9ca-b60975f610b6" />

- describe Challenges and how you addressed them in the challenge table below.( for example GitHub issues that you've faced at this stage and how you solve them with screenshots)
  Challenge 1 : The lighting caused incorrect shading on parts of the robot.
  Solution : Adjusted lighting intensity, added a second light source.

  Challenge 2 : Objects were overlapping incorrectly due to disabled depth testing.
  Solution : Enabled depth testing with glEnable(GL_DEPTH_TEST)
  
---
### Week 12
## ✅ Phase 2: Robot Construction

- Description of how the robot was modeled using 3D primitives.
- Include screenshots of work progress including all the versions you've made.
- describe Challenges and how you addressed them in the challenge table below.

---
### Week 13
## 🦿 Phase 3: Basic Animation

- Explanation of which parts were animated and how.
- Any specific animation logic or hierarchical modeling techniques.

---
### Week 15
## 🧩 Phase 4: Interaction

- Summary of added controls (keyboard/mouse).
- Any final improvements (design tweaks, environment polish).
- Screenshots 

---

## 🛠️ Challenges & Solutions

| Challenge | Solution |
|----------|----------|
| Example: Lighting was too dark | Adjusted light position and material shininess |

---


## 💬 Final Reflection 

- What did your team learn during this project?
- What was the most challenging and rewarding part?
- If you had more time, what would you improve or add?
