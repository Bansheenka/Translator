#ifndef RUSANDENG_H
#define RUSANDENG_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

//russian -> english
struct RusToEng
{
    std::wstring input, transWord, predWord;
    std::vector<std::wstring> result, trans;
    std::map<std::wstring, std::vector<std::wstring>> RToE
    {
        { L"мама", { L"mother" } },
        { L"маме", { L"mother" } }, //дательный и предложный падежи (дать маме, думать о маме)
        { L"маму", { L"mother" } }, //винительный падеж (вижу маму)
        { L"мамой", { L"mother" } }, //творительный падеж (доволен мамой)
        { L"мамы", { L"mother", L"mothers" } }, //родительный падеж (нет мамы) и множественное число
        { L"папа", { L"father" } },
        { L"папу", { L"father" } },
        { L"папе", { L"to father" } },
        { L"ругать", { L"scold" } },
        { L"ругает", { L"scolds" } },
        { L"ругают", { L"scold" } },
        { L"дети", { L"children" } },
        { L"просить", { L"ask" } },
        { L"просят", { L"ask" } },
        { L"просит", { L"asks" } },
        { L"идти", { L"go" } },
        { L"идет", { L"goes" } },
        { L"идем", { L"go" } },
        { L"идут", { L"go" } },
        { L"работать", { L"work" } },
        { L"работает", { L"works" } },
        { L"работают", { L"work" } },
        { L"нет", { L"no" } },
        { L"без", { L"without" } },
        { L"и", { L"and" } },
        { L"о", { L"about" } }
    };
    std::vector<std::wstring> Verbs;
    bool HasVerb;

    RusToEng();
    std::vector<std::wstring> translation();
    bool isVerb(std::wstring);
    std::vector<std::wstring> split (std::wstring a, std::wstring b);
};

//english -> russian
struct EngToRus
{
    std::wstring input, result, transWord, predWord;
    std::vector<std::wstring> trans;
    bool isMulp, HasVerb; // флаги того, что слово во множественноем числе и того, что в предложении уже встречался глагол
    std::vector<std::wstring> MultNumb, ImPad, Verbs; //вектора слов во множественном числе и в именительном падеже и глаголов
    int countImPad; //счетчик слов в именительном падеже (подлежащих)
    std::map<std::wstring, std::vector<std::wstring>> EToR
    {
        { L"mother", { L"мама", L"мамы", L"маме", L"маму", L"мамой", L"маме" } }, //именительный, родительный, дательный, винительный, творительный и предложный падежи
        { L"mothers", { L"мамы" } },
        { L"father", { L"папа", L"папу" } },
        { L"scold", { L"ругать", L"ругают" } },
        { L"scolds", {  L"ругает" } },
        { L"children", { L"дети" } },
        { L"ask", { L"просить", L"просят" } },
        { L"asks", { L"просит" } },
        { L"go", { L"идти", L"идут" } },
        { L"goes", { L"идет" } },
        { L"work", { L"работать", L"работают" } },
        { L"works", { L"работает" } },
        { L"no", { L"нет" } },
        { L"without", { L"без" } },
        { L"and", { L"и" } },
        { L"to", { L"" } },
        { L"for", { L"" } },
        { L"of", { L"" } },
        { L"about", { L"о" } }
    };

    EngToRus();
    std::wstring translation(std::vector<std::wstring>);
    bool IsMultNumb(std::wstring);
    bool IsPodl(std::wstring);
    bool isVerb(std::wstring);
};

#endif // RUSANDENG_H
