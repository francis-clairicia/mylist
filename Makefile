##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

include		lib/mylist/config.mk

SRC_MAIN			=	src/main.c

SRC_PROJECT			=	$(addprefix ./lib/mylist/, $(SRC_LIB))

SRC					=	$(SRC_MAIN)

SRC_TESTS			=	./tests/test_generic_list.c		\
						./tests/test_ptr_list.c			\
						./tests/test_string_list.c		\
						./tests/test_node_iterator.c

CFLAGS				=	-W -Wall -Wextra

CPPFLAGS			=	-I./lib/mylist/

LIBS				=	mylist

LIBS_DIR			=	./lib

override LDFLAGS	+=	$(addprefix -L, $(LIBS_DIR))

override LDLIBS		+=	$(addprefix -l, $(LIBS))

OBJ					=	$(SRC:.c=.o)

override NAME		=	libmylist

all:	$(NAME)

$(NAME):	CFLAGS += -O2
$(NAME):	$(LIBS) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

$(LIBS):
	$(MAKE) -C $(LIBS_DIR)/$@

tests_run:	CPPFLAGS +=  -I./tests
tests_run:	CFLAGS += --coverage
tests_run:	LDLIBS += -lcriterion
tests_run:	$(LIBS)
	@find -name "*.gc*" -delete
	$(CC) -o unit_tests $(SRC_PROJECT) $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	./unit_tests --verbose --always-succeed
	$(RM) unit_tests test*.gc* unit_tests-test*.gc*
	mkdir -p coverage
	mv *.gc* coverage/

coverage:
	@gcovr --exclude tests/
	@gcovr --branches --exclude tests/

debug:	CFLAGS += -g
debug:	$(LIBS)
	$(CC) -o $(NAME) $(SRC_MAIN) $(SRC_PROJECT) $(CFLAGS) $(CPPFLAGS)

clean:
	$(RM) $(OBJ)
	$(RM) debug unit_tests *.gc*

fclean:	clean
	$(RM) $(NAME)
	for lib in $(LIBS); do $(MAKE) -C $(LIBS_DIR)/$$lib fclean; done;

re::	fclean
re::	all

.PHONY:	all $(LIBS) tests_run coverage debug clean fclean re
