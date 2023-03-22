/*
 * Copyright (C) Mohsen Zohrevandi, 2017
 *               Rida Bazzi 2019
 * Do not share this file with anyone
 */
#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <fstream>
#include "lexer.h"

using namespace std;

string readString;
string grammar;

LexicalAnalyzer* lexGrammar = new LexicalAnalyzer();
LexicalAnalyzer* lexRule = new LexicalAnalyzer();

class Rule {
    public:
        Token leftHand;
        std::vector<Token> rightHand;
};

vector<Rule> ruleList;

vector<string> Terminals;
vector<string> Nonterminals;

/*
Rule parseRule(string ruleInput) {
    //add LHS and RHS onto respective vectors
    //read input up to ARROW and make that LHS
    Rule rule;
    
    //lexical analyzer's token string = ruleInput
    lexRule->GetToken().lexeme = ruleInput;

    

    //get {LEFTHAND}
    rule.leftHand = lexRule->GetToken();
    std::cout << rule.leftHand.lexeme << endl;
    //add to nonterminal directly, anything in lefthand will be nonterminal
    Nonterminals.push_back(rule.leftHand.lexeme);
    
    //get {ARROW}
    //inputRule->GetToken();

    //get {RIGHTHAND}
    while (lexRule->peek(1).token_type != END_OF_FILE){
        if(lexRule->peek(1).token_type != ARROW) {
            rule.rightHand.push_back(lexRule->GetToken());
        }
        else {
            lexRule->GetToken();
        }
    }

    //add the final token into RHS because the while loop will stop before reading the last token
    rule.rightHand.push_back(lexRule->GetToken());
    
    //now return rule
    return rule;
}*/

// read grammar
void ReadGrammar()
{
    std::cout << "0\n";
    Rule* thisRule = new Rule();

    int i = 1;
    cout << "peek: " << lexGrammar->peek(i).lexeme << endl;
    while (lexGrammar->peek(i).lexeme != "HASH"){

        //get left hand side (first one)
        thisRule->leftHand = lexGrammar->peek(i);
        cout << "leftHand: " << thisRule->leftHand.lexeme << endl;
        //arrow isnt taken 

        //get right hand side 
        int j = 0;
        while (lexGrammar->peek(i).lexeme != "STAR"){
            thisRule->rightHand.push_back(lexGrammar->peek(i));
            cout << "rightHand: " << thisRule->rightHand[j].lexeme;
            i++;
            j++;
        }
        i++;
    }

    
    /*
    while (inputString != "#"){
        char star = '*';
        string ruleString = "";
        Rule thisRule;
        
        //gor through string till star
        for (int i = 0; i < inputString.length(); i++){
            //if star make rule
            if (inputString[i] == star){
                
                //use parseRule to return one individual rule using ruleString
                thisRule = parseRule(ruleString);

                //add to rule list
                ruleList.push_back(thisRule);

                //reset
                ruleString = "";

            }
            else{
                //get the one rule as a string (delimiter is star)
                ruleString += inputString[i];
            }
        }
        
        //get input - this input is one individual rule
        std::getline(std::cin, inputString); 
    }*/
}

//tells if it is an element in given list
bool isElement(string target) {
    for(int i = 0; i < Nonterminals.size(); i++) {
        if(Nonterminals[i] == target) {
            return true;
        }
    }
    return false;
}

bool isElement(string target, vector<string> list) {
    for(int i = 0; i < list.size(); i++) {
        if(target == list[i]) {
            return true;
        }
    }
    return false;
}

bool isTerminal(string target) {
    for(int i = 0; i < Terminals.size(); i++) {
        if(Terminals[i] == target) {
            return true;
        }
    }
    return false;
}

// Task 1
void printTerminalsAndNoneTerminals()
{
    std::cout << "1\n";

    //iterate through full ruleList
    for(int i = 0; i < ruleList.size(); i++) {
        //iterate through RHS of each rule
        for(int j = 0; j < ruleList[i].rightHand.size(); j++) {
            if(!isElement(ruleList[i].rightHand[j].lexeme)) {
                Terminals.push_back(ruleList[i].rightHand[j].lexeme);
            }
        }
    }

    //sort the terminal and nonTerminal list to be in order as they appear in the grammar
    //create sorted lists
    vector<string> sortedTerminals;
    vector<string> sortedNonterminals;

    //go each rule in the grammar
    for(int i = 0; i < ruleList.size(); i++) {
        //go through LHS first
        if(!isTerminal(ruleList[i].leftHand.lexeme) && !(isElement(ruleList[i].leftHand.lexeme, sortedNonterminals))) {
            sortedNonterminals.push_back(ruleList[i].leftHand.lexeme);
        }
        //go through RHS second
        for(int j = 0; j < ruleList[i].rightHand.size(); j++) {
            if(isTerminal(ruleList[i].rightHand[j].lexeme)  && !(isElement(ruleList[i].rightHand[j].lexeme, sortedTerminals))) {
                sortedTerminals.push_back(ruleList[i].rightHand[j].lexeme);
            }
            else if(!(isTerminal(ruleList[i].rightHand[j].lexeme))  && !(isElement(ruleList[i].rightHand[j].lexeme, sortedNonterminals))){
                sortedNonterminals.push_back(ruleList[i].rightHand[j].lexeme);
            }
        }
    }

    //print out the sorted lists
    for(int i = 0; i < sortedTerminals.size(); i++) {
        cout << sortedTerminals[i] << " ";
    }
    for(int i = 0; i < sortedNonterminals.size(); i++) {
        cout << sortedNonterminals[i] << " ";
    }
}



// Task 2
void RemoveUselessSymbols()

    //remove any rules that are A->episolon
    //go through the grammar if there are any RHS that are *, that is an epsilon rule and needs to be removed

    //remove any unaccessible rules S->AB, C->c, A->a, B->b: remove C->c
{
    std::cout << "2\n";
}

// Task 3
void CalculateFirstSets()
{
    std::cout << "3\n";

    //S->ABC, FIRST(S) = FIRST(A)
    //if FIRST(A) contains epsilon, FIRST(S) = FIRST(A) - epislon U FIRST(B)

    vector<string>  firstSets;

    //go throught the rule list for each nonterminal
    for(int i = 0; i < ruleList.size(); i++) {
        
    }
}

// Task 4
void CalculateFollowSets()
{
    std::cout << "4\n";
}

// Task 5
void CheckIfGrammarHasPredictiveParser()
{
    std::cout << "5\n";
}
    
int main (int argc, char* argv[])
{
    int task;

    if (argc < 2)
    {
        std::cout << "Error: missing argument\n";
        return 1;
    }

    /*
       Note that by convention argv[0] is the name of your executable,
       and the first argument to your program is stored in argv[1]
     */

    task = atoi(argv[1]);
    
    ReadGrammar();  // Reads the input grammar from standard input
                    // and represent it internally in data structures
                    // ad described in project 2 presentation file

    switch (task) {
        case 1: printTerminalsAndNoneTerminals();
            break;

        case 2: RemoveUselessSymbols();
            break;

        case 3: CalculateFirstSets();
            break;

        case 4: CalculateFollowSets();
            break;

        case 5: CheckIfGrammarHasPredictiveParser();
            break;

        default:
            std::cout << "Error: unrecognized task number " << task << "\n";
            break;
    }
    return 0;
}
