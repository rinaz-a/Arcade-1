//
// Pacman.cpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 14:51:47 2017 Simon
// Last update Tue Apr  4 17:01:48 2017 Simon
//

#include "../../Launcher.hpp"
#include "../../graphic/IGraphic.hpp"
#include "../include/Protocol.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include "Pacman.hpp"

struct arcade::WhereAmI&		Pacman::_whereAmI() const
{
  return (*this->_position);
}

struct arcade::GetMap&		Pacman::_getMap() const
{
  return (*this->_map);
}

void		Pacman::_move(IGraphic::e_key)
{

}

void		Pacman::_getKey(IGraphic::e_key)
{

}

void		Pacman::Play()
{
  
}

void		Pacman::_pause()
{

}

void		Pacman::_gameOver(IGame::e_end)
{
  
}

static std::string&	getFile()
{
  struct stat		stat;
  int			rc = stat("./games/pacman/map.txt", &sta);
  std::string		line;
  std::string*		res = new std::string;

  if (rc == 0 || (statst_size != 1639 && stat.st_size != 1640))
    {
      std::cerr << "A problem occured with map.txt" << std::endl;
      exit(84);
    }
  ifstream myfile("./games/pacman/map.txt");
  while (getline(myfile, line))
    res << line;
  myfile.close();
  std::cout << res << std::endl;
  return (res);
}

void		Pacman::_initMap()
{
  int		total = (this->_map->width * this->_map->height * sizeof(arcade::TileType));
  int		i = 0;
  int		save = 0;
  std::string	*map;

  if ((map = getFile()) == NULL)
    exit(84);
  while (i < total)
    {
      if (map->at(i) == '1')
	this->_map->tile[i] = static_cast<arcade::TileType>(1); //BLOCK
      else if (map->at(i) == '0')
	this->_map->tile[i] = static_cast<arcade::TileType>(0);  //EMPTY
      else
	{
	  std::cerr << "map.txt contains some illegal caracters" << std::endl;
	  exit(84);
	}
      i = i + 1;
    }
}

Pacman::Pacman(int width, int height, Launcher& launcher)
{
  int	total = (width * height * sizeof(arcade::TileType));

  this->_launch = &launcher;
  this->_map = (struct arcade::GetMap *) malloc(sizeof (struct arcade::GetMap) + total);
  this->_map->width = width;
  this->_map->height = height;
  std::cout << "map->width == " << width << " | map->height == "
	    << height << " | total == "<< total <<std::endl;  
  this->_initMap();
}
