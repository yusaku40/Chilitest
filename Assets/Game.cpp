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
using namespace std;

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
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{
	Color mColor(150, 0, 150);
	Font font;
	Color color(100, 100, 100);

	if (mouse.LeftIsPressed()) {
		font.PrintGlyph(gfx, 'A', 150, 100, color);
		gfx.PutPixel(mouse.GetMouseX(), 100, color);
		//gfx.PutPixel(mouse.GetMouseX(), mouse.GetMouseY(), mColor.r, mColor.g, mColor.b);
	}else{ font.PrintGlyph(gfx, 'B', 150, 100, color); }
	
	Color color2(255, 0, 255);
	gfx.PutPixel(300, 100, color2);  //test PutPixel overload

	font.PrintGlyph(gfx,'A', 200, 200, color);		//fonttest 1
	font.PrintGlyph(gfx,'B', 209, 200, color);
	font.PrintGlyph(gfx, 'C', 218, 200, color);
	font.PrintGlyph(gfx, 'D', 226, 200, color);
	font.PrintGlyph(gfx, '0', 100, 100, color);

	int test=mouse.GetMouseX();			/// Get mouse pos X and display in TL corner
	char buffer[10];
	itoa(test, buffer, 10);
	font.PrintGlyph(gfx, 'X',	    10, 20, color);
	font.PrintGlyph(gfx, ':',	    20, 20, color);
	font.PrintGlyph(gfx, buffer[0], 30, 20, color);
	font.PrintGlyph(gfx, buffer[1], 40, 20, color);
	font.PrintGlyph(gfx, buffer[2], 50, 20, color);
	font.PrintGlyph(gfx, buffer[3], 50, 20, color);

	test = mouse.GetMouseY();			/// Get mouse pos X and display in TL corner
	char buffer2[10];
	itoa(test, buffer2, 10);
	font.PrintGlyph(gfx, 'Y',	    10, 40, color);
	font.PrintGlyph(gfx, ':',	    20, 40, color);
	font.PrintGlyph(gfx, buffer[0], 30, 40, color);
	font.PrintGlyph(gfx, buffer[1], 40, 40, color);
	font.PrintGlyph(gfx, buffer[2], 50, 40, color);
	font.PrintGlyph(gfx, buffer[3], 50, 40, color);
}