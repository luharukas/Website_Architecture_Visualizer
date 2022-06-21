
#include <GL/glut.h>
#include<stdio.h>
#include "math.h"
#include<string.h>
#include<stdlib.h>

// For Print the text
GLuint fontOffset;
GLubyte space[] =
{ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

GLubyte letters[][13] = {
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
{0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
{0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
{0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
{0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
{0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
{0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
{0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
{0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
{0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
{0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
};

void makeRasterFont(void)
{
	GLuint i, j;
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	fontOffset = glGenLists(128);
	for (i = 0, j = 'A'; i < 26; i++, j++) {
		glNewList(fontOffset + j, GL_COMPILE);
		glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
		glEndList();
	}
	glNewList(fontOffset + ' ', GL_COMPILE);
	glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
	glEndList();
}

void init() {

	glClearColor(1, 1, 1, 1);
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(10.0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1500, 0.0, 800);

	glShadeModel(GL_FLAT);
	makeRasterFont();
}

void printString(char* s)
{
	glPushAttrib(GL_LIST_BIT);
	glListBase(fontOffset);
	glCallLists((GLsizei)strlen(s), GL_UNSIGNED_BYTE, (GLubyte*)s);
	glPopAttrib();
}
// End of the Text Display Function and code

// function to display the rectagle
void display_rectangle()
{
	glColor4f(0,0,0,0.2);
	glBegin(GL_QUADS);
	glVertex2d(500,50);
	glVertex2d(1400,50);
	glVertex2d(1400, 700);
	glVertex2d(500, 700);
	glEnd();
	glColor4f(1, 1, 1, 0.2);
	glBegin(GL_QUADS);
	glVertex2d(510, 60);
	glVertex2d(1390, 60);
	glVertex2d(1390, 690);
	glVertex2d(510, 690);
	glEnd();

}

//Function to draw the stripped lines use :---glEnable(GL_LINE_STIPPLE); glLineStipple(5, 0xAAAA); 
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2,GLfloat y2) {

	
	glBegin(GL_LINES);
	glVertex2f((x1), (y1));
	glVertex2f((x2), (y2));
	glEnd();
	
}

//Function arc segments
void draw_arc_segment(float x, float y, float radius, float start_angle, float end_angle)
{
	glBegin(GL_LINE_STRIP);
	for (float i = start_angle; i <= end_angle; i += 0.01)
	{
		float x1 = x + radius * cos(i);
		float y1 = y + radius * sin(i);
		glVertex2f(x1, y1);
	}
	glEnd();
}

// Function to draw the circle
void DrawCircle(float cx, float cy, float r, int num_segments)
{
	glDisable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle

		float x = r * cosf(theta);//calculate the x component
		float y = r * sinf(theta);//calculate the y component

		glVertex2f(x + cx, y + cy);//output vertex

	}
	glEnd();
}


//Function to draw the line arrow

void arrow_headed_line(float x1, float y1, float x2, float y2, const char* direc)
{
	if (direc == "left") {

		glBegin(GL_TRIANGLES);
		glVertex2f(x2, y2);
		glVertex2f(x2 - 10, y2 + 5);
		glVertex2f(x2 - 10, y2 - 5);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();

	}
	else {
		glBegin(GL_TRIANGLES);
		glVertex2f(x2, y2);
		glVertex2f(x2 + 10, y2 + 5);
		glVertex2f(x2 + 10, y2 - 5);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();

	}
	
	
	
}



//Function to draw the rounded rectangle
void draw_rounded_rectangle(float x, float y, float width, float height, float radius)
{
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(x + radius, y);
	glVertex2f(x + width - radius, y);
	glVertex2f(x + width, y + radius);
	glVertex2f(x + width, y + height - radius);
	glVertex2f(x + width - radius, y + height);
	glVertex2f(x + radius, y + height);
	glVertex2f(x, y + height - radius);
	glVertex2f(x, y + radius);
	glEnd();
}

//draw plain rectangle
void draw_rectangle(float x, float y, float width, float height)
{

	glBegin(GL_LINE_LOOP);
	glVertex2f(x , y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x , y + height);
	glEnd();
}

//OpenGL FUnction to draw a solid filled rectangle shape 
void solid_rectangle_filled(float x1, float y1, float x2, float y2)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

//OpenGL FUnction to draw a solid filled round curve rectangle shape 

void draw_solid_round_corner_rectangle(float x, float y, float width, float height, float radius)
{
	glBegin(GL_POLYGON);
	glVertex2f(x+radius, y);
	glVertex2f(x + width-radius, y);
	glVertex2f(x + width, y + radius);
	glVertex2f(x + width, y + height-radius);

	glVertex2f(x + width-radius, y+height);
	glVertex2f(x + radius, y+height);
	glVertex2f(x , y + height- radius);
	glVertex2f(x , y + radius);

	glEnd();
}

//Functio to draw file management system
void draw_file_system(float x, float y, float width, float height, float fold)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(x , y);
	glVertex2f(x + width , y);
	glVertex2f(x + width, y + height - fold);
	glVertex2f(x + width - fold, y + height);
	glVertex2f(x , y + height);
	glEnd();
}

//FUnction to draw ellipse
void draw_ellipse(float x, float y, float a, float b, int n)
{
	float theta = 0.0;
	float dtheta = 2 * 3.1415926 / n;
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		x1 = x + a * cos(theta);
		y1 = y + b * sin(theta);
		glVertex2f(x1, y1);
		theta += dtheta;
	}
	glEnd();
}
void draw_solid_ellipse_with_outline(float x, float y, float a, float b, float angle, float outline_width, float outline_color[])
{
	glPushMatrix();
	glTranslatef(x, y, 0.0);
	glRotatef(angle, 0.0, 0.0, 1.0);
	glColor3f(outline_color[0], outline_color[1], outline_color[2]);

	glBegin(GL_LINE_LOOP);
	for (float i = 0; i < 360; i += 0.1)
	{
		float rad = i * 3.14159 / 180;
		glVertex2f(a * cos(rad) + outline_width / 2, b * sin(rad) + outline_width / 2);
	}
	glEnd();
	glColor3f(outline_color[0], outline_color[1], outline_color[2]);
	glBegin(GL_LINE_LOOP);
	for (float i = 0; i < 360; i += 0.1)
	{
		float rad = i * 3.14159 / 180;
		glVertex2f(a * cos(rad), b * sin(rad));
	}
	glEnd();
	glPopMatrix();
}




























//Dispaly Function
void display() {

	glClear(GL_COLOR_BUFFER_BIT); // Make the Dispaly window white


	glRasterPos2i(600, 775);
	printString((char*)"WEBSITE ARCHITECTURE VISUALIZER");

	glEnable(GL_LINE_STIPPLE);
	glColor3f(0.64, 0.17, 1.35);
	glLineStipple(8, 0xAAAA);
	glLineWidth(3.0);
	draw_rounded_rectangle(480, 40, 1480 - 500, 730 - 40, 10);

	//draw user face
	glDisable(GL_LINE_STIPPLE);
	glColor3f(0, 0, 0);
	DrawCircle(240, 600, 50, 100);
	DrawCircle(215, 615, 8, 100);
	DrawCircle(265, 615, 8, 100);
	glColor3f(0, 0, 0);
	draw_arc_segment(240, 600, 25, 3.9, 5.45);

	//draw line to make blank on stripped rectangled
	glLineWidth(5.0);
	glColor3f(1, 1, 1);
	drawLine(480, 500, 480, 700);

	//Draw the arrow connecting user and main server
	glColor3f(0, 0, 0);
	glLineWidth(2.0);

	//switch between user and main server
	glColor3f(0.64, 0.17, 1.35);
	const char* left = "left";
	arrow_headed_line(430.0, 575.0, 530.0, 575.0, left);
	const char* right = "right";
	arrow_headed_line(530, 625, 430, 625, right);


	//user written
	glRasterPos2i(220, 510);
	printString((char*)"USERS");

	//writeen text between connection of user and client
	glRasterPos2i(430, 555);
	printString((char*)"COLLECT DATA");
	glRasterPos2i(430, 635);
	printString((char*)"DISPLAY DATA");

	//rectangle on the server side
	draw_rectangle(600, 350, 300, 350);
	draw_rectangle(1050, 100, 350, 550);   //////////////////////////////////////////////////////////////////////////////////////

	//hidden lines in the server side
	glColor3f(1, 1, 1);
	drawLine(1050, 500, 1050, 600);

	glColor3f(0, 0, 0);
	glRasterPos2i(690, 340 + 100);
	printString((char*)"USER INTERACTS");
	glRasterPos2i(600 + 130, 340 + 80);
	printString((char*)"WITH");
	glRasterPos2i(700, 350 + 50);
	printString((char*)"HTML, CSS, JS");
	glRasterPos2i(720, 350 + 25);
	printString((char*)"[FRONTEND]");


	// arrow head between middle layer and last layer
	glColor3f(0.64, 0.17, 1.35);
	arrow_headed_line(1000 - 50, 533, 1100 + 50, 533, left);
	arrow_headed_line(1100 + 50, 567, 1000 - 50, 567, right);
	//writeen text between connection of user and client
	glRasterPos2i(1010, 580);
	printString((char*)"RESPONSE");
	glRasterPos2i(1010, 513);
	printString((char*)"REQUEST");
	glRasterPos2i(1200, 78);
	printString((char*)"BACKEND");


	//function to draw the file management system
	draw_file_system(1120, 200, 75, 115, 15);
	draw_file_system(1110, 190, 75, 115, 15);
	draw_file_system(1100, 180, 75, 115, 15);
	glColor3f(0, 0, 0);
	glRasterPos2i(1090, 160);
	printString((char*)"FILE SYSTEM");
	glRasterPos2i(1080, 140);
	printString((char*)"HTML CSS IMAGES");


	//draw the database
	float c[] = { 0.64, 0.17, 1.35 };

	glColor3f(0.64, 0.17, 1.35);
	draw_ellipse(1312,230,37,10,200);
	glColor3f(1, 1, 1);
	draw_ellipse(1312, 240, 36, 9, 200);
	draw_solid_ellipse_with_outline(1312, 240, 37, 10, 0, 1, c);

	glColor3f(0.64, 0.17, 1.35);
	draw_ellipse(1312, 250, 37, 10, 200);
	glColor3f(1, 1, 1);
	draw_ellipse(1312, 260, 36, 9, 200);
	draw_solid_ellipse_with_outline(1312, 260, 37, 10, 0, 1, c);

	glColor3f(0.64, 0.17, 1.35);
	draw_ellipse(1312, 270, 37, 10, 200);
	glColor3f(1, 1, 1);
	draw_ellipse(1312, 280, 36, 9, 200);
	draw_solid_ellipse_with_outline(1312, 280, 37, 10, 0, 2, c);

	glColor3f(0, 0, 0);
	glRasterPos2i(1270, 190);
	printString((char*)"DATABASE");
	glRasterPos2i(1245, 170);
	printString((char*)"MYSQL | MARIADB");
	glRasterPos2i(1260, 150);
	printString((char*)"POSTGRESS SQL");

	//CPU at server
	glColor3f(0.64, 0.17, 1.35);
	draw_solid_round_corner_rectangle(1175, 475, 180, 150,3);
	glColor3f(1,1,1);
	draw_solid_round_corner_rectangle(1180, 480, 90, 140, 3);

	//Monitor at client
	glColor3f(0.64, 0.17, 1.35);
	draw_solid_round_corner_rectangle(667, 525, 180, 150, 3);
	glColor3f(1, 1, 1);
	draw_solid_round_corner_rectangle(677, 546, 160, 120, 3);



	glFlush();
}







































//Main Function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1500, 750);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Website Architecture Visualizer");
	init();
	glutDisplayFunc(display);
	glutMainLoop();

}

