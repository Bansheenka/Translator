#include "EngAndFranch.h"

//english -> french
EngToFran::EngToFran()
{}

std::wstring EngToFran::translation(std::vector<std::wstring> inp)
{
    result.clear();
    for (int i = 0; i < inp.size(); ++i)
    {
        input = inp[i];
        if (input == L".")
        {
            result.append(L".");
            return result;
        }
        else
        {
            try
            {
                trans = EToF.at(input);
                transWord = trans[0];
            }
            catch (const std::out_of_range &)
            {
                transWord = input;
            }
            result.append(transWord);
            result.append(L" ");
        }
    }
}

//french -> english
FranToEng::FranToEng()
{}
std::vector<std::wstring> FranToEng::split(std::wstring a, std::wstring b)
{
    std::vector<std::wstring> r;
    int i = 0;
    while (i != -1)
    {
        i = a.find(b);
        r.push_back(a.substr(0, i));
        a = a.substr(i+b.size(), a.size());
    }
    return r;
}

std::vector<std::wstring> FranToEng::translation()
{
    result.clear();
    std::getline(std::wcin, input);
    std::wstring delimiter = L" ";
    std::vector<std::wstring> tokens = split(input, delimiter);
    for (int i = 0; i < tokens.size(); ++i)
    {
        try
        {
            trans = FToE.at(tokens[i]);
            transWord = trans[0];
        }
        catch (const std::out_of_range &)
        {
            transWord = tokens[i];
        }
        result.push_back(transWord);
     }
}

