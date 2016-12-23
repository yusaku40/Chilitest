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
	Font font;
	Color color(100, 100, 100);

	for (int i=0; i < 10; i++) {					//just putpixel test
		gfx.PutPixel(100 + i, 100, 100, 0, 255);
		gfx.PutPixel(100 , 100 + i, 100, 0, 255);
	}

	font.PrintGlyph(gfx,'A', 200, 200, color);		//fonttest 1
	font.PrintGlyph(gfx,'B', 210, 200, color);
	font.PrintGlyph(gfx, 'C', 220, 200, color);
	font.PrintGlyph(gfx, 'D', 230, 200, color);
}