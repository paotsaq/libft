NAME	= libft.a

CC		= gcc
CFLAGS	= -g -Wall -Wextra -Werror

SRCS	=	ft_memset.c			\
			ft_bzero.c			\
			ft_memcpy.c			\
			ft_memccpy.c		\
			ft_memmove.c		\
			ft_memchr.c			\
			ft_memcmp.c			\
			ft_strlen.c			\
			ft_strlcpy.c		\
			ft_strlcat.c		\
			ft_strtoupper.c		\
			ft_strchr.c			\
			ft_strrchr.c		\
			ft_strnstr.c		\
			ft_strncmp.c		\
			ft_atoi.c			\
			ft_isalpha.c		\
			ft_isdigit.c		\
			ft_isalnum.c		\
			ft_isascii.c		\
			ft_isprint.c		\
			ft_inbetween.c		\
			ft_toupper.c		\
			ft_tolower.c		\
			ft_calloc.c			\
			ft_strdup.c			\
			ft_substr.c			\
			ft_strjoin.c		\
			ft_strtrim.c		\
			ft_split.c			\
			ft_itoa.c			\
			ft_strmapi.c		\
			ft_putchar_fd.c		\
			ft_putstr_fd.c		\
			ft_putendl_fd.c		\
			ft_putnbr_fd.c		\
			ft_max.c			\
			ft_min.c			\
			ft_strrev.c			\
			ft_atof.c			\
			ft_abs.c			\
			ft_check_for_positive_integer.c			\
			ft_content_is_int.c	\
			ft_reallocates_memory.c	\
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstclone.c \

HDRS = libft.h
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
SRCDIR = ./src
OBJDIR = ./obj


ARRC	= ar rcs
RM		= rm -f


all:		${NAME}

$(NAME):	${OBJS} $(OBJDIR)/get_next_line.o
			${ARRC} ${NAME} ${OBJS}

$(OBJDIR)/get_next_line.o: $(SRCDIR)/get_next_line.c	
			${CC} ${CFLAGS} -D BUFFER_SIZE=1000 -I. -o $(OBJDIR)/get_next_line.o -c $(SRCDIR)/get_next_line.c 

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -I. -o $@ -c $<

clean:
			${RM} ${OBJS} $(OBJDIR)/get_next_line.o ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:	${OBJS} ${BONUS_OBJS}
			${ARRC} ${NAME} ${OBJS} ${BONUS_OBJS}

.PHONY: all gnl
