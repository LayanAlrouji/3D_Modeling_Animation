#include <Windows.h>
#include <glut.h>
#include <cmath>

//***** Camera movement (DO NOT CHANGE THESE PARAMETERS) *****//
            // Default values
const float DEFAULT_RADIUS = 100.0f;
const float DEFAULT_ANGLE_X = 0.0f;
const float DEFAULT_ANGLE_Y = 0.0f;
// Camera angles for rotation
float angleX = 0.0f;
float angleY = 0.0f;
// Mouse tracking
float lastX = -100;
float lastY = -100;
bool leftButtonDown = false;
bool rightButtonDown = false;
// Camera distance from center
float radius = 100.0f;
//----------end of Camera movement----------------------------
// you can add and update variables here
int width = 800;
int height = 600;

// Animation flags
float legMovement = 0.0f;
float jumpMovement = 0.0f;
float jumpDirection = 1.0f;

bool isWalking = false;
bool isJumping = false;

// Draw the robot
 void drawRobot() {
        // Body
        glPushMatrix();
        glColor3f(1.0f, 0.5f, 0.0f);
        glutSolidSphere(2.0, 50, 50);
        glPopMatrix();

        // Head
        glPushMatrix();
        glColor3f(0.8f, 0.4f, 0.0f);
        glTranslatef(0.0f, 2.5f, 0.0f);
        glutSolidSphere(1.0, 50, 50);
        glPopMatrix();

        // Left Leg
        glPushMatrix();
        glColor3f(0.6f, 0.3f, 0.1f);
        glTranslatef(-1.0f, -2.5f, 0.0f);
        glutSolidSphere(0.5, 50, 50);
        glPopMatrix();
        // Right Leg
        glPushMatrix();
        glColor3f(0.6f, 0.3f, 0.1f);
        glTranslatef(1.0f, -2.5f, 0.0f);
        glutSolidSphere(0.5, 50, 50);
        glPopMatrix();

        // Left Wings
        glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        glTranslatef(2.5f, 0.0f, 0.0f);
        glutSolidSphere(0.8, 50, 50);
        glPopMatrix();
        // Right Wings
        glPushMatrix();
        glColor3f(0.5f, 0.5f, 0.5f);
        glTranslatef(-2.5f, 0.0f, 0.0f);
        glutSolidSphere(0.8, 50, 50);
        glPopMatrix();

      if (isWalking) {
            legMovement += 0.01f;
            if (legMovement > 30.0f) legMovement = -30.0f;
        }
        else {
            if (legMovement > 0) legMovement -= 1.0f;
            if (legMovement < 0) legMovement += 1.0f;
        }


        if (isJumping) {
            jumpMovement += jumpDirection * 0.01f;
            if (jumpMovement > 5.0f) jumpDirection = -1.0f;
            if (jumpMovement < 0.0f) jumpDirection = 1.0f;
        }
        else {
            if (jumpMovement > 0) jumpMovement -= 0.5f;
            if (jumpMovement < 0) jumpMovement = 0;
        }
    }


void draw() {
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //***** Convert spherical to Cartesian coordinates (DO NOT CHANGE)
    float camX = radius * sinf(angleY) * cosf(angleX);
    float camY = radius * sinf(angleX);
    float camZ = radius * cosf(angleY) * cosf(angleX);
    //***** End of Cartesian coordinates

    gluLookAt(camX, camY, camZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

    //************Start drawing here *****************

    // BASE PLANE 
    glColor3f(0.4f, 0.8f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(50, -20, 50);
    glVertex3f(50, -20, -50);
    glVertex3f(-50, -20, -50);
    glVertex3f(-50, -20, 50);
    glEnd();

    //sun:
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glTranslatef(0.0f, 30.0f, -50.0f);
    glutSolidSphere(5.0, 50, 50);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0f, jumpMovement, 0.0f);
    glTranslatef(legMovement, 0.0F, 0.0f);
    drawRobot();
    glPopMatrix();

    glFlush();
}

// **** Current interactions  
// Mouse left-click to move around the object
// Mouse right-click to zoom in/out 
// Space to reset the view 


//***** Interaction : Mouse button press ( DO NOT CHANGE THIS METHOD)
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON)
        leftButtonDown = (state == GLUT_DOWN);
    else if (button == GLUT_RIGHT_BUTTON)
        rightButtonDown = (state == GLUT_DOWN);
    lastX = x;
    lastY = y;
}

//***** Interaction : Mouse motion  ( DO NOT CHANGE THIS METHOD)
void motion(int x, int y) {
    float dx = (x - lastX) * 0.01f;
    float dy = (y - lastY) * 0.01f;
    if (leftButtonDown) {
        angleY += dx;
        angleX += dy;
        //  vertical angle
        if (angleX > 1.5f) angleX = 1.5f;
        if (angleX < -1.5f) angleX = -1.5f;
    }
    if (rightButtonDown) {
        radius += dy * 20.0f; // Zoom in/out faster
        // zoom range between -200 & 200 
        if (radius < -200.0f) radius = -200.0f;
        if (radius > 200.0f) radius = 200.0f;
    }
    lastX = x;
    lastY = y;
    glutPostRedisplay(); //requests a redraw of the window
}


// Keyboard kyes handlers (this method handles "SPACE" key to reset the view , you can add more keys to the same method for animation)
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case ' ':
        angleX = DEFAULT_ANGLE_X;
        angleY = DEFAULT_ANGLE_Y;
        radius = DEFAULT_RADIUS;
        break;
    case 'w':
        isWalking = !isWalking;
        break;
    case 'j':
        isJumping = !isJumping;
        break;
    default:
        return;
    }
}

int main() {
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("905");

    glEnable(GL_DEPTH_TEST);

    // Dierctional
    GLfloat pos[] = { 1.0f, 1.0f, 1.0f, 0.0f };
    GLfloat color[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
    glEnable(GL_LIGHT0);

    // Positional
    GLfloat pos2[] = { -1.0f, -1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT1, GL_POSITION, pos2);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
    glEnable(GL_LIGHT1);

    glEnable(GL_LIGHTING);

    glEnable(GL_COLOR_MATERIAL);


    // Setup perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, (float)width / (float)height, 1.0, 1000.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ****** Interaction : handlers ( DO NOT CHANGE)
    glutMouseFunc(mouse);  //  mouse button click/release handler
    glutMotionFunc(motion); // Register a callback for mouse motion while a button is held down (dragging)
    glutKeyboardFunc(keyboard);  // Register keyboard handler
    // ****** end of interaction

    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutMainLoop();
}
