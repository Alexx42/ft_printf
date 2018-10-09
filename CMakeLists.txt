cmake_minimum_required(VERSION 3.6)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)

add_executable(ft_printf
        libft/ft_atoi.c
        libft/ft_bzero.c
        libft/ft_isalnum.c
        libft/ft_isalpha.c
        libft/ft_strrchr.c
        libft/ft_strrev.c
        libft/ft_strsplit.c
        libft/ft_strstr.c
        libft/ft_strsub.c
        libft/ft_strtrim.c
        libft/ft_tolower.c
        libft/ft_toupper.c
        libft/libft.h
        basic_lists.c
        conversion.c
        create_array.c
        flags_handle.c
        ft_printf.c
        ft_printf.h
        helpers.c
        parse_args.c
        validate_fun.c
        wap.c)
