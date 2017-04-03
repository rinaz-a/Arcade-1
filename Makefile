##
## Makefile for arcade in /home/erwan/Code/teck/Cpp/cpp_arcade
## 
## Made by Simon
## Login   <erwan.simon@epitech.eu>
## 
## Started on  Thu Mar 30 11:17:19 2017 Simon
## Last update Mon Apr  3 13:27:27 2017 Simon
##

NAME_EXE	= arcade
SRCS_EXE	= ./Launcher.cpp	\
		  ./main.cpp
OBJS_EXE	= $(SRCS_EXE:.cpp=.o)

NAME_NC		= ./lib/lib_arcade_ncurses.so
SRCS_NC		= ./lib/ncurses/myNcurses.cpp
OBJS_NC		= $(SRCS_NC:.cpp=.o)

NAME_SF		= ./lib/lib_arcade_sfml.so
SRCS_SF		= ./lib/sfml/mySfml.cpp
OBJS_SF		= $(SRCS_SF:.cpp=.o)

# NAME_LA		= ./lib/lib_arcade_lapin.so
# SRCS_LA		= ./lib/lapin/myLibLapin.cpp
# OBJS_LA		= $(SRCS_LA:.cpp=.o)

CXXFLAGS	+= -Wall -Wextra -fPIC -std=c++11 -Igraphic -g -g3
LDFLAGS		+= -ldl							\
		   # -L/home/${USER}/.froot/lib/ -llapin			\
		   # -L/usr/local/lib					\
		   # -lm							\
		   # -I../../graphic/ -I/home/${USER}/.froot/include/

CXX		= g++
RM		= rm -f

all:		$(NAME_EXE) $(NAME_NC) $(NAME_SF) # $(NAME_LA)

$(NAME_EXE):	$(OBJS_EXE)
		$(CXX) -o $(NAME_EXE) $(OBJS_EXE) $(LDFLAGS)

$(NAME_NC):	$(OBJS_NC)
		$(CXX) -shared -o $(NAME_NC) $(OBJS_NC) -lncurses

$(NAME_SF):	$(OBJS_SF)
		$(CXX) -shared -o $(NAME_SF) $(OBJS_SF) -lsfml-graphics -lsfml-window -lsfml-system

$(NAME_LA):	$(OBJS_LA)
		$(CXX) -shared -o $(NAME_LA) $(OBJS_LA) -lsfml-graphics -lsfml-window -lsfml-system

clean:
		$(RM) $(OBJS_EXE) $(OBJS_NC) $(OBJS_SF) $(OBJS_LA)

fclean: 	clean
		$(RM) $(NAME_EXE) $(NAME_NC) $(NAME_SF) $(NAME_LA)

re:		fclean all

.PHONY:		all clean fclean re
