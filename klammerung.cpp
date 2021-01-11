//
// Created by Xuantong Pan on 2021/1/11.
//
#include <unordered_map>
#include "Stapel.h"
#include "projekt15.h"

bool klammerung(ifstream &datei)
{
    Stapel<char> stapel;
    Stapel<char> ascii;
    bool asc = false; // fuer ASCII-Zeichen
    unordered_map<char, char> klammer
    {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'},
    };
    bool kom = false; // Kommentarmodus
    string ka = ""; // Kommentaranfang
    string ke = ""; // Kommentarende
    char c;
    datei >> noskipws;
    while (datei >> c) //lese aus datei ein weiteres Zeichen aus
    {

        /*** behandle ASCII-Zeichen ***/
        if (c == '"' || c == '\'')
        {
            if (!ascii.empty())
            {
                char top = ascii.top();
                if (top == c)
                {
                    ascii.pop();
                    asc = false;
                } else
                    ascii.push(c);
            }
            else
            {
                ascii.push(c);
                asc = true;
            }
        }
        if (asc)
            continue;

        /*** behandle Kommentare ***/
        if (!kom) // kein Kommentarmodus ist an
        {
            if (c == '/' || c == '*')
            {
                ka += c;
                if (ka == "//" || ka == "/*")
                    kom = true;
            }
            else
                ka.clear();
        }
        else if (c == '/' || c == '*' || c == '\n')
        {
            if (c == '\n' && ka == "//")
            {
                ka.clear();
                kom = false;
                ke.clear();
            }
            else
            {
                ke += c;
                if (ke == "*/" && ka == "/*")
                {
                    kom = false;
                    ka.clear();
                    ke.clear();
                }
                if (ke.size() == 2)
                    ke.erase(ke.begin());
            }
        }
        else
            ke.clear();

        if (kom)
            continue;

        /*** behandle oeffnende Klammerung ***/
        if (c == '(' || c == '[' || c == '{')
            stapel.push(c);
        /*** behandle schließende Klammerung ***/
        if (c == ')' || c == ']' || c == '}')
        {
            if (stapel.empty())
            {
                cout << "schliessende Klammer zuviel! " << c << endl;
                return false;
            }
            char oK = stapel.top();
            if (klammer[oK] != c)
            {
                cout << "falsches Klammerpaar " << c << endl;
                return false;
            } else
                stapel.pop();
        }
    }
    /*** prufe, ob alle Klammern geschlossen wurden ***/
    if (!stapel.empty())
    {
        cout << "zuviele oeffnende Klammern!" << endl;
        return false;
    }
    return true;
}

