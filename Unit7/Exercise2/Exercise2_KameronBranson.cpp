/**
 * @file Exercise2_KameronBranson.cpp
 * @author Kameron Branson
 * @date 2026-11-22
 * @brief Translator app with implemented encoder/decoder of English to Morse Code
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;

/**
 * @brief
 * @public
 */

class Translator
{
public:
    virtual void translate(string &input) {}
protected:
    virtual ~Translator() = default;

};

class MorseCodeEncoder : public Translator
{
public:
    MorseCodeEncoder() : Translator()
    {

    };

    void translate(string &input) override
    {
        cout << toMorseCode(input) << endl;
    };

private:
    std::vector<std::vector<string>> englishDictionary = {
        {"A", ".-"},   {"B", "-..."}, {"C", "-.-."}, {"D", "-.."},
        {"E", "."},    {"F", "..-."}, {"G", "--."},  {"H", "...."},
        {"I", ".."},   {"J", ".---"}, {"K", "-.-"},  {"L", ".-.."},
        {"M", "--"},   {"N", "-."},   {"O", "---"},  {"P", ".--."},
        {"Q", "--.-"}, {"R", ".-."},  {"S", "..."},  {"T", "-"},
        {"U", "..-"},  {"V", "...-"}, {"W", ".--"},  {"X", "-..-"},
        {"Y", "-.--"}, {"Z", "--.."}
    };


    void englishToUpperCase(string &input)
    {
        for (char &s: input)
        {
            s = toupper(s);
        }
    };

    string toMorseCode(string &input)
    {
        string result = "";
        englishToUpperCase(input);

        for (char c : input)
        {
            bool match = false;

            for (std::vector<string> s: englishDictionary)
            {
                for (string r : s)
                {
                    for (string r2: s)
                    {
                        if (c == r2[0])
                        {
                            result = result + r2[1] + "\n";
                        } else
                        {
                            result += "";
                        }
                    }
                }
            }

        }
        return result;
    }

};

class TranslationApp
{
public:
    TranslationApp()
    {
        menuSelection = nullptr;
        sourceText = nullptr;
        translator = nullptr;
    }
    ~TranslationApp()
    {
        delete menuSelection;
        delete sourceText;
        menuSelection = nullptr;
        sourceText = nullptr;
    }
    void app()
    {
        while (!menuSelection)
        {
            setMenuSelection();

            if (*menuSelection == 2)
            {
                break;

            } else
            {
                setSourceText();
                if (*menuSelection == 1)
                {
                    cout << "I tried!";
                    translator = new MorseCodeEncoder();
                    translator->translate(*sourceText);
                    menuSelection = nullptr;
                } else
                {
                    cout << &menuSelection;
                }
            }
        }
    }
private:
    int* menuSelection;
    string* sourceText;
    Translator* translator;
    void setMenuSelection()
    {
        int response;

        while (menuSelection == nullptr)
        {
            cout << "-\t-\tTranslation App\t-\t" << endl;
            cout << "1 - English To Morse Code" << endl;
            cout << "2 - Quit" << endl;
            cin >> response;

            if (response == 1 || response == 2) {menuSelection = &response;}
            else {invalidOption();}
            cin.clear();
        }

    };
    void invalidOption()
    {
        cout << "Invalid Option: Please input valid option!" << endl;
    }
    void setSourceText()
    {
        while (sourceText == nullptr)
        {
            string input;
            cout << "Please enter text to translate (50 character limit): " << endl;
            cin >> input;
            if (input.length() <= 50) {sourceText = &input;}
        }
    }
};

int main()
{
    TranslationApp* tester = new TranslationApp();
    tester->app();

    return 0;
}
