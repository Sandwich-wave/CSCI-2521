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
    virtual void translate(string* input) {}
    virtual ~Translator() = default;

};

class MorseCodeEncoder : public Translator
{
public:
    MorseCodeEncoder() : Translator(){}

    void translate(string* input) override
    {
        cout << toMorseCode(*input) << "\n" << endl;
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
            for (std::vector<string> &s: englishDictionary)
            {
                if (c == s[0][0])
                {
                    result += s[1];
                }
            }
            result += "\n";

        }
        return result;
    }

};

class TranslationApp
{
public:
    TranslationApp()
    {
        menuSelection = new int(0);
        sourceText = new string("");
        translator = new Translator();
    }
    ~TranslationApp()
    {
        delete menuSelection;
        delete sourceText;
        delete translator;
        menuSelection = nullptr;
        sourceText = nullptr;
        translator = nullptr;
    }
    void app()
    {
        while (*menuSelection != 2)
        {
            setMenuSelection();

            if (*menuSelection == 2)
            {
                break;

            }
            if (*menuSelection == 1)
            {
                setSourceText();

                delete translator;
                translator = new MorseCodeEncoder();
                translator->translate(sourceText);
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

        while (true)
        {
            cout << "-\t-\tTranslation App\t-\t" << endl;
            cout << "1 - English To Morse Code" << endl;
            cout << "2 - Quit" << endl;
            cin >> response;

            if (response == 1 || response == 2) {*menuSelection = response; break;}
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
        while (sourceText)
        {
            string input;
            cout << "Please enter text to translate (50 character limit): " << endl;
            cin >> input;
            if (input.length() <= 50) {*sourceText = input; break;}
        }
    }
};

int main()
{
    TranslationApp* tester = new TranslationApp();
    tester->app();

    return 0;
}
