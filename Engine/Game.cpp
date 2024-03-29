/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
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
#include "MainWindow.h"
#include "Game.h"
#include "Vec2.h"
#include "SpriteEffect.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	monkey( Vec2(100, 100), "Images/monkey50x50.bmp")
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	float elapsedTime = ft.Mark();
	while (elapsedTime > 0.0f)
	{
		const float dt = std::min(0.01f, elapsedTime);
		UpdateModel(dt);
		elapsedTime -= dt;
	}
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel(float  dt)
{
	Vec2 dir = { 0.0f, 0.0f };
	if (wnd.kbd.KeyIsPressed('A'))
	{
		dir += {-1.0f, 0.0f};
	}
	if (wnd.kbd.KeyIsPressed('D'))
	{
		dir += {1.0f, 0.0f};
	}
	if (wnd.kbd.KeyIsPressed('W'))
	{
		dir += {0.0f, -1.0f};
	}
	if (wnd.kbd.KeyIsPressed('S'))
	{
		dir += {0.0f, 1.0f};
	}

	monkey.SetDirection(dir);
	monkey.Update(dt, enemy, wnd.kbd);
}

void Game::ComposeFrame()
{
	monkey.Draw(gfx);
}
