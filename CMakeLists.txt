cmake_minimum_required(VERSION 3.6)
project(ft_printf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(libft)

add_executable(ft_printf
        basic_lists.c
        conversion.c
        create_array.c
        flags_handle.c
        ft_printf.c
        ft_printf.h
        helpers.c
        parse_args.c
        validate_fun.c
        principal_functions.c
        wap.c)
