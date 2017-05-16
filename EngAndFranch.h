#ifndef ENGANDFRANCH_H
#define ENGANDFRANCH_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

//english -> french
struct EngToFran
{
    std::wstring input, transWord, result;
    std::vector<std::wstring> trans;
    std::map<std::wstring, std::vector<std::wstring>> EToF
    {
        { L"mother", { L"mere" } },
        { L"mothers", { L"meres" } },
        { L"father", { L"pere" } },
        { L"scold", { L"gronder" } }, //ругать + ругают
        { L"scolds", { L"gronde" } }, //ругает
        { L"children", { L"enfants" } },
        { L"ask", { L"demander" } }, //просить + просят
        { L"asks", { L"demandes" } }, //просит
        { L"go", { L"vont" } }, //идти + идут
        { L"goes", { L"va" } }, //идет
        { L"work", { L"travail" } }, //работать + работают
        { L"works", { L"travaille" } }, //работает
        { L"no", { L"non" } },
        { L"without", { L"sans" } },
        { L"and", { L"et" } },
        { L"to", { L"au" } },
        { L"for", { L"pour" } },
        { L"about", { L"sur" } }
    };
    EngToFran();
    std::wstring translation(std::vector<std::wstring>);
};

//french -> english
struct FranToEng
{
    std::wstring input, transWord, predWord;
    std::vector<std::wstring> trans, result;
    std::map<std::wstring, std::vector<std::wstring>> FToE
    {
        { L"mere", { L"mother" } },
        { L"meres", { L"mothers" } },
        { L"pere", { L"father" } },
        { L"gronder", { L"scold" } },
        { L"gronde", {  L"scolds" } },
        { L"enfants", { L"children" } },
        { L"demander", { L"ask" } },
        { L"demandes", { L"asks" } },
        { L"vont", { L"go" } },
        { L"va", { L"goes" } },
        { L"travail", { L"work" } },
        { L"travaille", { L"works" } },
        { L"non", { L"no" } },
        { L"sans", { L"without" } },
        { L"et", { L"and" } },
        { L"au", { L"to" } },
        { L"pour", { L"for" } },
        { L"of", { L"" } },
        { L"sur", { L"abоut" } }
    };

    FranToEng();
    std::vector<std::wstring> translation();
    std::vector<std::wstring> split (std::wstring a, std::wstring b);
};

#endif // ENGANDFRANCH_H
