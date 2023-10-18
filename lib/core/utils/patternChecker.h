//
// Created by Bennett Westfall on 10/16/23.
//

#ifndef DECKOFCARDS_PATTERNCHECKER_H
#define DECKOFCARDS_PATTERNCHECKER_H

#include <vector>
#include "card/cards.h"
#include "../piles.h"


class Rule {
public:
// Variables
    enum RuleType {
        RUN,
        SET
    };
    RuleType ruleType;
    int numCards;
    int points{};

    // Constructor and Destructor
    Rule(RuleType ruleType, int numCards);
    Rule(RuleType ruleType, int numCards, int points);
    ~Rule();

    // Methods
    bool checkRule(Set &cards);


};

class Rules {
public:
    // Variables
    std::vector<Rule> rules;
    void addRule(Rule rule);
    void removeRule(Rule rule);
    bool checkRules(Pile pile);



};

class patternChecker {
public:
    // Variables

    // Constructor and Destructor
    patternChecker();
    ~patternChecker();

    // Methods
    bool isRun(std::vector<Card> cards);
    bool isSet(std::vector<Card> cards);
    bool hasRun(std::vector<Card> cards);
    bool hasSet(std::vector<Card> cards);
    int numRuns(std::vector<Card> cards);
    int numSets(std::vector<Card> cards);
    int numCardsInRun(std::vector<Card> cards);
    int numCardsInSet(std::vector<Card> cards);

protected:
    // Variables
    Rules rules;
};





#endif //DECKOFCARDS_PATTERNCHECKER_H
