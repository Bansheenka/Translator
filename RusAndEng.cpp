#include "RusAndEng.h"

//russian -> english
RusToEng::RusToEng()
{
    Verbs.push_back(L"ругать");
    Verbs.push_back(L"ругает");
    Verbs.push_back(L"ругают");
    Verbs.push_back(L"просить");
    Verbs.push_back(L"просят");
    Verbs.push_back(L"просит");
    Verbs.push_back(L"идти");
    Verbs.push_back(L"идет");
    Verbs.push_back(L"идем");
    Verbs.push_back(L"идут");
    Verbs.push_back(L"работать");
    Verbs.push_back(L"работает");
    Verbs.push_back(L"работают");
}

std::vector<std::wstring> RusToEng::split(std::wstring a, std::wstring b)
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

std::vector<std::wstring> RusToEng::translation()
{
    HasVerb = false;
    result.clear();

    std::string str = "";
    std::getline(std::cin, str);
//    std::getline(std::wcin, input);
    std::wstring delimiter = L" ";
    std::vector<std::wstring> tokens = split(input, delimiter);

    for (int i = 0; i < tokens.size(); ++i)
    {
        try
        {
            trans = RToE.at(tokens[i]);
            transWord = trans[0];
            if (HasVerb && isVerb(tokens[i]))
                result.push_back(L"to");
            if (trans.size() > 1 && !(predWord == L"нет" || predWord == L"без")) // родительный падеж/множественное число
                transWord = trans[1];
            if (isVerb(tokens[i]))
                HasVerb = true;
        }
        catch (const std::out_of_range &)
        {
            transWord = tokens[i];
        }
        result.push_back(transWord);
        predWord = tokens[i];
    }
}

bool RusToEng::isVerb(std::wstring word)
{
    for (int i = 0; i < Verbs.size(); ++i)
    {
        if (Verbs[i] == word)
            return true;
        else if (Verbs[i] != word && i < Verbs.size() - 1)
            continue;
        else if (i == Verbs.size() - 1 && Verbs[i] != word)
            return false;
    }
}

//english -> russian
EngToRus::EngToRus()
{
    MultNumb.push_back(L"children");
    MultNumb.push_back(L"mothers");

    ImPad.push_back(L"mother");
    ImPad.push_back(L"father");
    ImPad.push_back(L"son");

    Verbs.push_back(L"scold");
    Verbs.push_back(L"scolds");
    Verbs.push_back(L"ask");
    Verbs.push_back(L"asks");
    Verbs.push_back(L"go");
    Verbs.push_back(L"goes");
    Verbs.push_back(L"work");
    Verbs.push_back(L"works");

}

bool EngToRus::IsMultNumb(std::wstring word)
{
    for (int i = 0; i < MultNumb.size(); ++i)
    {
        if (MultNumb[i] == word)
            return true;
        else if (MultNumb[i] != word && i < MultNumb.size() - 1)
            continue;
        else if (i == MultNumb.size() - 1 && MultNumb[i] != word)
            return false;
    }
}

bool EngToRus::IsPodl(std::wstring word)
{
    for (int i = 0; i < ImPad.size(); ++i)
    {
        if (ImPad[i] == word)
            return true;
        else if (ImPad[i] != word && i < ImPad.size() - 1)
            continue;
        else if (i == ImPad.size() - 1 && ImPad[i] != word)
            return false;
    }
}

bool EngToRus::isVerb(std::wstring word)
{
    for (int i = 0; i < Verbs.size(); ++i)
    {
        if (Verbs[i] == word)
            return true;
        else if (Verbs[i] != word && i < Verbs.size() - 1)
            continue;
        else if (i == Verbs.size() - 1 && Verbs[i] != word)
            return false;
    }
}

std::wstring EngToRus::translation(std::vector<std::wstring> inp)
{
    countImPad = 0;
    HasVerb = false;
    isMulp = false;
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
                trans = EToR.at(input);
                transWord = trans[0];
                if (IsMultNumb(input))
                    isMulp = true;
                if (IsPodl(input) && !HasVerb)
                    countImPad++;
                if (trans.size() > 1 && isVerb(input) && !HasVerb && (isMulp || countImPad > 1))
                    transWord = trans[1];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb)
                    transWord = trans[1];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb && (predWord == L"no" || predWord == L"without")) //родительный падеж
                    transWord = trans[1];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb && predWord == L"to") //дательный падеж (give to)
                    transWord = trans[2];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb && predWord == L"for") //винительный падеж (looking for)
                    transWord = trans[3];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb && predWord == L"of") //творительный падеж (proud of)
                    transWord = trans[4];
                if (trans.size() > 1 && !(isVerb(input)) && HasVerb && predWord == L"about") //предложный падеж (think about)
                    transWord = trans[5];
                if (isVerb(input))
                    HasVerb = true;
            }
            catch (const std::out_of_range &)
            {
                transWord = input;
            }
            result.append(transWord);
            result.append(L" ");
        }
        predWord = input;
    }
}
