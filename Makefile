# <==== Meta Data =====>
NAME	:= philo
CC		:= cc
CFLAGS	:= #-Wall -Werror -Wextra

#Includes
INC_FILES		:= inc

# <==== Files & Folders =====>
MAIN_FILE	:= main.c

SRC_DIR		:= src/
OBJS_DIR	:= objs/

#Folders inside src/
CORE_DIR	:= core/



CORE_FILES	:= $(addprefix $(CORE_DIR), $(addsuffix .c, type_converters)) 


# Every folder path including the .c files inside the src/ folder 
MELTING_POT	:= $(CORE_FILES)


# Every Folder path prefixed with src/ and the main (top level)
SRCS		:= $(MAIN_FILE) $(addprefix $(SRC_DIR), $(MELTING_POT))

# All .c to .o -> See compilation Rule $< $@
OBJS		:= $(addprefix $(OBJS_DIR), $(SRCS:%.c=%.o))



# <===== Rules =====>

all: $(NAME)

#Compile executable including every .o file
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -Iinclude -I$(INC_FILES) -o $(NAME)

#Rule to compile all .o files
$(OBJS_DIR)%.o: %.c | $(OBJS_DIR)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I $(INC_FILES) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@make

.PHONY: all clean fclean re