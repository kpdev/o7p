#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>

#include "context.h"

// Класс, задающий обобщение для всех типов языка
class TypeContext: public Context {
public:
    // Получение размера типа
    int getTypeSize() { return typeSize; }

    // Вывод отладочной информации о базовом типе
    virtual void debugOut();
protected:
    // Размер типа
    int typeSize;
};

// Класс, определяющий булевский тип
class TypeBoolContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypeBoolContext() {
        typeSize = sizeof(bool);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

// Класс, определяющий целочисленный тип
class TypeIntegerContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypeIntegerContext() {
        typeSize = sizeof(int);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

// Класс, определяющий действительный тип
class TypeRealContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypeRealContext() {
        typeSize = sizeof(double);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

// Класс, определяющий символьный тип
class TypeCharContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypeCharContext() {
        typeSize = sizeof(char);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

// Класс, определяющий множественный тип
class TypeSetContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypeSetContext() {
        typeSize = sizeof(unsigned);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
};

// Класс, определяющий тип "запись"
class TypeRecordContext: public TypeContext {
public:
    // Создание оболочки типа и задание его контекста
    TypeRecordContext(TypeRecordContext* p = nullptr): parentContext(p) {
        typeSize = 0;
    }

    // Добавление к записи именованного поля
    void AddNamedModuleField(std::string name, TypeContext* typeContext, bool access = true);

    // Вывод отладочной информации о записи
    virtual void debugOut();
private:
    // Родительский контекст (если присутствует, иначе nullptr)
    TypeRecordContext* parentContext;
    // Список именованных типов записи, объявленной в модуле
    std::vector<NamedArtefact> namedFields;
};

// Класс, определяющий тип - указатель
class TypePointerContext: public TypeContext {
public:
    // Создание типа и определение его размера
    TypePointerContext(TypeRecordContext* r = nullptr): recordType(r) {
        typeSize = sizeof(int*);
    }

    // Вывод отладочной информации о типе
    virtual void debugOut();
private:
    TypeRecordContext* recordType;    // указатель ссылается только на запись
};

#endif // TYPE_H
