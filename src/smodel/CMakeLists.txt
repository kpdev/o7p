# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# Установка переменной со списком исходников
set(SOURCE_LIB 
    # headers
    const.h
    context.h
    creator.h
    import.h
    instruction.h
    module.h
    operand.h
    procedure.h
    type.h
    variable.h
    
    #sources
    const.cpp
    context.cpp
    creator.cpp
    import.cpp
    instruction.cpp
    module.cpp
    operand.cpp
    procedure.cpp
    type.cpp
    variable.cpp
)

add_library(smodel STATIC ${SOURCE_LIB})   # Создание статической библиотеки
