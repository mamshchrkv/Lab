
#pragma once
template<typename TK, typename TV>
class IDictionary {
public:
    //методы
    virtual bool ContainsKey(TK Key) = 0; //Проверка на существование ключа в словаре;
    virtual TV Get(TK key) = 0;
    virtual int GetSize()  = 0;//получает размер
    virtual void Add(TK key, TV val) = 0;//Добавляет элемент в конец списка
    virtual void Print() = 0;//выводит
    virtual TK* GetKeys() = 0;
    virtual TV* GetValues() = 0;
    virtual ~IDictionary() = default;
};
