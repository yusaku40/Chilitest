/****************************************************************************************** 
 *	Chili DirectX Framework Version 12.04.24											  *	
 *	Game.cpp																			  *
 *	Copyright 2012 PlanetChili.net														  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"
#include "Font.h"
#include <iostream>
#include <math.h>


using namespace std;

//Globals(ish)
SYSTEMTIME st;
int oldMs = 1;
int deltaMs = 1;
int fps = 0;
Font font;


Game::Game( HWND hWnd,const KeyboardServer& kServer,const MouseServer& mServer )
:	
	gfx(hWnd),
	audio( hWnd ),
	kbd( kServer ),
	mouse( mServer )
{
	 
}

void Game::Go()
{
	
	GetSystemTime(&st);

	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}
float Game::getPt(int n1, int n2, float perc)
{
	int diff = n2 - n1;

	return n1 + (diff * perc);
}
void Game::DrawBCurve(Vec2 p1, Vec2 pc, Vec2 p2, Color color) {
	float xa, ya, xb, yb,x,y;
	
	//Check whether vertical or horizontal curve and set num loops
	float numPixels;
	if (abs(p1.x - p2.x) >= abs(p1.y - p2.y)) {
		numPixels = 2 * (abs(p1.x - p2.x));
	}
	else {
		numPixels = 2 * (abs(p1.y - p2.y));
	}
	for (float i = 0; i < 1; i += (1/numPixels))
	{
		// The Green Line
		xa = getPt(p1.x, pc.x, i);
		ya = getPt(p1.y, pc.y, i);
		xb = getPt(pc.x, p2.x, i);
		yb = getPt(pc.y, p2.y, i);

		// The Black Dot
		x = getPt(xa, xb, i);
		y = getPt(ya, yb, i);

		gfx.PutPixel((int)round(x),(int)round(y), color);
		
	}
}



void MouseWindow(D3DGraphics& gfx,MouseClient& mouse) {
	int test = mouse.GetMouseX();			/// Get mouse pos X and display in TL corner
	char buffer[10];
	itoa(test, buffer, 10);
	
	Color color = { 100,100,150 };
	font.PrintGlyph(gfx, 'X', 10, 20, color);
	font.PrintGlyph(gfx, ':', 20, 20, color);
	font.PrintGlyph(gfx, buffer[0], 30, 20, color);
	font.PrintGlyph(gfx, buffer[1], 40, 20, color);
	font.PrintGlyph(gfx, buffer[2], 50, 20, color);
	font.PrintGlyph(gfx, buffer[3], 50, 20, color);


	int test2 = mouse.GetMouseY();			/// Get mouse pos X and display in TL corner
	char buffer2[10];
	itoa(test2, buffer2, 10);
	font.PrintGlyph(gfx, 'Y', 10, 40, color);
	font.PrintGlyph(gfx, ':', 20, 40, color);
	font.PrintGlyph(gfx, buffer2[0], 30, 40, color);
	font.PrintGlyph(gfx, buffer2[1], 40, 40, color);
	font.PrintGlyph(gfx, buffer2[2], 50, 40, color);
	font.PrintGlyph(gfx, buffer2[3], 60, 40, color);

	//box in top left
	gfx.DrawLine(0, 50, 70, 50, Color(100, 0, 200));
	gfx.DrawLine(70, 50, 70, 0, Color(100, 0, 200));
}


void PrintS( D3DGraphics& gfx, int sX,int sY, const char* s,Color color) {
	int i = 0;
	for (i = 0; i < strlen(s); i++) {
		if (sX + (i * 10) < 790) {
			font.PrintGlyph(gfx, s[i], sX+(i * 10), sY , color);
		}
	}
	
}

void Game::ComposeFrame()
{
	MouseWindow(gfx, mouse);

	Color color(100, 100, 100);
	PrintS(gfx, 200, 200, "ABCDEFGHIJKLMNOP", color);
	PrintS(gfx, 100, 230, "ABBA WAS HERE", { 0,250,0 });
	
	//fps system parts
	char buffer3[10];
	color = { 200,100,255 };

	GetSystemTime(&st);
	deltaMs = oldMs - st.wMilliseconds;
	
	fps = 1000 / deltaMs;
	itoa(fps, buffer3, 10);
	
	PrintS(gfx, 700, 20, "FPS:", color);
	PrintS(gfx, 750, 20, buffer3, color);
	

	
	oldMs = st.wMilliseconds;

	gfx.DrawLine({ 690,30 }, { 799,30 }, { 150,50,150 });
	gfx.DrawLine({ 690,30 }, { 690,0 }, { 150,50,150 });

}

