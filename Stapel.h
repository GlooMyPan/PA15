//
// Created by Xuantong Pan on 2021/1/9.
//

#ifndef PA15_STAPEL_H
#define PA15_STAPEL_H

#include <iostream>
#include <valarray>
using namespace std;

template<class T>
class Stapel
{
private:
    valarray<T> _data; // alle Eintraege
    size_t _size; // Hoehe des Stapels

    static int const _MIN_LAENGE = 4;


public:

    /*** Standardkonstruktor ***/
    Stapel()
    {
        _data.resize(_MIN_LAENGE);
        _size = 0;
    }
    /*** get-Methode ***/
    bool empty() const
    {
        return _size == 0;
    }
    size_t size() const
    {
        return _size;
    }
    T const& top() const
    {
        if (empty())
            throw "Data is out of range!";
        else
            return _data[_size-1];
    }
    /*** set-Methode ***/
    void clear()
    {
        _size = 0;
    }
    T const& pop ()
    {
        if (empty())
            throw "Data is out of range!";
        else
            return _data[_size-- - 1];

    }

    void push(T const& obj)
    {
        if (_size == _data.size())
        { // falls das Array bereits voll sein
            valarray<T> temp(_data.size()*2); // dpppelte Laenge
            for (int i = 0; i < _data.size(); ++i)
            { //alten Eintraege ergalten
                temp[i] = _data[i];
            }
            temp[_data.size()] = obj;
            _data = temp;
        } else
            _data[_size] = obj;
        ++_size;
    }

    friend
    ostream& operator << (ostream& ostr, Stapel const& sta)
    {
        ostr << "[" << sta.size() << "]";
        for (int i = 0; i < sta.size(); ++i)
            ostr << " " << sta._data[i];

        return ostr;
    };


};

#endif //PA15_STAPEL_H
