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
protected:
    virtual ~Translator() = default;
    virtual void translate(string input) {}
};

class MorseCodeEncoder : public Translator
{
public:
    MorseCodeEncoder() : Translator()
    {

    };

protected:
    void translate(string &input) override
    {
        string result = "";
        englishToUpperCase(input);

        for (int i = 0; i < input.length(); i++)
        {

        }

    };

private:
    std::vector<std::vector<std::string>> englishDictionary = {
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




};

class TranslationApp
{
public:
    TranslationApp()
    {

    }
};

int main()
{
    MorseCodeEncoder encoder;
    encoder;

    return 0;
}
