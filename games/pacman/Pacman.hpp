//
// Pacman.hpp for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade/games/pacman
// 
// Made by Simon
// Login   <erwan.simon@epitech.eu>
// 
// Started on  Mon Apr  3 15:01:55 2017 Simon
// Last update Sat Apr  8 16:16:50 2017 Simon
//

#ifndef PACMAN_HPP_
# define PACMAN_HPP_

#include "../include/IGame.hpp"
#include "Ghost.hpp"

class	Pacman : public IGame {
public:
  Pacman(int width, int height);
  ~Pacman();
  
  // Getters
  virtual struct arcade::WhereAmI&	_whereAmI() const;
  virtual struct arcade::GetMap&	_getMap() const;
  virtual int				_getScore() const;
  Ghost const &				_getGhost() const;
  
  virtual void				_setHeading(IGraphic::e_key key);

  // Input
  virtual void				_move(IGraphic::e_key);
  void					_evilMove();

  // the game
  virtual IGame::e_end			_graphPlay();
  virtual IGame::e_end			_gameOver();

  virtual void				_initMap();
  virtual void				_initPosition();

private:
  Ghost *				_ghost;
  struct arcade::GetMap			*_map;
  struct arcade::WhereAmI		*_position;
  IGraphic::e_key			_initial_heading;
  IGraphic::e_key			_heading;
  int					_score;
};

#endif
