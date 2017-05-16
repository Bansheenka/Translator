#include <RusAndEng.h>
#include <EngAndFranch.h>
#include <locale.h>

int main()
{
    setlocale (LC_ALL, ".866");

    std::wstring str = L"";
    std::getline(std::wcin, str);

    RusToEng RE;
    EngToRus ER;
    EngToFran EF;
    FranToEng FE;
    bool b = true;
    std::wstring cont, lang;
    std::vector<std::wstring> eng;
    std::wstring russian, fran;
    while(b)
    {
        std::wcout << "Do you want translate russian or french sentense?" << std::endl;
        std::wcin >> lang;
        if (lang == L"russian")
        {
            std::wcout << "Enter russian sentense" << std::endl;
            eng = RE.translation();
            fran = EF.translation(eng);
            std::wcout << fran << std::endl;
        }
        if (lang == L"french")
        {
            std::wcout << "Enter french sentense" << std::endl;
            eng = FE.translation();
            russian = ER.translation(eng);
            std::wcout << russian;
        }
        std::wcout << std::endl << "If you want to leave enter 'exit' and something else if you don't" << std::endl;
        std::wcin >> cont;
        if (cont == L"exit")
            b = false;
    }

    return 0;
}
