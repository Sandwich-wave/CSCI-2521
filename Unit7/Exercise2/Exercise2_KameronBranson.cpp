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
 * @class Translator
 * @brief Abstract translator class
 */

class Translator
{
public:
    /**
     * @brief Translates provided input string
     * @param input pointer to string to be translated
     */
    virtual void translate(string* input) {}

    /**
     * @brief Virtual default destructor
     */
    virtual ~Translator() = default;

};

/**
 * @class MorseCodeEncoder
 * @brief MorseCodeEncoder implementation of Translator
 */
class MorseCodeEncoder : public Translator
{
public:
    /**
     * @brief default constructor for MorseCodeEncoder
     */
    MorseCodeEncoder() : Translator(){}

    /**
     * @brief Translates English string to morse code and outputs result
     * @param input pointer to user gathered input
     */
    void translate(string* input) override
    {
        cout << toMorseCode(*input) << "\n" << endl;
    };

private:
    /**
     * @brief mapping table to lookup uppercase English characters to gather equivalent
     * @
     */
    std::vector<std::vector<string>> englishDictionary = {
        {"A", ".-"},   {"B", "-..."}, {"C", "-.-."}, {"D", "-.."},
        {"E", "."},    {"F", "..-."}, {"G", "--."},  {"H", "...."},
        {"I", ".."},   {"J", ".---"}, {"K", "-.-"},  {"L", ".-.."},
        {"M", "--"},   {"N", "-."},   {"O", "---"},  {"P", ".--."},
        {"Q", "--.-"}, {"R", ".-."},  {"S", "..."},  {"T", "-"},
        {"U", "..-"},  {"V", "...-"}, {"W", ".--"},  {"X", "-..-"},
        {"Y", "-.--"}, {"Z", "--.."}
    };

    /**
     * @brief Converts lowercase characters to uppercase in place
     * @param input Reference to string to be converted to uppercase
     */
    void englishToUpperCase(string &input)
    {
        for (char &s: input)
        {
            s = toupper(s);
        }
    };

    /**
     * @brief Encodes English string to morse code and displays each character on a new line
     * @param input Reference to string to encode
     * @return String with morse code for each character passed in input reference
     */
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

/**
 * @class TranslationApp
 * @brief Handles user interaction, input validation, and translation
 */
class TranslationApp
{
public:
    /**
     * @brief Constructs TranslationApp object and allocates memory
     */
    TranslationApp()
    {
        menuSelection = new int(0);
        sourceText = new string("");
        translator = new Translator();
    }

    /**
     * @brief Deconstructor that frees allocated memory and nulls pointer
     */
    ~TranslationApp()
    {
        delete menuSelection;
        delete sourceText;
        delete translator;
        menuSelection = nullptr;
        sourceText = nullptr;
        translator = nullptr;
    }

    /**
     * @brief Runs the main application until user selects option to quit
     */
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
    /** @brief Pointer storing current menu choice*/
    int* menuSelection;
    /** @brief Pointer storing user text for translation*/
    string* sourceText;
    /** @brief Pointer storing active Translator*/
    Translator* translator;

    /**
     * @brief Displays menu and prompts user until valid selection is given
     */
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

    /**
     * @brief Displays error when user provides invalid menu option
     */
    void invalidOption()
    {
        cout << "Invalid Option: Please input valid option!" << endl;
    }

    /**
     * @brief Prompts user to enter text for translation with 50 character limit
     */
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

/**
 * @brief Entry point for Translator Application
 * @return 0 upon successful termination of TranslationApp
 */
int main()
{
    TranslationApp* tester = new TranslationApp();
    tester->app();
    delete tester;

    return 0;
}
