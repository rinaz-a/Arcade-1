/*
** IGraphic.hpp for IGraphic in /home/selimrinaz/repo/tek2/B4-CPP/cpp_arcade/lib/liblapin
** 
** Made by Selim Rinaz
** Login   <selimrinaz@epitech.net>
** 
** Started on  Wed Mar 29 15:05:04 2017 Selim Rinaz
// Last update Tue Apr  4 15:03:25 2017 Simon
*/

#ifndef IGRAPHIC_HPP_
# define IGRAPHIC_HPP_

#include <iostream>
#include <string>
#include <array>

class		IGraphic
{
public:
  typedef enum {
    E_BLACK,
    E_WHITE,
    E_YELLOW,
    E_RED,
    E_BLUE,
    E_PINK,
    E_GREEN
  }			e_color;

  typedef enum {
    E_NONE = -1,
    E_LEFT = 0,
    E_RIGHT,
    E_UP,
    E_DOWN,
    E_2,
    E_3,
    E_4,
    E_5,
    E_8,
    E_9,
    E_ESC,
    E_ENT
  }			e_key;

  // Window
  virtual int		openWindow(int x, int y) = 0;
  virtual int		refreshWindow() = 0;
  virtual int		clearWindow() = 0;
  virtual int		closeWindow() = 0;
  virtual e_key		getKey() = 0;

  // Draw
  virtual int		writeStuff(int x, int y, std::string& text) = 0;
  virtual int		buildCell(int x, int y, e_color col) = 0;
};

#endif
