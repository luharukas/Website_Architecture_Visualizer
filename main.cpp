
#include <GL/glut.h>
#include<stdio.h>
#include "math.h"
#include<string.h>
#include<stdlib.h>
#include<chrono>
#include<thread>
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

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

float text1x = 250;
int timex = 0;

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
	else if (direc=="right") {
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
	else if (direc=="down") {
		glBegin(GL_TRIANGLES);
		glVertex2f(x2, y2);
		glVertex2f(x2 + 5, y2 + 10);
		glVertex2f(x2 - 5, y2 + 10);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
		glEnd();
	}
	else {return;}
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
void draw_solid_rectangle(float x, float y, float width, float height)
{

	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
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
void fixed_frame() {
	glColor3f(0, 0, 0);
	glRasterPos2i(600, 775);
	printString((char*)"WEBSITE ARCHITECTURE VISUALIZER");
	glEnable(GL_LINE_STIPPLE);
	glColor3f(0.64, 0.17, 1.35);
	glLineStipple(8, 0xAAAA);
	glLineWidth(3.0);
	draw_rounded_rectangle(480, 40, 1480 - 500, 730 - 40, 10);
	//draw user face
	glDisable(GL_LINE_STIPPLE);
	glColor3f(0.64, 0.17, 1.35);
	DrawCircle(240, 600, 50, 100);
	DrawCircle(215, 615, 8, 100);
	DrawCircle(265, 615, 8, 100);
	glColor3f(0.64, 0.17, 1.35);
	draw_arc_segment(240, 600, 25, 3.9, 5.45);
	draw_arc_segment(240,500,75,0,3.14/4);
	draw_arc_segment(240, 500, 75,3*3.14/4,3.14);
	glColor3f(0.64, 0.17, 1.35);
	drawLine(240-75	, 500, 240+75,500);
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
	draw_rectangle(1050, 100, 350, 550);   //
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
	draw_ellipse(1312, 230, 37, 10, 200);
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
	draw_solid_round_corner_rectangle(1175, 475, 180, 150, 3);
	glColor3f(1, 1, 1);
	draw_solid_round_corner_rectangle(1180, 480, 90, 140, 3);
	glColor3f(0, 0, 0);
	for (int i = 600; i > 550; i -= 20)
	{
		draw_solid_round_corner_rectangle(1195, i, 60, 7, 2);
	}
	glColor3f(1, 1, 1);
	draw_ellipse(1225, 530, 6, 6, 100);
	draw_solid_ellipse_with_outline(1225, 530, 6, 6, 0, 0.5, c);
	glColor3f(0.64, 0.17, 1.35);
	draw_ellipse(1225, 515, 4, 4, 100);
	glColor3f(0, 0, 0);
	glRasterPos2i(1180, 450);
	printString((char*)"CONTAINS APP LOGIC");
	glRasterPos2i(1205, 430);
	printString((char*)"PYTHON JS PHP");
	glColor3f(0.70196, 0.70196, 0.70196);
	draw_solid_round_corner_rectangle(1180, 360, 120, 50, 0);
	glColor3f(0, 0, 0);
	glRasterPos2i(1190, 380);
	printString((char*)"WEB-SERVERS");
	glColor3f(0, 0, 0);
	arrow_headed_line(1140, 385, 1170, 385, left);
	arrow_headed_line(1140, 385, 1140, 340, "down");
	arrow_headed_line(1340, 385, 1310, 385, right);
	arrow_headed_line(1340, 385, 1340, 340, "down");
	drawLine(1230, 330, 1230, 250);
	drawLine(1250, 330, 1250, 250);
	arrow_headed_line(1230, 250, 1210, 250, right);
	arrow_headed_line(1250, 250, 1270, 250, left);
	//Monitor at client
	glColor3f(0.64, 0.17, 1.35);
	draw_solid_round_corner_rectangle(667, 525, 180, 150, 3);

	glColor3f(0.64, 0.17, 2);
	draw_solid_rectangle(747, 505, 30, 20);
	glColor3f(0, 0, 0);
	draw_solid_round_corner_rectangle(733, 494, 60, 7, 1);
	glColor3f(1, 1, 1);
	draw_solid_round_corner_rectangle(677, 546, 160, 120, 3);
	//Mobile phone design
	glColor3f(0.77, 0, 0.77);
	draw_solid_round_corner_rectangle(800, 500, 75, 100, 2);
	glColor3f(1, 1, 1);
	draw_solid_round_corner_rectangle(805, 515, 65, 80, 2);
}
void draw_processing(int pro);
void draw_tick_mark();
int mon_x = 690, mon_y = 640;
//Dispaly Function
void display() {


	for (int loop = 1; loop <= 10; loop += 1) {
		int i;
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(117/255.0, 6/255.0, 86/255.0);
		char f[] = "RV INSTITUTE OF TECHNOLOGY AND MANAGEMENT";
		glRasterPos2f(525.0, 750.0);
		for (i = 0; f[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, f[i]);

		glColor3f(9/255.0, 237/255.0, 230/255.0);
		char dn[] = "DEPARTMENT OF COMPUTER SCIENCE AND TECHNOLOGY";
		glRasterPos2f(505.0, 700.0);
		for (i = 0; dn[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dn[i]);


		glColor3f(0,0,0);
		char cn[] = "18CSL67 : COMPUTER GRAPHICS AND LABORATORY WITH MINI PROJECT";
		glRasterPos2f(430.0, 600.0);
		for (i = 0; cn[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, cn[i]);


		glColor3f(0, 0, 0);
		char title[] = "TITLE : WEBSITE ARCHITECTURE VISUALIZER";
		glRasterPos2f(520.0, 500.0);
		for (i = 0; title[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, title[i]);


		glColor3f(0.0, 0.0, 0.0);
		char t[] = "DESIGNED BY:";
		glRasterPos2f(200.0, 400.0);
		for (i = 0; t[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, t[i]);

		glColor3f(0.0, 0.0, 0.0);
		char s[] = "1RF19CS050";
		glRasterPos2f(200.0, 350.0);
		for (i = 0; s[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, s[i]);

		glColor3f(0.0, 0.0, 0.0);
		char u[] = "SHUBHAM LUHARUKA";
		glRasterPos2f(350.0, 350.0);
		for (i = 0; u[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, u[i]);

		glColor3f(0.0, 0.0, 0.0);
		char v[] = "1RFCS19009";
		glRasterPos2f(200.0, 300.0);
		for (i = 0; v[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, v[i]);

		glColor3f(0.0, 0.0, 0.0);
		char w[] = "AUTRI ACHARYYA";
		glRasterPos2f(350.0, 300.0);
		for (i = 0; w[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, w[i]);


		glColor3f(0.0, 0.0, 0.0);
		char gu[] = "PROJRCT GUIDE";
		glRasterPos2f(1100.0, 400.0);
		for (i = 0; gu[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gu[i]);

		glColor3f(0.0, 0.0, 0.0);
		char gn[] = "DR. ASHA S MANEK";
		glRasterPos2f(1100.0, 375.0);
		for (i = 0; gn[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, gn[i]);

		glColor3f(0.0, 0.0, 0.0);
		char td[] = "PROJRCT CO-ORDINATOR";
		glRasterPos2f(1100.0, 325.0);
		for (i = 0; td[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, td[i]);

		glColor3f(0.0, 0.0, 0.0);
		char tn[] = "DR. DEEPAK N.A.";
		glRasterPos2f(1100.0, 300.0);
		for (i = 0; tn[i] != '\0'; i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, tn[i]);

		sleep_for(seconds(1));
		glFlush();


	}



	glClear(GL_COLOR_BUFFER_BIT);
	fixed_frame();
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(50, 100);
	printString((char*)"GO TO CONSOLE");
	glFlush();
	int choice;
	printf("Do you want to start the program\n1.Yes\n2.No\n");
	scanf("%d", &choice);
	if (choice == 2) {
		exit(0);
	}
	if (choice != 2 && choice!=1) {
		printf("You gave wrong input\n");
		exit(0);
	}
	for (timex = 0; timex < 5; timex += 0.9) {
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		if (text1x <= 500) {
			text1x += 1;
			glColor3f(0.0, 0.0, 0.0);
			glRasterPos2i(text1x, 600);
			printString((char*)"IOIOIIIOOOIIIIOO");
		}
		if (text1x == 501) {
			break;
		}
		glFlush();}
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos2i(text1x, 600);
		printString((char*)"IOIOIIIOOOIIIIOO");
		sleep_for(seconds(1));
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(mon_x, mon_y);
		printString((char*)"IOIOIOOIIIO");
		sleep_for(seconds(5));
		glRasterPos2i(mon_x, mon_y-20);
		printString((char*)"IOIOIOOIIIO");
		sleep_for(seconds(2));
		glRasterPos2i(807, 570);
		printString((char*)"IOIOI");
		glFlush();
		for (float timer = 0; timer < 500; timer += 0.0001)
		{}
		sleep_for(seconds(3));
		text1x = 850;
		for (timex = 0; timex < 5; timex += 0.5) {
			glClear(GL_COLOR_BUFFER_BIT);
			fixed_frame();
			if (text1x <= 1050) {
				text1x += 0.5;
				glColor3f(0.0, 0.0, 0.0);
				glRasterPos2i(text1x, 555);
				printString((char*)"IOIOIIIOOOII");
				glRasterPos2i(text1x, 535);
				printString((char*)"IOIOIIIOOOII");
			}
			if (text1x == 1050) {
				break;}
			glFlush();
		}

		for (int i = 1; i <=10; i+=1) {
			glClear(GL_COLOR_BUFFER_BIT);
			fixed_frame();
			glColor3f(0, 0, 0);
			glRasterPos2i(1278, 600);
			printString((char*)"PROCESS..");
			draw_processing(i);
			sleep_for(seconds(5));
			glFlush();
		}
	for (float y=350; y > 275; y -= 0.1) {
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2i(1235, y);
		printString((char*)"I");
		glRasterPos2i(1235, y - 15.0);
		printString((char*)"O");
		glRasterPos2i(1235, y - 30.0);
		printString((char*)"I");
		glRasterPos2i(1235, y - 45.0);
		printString((char*)"I");
		if (y < 275) {
			break;
		}
		glFlush();
	}
	for (float i = 0; i < 37; i += 0.1) {
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		glColor3f(0.0, 0.0, 0.0);
		glRasterPos2f(1235-i,250);
		printString((char*)"II");
		glRasterPos2f(1235 + i, 250);
		printString((char*)"OI");
		glFlush();
	}
	for (float i = 0; i < 60; i += 0.05) {
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		if (i >= 0 && i <=20)
			glColor3f(0, 1.0, 0);
		if (i >20 && i<=40)
			glColor3f(1.0, 1.0, 0);
		if (i>40)
			glColor3f(1.0, 0, 0);
	
		draw_solid_rectangle(1362, 225, 15, i);
		glFlush();
	}
	for (float i = 0; i < 30; i += 0.1) {
		glClear(GL_COLOR_BUFFER_BIT);
		fixed_frame();
		glColor3f(12 / 255.0, 97 / 255.0, 53 / 255.0);
		draw_ellipse(1137.5, 237.5, i, i, 50);
		glFlush();
	}
	sleep_for(seconds(1));
	draw_tick_mark();

}
void draw_tick_mark() {
	glClear(GL_COLOR_BUFFER_BIT);
	fixed_frame();
	glColor3f(12 / 255.0, 97 / 255.0, 53 / 255.0);
	draw_ellipse(1137.5, 237.5, 30, 30, 50);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(1137.5-7, 237.5-8);
	glVertex2f(1137.5+20, 237.5+8);
	glVertex2f(1137.5 - 7, 237.5 - 8);
	glVertex2f(1137.5 - 20, 237.5 + 8);
	glEnd();
	sleep_for(seconds(2));
	glColor3f(0.0, 0.0, 0.0);
	glRasterPos2i(60, 120);
	printString((char*)"PROCESS FINISHED");
	glRasterPos2i(80, 100);
	printString((char*)"THANK YOU");
	glFlush();
}
void draw_processing(int pro) {
	int x = 1278, y = 570;
	for (int pro_count = 0; pro_count < pro; pro_count++) {
		if (pro_count % 5 == 0){
			y -= 15;
			x = 1278;
		}
		glColor3f(1.0, 1.0, 0.0);
		draw_ellipse(x, y, 3, 3, 20);
		x = x + 15;
		sleep_for(milliseconds(500));
		if (pro_count == 9) {
			sleep_for(milliseconds(1000));
			glColor3f(0, 0, 0);
			glRasterPos2i(1278, 490);
			printString((char*)"FINISH..");
			sleep_for(seconds(2));

		}}}





//Main Function
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB| GLUT_DEPTH);
	glutInitWindowSize(1500, 750);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Website Architecture Visualizer");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

