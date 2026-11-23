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
    virtual void translate() {}
    virtual const std::vector<std::vector<std::string>> getDictionary() {};
};

class MorseCodeEncoder : public Translator
{
public:
    MorseCodeEncoder() : Translator()
    {

    };
    void translate()
    {

    };

private:
    std::vector<std::vector<std::string>> dictionary = {
        {"A", ".-"},   {"B", "-..."}, {"C", "-.-."}, {"D", "-.."},
        {"E", "."},    {"F", "..-."}, {"G", "--."},  {"H", "...."},
        {"I", ".."},   {"J", ".---"}, {"K", "-.-"},  {"L", ".-.."},
        {"M", "--"},   {"N", "-."},   {"O", "---"},  {"P", ".--."},
        {"Q", "--.-"}, {"R", ".-."},  {"S", "..."},  {"T", "-"},
        {"U", "..-"},  {"V", "...-"}, {"W", ".--"},  {"X", "-..-"},
        {"Y", "-.--"}, {"Z", "--.."}
    };
    const std::vector<std::vector<std::string>> getDictionary() override
    {
        return dictionary;
    }

};

class TranslationApp
{
public:
    TranslationApp() :
};

int main()
{
    MorseCodeEncoder encoder;
    encoder.dictionary = {};

    return 0;
}
